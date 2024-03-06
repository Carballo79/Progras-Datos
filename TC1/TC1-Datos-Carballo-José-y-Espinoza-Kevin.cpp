#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>

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
    void convertirExpresionAPostfijo(pnodo aux, listaD pila);

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
        cout << "La lista está vacía." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posición." << endl;
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

void listaD::convertirExpresionAPostfijo(pnodo aux, listaD pila)
{
    string tablaPrioridades[] = {
        "^", "4", "3",
        "*", "2", "2",
        "/", "2", "2",
        "+", "1", "1",
        "-", "1", "1",
        "(", "5", "0"
    };

    while (aux)
    {
        if (!isdigit(aux->dato[0]))
        {
            if (pila.ListaVacia() || aux->dato == "(")
                pila.InsertarFinal(aux->dato);
            else if (aux->dato == ")")
            {
                while (pila.primero && pila.primero->dato != "(")
                {
                    InsertarFinal(pila.primero->dato);
                    pila.BorrarInicio();
                }
                
                if (pila.primero && pila.primero->dato == "(")
                    pila.BorrarInicio();
            }
            else
            {
                int numPrioridadActual = 0;
                int numPrioridadEnPila = 0;
                string prioridadActual = "";
                string prioridadEnPila = "";

                for (int i = 0; i < 18; i += 3)
                {
                    if (aux->dato == tablaPrioridades[i])
                    {
                        prioridadActual = tablaPrioridades[i + 1];
                        pnodo2 anterior = pila.primero;
                        while (anterior && anterior->siguiente)
                            anterior = anterior->siguiente;

                        for (int j = 0; j < 18; j += 3)
                        {
                            if (anterior && anterior->dato == tablaPrioridades[j])
                                prioridadEnPila = tablaPrioridades[j + 2];
                        }
                        
                        break;
                    }
                }
                
                istringstream(prioridadActual) >> numPrioridadActual;
                istringstream(prioridadEnPila) >> numPrioridadEnPila;

                if (numPrioridadActual > numPrioridadEnPila)
                    pila.InsertarFinal(aux->dato);
                else
                {
                    InsertarFinal(pila.primero->dato);
                    pila.BorrarInicio();
                    pila.InsertarFinal(aux->dato);
                }
            }
        }
        else
            InsertarFinal(aux->dato);

        aux = aux->siguiente;
    }

    while (pila.primero)
    {
        if (pila.primero->dato != "(")
        {
            InsertarFinal(pila.primero->dato);
            pila.BorrarInicio();
        }
        else
            pila.BorrarInicio();
    }

    cout << endl << "Lista Pila:" << endl;
    pila.Mostrar();
    cout << endl << "Lista Postfijo:" << endl;
    Mostrar();
}



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
    void mostrarExpresion(pnodo aux);
    void crearCola(pnodo Cola[]);

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
        cout << "La lista está vacía." << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posición." << endl;
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

void lista::mostrarExpresion(pnodo aux)
{
    aux = aux->siguiente;

    if (aux == NULL)
        cout << "No hay elementos.";
    else
    {
        while (aux->siguiente != NULL)
        {
            cout << aux->dato;
            aux = aux->siguiente;
        }

        cout << endl;
    }
}

void lista::crearCola(pnodo Cola[])
{
    string linea = "";
    ifstream archivo;
    pnodo aux = NULL;

    for (int i = 0; i < 5; i++)
    {
        stringstream nombreArchivo;
        nombreArchivo << "Arch" << (i + 1) << ".txt";

        archivo.open(nombreArchivo.str().c_str());
        if (!archivo)
		{
            cout << "No se pudo abrir el archivo: " << nombreArchivo.str() << endl;
            continue;
        }

        Cola[i]->dato = "(";
        while (getline(archivo, linea))
		{
            aux = Cola[i];
            while (aux->siguiente != NULL)
                aux = aux->siguiente;

            aux->siguiente = new Nodo(linea);
        }

        if (Cola[i]->siguiente != NULL)
            aux->siguiente->siguiente = new Nodo(")");

        archivo.close();
    }
}



int main()
{
	lista lista;

    pnodo primeroL1 = new Nodo();
    pnodo primeroL2 = new Nodo();
    pnodo primeroL3 = new Nodo();
    pnodo primeroL4 = new Nodo();
    pnodo primeroL5 = new Nodo();

    pnodo Cola[5] = {primeroL1, primeroL2, primeroL3, primeroL4, primeroL5};

    lista.crearCola(Cola);

    listaD pila, postfijo;

    cout << "Tarea Corta #1 - Estructuras de Datos" << endl;
    cout << "Estudiantes:" << endl;
    cout << "  + Jose Carballo Martinez" << endl;
    cout << "  + Kevin Espinoza Barrantes" << endl;

    for (int expresion = 0; expresion < 5; expresion++)
    {
        cout << endl;
        for (int i = 0; i < 45; i++)
            cout.put(char(220));

        cout << endl;
        
        pila.~listaD();
        postfijo.~listaD();
        cout << endl;
        cout << "Expresion original:" << endl;
        lista.mostrarExpresion(Cola[expresion]);
        postfijo.convertirExpresionAPostfijo(Cola[expresion], pila);

        for (int i = 0; i < 45; i++)
            cout.put(char(205));
        
        cout << endl;
    }
    
    cout << endl;

	system("pause");
	return 0;
}

