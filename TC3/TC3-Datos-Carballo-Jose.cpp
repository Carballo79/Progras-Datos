// Estudiante: José Carballo Martínez

#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
#include <fstream> 
#include <sstream>

// Define un comando para limpiar/borrar la terminal
#ifdef _WIN32 // Si se compila en Windows
    #define LIMPIAR "cls"
#else // Si se compila en Linux
    #define LIMPIAR "clear"
#endif

using namespace std;


// Clases
class NodoABB
{
public:
	NodoABB() {}
	
	NodoABB(int _indice, int _cedula) : indice(_indice), cedula(_cedula),
		Hizq(NULL), Hder(NULL), siguiente(NULL), anterior(NULL) {}
	
	void insertarBinario(int, int);

	int getIndice() { return indice; }
	int getCedula() { return cedula; }
	
private:
	int indice, cedula;
	NodoABB* Hizq, * Hder, * siguiente, * anterior;

	friend class ArbolBB;
	friend class Pila;
};

typedef NodoABB* pnodo;
typedef NodoABB* pnodoABB;


class ArbolBB
{
public:
	pnodoABB raiz;
	
	ArbolBB() : raiz(NULL) {}

	void insertarNodo(int, int);
	pnodoABB buscarNodo(pnodoABB, int);
	void borrarNodo(pnodoABB&, int);
	void borrarNodoAux(pnodoABB&, pnodoABB&);
	
	void preordenI();
	void inordenI();
	void postordenI();

	void leerArchivos();
	void leerIndices();
};


class Pila
{
public:
	Pila() : plista(NULL) {}

	void push(pnodo);
	void mostrar();
	bool pilaVacia() { return plista == NULL; }
	pnodo pop();
	int size();

	pnodo plista;
};


class Cliente
{
public:
	Cliente() : cedula(0), nombre("") {}
	Cliente(int _cedula, string _nombre) : cedula(_cedula), nombre(_nombre) {}

	int getCedula() { return cedula; }
	string getNombre() { return nombre; }
	void setCedula(int _cedula) { cedula = _cedula; }
	void setNombre(string _nombre) { nombre = _nombre; }

private:
	int cedula;
	string nombre;
};


// Comportamiento de la clase NodoABB
void NodoABB::insertarBinario(int ind, int ced)
{
	if (ced < cedula)
	{
		if (Hizq == NULL)
			Hizq = new NodoABB(ind, ced);
		else
			Hizq->insertarBinario(ind, ced);
	}
	else
	{
		if (cedula != ced)
		{
			if (Hder == NULL)
				Hder = new NodoABB(ind, ced);
			else
				Hder->insertarBinario(ind, ced);
		}
	}
}


// Comportamientos de la clase ArbolBB
void ArbolBB::insertarNodo(int ind, int ced)
{
	if (raiz == NULL)
		raiz = new NodoABB(ind, ced);
	else
		raiz->insertarBinario(ind, ced);
}

pnodoABB ArbolBB::buscarNodo(pnodo nodo, int ced)
{
	if (nodo->cedula == ced)
		return nodo;
	else
	{
		if (ced < nodo->cedula)
		{
			if (nodo->Hizq == NULL)
				return NULL;
			
			return buscarNodo(nodo->Hizq, ced);
		}
		else
		{
			if (nodo->Hder == NULL)
				return NULL;
			
			return buscarNodo(nodo->Hder, ced);
		}
	}

	return NULL;
}

void ArbolBB::borrarNodo(pnodoABB& raiz, int x)
{
	pnodoABB q;

	if (raiz != NULL)
	{
		if (x < raiz->cedula)
			borrarNodo(raiz->Hizq, x);
		else
		{
			if (x > raiz->cedula)
				borrarNodo(raiz->Hder, x);
			else
			{
				q = raiz;
				
				if (q->Hder == NULL)
					raiz = q->Hizq;
				else
				{
					if (q->Hizq == NULL)
						raiz = q->Hder;
					else
						borrarNodoAux(q->Hizq, q);
				}

				delete q;
			}
		}
	}
}

