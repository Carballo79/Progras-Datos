// Estudiantes: José Carballo Martínez y Kevin Espinoza Barrantes

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;

class NodoLista
{
public:
    NodoLista()
    {
        valor = "";
        siguiente = NULL;
    }

    NodoLista(string _valor)
    {
        valor = _valor;
        siguiente = NULL;
    }

    NodoLista(string _valor, NodoLista* _siguiente)
    {
        valor = _valor;
        siguiente = _siguiente;
    }

private:
    string valor;
    NodoLista* siguiente;

    friend class Cola;
	friend class Pila;
};

typedef NodoLista* pnodoLista;


class NodoBinario
{
public:
    NodoBinario(string _valor)
    {
        valor = _valor;
        derecho = NULL;
        izquierdo = NULL;
        siguiente = NULL;
    }

    NodoBinario(string _valor, NodoBinario* _siguiente)
    {
        valor = _valor;
        derecho = NULL;
        izquierdo = NULL;
        siguiente = _siguiente;
    }

private:
    string valor;
    NodoBinario* derecho;
    NodoBinario* izquierdo;
    NodoBinario* siguiente;

    friend class Cola;
	friend class Pila;
};

typedef NodoBinario* pnodoBinario;


class Pila
{
public:
    Pila() { tope = NULL; }
    bool pilaVacia() { return tope == NULL; }
    pnodoBinario top();
    void push(pnodoBinario nuevo);
    void pop();
    void imprimir();
    double stringADouble(string str);
    double evaluar(pnodoBinario raiz);

private:
    pnodoBinario tope;
};


class Cola
{
public:
    Cola()
    {
        frente = 0;
        fondo = -1;

        for (int i = 0; i < 5; i++)
            cola[i] = new NodoLista();
    }

    bool ColaVacia() { return (fondo < frente); }
    void crearCola(pnodoLista cola[]);
    void imprimir();
    void imprimir(int i);
    bool esNumero(string str);
    string intAString(int num);
    pnodoBinario crearArbolExpresion(int i);
    void manejarOperador(Pila& pilaOperadores, Pila& resultados,
		    ofstream& archivoResultado, ofstream& archivo);
    void manejarOperando(string valor, Pila& pilaOperadores, 
            Pila& resultados, ofstream& archivo, ofstream& archivoResultado);
    void imprimirResultados(Pila& resultados);
    int prioridadFuera(string c);
    int prioridadDentro(string c);
    void expresionInfija(pnodoBinario raiz);
    void expresionPostfija(pnodoBinario raiz);
    void expresionPrefija(pnodoBinario raiz);

	pnodoLista* getCola() { return cola; }

private:
    int frente;
    int fondo;
    pnodoLista cola[5];
};



// ---------- Comportamientos de la clase Pila ----------
pnodoBinario Pila::top()
{
    if (pilaVacia())
        return NULL;

    return tope;
}

void Pila::push(pnodoBinario nuevo)
{
    if (pilaVacia())
        tope = nuevo;
    else
    {
        nuevo->siguiente = tope;
        tope = nuevo;
    }
}

void Pila::pop()
{
    if (pilaVacia())
        cout << "No hay elementos en la pila." << endl;
    else
    {
        if (tope->siguiente == NULL)
            tope = NULL;
        else
        {
            pnodoBinario aux = tope;
            tope = tope->siguiente;
            aux->siguiente = NULL;
        }
    }
}

void Pila::imprimir()
{
    if (!pilaVacia())
    {
        cout << "Pila: ";
        pnodoBinario temp = tope;

        while (temp->siguiente != NULL)
        {
            cout << temp->valor << " <- ";
            temp = temp->siguiente;
        }

        cout << temp->valor << endl;
    }
    else
        cout << "La pila esta vacia." << endl;
}

double Pila::stringADouble(string str)
{
    istringstream iss(str);
    double res;
    iss >> res;

    return res;
}

