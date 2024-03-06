#include <iostream>
#include <stdlib.h>

using namespace std;

class Nodo
{
public:
    Nodo()
    {
        dato = "";
        siguiente = NULL;
    }

    Nodo(string _dato)
    {
        dato = _dato;
        siguiente = NULL;
    }

    Nodo(string _dato, Nodo* _siguiente)
    {
        dato = _dato;
        siguiente = _siguiente;
    }

private:
    string dato;
    Nodo* siguiente;

    friend class lista;
    friend class listaD;
};

typedef Nodo* pnodo;


class Nodo2
{
public:
    Nodo2(string _dato)
    {
        dato = _dato;
        siguiente = NULL;
        anterior = NULL;
    }

    Nodo2(string _dato, Nodo2* _siguiente)
    {
        dato = _dato;
        siguiente = _siguiente;
        anterior = NULL;
    }

private:
    string dato;
    Nodo2* siguiente;
    Nodo2* anterior;

    friend class lista;
    friend class listaD;
};

typedef Nodo2* pnodo2;



class listaD
{
public:
    listaD() { primero = NULL; }
    ~listaD();

    bool ListaVacia() { return primero == NULL; }
    int largoLista();
    void InsertarInicio(string dato);
    void InsertarFinal(string dato);
    void InsertarPos(string dato, int pos);
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();

private:
    pnodo2 primero;

    friend class lista;
};

listaD::~listaD()
{
    pnodo2 aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

int listaD::largoLista()
{
    int cont = 0;

    pnodo2 aux = primero;

    if (ListaVacia())
        return cont;
    else
    {
        while (aux != NULL)
        {
            aux = aux->siguiente;
            cont++;
        }

        return cont;
    }
}

void listaD::InsertarInicio(string dato)
{
    if (ListaVacia())
        primero = new Nodo2(dato);
    else
    {
        primero = new Nodo2(dato, primero);
        primero->siguiente->anterior = primero;
    }
}

void listaD::InsertarFinal(string dato)
{
    if (ListaVacia())
        primero = new Nodo2(dato);
    else
    {
        pnodo2 aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new Nodo2(dato);
        aux->siguiente->anterior = aux;
    }
}

void listaD::InsertarPos(string dato, int pos)
{
    if (ListaVacia())
        primero = new Nodo2(dato);
    else
    {
        if (pos <= 1)
            InsertarInicio(dato);
        else
        {
            pnodo2 aux = primero;

            int i = 2;
            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodo2 nuevo = new Nodo2(dato);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
            aux->siguiente->anterior = aux;
            nuevo->siguiente->anterior = nuevo;
        }
    }
}

void listaD::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
            primero = NULL;
        else
        {
            pnodo2 aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}

void listaD::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
            primero = NULL;
        else
        {
            pnodo2 aux = primero;

            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodo2 temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void listaD::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista est� vac�a." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posici�n." << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                if (pos == largoLista())
                    BorrarFinal();
                else
                {
                    pnodo2 aux = primero;

                    int cont = 2;
                    while (cont < pos)
                    {
                        aux = aux->siguiente;
                        cont++;
                    }

                    pnodo2 temp = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;
                    aux->siguiente->anterior = aux;
                    delete temp;
                }
            }
        }
    }
}

void listaD::Mostrar()
{
    pnodo2 aux = primero;
    
    while (aux)
    {
        cout << aux->dato << ", ";
        aux = aux->siguiente;
    }

    cout << endl;
}

/* Aquí debe ir un método que controle la pila y la expresión y
 * otro método que evalue la expresión correspondiente */



class lista
{
public:
    lista() { primero = NULL; }
    ~lista();

    bool ListaVacia() { return primero == NULL; }
    int largoLista();
    void InsertarInicio(string dato);
    void InsertarFinal(string dato);
    void InsertarPos(string dato, int pos);
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();

private:
    pnodo primero;
};

lista::~lista()
{
    pnodo aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}


int lista::largoLista()
{
    pnodo aux = primero;

    int cont = 0;
    if (ListaVacia())
        return cont;
    else
    {
        while (aux != NULL)
        {
            aux = aux->siguiente;
            cont++;
        }

        return cont;
    }
}

void lista::InsertarInicio(string dato)
{
    if (ListaVacia())
        primero = new Nodo(dato);
    else
        primero = new Nodo(dato, primero);
}

void lista::InsertarFinal(string dato)
{
    if (ListaVacia())
        primero = new Nodo(dato);
    else
    {
        pnodo aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new Nodo(dato);
    }
}

void lista::InsertarPos(string dato, int pos)
{
    if (ListaVacia())
        primero = new Nodo(dato);
    else
    {
        if (pos <= 1)
        {
            pnodo nuevo = new Nodo(dato);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else
        {
            pnodo aux = primero;

            int i = 2;
            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodo nuevo = new Nodo(dato);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void lista::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
            primero = NULL;
        else
        {
            pnodo aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}

void lista::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista." << endl;
    else
    {
        if (primero->siguiente == NULL)
            primero = NULL;
        else
        {
            pnodo aux = primero;

            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodo temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void lista::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "La lista est� vac�a." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posici�n." << endl;
        else
        {
            if (pos == 1)
                primero = primero->siguiente;
            else
            {
                pnodo aux = primero;

                int cont = 2;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }

                aux->siguiente = aux->siguiente->siguiente;
            }
        }
    }
}

void lista::Mostrar()
{
    pnodo aux;

    if (primero == NULL)
        cout << "No hay elementos.";
    else
    {
        aux = primero;

        while (aux)
        {
            cout << aux->dato << ", ";
            aux = aux->siguiente;
        }

        cout << endl;
    }
}



int main()
{
	cout << "Main" << endl;
	cout << endl;

	system("pause");
	return 0;
}