void ArbolBB::borrarNodoAux(pnodoABB& D, pnodoABB& q)
{
	if (D->Hder != NULL)
		borrarNodoAux(D->Hder, q);
	else
	{
		q->cedula = D->cedula;
		q = D;
		D = D->Hizq;
	}
}

void ArbolBB::preordenI()
{
	pnodoABB act = raiz;
	Pila p;

	cout << endl;

	while (!p.pilaVacia() || (act != NULL))
	{
		if (act != NULL)
		{
			cout << act->indice << "->" << act->cedula << " - ";
			p.push(act);
			act = act->Hizq;
		}
		else
		{
			act = p.pop();
			act = act->Hder;
		}
	}

	cout << endl;
}

void ArbolBB::inordenI()
{
	pnodoABB act = raiz;
	Pila p;
	bool flag = true;
	
	cout << endl;

	while (flag)
	{
		while (act != NULL)
		{
			p.push(act);
			act = act->Hizq;
		}

		if (!p.pilaVacia())
		{
			act = p.pop();
			cout << act->indice << ";" << act->cedula << " - ";
			act = act->Hder;          
		}
		
		if (p.pilaVacia() && (act == NULL))
			break;
	}

	cout << endl;
}

void ArbolBB::postordenI()
{
	pnodoABB act = raiz;
	Pila p;
	Pila p2;
	
	cout << endl;

	while (!p.pilaVacia() || (act != NULL))
	{
		if (act != NULL)
		{
			p2.push(new NodoABB(act->indice, act->cedula));            
			p.push(act);
			act = act->Hder;
		}
		else
		{
			act = p.pop();
			act = act->Hizq;
		}
	}

	while (!p2.pilaVacia())
	{
		p2.pop();
		cout << act->indice << ";" << act->cedula << " - ";
	}

	cout << endl;
}


// Comportamientos de la clase Pila
void Pila::push(pnodo v)
{
	if (pilaVacia())
		plista = v;
	else
	{
		pnodoABB aux = plista;
		
		while (aux->siguiente)
			aux = aux->siguiente;
		
		aux->siguiente = v;
		v->anterior = aux;
	}
}

pnodo Pila::pop()
{
	pnodoABB borrar, salida;
	
	if (pilaVacia())
		cout << "\nPila vacia.\n" << endl;
	else
	{
		borrar = plista;

		while (borrar->siguiente)
			borrar = borrar->siguiente;
		
		if (size() > 1)
		{
			salida = borrar;
			borrar->anterior->siguiente = NULL;
			borrar = NULL;
			delete borrar;
		}
		else
		{
			salida = plista;        
			plista = NULL;
		}
	}

	return salida;
}

int Pila::size()
{
	while (plista && plista->anterior)
		plista = plista->anterior;
	
	int cont = 0;
	pnodoABB aux;
	aux = plista;
	
	while (aux)
	{
		cont++;
		aux = aux->siguiente;
	}

	return cont;
}

void Pila::mostrar()
{
	if (pilaVacia())
		cout << "\nNo hay elementos en la pila.\n";

	pnodoABB aux = plista;
	
	while (aux)
	{
		cout << aux->indice << ";" << aux->cedula << " - ";
		aux = aux->siguiente;
	}
}


// Función que convierte un string a entero
int stringAInt(string str)
{
	stringstream ss(str);
	int num = 0;

	ss >> num;

	return num;
}

// Función que convierte un entero a string
string intAString(int num)
{
    stringstream ss;
    
    ss << num;

    return ss.str();
}

// Función que extrae datos de un string
string extraerDato(string dato, int pos)
{
	stringstream ss(dato);
	string temp;

	for (int i = 0; i < pos; i++)
	{
		getline(ss, temp, ';'); ss >> ws;
	}

	getline(ss, temp, ';'); ss >> ws;

	return temp;
}


