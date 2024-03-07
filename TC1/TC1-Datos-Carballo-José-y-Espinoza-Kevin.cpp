#include <cctype>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>

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

    friend class listaD;
    friend class lista;
};

typedef Nodo2* pnodo2;



class pila
{
private:
    int Tope;
    double Pila[5];

public:
    pila()
    {
        Tope = -1;
        for (int i = 0; i < 5; i++)
            Pila[i] = 0;
    }

    bool pilaVacia() { return Tope < 0; }
    void push(double v);
    void pop();
    void imprimir();
    double top();
};


void pila::push(double v)
{
    if (Tope < (5 - 1))
    {
        Tope++;
        Pila[Tope] = v;
    }
    else
        cout << "La pila esta llena.";
}

void pila::pop()
{
    if (!pilaVacia())
        Tope--;
    else
        cout << "La pila esta vacia.";
}

void pila::imprimir()
{
    for (int i = Tope; i >= 0; i--)
        cout << Pila[i] << " -> ";
}

double pila::top()
{
    int e = Tope;
    return Pila[e];
}



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
    //void convertirExpresionAPostfijo(pnodo aux, pila pila);
    //void evaluar(pila& pila);

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
    void convertirExpresionAPostfijo(pnodo aux, pila pila);
    void crearCola(pnodo Cola[]);
    void evaluar(pila pila);

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

void lista::convertirExpresionAPostfijo(pnodo aux, pila pila)
{
    string tablaPrioridades[] = {
        "^", "4", "3",
        "*", "2", "2",
        "/", "2", "2",
        "+", "1", "1",
        "-", "1", "1",
        "(", "5", "0"
    };

    cout << "\nLista Pila:" << endl;

    while (aux)
    {
        if (!isdigit(aux->dato[0]))
        {
            if (pila.pilaVacia())
                pila.push(0.0); // Valor arbitrario, ya que los operadores no importan en este contexto
            else if (aux->dato == ")")
            {
                while (pila.top() != 0.0 && !pila.pilaVacia())
                {
                    InsertarFinal(to_string(static_cast<int>(pila.top()))); // Inserta el operador en la lista
                    pila.pop();
                }
                if (pila.top() == 0.0)
                    pila.pop(); // Elimina el valor arbitrario de la pila
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

                        if (!pila.pilaVacia())
                        {
                            double topElement;
                            stringstream(pila.top()) >> topElement;
                            for (int j = 0; j < 18; j += 3)
                            {
                                if (topElement == stoi(tablaPrioridades[j]))
                                    prioridadEnPila = tablaPrioridades[j + 2];
                            }
                        }

                        istringstream(prioridadActual) >> numPrioridadActual;
                        istringstream(prioridadEnPila) >> numPrioridadEnPila;

                        if (numPrioridadActual > numPrioridadEnPila)
                            pila.push(stod(aux->dato));
                        else
                        {
                            while (!pila.pilaVacia() && numPrioridadActual <= numPrioridadEnPila)
                            {
                                InsertarFinal(to_string(static_cast<int>(pila.top())));
                                pila.pop();
                                if (!pila.pilaVacia()) {
                                    double newTopElement;
                                    stringstream(pila.top()) >> newTopElement;
                                    for (int j = 0; j < 18; j += 3)
                                    {
                                        if (newTopElement == stoi(tablaPrioridades[j]))
                                            prioridadEnPila = tablaPrioridades[j + 2];
                                    }
                                    istringstream(prioridadEnPila) >> numPrioridadEnPila;
                                }
                            }
                            pila.push(stod(aux->dato));
                        }
                    }
                }
            }
        }
        else
            InsertarFinal(aux->dato);

        aux = aux->siguiente;

        pila.imprimir();
    }

    while (!pila.pilaVacia())
    {
        InsertarFinal(to_string(static_cast<int>(pila.top())));
        pila.pop();
    }

    cout << endl << "Lista Postfijo:" << endl;
    Mostrar();
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

void lista::evaluar(pila pila)
{
    pnodo aux = primero;
    double num1, num2, resultado;

    while (aux != NULL)
    {
        if (isdigit(aux->dato[0]))
        {
            pila.push(stod(aux->dato));
            pila.imprimir();
            cout << endl;
        }
        if (aux->dato == "+")
        {
            num2 = pila.top();
            pila.pop();
            num1 = pila.top();
            pila.pop();
            resultado = num1 + num2;
            pila.push(resultado);
            pila.imprimir();
            cout << endl;
        }
        if (aux->dato == "-")
        {
            num2 = pila.top();
            pila.pop();
            num1 = pila.top();
            pila.pop();
            resultado = num1 - num2;
            pila.push(resultado);
            pila.imprimir();
            cout << endl;
        }
        if (aux->dato == "*")
        {
            num2 = pila.top();
            pila.pop();
            num1 = pila.top();
            pila.pop();
            resultado = num1 * num2;
            pila.push(resultado);
            pila.imprimir();
            cout << endl;
        }
        if (aux->dato == "/")
        {
            num2 = pila.top();
            pila.pop();
            num1 = pila.top();
            pila.pop();
            if (num2 == 0) {
                cout << "";
            }
            resultado = num1 / num2;
            pila.push(resultado);
            pila.imprimir();
            cout << endl;

            
        }
        if (aux->dato == "^")
        {
            num2 = pila.top();
            pila.pop();
            num1 = pila.top();
            pila.pop();
            resultado = pow(num1, num2);
            pila.push(resultado);
            pila.imprimir();
            cout << endl;
        }

        aux = aux->siguiente;
    }
    pila.imprimir();
}




int main()
{
	lista lista, postfijo;

    pnodo primeroL1 = new Nodo();
    pnodo primeroL2 = new Nodo();
    pnodo primeroL3 = new Nodo();
    pnodo primeroL4 = new Nodo();
    pnodo primeroL5 = new Nodo();

    pnodo Cola[5] = {primeroL1, primeroL2, primeroL3, primeroL4, primeroL5};

    lista.crearCola(Cola);

    listaD listaPila;
    pila pila;

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
        
        // pila.~listaD();
        postfijo.~lista();
        cout << endl;
        cout << "Expresion original:" << endl;
        lista.mostrarExpresion(Cola[expresion]);
        postfijo.convertirExpresionAPostfijo(Cola[expresion], pila);

        for (int i = 0; i < 45; i++)
            cout.put(char(205));
        
        cout << endl;

        postfijo.evaluar(pila);

        pila.pop();

        cout << endl;
    }
    
    cout << endl;

	system("pause");
	return 0;
}

