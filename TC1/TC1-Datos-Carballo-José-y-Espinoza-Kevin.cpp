#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
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



class pila
{
private:
    int Tope;
    string Pila[5];

public:
    pila()
    {
        Tope = -1;
        for (int i = 0; i < 5; i++)
            Pila[i] = "";
    }

    bool pilaVacia() { return Tope < 0; }
    void push(string dato);
    void pop();
    void imprimir();
    string top();
};


void pila::push(string dato)
{
    if (Tope < (5 - 1))
    {
        Tope++;
        Pila[Tope] = dato;
    }
}

void pila::pop()
{
    if (!pilaVacia())
        Tope--;
}

void pila::imprimir()
{
    for (int i = Tope; i >= 0; i--)
        cout << Pila[i] << " -> ";
}

string pila::top()
{
    int e = Tope;
    return Pila[e];
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
    void convertirExpresionAPostfijo(pnodo aux, listaD pila);
    void crearCola(pnodo Cola[]);
    void evaluar(pila pila);
    
    string to_string(double valor);

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

void lista::convertirExpresionAPostfijo(pnodo aux, listaD pila)
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
            if (pila.ListaVacia())
                pila.InsertarFinal(aux->dato);

            if (aux->dato == ")")
            {
                pnodo2 aux2 = pila.primero;
                bool bandera = false;

                while (aux2->siguiente != NULL)
                    aux2 = aux2->siguiente;

                while ((aux2->dato != "(") && (aux2 != pila.primero))
                {
                    InsertarFinal(aux2->dato);
                    pila.BorrarFinal();
                    aux2 = aux2->anterior;
                    bandera = true;
                }

                if (bandera == true)
                    pila.BorrarFinal();
            }
            else
            {
                int numPrioridadActual = 0;
                int numPrioridadEnPila = 0;

                for (int i = 0; i < 18; i += 3)
                {
                    if ((aux->dato == tablaPrioridades[i]) && (!isdigit(tablaPrioridades[i][0])))
                    {
                        string prioridadActual = "";
                        string prioridadEnPila = "";
                        
						prioridadActual = tablaPrioridades[i + 1];

                        pnodo2 ante = pila.primero;

                        while (ante->siguiente != NULL)
                            ante = ante->siguiente;

                        for (int j = 0; j < 18; j += 3)
                        {
                            if ((ante->dato == tablaPrioridades[j]) && (pila.primero != NULL))
                                prioridadEnPila = tablaPrioridades[j + 2];
                        }

                        istringstream(prioridadActual) >> numPrioridadActual;
                        istringstream(prioridadEnPila) >> numPrioridadEnPila;

                        if (numPrioridadActual > numPrioridadEnPila)
                            pila.InsertarFinal(aux->dato);
                        else
                        {
                            pnodo2 aux3 = pila.primero;

                            while (aux3->siguiente != NULL)
                                aux3 = aux3->siguiente;

                            InsertarFinal(aux3->dato);
                            pila.BorrarFinal();
                            pila.InsertarFinal(aux->dato);
                        }
                    }
                }
            }
        }
        else
            InsertarFinal(aux->dato);

        aux = aux->siguiente;
        
        pila.Mostrar();
    }

    if (pila.primero != NULL)
    {
        pnodo2 operadores = pila.primero;

        int cont = 1;
        while (operadores)
        {
            if (operadores->dato != "(")
            {
                InsertarFinal(operadores->dato);
                pila.BorrarPosicion(cont);
            }

            operadores = operadores->siguiente;
            cont++;
        }
    }

    cout << "\nLista Postfijo:" << endl;
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
    float num1, num2, resultado;
    bool divisionEntreCero = false;

    while (aux != NULL)
    {
        if (isdigit(aux->dato[0]))
        {
            pila.push(aux->dato);
            pila.imprimir();
            cout << endl;
        }
        
        if (aux->dato == "+")
        {
        	istringstream(pila.top()) >> num2;
            pila.pop();
            istringstream(pila.top()) >> num1;
            pila.pop();
            resultado = num1 + num2;
            pila.push(to_string(resultado));
            pila.imprimir();
            cout << endl;
        }
        
        if (aux->dato == "-")
        {
            istringstream(pila.top()) >> num2;
            pila.pop();
            istringstream(pila.top()) >> num1;
            pila.pop();
            resultado = num1 - num2;
            pila.push(to_string(resultado));
            pila.imprimir();
            cout << endl;
        }
        
        if (aux->dato == "*")
        {
            istringstream(pila.top()) >> num2;
            pila.pop();
            istringstream(pila.top()) >> num1;
            pila.pop();
            resultado = num1 * num2;
            pila.push(to_string(resultado));
            pila.imprimir();
            cout << endl;
        }
        
        if (aux->dato == "/")
        {
            istringstream(pila.top()) >> num2;
            pila.pop();
            istringstream(pila.top()) >> num1;
            pila.pop();
            
            if (num2 == 0)
            {
                cout << "Error: División entre 0." << endl;
                divisionEntreCero = true;
                break;
            }
            else
                resultado = num1 / num2;
            
            pila.push(to_string(resultado));
            pila.imprimir();
            cout << endl;   
        }
        
        if (aux->dato == "^")
        {
            istringstream(pila.top()) >> num2;
            pila.pop();
            istringstream(pila.top()) >> num1;
            pila.pop();
            resultado = pow(num1, num2);
            pila.push(to_string(resultado));
            pila.imprimir();
            cout << endl;
        }

        aux = aux->siguiente;
    }
    
    cout << "\nResultado Final: " << resultado;
}

string lista::to_string(double valor)
{
	ostringstream oss;
    oss << valor;
    
    return oss.str();	
}



int main()
{
    lista lista, listaPostfijo;

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
        for (int i = 0; i < 50; i++)
            cout.put(char(220));

        cout << endl;
        
        listaPila.~listaD();
        listaPostfijo.~lista();
        cout << endl;
        cout << "Expresion original:" << endl;
        lista.mostrarExpresion(Cola[expresion]);
        listaPostfijo.convertirExpresionAPostfijo(Cola[expresion], listaPila);

        for (int i = 0; i < 50; i++)
            cout.put(char(205));
        
        cout << endl;

        listaPostfijo.evaluar(pila);

        pila.pop();

        cout << endl;
    }
    
    cout << endl;
    
    system("pause");
    return 0;
}