// Arreglo de tipo Cliente que representa la memoria cache de tamaño 20
Cliente memoriaCache[20];

bool registroValido(int x)
{
	for (int i = 0; i < 20; i++)
	{
		if (memoriaCache[i].getCedula() == x)
			return true;		
	}
	
	return false;
}

bool estaRepetido(string x)
{
	fstream archivo;
	string linea;

	archivo.open("Indices.txt");

	while (getline(archivo, linea))
	{
		int i = stringAInt(extraerDato(linea, 0));
		string s = extraerDato(linea, i + 1);

		if (s == x)
		{
			archivo.close();
			return true;
		}
	}

	archivo.close();

	return false;
}

void borrarClienteDeCache(int cedula)
{
	bool encontrado = false;

	for (int i = 0; i < 20; i++)
	{
		if (memoriaCache[i].getCedula() == cedula)
			encontrado = true;

		if (encontrado && (i != 19))
		{
			memoriaCache[i] = memoriaCache[i + 1];

			if (i == 18)
			{	
				memoriaCache[i + 1].setCedula(0);
				memoriaCache[i + 1].setNombre("");
			}
		}
	}
}

ofstream archivoNuevo;
int ultimo = 1;
string cedulasAux[200];

void ArbolBB::leerArchivos()
{
	ifstream archivo;
	string str, cedula, nombre, titulo = "Indices.txt";
	int indice = 1;
	bool primero = true;
	
	archivo.open("Clientes.txt");
	
	archivoNuevo.open(titulo.c_str(),ios::out);

	while (getline(archivo, str))
	{
		cedula = extraerDato(str, 0);
		cedulasAux[ultimo] = cedula;
		
		if (primero)
			primero = false;

		nombre = extraerDato(str, 1);
		
		if (!estaRepetido(cedula))
		{
			stringstream indiceStr;
			
			indiceStr << indice;

			if (indice != 1)
				archivoNuevo << endl;

			archivoNuevo << indiceStr.str();
			archivoNuevo << ";";
			archivoNuevo << cedula << endl;

			indice++;
		}

		ultimo++;
	}

	archivo.close();
	archivoNuevo.close();

	leerIndices();

	// Limpia los últimos 20 elementos del arreglo cedulasAux
	for (int i = ultimo - 21; i != ultimo; i++)
		cedulasAux[i] = "";
}

void ArbolBB::leerIndices()
{
	ifstream archivo;
	string linea = "", cedulaStr, indiceStr;
	int cedula, indice, cont = 0;

	archivo.open("Indices.txt");

	while (getline(archivo, linea))
	{
		if (extraerDato(linea, 2) != "1")
		{
			indiceStr = extraerDato(linea, 0);
			cedulaStr = extraerDato(linea, 1);
			
			istringstream(indiceStr) >> indice;
			istringstream(cedulaStr) >> cedula;
			
			insertarNodo(indice, cedula);
		}
	}

	archivo.close();
}

void marcarArchivo(int cedula)
{
	fstream archivo;
	ofstream archivoTemp;
	string linea;
	int cont = 1;
	
	archivo.open("Clientes.txt");
	
	archivoTemp.open("Temp.txt",ios::out);
	
	int cedulaInt;

	while (getline(archivo, linea))
	{
		string ced = extraerDato(linea, 0);
		
		istringstream(ced) >> cedulaInt;
		
		if (cedulaInt == cedula)
			archivoTemp << linea + ";1" << endl;
		else
			archivoTemp << linea << endl;
	}

	archivo.close();
	archivoTemp.close();

	remove("Clientes.txt");
	rename("Temp.txt","Clientes.txt");
}

string cedulas[200];

bool validarRegistros(string x)
{
	for (int i = 0; i < 200; i++)
	{
		if (cedulas[i] == x)
			return true;
	}
	
	return false;
}

bool validarRegAnteriores(string x)
{
	for (int i = 0; i < 200; i++)
	{
		if (cedulasAux[i] == x)
			return true;
	}

	return false;
}

