// Estudiantes: José Carballo Martínez y Kevin Espinoza Barrantes

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;

// Clase Lista Simple
class NodoLista
{
	public:
		NodoLista(string _valor)
		{
			valor = _valor;
			siguiente = NULL;
		}

	private:
		string valor;
		NodoLista* siguiente;

		friend class Cola;
		friend class Pila;
};

typedef NodoLista* pnodoLista;


// Clase Arbol Binario
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
			siguiente = _siguiente;
			derecho = NULL;
            izquierdo = NULL;
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


// Clase Cola
class Cola
{	
	public:
		Cola()
		{
			frente = 0;
			fondo = -1;

			for (int i = 0; i < 5; i++)
				cola[i] = NULL;
		}
		
		bool ColaVacia() { return fondo < frente; }
		void cargar(string nombreArchivo);
		void imprimir();
		void imprimir(int i);
		void infija(pnodoBinario raiz);
		void postfija(pnodoBinario raiz);
		void prefija(pnodoBinario raiz);

	private:
		int frente;
		int fondo;
		pnodoLista cola [5];
};


// Clase Pila
class Pila
{
	public:
		Pila() { tope = NULL; }
		bool pilaVacia() { return tope == NULL; }
		pnodoBinario top();
		void push(pnodoBinario nuevo);
		void pop();
		void imprimir();

	private:
		pnodoBinario tope;
};



// ---------- Métodos de Cola ----------
// Función que carga los archivos
// void Cola::cargar(string nombreArchivo)
// {
//	 ifstream archivo;
//	 string linea;
//
//	 archivo.open(nombreArchivo.c_str(), ios::in);
//
//	 if (archivo.fail())
//	 {
//		 cout << "No se pudo abrir el archivo o no existe el archivo: "
//			 << nombreArchivo << endl;
//		 exit(1);
//	 }
//
//	 while (!archivo.eof())
//		 getline(archivo,linea);
//
//	 archivo.close();
// }

// Imprime la cola completa
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

// Imprime una posición de la cola
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

void Cola::postfija(pnodoBinario raiz)
{
	if (raiz == NULL)
		return;
	else
	{
		postfija(raiz->izquierdo);
		postfija(raiz->derecho);
		cout << raiz->valor << " ";	
	}
}

void Cola::prefija(pnodoBinario raiz)
{
	if (raiz == NULL)
		return;
	else
	{
		cout << raiz->valor << " ";
		prefija(raiz->izquierdo);
		prefija(raiz->derecho);	
	}
}

void Cola::infija(pnodoBinario raiz)
{
	if (raiz == NULL)
		return;
	else
	{
		infija(raiz->izquierdo);
		cout << raiz->valor << " ";
		infija(raiz->derecho);	
	}
}



// ---------- Métodos de Pila ----------
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
		nuevo->siguiente = tope;
		tope = nuevo;
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



int main()
{
	cout << "Hola mundo!!\n" << endl;
	
	system("pause");
	return 0;
}