double Pila::evaluar(pnodoBinario raiz)
{
    if (raiz->valor == "+")
	{
		if ((raiz->izquierdo == NULL) && (raiz->derecho != NULL))
			return (0 + evaluar(raiz->derecho));

		if ((raiz->izquierdo != NULL) && (raiz->derecho == NULL))
			return (evaluar(raiz->izquierdo) + 0);

		if ((raiz->izquierdo != NULL) && (raiz->derecho != NULL))
			return (evaluar(raiz->izquierdo) + evaluar(raiz->derecho));
	}

	if (raiz->valor == "-")
	{
        if ((raiz->izquierdo == NULL) && (raiz->derecho != NULL))
			return (0 - evaluar(raiz->derecho));

		if ((raiz->izquierdo != NULL) && (raiz->derecho == NULL))
			return (evaluar(raiz->izquierdo) - 0);

		if ((raiz->izquierdo != NULL) && (raiz->derecho != NULL))
			return (evaluar(raiz->izquierdo) - evaluar(raiz->derecho));
    }

	if (raiz->valor == "/")
	{
		if ((raiz->izquierdo == NULL) && (raiz->derecho != NULL))
		{
			cout << "Division entre cero. Se considerara que esta division da 0.";
			return 0;
		}

		if ((raiz->izquierdo != NULL) && (raiz->derecho == NULL))
		{
			cout << "Division entre cero. Se considerara que esta division da 0.";
			return 0;
		}

		if ((raiz->izquierdo != NULL) && (raiz->derecho != NULL))
			return (evaluar(raiz->izquierdo) / evaluar(raiz->derecho));
	}

	if (raiz->valor == "*")
	{
		if ((raiz->izquierdo == NULL) && (raiz->derecho != NULL))
			return (0 * evaluar(raiz->derecho));

		if ((raiz->izquierdo != NULL) && (raiz->derecho == NULL))
			return (evaluar(raiz->izquierdo) * 0);

		if ((raiz->izquierdo != NULL) && (raiz->derecho != NULL))
			return (evaluar(raiz->izquierdo) * evaluar(raiz->derecho));
	}

	if (raiz->valor == "^")
	{
		if ((raiz->izquierdo != NULL) && (raiz->derecho == NULL))
			return (pow(evaluar(raiz->izquierdo), 0));

		if ((raiz->izquierdo == NULL) && (raiz->derecho != NULL))
			return (pow(0, evaluar(raiz->derecho)));

		if ((raiz->izquierdo != NULL) && (raiz->derecho != NULL))
			return (pow(evaluar(raiz->izquierdo), evaluar(raiz->derecho)));
	}
	
	return stringADouble(raiz->valor);
}



// ---------- Comportamientos de la clase Cola ----------
void Cola::crearCola(pnodoLista cola[])
{
    string linea = "";
    ifstream archivo;
    pnodoLista aux = NULL;

    for (int i = 0; i < 5; i++)
    {
        stringstream nombreArchivo;
        nombreArchivo << "Arch" << (i + 1) << ".txt";

        archivo.open(nombreArchivo.str().c_str());

        if (!archivo)
        {
            cout << "No se pudo abrir el archivo: "
                << nombreArchivo.str() << endl;
            continue;
        }

        cola[i]->valor = "(";

		// Llena la cola con la información del archivo
        while (getline(archivo, linea))
        {
            aux = cola[i];

            while (aux->siguiente != NULL)
                aux = aux->siguiente;

            aux->siguiente = new NodoLista(linea);
        }

        if (cola[i]->siguiente != NULL)
            aux->siguiente->siguiente = new NodoLista(")");

        archivo.close();
    }
}

void Cola::imprimir()
{
    for (int i = frente; i < fondo + 1; i++)
    {
        pnodoLista temp = cola[i];

        while (temp->siguiente != NULL)
        {
            cout << temp->valor << " -> ";
            temp = temp->siguiente;
        }

        cout << temp->valor << endl;
    }
}

void Cola::imprimir(int i)
{
    pnodoLista temp = cola[i];

    while (temp->siguiente != NULL)
    {
        cout << temp->valor << " -> ";
        temp = temp->siguiente;
    }

    cout << temp->valor << endl;
}