ifstream archivoPost;
int cont2Post = 0;

void posteriores(string linea, int indice, int cont)
{
	if (cont == indice)
		return;
	else
	{
		getline(archivoPost, linea);
		posteriores(linea, indice, cont + 1);

		string cedula = extraerDato(linea, 0);
		int cedulaInt;

		istringstream(cedula) >> cedulaInt;
		
		if (!validarRegistros(cedula) && (extraerDato(linea, 2) != "1")
			&& (cont2Post <= 19) && !validarRegAnteriores(cedula))
		{
			cedulas[cont2Post] = cedula;
			cedula = extraerDato(linea, 0);
			
			string nombre = extraerDato(linea, 1);
			
			Cliente cliente;
			
			istringstream(cedula) >> cedulaInt;
			
			cliente.setCedula(cedulaInt);
			cliente.setNombre(nombre);
			
			memoriaCache[cont2Post] = cliente;
			
			cont2Post++;
		}
	}
}

void llenarMemCache(int indice)
{
	ifstream archivo;
	archivo.open("Clientes.txt");
	
	Cliente cliente;
	string linea, cedula, nombre;
	int cedulaInt, cont = 1, cont2 = 1;
	
	for (int i = 0; i < 200; i++)
		cedulas[i] = "";

	while (getline(archivo, linea))
	{
		cedula = extraerDato(linea, 0);
		
		istringstream(cedula) >> cedulaInt;

		if (!validarRegistros(cedula) && (extraerDato(linea, 2) != "1"))
		{
			cedulas[cont] = cedula;

			if (cont == indice)
			{
				cedula = extraerDato(linea, 0);
				nombre = extraerDato(linea, 1);
				
				istringstream(cedula) >> cedulaInt;
				
				cliente.setCedula(cedulaInt);
				cliente.setNombre(nombre);
				
				memoriaCache[0] = cliente;
			}

			if ((cont > indice) && (cont2 <= 19))
			{
				cedula = extraerDato(linea, 0);
				nombre = extraerDato(linea, 1);
				
				istringstream(cedula) >> cedulaInt;
				
				cliente.setCedula(cedulaInt);
				cliente.setNombre(nombre);
				
				memoriaCache[cont2] = cliente;
				
				cont2++;
			}

		    cont++;
		}
	}

	if (cont2 != 19)
	{	
		archivo.close();
		archivo.open("Clientes.txt");

		for (int i = 0; i < 200; i++)
			cedulas[i] = "";

		while (getline(archivo, linea) && (cont2 <= 19))
		{
			cedula = extraerDato(linea, 0);
			
			istringstream(cedula) >> cedulaInt;

			if (!registroValido(cedulaInt) && !validarRegistros(cedula)
				&& (extraerDato(linea, 3) != "1"))
			{
				cedulas[cont2] = cedula;
				
				cedula = extraerDato(linea, 0);
				nombre = extraerDato(linea, 1);
				
				istringstream(cedula) >> cedulaInt;
				
				cliente.setCedula(cedulaInt);
				cliente.setNombre(nombre);
				
				memoriaCache[cont2] = cliente;
				
				cont2++;
			}
		}
	}

	archivo.close();	
}

void mostrarMemCache(ArbolBB& clientes)
{
	bool vacia = true;

	for (int i = 0; i < 20; i++)
	{
		if (memoriaCache[i].getCedula() != 0)
		{
			vacia = false;
			break;
		}
	}

	if (vacia)
		cout << "\nMemoria cache vacia.\n" << endl;
	else
	{
		cout << endl;

		for (int i = 0; i < 20; i++)
		{
			pnodoABB cliente = clientes.buscarNodo(clientes.raiz,
				memoriaCache[i].getCedula());

			if (cliente != NULL)
				cout << cliente->getIndice() << " -> " << memoriaCache[i].getCedula() << "; "
					<< memoriaCache[i].getNombre() << endl;
		}

		cout << endl;
	}
}

void agregarATxt(string nombre, string texto)
{
	ofstream archivo;
	
	archivo.open(nombre.c_str(),ios::app);
	
	archivo << texto;
	
	archivo.close();
}

string leerUltimo(string nombre)
{
	ifstream archivo;
	string linea = "", ultima = "";

	archivo.open(nombre.c_str(), ios::in);
	
	while (!archivo.eof())
	{
		getline(archivo, linea);
		ultima = linea;
	}

	archivo.close();
	
	return ultima;
}

string leerUltimoIndice(string nombre)
{
	ifstream archivo;
	string linea = "", ultima = "";
	
	archivo.open(nombre.c_str(), ios::in);
	
	while (!archivo.eof())
	{
		getline(archivo, linea);
		
		if (linea != "")
			ultima = linea;
	}

	archivo.close();
	
	return ultima;
}

int calcularUltimoIndice()
{
	string ultimoDatoInd = leerUltimoIndice("Indices.txt");
	string ultimoIndiceStr = extraerDato(ultimoDatoInd, 0);
	
	int ultimoIndice = 0;
	
	istringstream(ultimoIndiceStr) >> ultimoIndice;

	return ultimoIndice;
}


void agregarNuevoIndice(string cedulaNueva)
{
	int calcUltimoInd = (calcularUltimoIndice()) + 1;
	
	stringstream ss;
	
	ss << calcUltimoInd;
	
	string datoAInsertar;

	if (leerUltimo("Indices.txt") == "")
		datoAInsertar = ss.str() + ";" + cedulaNueva;
	else
		datoAInsertar = "\n" + ss.str() + ";" + cedulaNueva;

	agregarATxt("Indices.txt", datoAInsertar);	
}

bool verificarNoBorrado(string registro)
{
	if (extraerDato(registro, 2) == "1")
		return false;
	else
		return true;
}

void purgar()
{
	fstream archivoEntrada;
	ofstream archivoSalida;
	string linea;

	archivoEntrada.open("Clientes.txt");
	archivoSalida.open("Temp.txt", ios::out);
	
	while (getline(archivoEntrada, linea))
	{
		if (verificarNoBorrado(linea))
			archivoSalida << linea << endl;
	}

	archivoEntrada.close();
	archivoSalida.close();

	remove("Clientes.txt");
	rename("Temp.txt","Clientes.txt");
}

void menuBuscar(ArbolBB& clientes, int cedulaABuscar, bool enCache)
{
	clientes.preordenI();
	mostrarMemCache(clientes);

	cout << "Digite la cedula a buscar: "; cin >> cedulaABuscar;
	cout << endl;
	
	for (int i = 0; i < 20; i++)
	{
		if (memoriaCache[i].getCedula() == cedulaABuscar)
		{
			cout << "Cliente encontrado en la memoria cache:" << endl;
			cout << "Cedula: " << memoriaCache[i].getCedula() << "\n"
				<< "Nombre: " << memoriaCache[i].getNombre() << endl << endl;
			
			enCache = true;
		}
	}

	if (!enCache)
	{
		pnodoABB encontrado = clientes.buscarNodo(clientes.raiz, cedulaABuscar);

		if (encontrado != NULL)
		{
			llenarMemCache(encontrado->getIndice());
			
			cout << "Cliente no encontrado en la memoria cache." << endl << endl;
			cout << "Cedula encontrada en el arbol:" << endl;
			cout << "Indice: " << encontrado->getIndice() << "\n"
				<< "Cedula: " << encontrado->getCedula() << endl << endl;
			cout << "Cargando la memoria cache..." << endl;
			
			Sleep(2000);

			mostrarMemCache(clientes);
		}
		else
			cout << "Cedula no encontrada en el sistema.\n" << endl;
	}

	enCache = false;
}