bool Cola::esNumero(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

string Cola::intAString(int num)
{
    stringstream ss;
    ss << num;
    string str;
    ss >> str;

    return str;
}

pnodoBinario Cola::crearArbolExpresion(int i)
{
	ofstream archivo, archivoResultado;
    string nombreArchivo, inicio, valor, texto;
    Pila pilaOperadores, resultados;

	nombreArchivo = "Análisis" + intAString(i + 1) + ".txt";
  	archivo.open(nombreArchivo.c_str());
  	
  	nombreArchivo = "Evaluación" + intAString(i + 1) + ".txt";
  	archivoResultado.open(nombreArchivo.c_str());
  	
  	inicio = "Orden de los operando en los que serán evaluados del archivo Arch"
		+ intAString(i + 1) + ".txt\n";
	archivoResultado << inicio;

	while (cola[i] != NULL)
	{
		valor = cola[i]->valor;

		if (esNumero(valor))
		{
			texto = "Se encontró el número: " + valor
				+ ", entonces se agrega directamente a la pila de resultados.\n";
			archivo << texto;

			pnodoBinario nuevo = new NodoBinario(valor);
			resultados.push(nuevo);
		}
		else if (valor == ")")
		{
			texto = "Como se encontró un " + valor
				+ ", se vacía la pila de operadores hasta encontrar un (.\n";
			archivo << texto;

			while (!pilaOperadores.pilaVacia()
                    && (pilaOperadores.top()->valor != "("))
				manejarOperador(pilaOperadores, resultados, archivoResultado, archivo);

			if (pilaOperadores.top()->valor == "(" )
			{
				texto = "\tSe encuentra un paréntesis, así que, "
                    + pilaOperadores.top()->valor 
                    + " se saca de la pila de operadores.\n";
				archivo << texto;

				pilaOperadores.pop(); 
			}
		}
		else
			manejarOperando(valor, pilaOperadores, resultados, archivo, archivoResultado);

		cola[i] = cola[i]->siguiente;
	}

	while(!pilaOperadores.pilaVacia())
	{ 
		texto = "Se unen los operadores de la pila de operadores hasta que quede vacía.\n";

        manejarOperador(pilaOperadores, resultados, archivoResultado, archivo);
	}

	imprimirResultados(resultados);

	archivo.close();
	archivoResultado.close();

	return resultados.top();
}

void Cola::manejarOperador(Pila& pilaOperadores, Pila& resultados,
		ofstream& archivoResultado, ofstream& archivo) 
{
    pnodoBinario operador = pilaOperadores.top();
    pilaOperadores.pop();

	pnodoBinario hojaDerecha = resultados.top();
    resultados.pop();

    pnodoBinario hojaIzquierda = resultados.top();
    resultados.pop();

    operador->derecho = hojaDerecha;
    operador->izquierdo = hojaIzquierda;

    resultados.push(operador);

    archivo << "\tSale de la pila de operadores: "
		<< operador->valor << "\n";
    archivo << "\tSale de la pila de resultados la hoja derecha: "
		<< hojaDerecha->valor << "\n";
    archivo << "\tSale de la pila de resultados la hoja izquierda: "
		<< hojaIzquierda->valor << "\n";
    archivo << "\tSe agrega a la pila de resultados: "
		<< operador->valor << " con sus hojas." << "\n";

    archivoResultado << operador->valor << "\n";
}

void Cola::manejarOperando(string valor, Pila& pilaOperadores, Pila& resultados,
		ofstream& archivo, ofstream& archivoResultado)
{
    archivo << "Operando encontrado: " << valor << "\n";

	if (!pilaOperadores.pilaVacia())
	{
        if (prioridadFuera(valor) > prioridadDentro(pilaOperadores.top()->valor))
		{
            archivo << "\tComo PFp de " << valor << " es mayor o igual que PDp de "
                << pilaOperadores.top()->valor << ", " << valor
                << " se agrega a la pila de operadores.\n";

            pilaOperadores.push(new NodoBinario(valor));
        }
		else
		{
            while (!pilaOperadores.pilaVacia()
					&& (prioridadFuera(valor) <= prioridadDentro(pilaOperadores.top()->valor)))
                manejarOperador(pilaOperadores, resultados, archivoResultado, archivo);

            archivo << "\tSe agrega a la pila de operadores: " << valor << "\n";

            pilaOperadores.push(new NodoBinario(valor));
        }
    }
	else
	{
        pilaOperadores.push(new NodoBinario(valor));

        archivo << "Pila vacía. Se agrega a la pila de operadores: "
			<< valor << "\n";
    }
}

void Cola::imprimirResultados(Pila& resultados)
{
    cout << "Expresion Postfija: ";
	expresionPostfija(resultados.top());

	cout << endl << "Expresion Prefija: ";
	expresionPrefija(resultados.top());

	cout << endl << "Expresion Infija: ";
	expresionInfija(resultados.top());
	cout << endl << endl;

	cout << "Resultado: ";
	cout << Pila().evaluar(resultados.top()) << endl;
}

int Cola::prioridadFuera(string c)
{
	if (c == "^")
		return 4;
	else if (c == "*" || c == "/")
		return 2;
	else if (c == "+" || c == "-")
		return 1;
	else
		return 5;
}

int Cola::prioridadDentro(string c)
{
	if (c == "^")
		return 3;
	else if ((c == "*") || (c == "/"))
		return 2;
	else if ((c == "+") || (c == "-"))
		return 1;
	else
		return 0;
}

void Cola::expresionPostfija(pnodoBinario raiz)
{
	if (raiz == NULL)
		return;
	else
	{
		expresionPostfija(raiz->izquierdo);
		expresionPostfija(raiz->derecho);
		cout << raiz->valor << ", ";	
	}
}

void Cola::expresionPrefija(pnodoBinario raiz)
{
	if (raiz == NULL)
		return;
	else
	{
		cout << raiz->valor << ", ";
		expresionPrefija(raiz->izquierdo);
		expresionPrefija(raiz->derecho);	
	}
}

void Cola::expresionInfija(pnodoBinario raiz)
{
	if (raiz == NULL)
		return;
	else
	{
		expresionInfija(raiz->izquierdo);
		cout << raiz->valor << ", ";
		expresionInfija(raiz->derecho);
	}
}



int main()
{
	Cola cola;

    // Llena la cola con la información de los archivos
    cola.crearCola(cola.getCola());

    for (int i = 0; i < 5; i++)
	{
        cola.imprimir(i);
        pnodoBinario arbolExpresion = cola.crearArbolExpresion(i);
        cout << endl << endl;
    }

    system("pause");
    return 0;
}