void menuEliminar(ArbolBB& clientes, int cedulaABuscar)
{
	clientes.preordenI();
	mostrarMemCache(clientes);

	cout << "Digite la cedula a eliminar: "; cin >> cedulaABuscar;
	cout << endl;

	pnodoABB encontrado = clientes.buscarNodo(clientes.raiz, cedulaABuscar);

	if (encontrado != NULL)
	{
		borrarClienteDeCache(cedulaABuscar);

		clientes.borrarNodo(clientes.raiz, cedulaABuscar);

		clientes.preordenI();
		
		marcarArchivo(cedulaABuscar);
		
		mostrarMemCache(clientes);

		cout << "Cliente eliminado exitosamente.\n" << endl;
	}
	else
		cout << "Cedula no encontrada en el sistema.\n" << endl;
}

void menuInsertar(ArbolBB& clientes)
{
	int ced;
	string nombre, dato = "";

	cout << "\nIngrese la cedula del cliente: "; cin >> ced;

	if (clientes.buscarNodo(clientes.raiz, ced) != NULL)
	{
		cout << "\nCedula encontrada en el sistema.\n" << endl;
		return;
	}

	cout << "Digite el nombre del cliente: "; getline(cin >> ws, nombre);

	stringstream cedStr;
	cedStr << ced;

	dato += cedStr.str() + ";" + nombre;
	
	for (int i = 0; i < 18; ++i)
	{
		memoriaCache[i] = memoriaCache[i + 1];
	}

	Cliente cliente;
	cliente.setCedula(ced);
	cliente.setNombre(nombre);
	memoriaCache[19] = cliente;

	if (leerUltimo("Clientes.txt") != "")
		dato = "\n" + dato;

	agregarATxt("Clientes.txt", dato);
	agregarNuevoIndice(cedStr.str());

	clientes.insertarNodo(calcularUltimoIndice(), ced);

	string linea;

	archivoPost.open("Clientes.txt");

	for (int i = 0; i < 200; i++)
		cedulas[i] = "";

	posteriores(linea, ultimo + 1, 0);

	archivoPost.close();

	mostrarMemCache(clientes);

	cout << "\nCliente registrado exitosamente.\n" << endl;
}



int main()
{
	ArbolBB clientes;
	
	clientes.leerArchivos();
	clientes.preordenI();

	int opcion, cedulaABuscar;
	bool salir = false, enCache = false, purgado = false;

	while (salir != true)
	{
		cout << "\n***************MENU PRINCIPAL:***************" << endl << endl;
		cout << "[1] Buscar cliente" << endl;
		cout << "[2] Eliminar cliente" << endl;
		cout << "[3] Insertar cliente" << endl;
		cout << "[4] Purgar" << endl;
		cout << "[5] Reindexar" << endl;
		cout << "[6] Ver Arbol Binario de Busqueda" << endl;
		cout << "[7] Ver Memoria Cache" << endl;
		cout << "[0] Salir" << endl << endl;
		cout << "Seleccione una opcion: "; cin >> opcion;

		switch (opcion)
		{
			case 1:
				menuBuscar(clientes, cedulaABuscar, enCache);
				break;

			case 2:
				menuEliminar(clientes, cedulaABuscar);
				break;

			case 3:
				menuInsertar(clientes);
				break;

			case 4:
				purgar();
				
				cout << "\nArchivo de clientes purgado exitosamente.\n" << endl;
				
				purgado = true;

				break;

			case 5:
				if (!purgado)
					cout << "\nPrimero debes purgar el archivo de clientes.\n" << endl;
				else
				{
					clientes.raiz = NULL;
					clientes.leerArchivos();

					purgado = false;

					cout << "\nArbol de clientes reindexado exitosamente.\n" << endl;
				}

				break;

			case 6:
				clientes.preordenI();
				cout << endl;

				break;

			case 7:
				mostrarMemCache(clientes);

				break;

			case 0:
				salir = true;

				cout << "\nSaliendo del sistema...\n" << endl;
				
				Sleep(2000);

				break;

			default:
				cout << "\nDigite una opcion valida.\n" << endl;
		}
		
	}
	
	return 0;
	system("pause");
}
