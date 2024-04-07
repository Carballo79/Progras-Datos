// Estudiantes: José Carballo Martínez y Kevin Espinoza Barrantes

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class NodoPasillo
{
public:
    NodoPasillo(int _codPasillo, string _nombre)
    {
        codPasillo = _codPasillo;
        nombre = _nombre;
        contVisitas = 0;
        siguiente = NULL;
    }

    NodoPasillo(int _codPasillo, string _nombre, NodoPasillo* _siguiente)
    {
        codPasillo = _codPasillo;
        nombre = _nombre;
        contVisitas = 0;
        siguiente = _siguiente;
    }

	int getCodPasillo() { return codPasillo; }
	string getNombre() { return nombre; }

private:
    int codPasillo;
    string nombre;
    int contVisitas;
    NodoPasillo* siguiente;

    friend class ListaSimplePasillos;
};

typedef NodoPasillo* pnodoPasillo;


class NodoProductoPasillo
{
public:
    NodoProductoPasillo(int _codPasillo, int _codProducto, string _nombre)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        nombre = _nombre;
        contBusquedas = 0;
        siguiente = NULL;
        anterior = NULL;
    }
    
    NodoProductoPasillo(int _codPasillo, int _codProducto, string _nombre,
        NodoProductoPasillo* _siguiente)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        nombre = _nombre;
        contBusquedas = 0;
        siguiente = _siguiente;
        anterior = NULL;
    }
    
    int getCodPasillo() { return codPasillo; }
	int getCodProducto() { return codProducto; }
	string getNombre() { return nombre; }

private:
    int codPasillo;
    int codProducto;
    string nombre;
    int contBusquedas;
    NodoProductoPasillo* siguiente;
    NodoProductoPasillo* anterior;

    friend class ListaDobleProductosPasillo;
};

typedef NodoProductoPasillo* pnodoProductoPasillo;


class NodoMarcaProducto
{
public:
    NodoMarcaProducto(int _codPasillo, int _codProducto, int _codMarca, string _nombre,
        int _cantGondola, int _precio)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        codMarca = _codMarca;
        nombre = _nombre;
        cantGondola = _cantGondola;
        precio = _precio;
        contBusquedas = 0;
        siguiente = NULL;
        anterior = NULL;
    }
    
    int getCodPasillo() { return codPasillo; }
    int getCodProducto() { return codProducto; }
    int getCodMarca() { return codMarca; }
	string getNombre() { return nombre; }
	int getCantGondola() { return cantGondola; }
	int getPrecio() { return precio; }

private:
    int codPasillo;
    int codProducto;
    int codMarca;
    string nombre;
    int cantGondola;
    int precio;
    int contBusquedas;
    NodoMarcaProducto* siguiente;
    NodoMarcaProducto* anterior;

    friend class ListaDCMarcaProductos;
};

typedef NodoMarcaProducto* pnodoMarcaProducto;


class NodoInventario
{
public:
    NodoInventario(int _codPasillo, int _codProducto, int _codMarca, int _codInventario,
        string _nombre, int _cantStock, bool _codCanasta)
    {
        codPasillo = _codPasillo;
        codProducto = _codProducto;
        codMarca = _codMarca;
        codInventario = _codInventario;
        nombre = _nombre;
        cantStock = _cantStock;
        codCanasta = _codCanasta;
        siguiente = NULL;
        anterior = NULL;
    }
    
    int getCodPasillo() { return codPasillo; }
    int getCodProducto() { return codProducto; }
    int getCodMarca() { return codMarca; }
    int getCodInventario() { return codInventario; }
	string getNombre() { return nombre; }
	int getCantStock() { return cantStock; }
	bool getCodCanasta() { return codCanasta; }

private:
    int codPasillo;
    int codProducto;
    int codMarca;
    int codInventario;
    string nombre;
    int cantStock;
    bool codCanasta;
    NodoInventario* siguiente;
    NodoInventario* anterior;

    friend class ListaDobleInventarios;
};

typedef NodoInventario* pnodoInventario;


class NodoCliente
{
public:
    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono,
		string _correo)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = NULL;
    }

    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono,
		string _correo, NodoCliente* _siguiente)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = _siguiente;
    }
    
    int getCedula() { return cedula; }
    string getNombre() { return nombre; }
    int getCodCiudad() { return codCiudad; }
    string getTelefono() { return telefono; }
    string getCorreo() { return correo; }

private:
    int cedula;
    string nombre;
    int codCiudad;
    string telefono;
    string correo;
    NodoCliente* siguiente; // Clase de Autoreferencia

    friend class HashingClientes;
    friend class ListaCircularCiudades;
};

typedef NodoCliente* pnodoCliente;


class NodoAdmin
{
public:
    NodoAdmin(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = NULL;
    }

    NodoAdmin(int _cedula, string _nombre, int _codCiudad, string _telefono, string _correo,
		NodoAdmin* _siguiente)
    {
        cedula = _cedula;
        nombre = _nombre;
        codCiudad = _codCiudad;
        telefono = _telefono;
        correo = _correo;
        siguiente = _siguiente;
    }
    
    int getCedula() { return cedula; }
    string getNombre() { return nombre; }
    int getCodCiudad() { return codCiudad; }
    string getTelefono() { return telefono; }
    string getCorreo() { return correo; }

private:
    int cedula;
    string nombre;
    int codCiudad;
    string telefono;
    string correo;
    NodoAdmin* siguiente; // Clase de Autoreferencia

    friend class HashingAdmins;
    friend class ListaCircularCiudades;
};

typedef NodoAdmin* pnodoAdmin;


class NodoCiudad
{
public:
    NodoCiudad(int _codCiudad, string _nombre)
    {
        codCiudad = _codCiudad;
        nombre = _nombre;
        siguiente = NULL;
    }

	int getCodCiudad() { return codCiudad; }
	string getNombre() { return nombre; }

private:
    int codCiudad;
    string nombre;
    NodoCiudad* siguiente;

    friend class ListaCircularCiudades;
};

typedef NodoCiudad* pnodoCiudad;



class ListaSimplePasillos  
{
public:
    ListaSimplePasillos() { primero = NULL; }
    ~ListaSimplePasillos();

    void InsertarInicio(int codPasillo, string nombre);
    void InsertarFinal(int codPasillo, string nombre);
    void InsertarPos(int codPasillo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarPasillo(int codPasillo, string nombre);
    bool pasilloRepetido(int codPasillo);
    void eliminarPasillo(int codPasillo);
    pnodoPasillo buscarPasillo(int codPasillo);
    void modificarPasillo(int codPasillo, string nombre);
    void reportePasillos();
    void reportePasilloMasVisitado();
    void reportePasilloMenosVisitado();

private:
    pnodoPasillo primero;
};

void ListaSimplePasillos::insertarPasillo(int codPasillo, string nombre)
{
    if (!pasilloRepetido(codPasillo))
    {
        // Si no existe, inserta al final
        InsertarFinal(codPasillo, nombre);
        cout << "\nPasillo insertado exitosamente." << endl;
        cout << "\nPasillo insertado:" << endl;
        cout << "-> CodPasillo: " << codPasillo << endl;
        cout << "   Nombre: " << nombre << endl << endl;
    }
    else
        cout << "\nEl pasillo ya existe en la lista.\n" << endl;
}

bool ListaSimplePasillos::pasilloRepetido(int codPasillo)
{
    pnodoPasillo aux = primero;

    while (aux != NULL)
    {
        if (aux->codPasillo == codPasillo)
            // Si se encuentra el pasillo, es repetido
            return true;

        aux = aux->siguiente;
    }

    // Si no se encuentra, no es repetido
    return false;
}

void ListaSimplePasillos::eliminarPasillo(int codPasillo)
{
    if (ListaVacia())
    {
        cout << "\nLa lista de pasillos esta vacia.\n" << endl;
        return;
    }

    pnodoPasillo actual = primero;
    int pos = 1;

    do
    {
        if (actual->codPasillo == codPasillo)
        {
            // Elimina el pasillo
            BorrarPosicion(pos);
            cout << "\nPasillo eliminado exitosamente.\n" << endl;
            return;
        }

        actual = actual->siguiente;
        pos++;
    } while (actual != primero);

    cout << "\nEl pasillo con el código especificado no se encontró.\n" << endl;
}

pnodoPasillo ListaSimplePasillos::buscarPasillo(int codPasillo)
{
    if (ListaVacia())
    {
        cout << "\nLa lista de pasillos esta vacia.\n" << endl;
        return NULL;
    }

    pnodoPasillo aux = primero;

    while (aux != NULL)
	{
		if (aux->codPasillo == codPasillo)
		{
			aux->contVisitas++; // Incrementa el contador de búsquedas
            return aux;
    	}

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaSimplePasillos::modificarPasillo(int codPasillo, string nombre)
{
	pnodoPasillo pasillo = buscarPasillo(codPasillo);
	
	if (pasillo == NULL)
	{
		cout << "\nPasillo no encontrado.\n";
		return;
	}
	
    pasillo->codPasillo = codPasillo;
    pasillo->nombre = nombre;

    cout << "\nPasillo modificado exitosamente." << endl;
    cout << "\nPasillo modificado:" << endl;
	cout << "-> CodPasillo: " << codPasillo << endl;
	cout << "   Nombre: " << nombre << endl << endl;
}

ListaSimplePasillos::~ListaSimplePasillos()
{
    pnodoPasillo aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = NULL;
}

void ListaSimplePasillos::InsertarInicio(int codPasillo, string nombre)
{
    if (ListaVacia())
        primero = new NodoPasillo(codPasillo, nombre);
    else
    {
        pnodoPasillo nuevo = new NodoPasillo(codPasillo, nombre, primero);
        primero = nuevo;
    }
}

void ListaSimplePasillos::InsertarFinal(int codPasillo, string nombre)
{
    if (ListaVacia())
        primero = new NodoPasillo(codPasillo, nombre);
    else
    {
        pnodoPasillo aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoPasillo(codPasillo, nombre);
    }
}

void ListaSimplePasillos::InsertarPos(int codPasillo, string nombre, int pos)
{
    if (ListaVacia())
        primero = new NodoPasillo(codPasillo, nombre);
    else
    {
        if (pos <= 1)
            InsertarInicio(codPasillo, nombre);
        else
        {
            pnodoPasillo aux = primero;
            int i = 2;

            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoPasillo nuevo = new NodoPasillo(codPasillo, nombre);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void ListaSimplePasillos::BorrarInicio()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        pnodoPasillo temp = primero;
        primero = primero->siguiente;
        delete temp;
    }
}

void ListaSimplePasillos::BorrarFinal()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoPasillo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoPasillo aux = primero;

            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoPasillo temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaSimplePasillos::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "\nError en posicion." << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                int cont = 2;
                pnodoPasillo aux = primero;

                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }

                pnodoPasillo temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void ListaSimplePasillos::Mostrar()
{
    pnodoPasillo aux = primero;

    while (aux)
    {	
        cout << "-> " << aux->codPasillo << "; " << aux->nombre << endl << endl;

        aux = aux->siguiente;
    }
}

int ListaSimplePasillos::largoLista()
{
    int cont = 0;
    pnodoPasillo aux = primero;

    while (aux != NULL)
    {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}


class ListaDobleProductosPasillo
{
public:
    ListaDobleProductosPasillo() { primero = NULL; }
    ~ListaDobleProductosPasillo();

    void InsertarInicio(int codPasillo, int codProducto, string nombre);
    void InsertarFinal(int codPasillo, int codProducto, string nombre);
    void InsertarPos(int codPasillo, int codProducto, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarProducto(int codPasillo, int codProducto, string nombre,
        ListaSimplePasillos& listaPasillos);
    bool productoRepetido(int codProducto);
    void eliminarProducto(int codProducto);
    int obtenerPosicion(pnodoProductoPasillo producto);
    void eliminarProductosPasillo(int codPasillo);
    pnodoProductoPasillo buscarProducto(int codProducto);
    void modificarProducto(int codProducto, string nombre);
    void reporteProductosPasillo();
    void reporteProductoMasBuscado(ListaSimplePasillos& listaPasillos);

private:
    pnodoProductoPasillo primero;
};

void ListaDobleProductosPasillo::insertarProducto(int codPasillo, int codProducto,
    string nombre, ListaSimplePasillos& listaPasillos)
{
    // Verifica si el producto ya está repetido
    if (!productoRepetido(codProducto))
    {
        if (listaPasillos.pasilloRepetido(codPasillo))
        {
            // Inserta al inicio después de las validaciones
            InsertarFinal(codPasillo, codProducto, nombre);
            
            cout << "\nProducto insertado exitosamente." << endl;
	        cout << "\nProducto insertado:" << endl;
	        cout << "-> CodPasillo: " << codPasillo << endl;
	        cout << "   CodProducto: " << codProducto << endl;
	        cout << "   Nombre: " << nombre << endl << endl;
		}
		else
			cout << "\nEl pasillo no existe en la lista.\n" << endl;
    }
    else
    	cout << "\nEl producto ya existe en el pasillo.\n" << endl;
}

bool ListaDobleProductosPasillo::productoRepetido(int codProducto)
{
    pnodoProductoPasillo aux = primero;

    while (aux != NULL)
    {
        if (aux->codProducto == codProducto)
            // Si se encuentra el producto, es repetido
            return true;

        aux = aux->siguiente;
    }

    // Si no se encuentra, no es repetido
    return false;
}

void ListaDobleProductosPasillo::eliminarProducto(int codProducto)
{
    if (ListaVacia())
    {
        cout << "\nLa lista de productos esta vacia.\n" << endl;
        return;
    }

    pnodoProductoPasillo actual = primero;

    do
    {
        if (actual->codProducto == codProducto)
        {
            pnodoProductoPasillo siguienteNodo;
            // Elimina todas las marcas de ese producto
            while (actual != NULL && actual->codProducto == codProducto)
            {
                pnodoProductoPasillo siguienteNodo = actual->siguiente;
                BorrarPosicion(obtenerPosicion(actual));
                actual = siguienteNodo;
            }

            cout << "\nProducto y sus marcas eliminados exitosamente.\n" << endl;
            return;
        }

        actual = actual->siguiente;
    } while (actual != NULL);

    cout << "\nEl producto no se encuentra en la lista.\n" << endl;
}

int ListaDobleProductosPasillo::obtenerPosicion(pnodoProductoPasillo producto)
{
    int pos = 1;
    pnodoProductoPasillo actual = primero;

    while (actual != NULL)
    {
        if (actual == producto)
            return pos;

        actual = actual->siguiente;
        pos++;
    }

    return -1; // -1 si el producto no se encuentra en la lista
}

void ListaDobleProductosPasillo::eliminarProductosPasillo(int codPasillo)
{
    pnodoProductoPasillo productoActual = primero;

    while (productoActual != NULL)
    {
        if (productoActual->codPasillo == codPasillo)
        {
            pnodoProductoPasillo temp = productoActual;
            productoActual = productoActual->siguiente;

            // Elimina el nodo actual
            if (temp->anterior)
                temp->anterior->siguiente = temp->siguiente;
            if (temp->siguiente)
                temp->siguiente->anterior = temp->anterior;
            if (temp == primero)
                primero = temp->siguiente;
            //if (temp == ultimo)
            //    ultimo = temp->anterior;

            delete temp;
            continue;
        }

        productoActual = productoActual->siguiente;
    }
}

pnodoProductoPasillo ListaDobleProductosPasillo::buscarProducto(int codProducto)
{
    if (ListaVacia())
	{
        cout << "\nLa lista de pasillos esta vacia.\n" << endl;
        return NULL;
    }

    pnodoProductoPasillo aux = primero;

    while (aux != NULL)
	{
        if (aux->codProducto == codProducto)
        {
        	aux->contBusquedas++;
            return aux;
    	}

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaDobleProductosPasillo::modificarProducto(int codProducto, string nombre)
{
	pnodoProductoPasillo productoPasillo = buscarProducto(codProducto);

    if (productoPasillo == NULL)
    {
        cout << "\nProducto no encontrado.\n" << endl;
        return;
    }

    productoPasillo->codProducto = codProducto;
    productoPasillo->nombre = nombre;

    cout << "\nProducto modificado exitosamente." << endl;
    cout << "\nProducto modificado:" << endl;
	cout << "-> CodProducto: " << codProducto << endl;
	cout << "   Nombre: " << nombre << endl << endl;
}

ListaDobleProductosPasillo::~ListaDobleProductosPasillo()
{
    pnodoProductoPasillo aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = NULL;
}

void ListaDobleProductosPasillo::InsertarInicio(int codPasillo, int codProducto, string nombre)
{
    if (ListaVacia())
    {
        primero = new NodoProductoPasillo(codPasillo, codProducto, nombre);
        primero->anterior = NULL;
    }
    else
    {
        primero = new NodoProductoPasillo(codPasillo, codProducto, nombre, primero);
        primero->siguiente->anterior = primero;
    }
}

void ListaDobleProductosPasillo::InsertarFinal(int codPasillo, int codProducto, string nombre)
{
    if (ListaVacia())
    {
        primero = new NodoProductoPasillo(codPasillo, codProducto, nombre);
        primero->anterior = NULL;
    }
    else
    {
        pnodoProductoPasillo aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoProductoPasillo(codPasillo, codProducto, nombre);
        aux->siguiente->anterior = aux;
    }
}

void ListaDobleProductosPasillo::InsertarPos(int codPasillo, int codProducto, string nombre, int pos)
{
    if (ListaVacia())
    {
        primero = new NodoProductoPasillo(codPasillo, codProducto, nombre);
        primero->anterior = NULL;
    }
    else
    {
        if (pos <= 1)
        {
            // Ajusta el puntero anterior del nuevo nodo
            pnodoProductoPasillo nuevo = new NodoProductoPasillo(codPasillo, codProducto, nombre);
            nuevo->siguiente = primero;

            // Verifica si el siguiente nodo no es NULL antes de acceder al campo anterior
            if (primero != NULL)
                primero->anterior = nuevo;

            primero = nuevo;
        }
        else
        {
            pnodoProductoPasillo aux = primero;
            int i = 2;

            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoProductoPasillo nuevo = new NodoProductoPasillo(codPasillo, codProducto, nombre);
            nuevo->siguiente = aux->siguiente;

            // Verifica si el siguiente nodo no es NULL antes de acceder al campo anterior
            if (aux->siguiente != NULL)
                aux->siguiente->anterior = nuevo;

            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
}

void ListaDobleProductosPasillo::BorrarInicio()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoProductoPasillo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoProductoPasillo aux = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete aux;
        }
    }
}

void ListaDobleProductosPasillo::BorrarFinal()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoProductoPasillo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoProductoPasillo aux = primero;
            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoProductoPasillo temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaDobleProductosPasillo::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "\nError en posicion.\n" << endl;
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
                    int cont = 2;
                    pnodoProductoPasillo aux = primero;

                    while (cont < pos)
                    {
                        aux = aux->siguiente;
                        cont++;
                    }

                    pnodoProductoPasillo temp = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;
                    aux->siguiente->anterior = aux;
                    delete temp;
                }
            }
        }
    }
}

void ListaDobleProductosPasillo::Mostrar()
{
    pnodoProductoPasillo aux;
    aux = primero;

    while (aux)
    {
        cout << "-> " << aux->codPasillo << "; " << aux->codProducto << "; "
			<< aux->nombre << endl << endl;
        
		aux = aux->siguiente;
    }
}

int ListaDobleProductosPasillo::largoLista()
{
    int cont = 0;

    pnodoProductoPasillo aux;
    aux = primero;

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


class ListaDCMarcaProductos
{
public:
    ListaDCMarcaProductos() { primero = NULL; }
    ~ListaDCMarcaProductos();

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, string nombre,
        int cantGondola, int precio);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, string nombre,
        int cantGondola, int precio);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, string nombre,
        int cantGondola, int precio, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarMarcaProducto(int codPasillo, int codProducto, int codMarca,
        string nombre, int cantGondola, int precio, ListaSimplePasillos& listaPasillos,
        ListaDobleProductosPasillo& listaProductosPasillo);
    bool marcaProductoRepetida(int codMarca);
    bool productoRepetidoEnMarcas(int codProducto);
    void eliminarMarcasProductos();
    pnodoMarcaProducto buscarMarcaProducto(int codMarca);
    void modificarMarcaProducto(int codMarca, string nombre, int cantGondola, int precio);
    void reporteMarcaProductos();
    void reporteMarcaMasBuscada(ListaSimplePasillos& listaPasillos,
		ListaDobleProductosPasillo& listaProductosPasillo);

private:
    pnodoMarcaProducto primero;
};

void ListaDCMarcaProductos::insertarMarcaProducto(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio, ListaSimplePasillos& listaPasillos,
    ListaDobleProductosPasillo& listaProductosPasillo)
{
    // Valida si el pasillo existe en la lista simple de pasillos
    if (!listaPasillos.pasilloRepetido(codPasillo))
    {
    	cout << "\nEl pasillo no existe.\n" << endl;
    	return;
	}

    // Valida si el producto existe en la lista doble de productos
    if (!listaProductosPasillo.productoRepetido(codProducto))
    {
    	cout << "\nEl producto no existe.\n" << endl;
    	return;
	}

	// Valida si el producto ya tiene una marca en la lista de marcas
    if (productoRepetidoEnMarcas(codProducto))
    {
        cout << "\nLa marca ya existe para este producto.\n" << endl;
        return;
    }
    
    // Valida si el codMarca está repetido en la lista circular doble de marcas
    if (!marcaProductoRepetida(codMarca))
	{
    	// Inserta en la lista circular doble de marcas después de las validaciones
	    InsertarFinal(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);
	
	    cout << "\nMarca insertada exitosamente." << endl;
	    cout << "\nMarca insertada:" << endl;
	    cout << "-> CodPasillo: " << codPasillo << endl;
	    cout << "   CodProducto: " << codProducto << endl;
	    cout << "   CodMarca: " << codMarca << endl;
	    cout << "   Nombre: " << nombre << endl;
	    cout << "   CantGondola: " << cantGondola << endl;
	    cout << "   Precio: " << precio << endl << endl;
	}
	else
	{
		cout << "\nLa marca de producto ya existe.\n" << endl;
    	return;
	}
}

bool ListaDCMarcaProductos::marcaProductoRepetida(int codMarca)
{
    if (ListaVacia())
        return false; // La lista está vacía, por lo que no hay marcas repetidas

    pnodoMarcaProducto aux = primero;

    do
	{
        if (aux->codMarca == codMarca)
            // El código de marca ya existe en la lista
            return true;
            
        aux = aux->siguiente;
    } while (aux != primero);

    // El código de marca no está repetido en la lista
    return false;
}

bool ListaDCMarcaProductos::productoRepetidoEnMarcas(int codProducto)
{
	if (ListaVacia())
        return false;
        
    pnodoMarcaProducto actual = primero;

	do
	{
		if (actual->codProducto == codProducto)
            return true;

        actual = actual->siguiente;
	} while (actual != primero);

    return false;
}

void ListaDCMarcaProductos::eliminarMarcasProductos()
{
    if (ListaVacia())
    {
        cout << "\nLa lista esta vacia.\n" << endl;
        return;
    }

    pnodoMarcaProducto actual = primero;
    pnodoMarcaProducto siguiente;

    do
    {
        siguiente = actual->siguiente;
        // Elimina la marca actual
        delete actual;
        actual = siguiente;
    } while (actual != primero);

    primero = NULL; // Establece primero como NULL después de eliminar todos los nodos
    cout << "\nTodas las marcas han sido eliminadas.\n" << endl;
}

pnodoMarcaProducto ListaDCMarcaProductos::buscarMarcaProducto(int codMarca)
{
	if (ListaVacia())
	{
        cout << "\nLa lista de marcas esta vacia.\n" << endl;
        return NULL;
    }

    pnodoMarcaProducto aux = primero;

    do
	{
        if (aux->codMarca == codMarca)
        {
        	aux->contBusquedas++;
            return aux;
        }

        aux = aux->siguiente;
    } while (aux != primero);

    return NULL;
}

void ListaDCMarcaProductos::modificarMarcaProducto(int codMarca, string nombre,
	int cantGondola, int precio)
{
	pnodoMarcaProducto marcaProducto = buscarMarcaProducto(codMarca);

    if (marcaProducto == NULL)
    {
        cout << "\nMarca de producto no encontrada.\n" << endl;
        return;
    }

    marcaProducto->codMarca = codMarca;
    marcaProducto->nombre = nombre;
    marcaProducto->cantGondola = cantGondola;
    marcaProducto->precio = precio;
    
    cout << "\nMarca modificada exitosamente." << endl;
    cout << "\nMarca modificada:" << endl;
	cout << "-> CodMarca: " << codMarca << endl;
	cout << "   Nombre: " << nombre << endl;
	cout << "   CantGondola: " << cantGondola << endl;
	cout << "   Precio: " << precio << endl << endl;
}

ListaDCMarcaProductos::~ListaDCMarcaProductos()
{
    if (primero != NULL)
    {
        pnodoMarcaProducto aux = primero->siguiente;
        primero->siguiente = NULL; // Corta el enlace circular
        aux->anterior = NULL;
        primero = aux;

        while (aux != NULL)
		{
            pnodoMarcaProducto temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }
}

void ListaDCMarcaProductos::InsertarInicio(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto,
		codMarca, nombre, cantGondola, precio);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
        primero->anterior = primero;  // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
        primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaDCMarcaProductos::InsertarFinal(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio)
{
    pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto,
		codMarca, nombre, cantGondola, precio);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
        primero->anterior = primero;  // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaDCMarcaProductos::InsertarPos(int codPasillo, int codProducto,
    int codMarca, string nombre, int cantGondola, int precio, int pos)
{
    if (ListaVacia() || pos <= 1)
        InsertarInicio(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);
    else
    {
        pnodoMarcaProducto aux = primero;
        int i = 2;

        while ((i != pos) && (aux->siguiente != primero))
        {
            i++;
            aux = aux->siguiente;
        }

        pnodoMarcaProducto nuevo = new NodoMarcaProducto(codPasillo, codProducto,
			codMarca, nombre, cantGondola, precio);
        nuevo->siguiente = aux->siguiente;
        nuevo->anterior = aux;
        aux->siguiente->anterior = nuevo;
        aux->siguiente = nuevo;

        if (aux == primero)
            primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaDCMarcaProductos::BorrarInicio()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoMarcaProducto aux = primero;

            aux->anterior->siguiente = primero->siguiente;
            primero->siguiente->anterior = aux->anterior;

            primero = primero->siguiente;

            delete aux;
        }
    }
}

void ListaDCMarcaProductos::BorrarFinal()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoMarcaProducto aux = primero->anterior;

            aux->anterior->siguiente = primero;
            primero->anterior = aux->anterior;

            delete aux;
        }
    }
}

void ListaDCMarcaProductos::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        if (pos == 1)
            BorrarInicio();
        else
        {
            int cont = 2;
            pnodoMarcaProducto aux = primero->siguiente;

            while (cont < pos && aux != primero)
            {
                aux = aux->siguiente;
                cont++;
            }

            if (cont == pos)
            {
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;

                if (aux == primero)
                    primero = aux->siguiente; // Actualiza el puntero al último elemento

                delete aux;
            }
            else
                cout << "\nPosicion no valida.\n" << endl;
        }
    }
}

void ListaDCMarcaProductos::Mostrar()
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        pnodoMarcaProducto aux = primero;

        do
        {
            cout << "-> " << aux->codPasillo << "; " << aux->codProducto << "; "
				<< aux->codMarca << "; " << aux->nombre << "; " << aux->cantGondola << "; "
				<< aux->precio << endl << endl;

            aux = aux->siguiente;
        } while (aux != primero);
    }
}

int ListaDCMarcaProductos::largoLista()
{
    if (ListaVacia())
        return 0;
    else
    {
        int cont = 0;
        pnodoMarcaProducto aux = primero;

        do
        {
            cont++;
            aux = aux->siguiente;
        } while (aux != primero);

        return cont;
    }
}


class ListaDobleInventarios
{
public:
    ListaDobleInventarios() { primero = NULL; }
    ~ListaDobleInventarios();

    void InsertarInicio(int codPasillo, int codProducto, int codMarca, int codInventario,
        string nombre, int cantStock, bool codCanasta);
    void InsertarFinal(int codPasillo, int codProducto, int codMarca, int codInventario,
        string nombre, int cantStock, bool codCanasta);
    void InsertarPos(int codPasillo, int codProducto, int codMarca, int codInventario,
        string nombre, int cantStock, bool codCanasta, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarInventario(int codPasillo, int codProducto, int codMarca, int codInventario,
		string nombre, int cantStock, bool codCanasta, ListaSimplePasillos& listaPasillos,
		ListaDobleProductosPasillo& listaProductosPasillo, ListaDCMarcaProductos& listaMarcaProductos);
    bool inventarioRepetido(int codInventario);
    bool productoRepetidoEnInventario(int codProducto);
    bool marcaRepetidaEnInventario(int codMarca);
    void eliminarInventario(int codInventario, ListaSimplePasillos& listaPasillos);
    pnodoInventario buscarInventario(int codInventario);
    void modificarInventario(int codInventario, string nombre, int cantStock, bool codCanasta);

private:
    pnodoInventario primero;
};

void ListaDobleInventarios::insertarInventario(int codPasillo, int codProducto,
	int codMarca, int codInventario, string nombre, int cantStock, bool codCanasta,
	ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos)
{
    // Valida si el codPasillo existe en la lista simple de pasillos
    if (!listaPasillos.pasilloRepetido(codPasillo))
    {
        cout << "\nEl pasillo no existe.\n" << endl;
        return;    
    }

    // Valida si el codProducto existe en la lista doble de productos de pasillo
    if (!listaProductosPasillo.productoRepetido(codProducto))
    {
        cout << "\nEl producto no existe.\n" << endl;
        return;
    }

    // Valida si el codMarca existe en la lista circular de marcas de productos
    if (!listaMarcaProductos.marcaProductoRepetida(codMarca))
    {
        cout << "\nLa marca del producto no existe.\n" << endl;
        return;
    }

    // Valida si el inventario ya existe en la lista doble de inventario
    if (inventarioRepetido(codInventario))
    {
        cout << "\nEl inventario ya existe.\n" << endl;
        return;    
    }

    // Valida si el producto ya tiene un inventario en la lista doble de inventario
    if (productoRepetidoEnInventario(codProducto))
    {
        cout << "\nEl inventario ya existe para este producto.\n" << endl;
        return;
    }

    // Valida si la marca ya tiene un inventario en la lista doble de inventario
    if (marcaRepetidaEnInventario(codMarca))
    {
        cout << "\nEl inventario ya existe para esta marca.\n" << endl;
        return;
    }

    // Inserta en la lista doble de inventario después de las validaciones
    InsertarFinal(codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta);

    cout << "\nInventario insertado exitosamente." << endl;
    cout << "\nInventario insertado:" << endl;
    cout << "-> CodPasillo: " << codPasillo << endl;
    cout << "   CodProducto: " << codProducto << endl;
    cout << "   CodMarca: " << codMarca << endl;
    cout << "   CodInventario: " << codInventario << endl;
    cout << "   Nombre: " << nombre << endl;
    cout << "   CantStock: " << cantStock << endl;
    cout << "   CodCanasta: " << codCanasta << endl << endl;
}

bool ListaDobleInventarios::inventarioRepetido(int codInventario)
{
    pnodoInventario aux = primero;

    while (aux != NULL)
    {
        if (aux->codInventario == codInventario)
            // El código de inventario ya existe en la lista
            return true;

        aux = aux->siguiente;
    }

    // El código de inventario no está repetido en la lista
    return false;
}

bool ListaDobleInventarios::productoRepetidoEnInventario(int codProducto)
{
    pnodoInventario actual = primero;

    while (actual != NULL)
    {
        if (actual->codProducto == codProducto)
            return true;

        actual = actual->siguiente;
    }

    return false;
}

bool ListaDobleInventarios::marcaRepetidaEnInventario(int codMarca)
{
    pnodoInventario actual = primero;

    while (actual != NULL)
    {
        if (actual->codMarca == codMarca)
            return true;

        actual = actual->siguiente;
    }

    return false;
}

void ListaDobleInventarios::eliminarInventario(int codInventario, ListaSimplePasillos& listaPasillos)
{
    if (ListaVacia())
    {
        cout << "\nLa lista está vacía.\n" << endl;
        return;
    }

    pnodoInventario actual = primero;
    int posicion = 1;

    while (actual != NULL)
    {
        if (actual->codInventario == codInventario)
        {
            if (!listaPasillos.pasilloRepetido(actual->codPasillo))
            {
                // Elimina el producto del inventario
                BorrarPosicion(posicion);
                cout << "\nProducto eliminado del inventario exitosamente.\n" << endl;
            }
            else
                cout << "\nNo se puede eliminar. El producto existe en el pasillo.\n" << endl;

            return;
        }

        actual = actual->siguiente;
        posicion++;
    }
}

pnodoInventario ListaDobleInventarios::buscarInventario(int codInventario)
{
	if (ListaVacia())
	{
        cout << "\nLa lista de inventario esta vacia.\n" << endl;
        return NULL;
    }

    pnodoInventario aux = primero;

    while (aux != NULL)
	{
        if (aux->codInventario == codInventario)
            return aux;

        aux = aux->siguiente;
    }

    return NULL;
}

void ListaDobleInventarios::modificarInventario(int codInventario, string nombre,
	int cantStock, bool codCanasta)
{
	pnodoInventario inventario = buscarInventario(codInventario);

    if (inventario == NULL)
    {
        cout << "\nInventario no encontrado.\n" << endl;
        return;
    }

    inventario->codInventario = codInventario;
    inventario->nombre = nombre;
    inventario->cantStock = cantStock;
    inventario->codCanasta = codCanasta;

    cout << "\nInventario modificado exitosamente." << endl;
    cout << "\nInventario modificado:" << endl;
	cout << "-> CodInventario: " << codInventario << endl;
	cout << "   Nombre: " << nombre << endl;
	cout << "   CantStock: " << cantStock << endl;
	cout << "   CodCanasta: " << codCanasta << endl << endl;
}

ListaDobleInventarios::~ListaDobleInventarios()
{
    pnodoInventario aux;

    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    primero = NULL;
}

void ListaDobleInventarios::InsertarInicio(int codPasillo, int codProducto, int codMarca,
	int codInventario, string nombre, int cantStock, bool codCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario,
            nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto, codMarca,
			codInventario, nombre, cantStock, codCanasta);
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }
}

void ListaDobleInventarios::InsertarFinal(int codPasillo, int codProducto, int codMarca,
	int codInventario, string nombre, int cantStock, bool codCanasta)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario,
            nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        pnodoInventario aux = primero;

        while (aux->siguiente != NULL)
            aux = aux->siguiente;

        aux->siguiente = new NodoInventario(codPasillo, codProducto, codMarca,
			codInventario, nombre, cantStock, codCanasta);
        aux->siguiente->anterior = aux;
    }
}

void ListaDobleInventarios::InsertarPos(int codPasillo, int codProducto, int codMarca,
    int codInventario, string nombre, int cantStock, bool codCanasta, int pos)
{
    if (ListaVacia())
    {
        primero = new NodoInventario(codPasillo, codProducto, codMarca, codInventario,
            nombre, cantStock, codCanasta);
        primero->anterior = NULL;
    }
    else
    {
        if (pos <= 1)
        {
            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto,
				codMarca, codInventario, nombre, cantStock, codCanasta);
            nuevo->siguiente = primero;

            if (primero != NULL)
                primero->anterior = nuevo;

            primero = nuevo;
        }
        else
        {
            pnodoInventario aux = primero;
            int i = 2;

            while ((i != pos) && (aux->siguiente != NULL))
            {
                i++;
                aux = aux->siguiente;
            }

            pnodoInventario nuevo = new NodoInventario(codPasillo, codProducto,
				codMarca, codInventario, nombre, cantStock, codCanasta);
            nuevo->siguiente = aux->siguiente;

            if (aux->siguiente != NULL)
                aux->siguiente->anterior = nuevo;

            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
}

void ListaDobleInventarios::BorrarInicio()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == NULL) {
            pnodoInventario temp = primero;
            primero = NULL;
            delete temp;
        }
        else {
            pnodoInventario temp = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete temp;
        }
    }
}

void ListaDobleInventarios::BorrarFinal()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoInventario temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoInventario aux = primero;
            while (aux->siguiente->siguiente != NULL)
                aux = aux->siguiente;

            pnodoInventario temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void ListaDobleInventarios::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "\nError en posicion.\n" << endl;
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
                    int cont = 2;
                    pnodoInventario aux = primero;

                    while (cont < pos)
                    {
                        aux = aux->siguiente;
                        cont++;
                    }

                    pnodoInventario temp = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;

                    if (aux->siguiente != NULL)
                        aux->siguiente->anterior = aux;

                    delete temp;
                }
            }
        }
    }
}

void ListaDobleInventarios::Mostrar()
{
    pnodoInventario aux = primero;

    while (aux)
	{
        cout << "-> " << aux->codPasillo << "; " << aux->codProducto << "; "
			<< aux->codMarca << "; " << aux->codInventario << "; " << aux->nombre << "; "
			<< aux->cantStock << "; " << aux->codCanasta << endl << endl;

        aux = aux->siguiente;
    }
}

int ListaDobleInventarios::largoLista()
{
    int cont = 0;
    pnodoInventario aux = primero;

    while (aux != NULL)
    {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}


class HashingClientes
{
public:
    HashingClientes(int N); // Constructor
    ~HashingClientes();     // Destructor

	int funcionHash(int cedula) { return cedula % 13; }
	bool hashingVacio();
    void insertarCliente(int cedula, string nombre, int codCiudad, string telefono,
		string correo);
	bool clienteRepetido(int cedula);
    void eliminarCliente(int cedula);
    pnodoCliente buscarCliente(int cedula);
    void modificarCliente(int cedula, string nombre, int codCiudad, string telefono,
		string correo, pnodoCliente cliente);
	void reporteClientes();
    string mostrarHash();
    bool loginCliente(int cedula);

private:
	pnodoCliente* tablaHash; // Puntero al arreglo que contiene los clientes
	
	friend class ListaCircularCiudades;
};

HashingClientes::HashingClientes(int N)
{
    tablaHash = new pnodoCliente[13]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < 13; i++)
        tablaHash[i] = NULL;
}

HashingClientes::~HashingClientes()
{
    for (int i = 0; i < 13; i++)
    {
        pnodoCliente actual = tablaHash[i];

        while (actual != NULL)
        {
            pnodoCliente siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    delete[] tablaHash;
}

// Método para comprobar si el hashing abierto está vacío
bool HashingClientes::hashingVacio()
{
    for (int i = 0; i < 13; i++)
	{
        if (tablaHash[i] != NULL)
            return false;
    }

    return true;
}

// Método que inserta un nuevo cliente en la tabla hash
void HashingClientes::insertarCliente(int cedula, string nombre, int codCiudad,
	string telefono, string correo)
{
	// Verifica si el cliente ya existe
    if (clienteRepetido(cedula))
	{
        cout << "\nEl cliente con cedula " << cedula << " ya existe.\n" << endl;
        return;
    }
        
    // Aplica la función de hashing
    int indice = funcionHash(cedula);

    pnodoCliente clienteNuevo = new NodoCliente(cedula, nombre, codCiudad, telefono, correo);

    // Verifica si ya hay un nodo en esa posición
    if (tablaHash[indice] == NULL)
        tablaHash[indice] = clienteNuevo;
    else
    {
        // Si ya hay un nodo, lo coloca al final de la lista
        pnodoCliente actual = tablaHash[indice];

        while (actual->siguiente != NULL)
            actual = actual->siguiente;

        actual->siguiente = clienteNuevo;
    }
    
    cout << "\nCliente insertado exitosamente." << endl;
    cout << "\nCliente insertado:" << endl;
    cout << indice << " -> Cedula: " << cedula << endl;
    cout << "     Nombre: " << nombre << endl;
    cout << "     CodCiudad: " << codCiudad << endl;
    cout << "     Telefono: " << telefono << endl;
    cout << "     Correo: " << correo << endl << endl;
}

bool HashingClientes::clienteRepetido(int cedula) 
{
    pnodoCliente actual = tablaHash[funcionHash(cedula)];

	while (actual != NULL)
	{
        if (actual->cedula == cedula)
            return true; // Cliente repetido encontrado

        actual = actual->siguiente;
    }

    return false; // Cliente no repetido
}

void HashingClientes::eliminarCliente(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoCliente actual = tablaHash[indice];
    pnodoCliente anterior = NULL;

    while ((actual != NULL) && (actual->cedula != cedula))
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;

    if (anterior == NULL)
        tablaHash[indice] = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    delete actual;
}

pnodoCliente HashingClientes::buscarCliente(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoCliente actual = tablaHash[indice];

    while ((actual != NULL) && (actual->cedula != cedula))
        actual = actual->siguiente;

    return actual;
}

void HashingClientes::modificarCliente(int cedula, string nombre, int codCiudad,
	string telefono, string correo, pnodoCliente cliente)
{
    cliente->nombre = nombre;
    cliente->codCiudad = codCiudad;
    cliente->telefono = telefono;
    cliente->correo = correo;
    
    cout << "\nCliente modificado exitosamente." << endl;
    cout << "\nCliente modificado:" << endl;
    cout << funcionHash(cedula) << " --> Cedula: " << cedula << endl;
    cout << "      Nombre: " << nombre << endl;
    cout << "      CodCiudad: " << codCiudad << endl;
    cout << "      Telefono: " << telefono << endl;
    cout << "      Correo: " << correo << endl << endl;
}

string HashingClientes::mostrarHash()
{
    stringstream ss; // Construye la salida como una cadena

	for (int i = 0; i < 13; i++)
    {
        ss << i;
        pnodoCliente actual = tablaHash[i];
        bool primerNodo = true;

        while (actual != NULL)
        {
            if (!primerNodo)
                ss << "  -> ";
            else
            {
                primerNodo = false;
                ss << " -> ";
            }

            ss << actual->cedula << "; " << actual->nombre << "; "
                << actual->codCiudad << "; " << actual->telefono << "; " << actual->correo << endl;

            if (actual->siguiente == NULL)
                ss << "     -------------------------------------------------------------";
            else
            	ss << "     -------------------------------------------------------------" << endl;

            actual = actual->siguiente;
        }

        ss << endl << endl;
    }

    return ss.str();
}

bool HashingClientes::loginCliente(int cedula)
{
    pnodoCliente cliente = buscarCliente(cedula);

    return ((cliente != NULL) && (cliente->cedula == cedula));
}


class HashingAdmins
{
public:
    HashingAdmins(int N); // Constructor
    ~HashingAdmins();     // Destructor

	int funcionHash(int cedula) { return cedula % 13; }
	bool hashingVacio();
    void insertarAdmin(int cedula, string nombre, int codCiudad, string telefono,
		string correo);
	bool adminRepetido(int cedula);
    void eliminarAdmin(int cedula);
    pnodoAdmin buscarAdmin(int cedula);
    void modificarAdmin(int cedula, string nombre, int codCiudad, string telefono,
		string correo, pnodoAdmin admin);
	void reporteAdmins();
    string mostrarHash();
    bool loginAdmin(int cedula);

private:
    pnodoAdmin* tablaHash; // Puntero al arreglo que contiene los administradores
    
    friend class ListaCircularCiudades;
};

HashingAdmins::HashingAdmins(int N)
{
    tablaHash = new pnodoAdmin[13]();

    // Inicializa la tabla hash con NULL
    for (int i = 0; i < 13; i++)
        tablaHash[i] = NULL;
}

HashingAdmins::~HashingAdmins()
{
    for (int i = 0; i < 13; i++)
    {
        pnodoAdmin actual = tablaHash[i];

        while (actual != NULL)
        {
            pnodoAdmin siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    delete[] tablaHash;
}

// Método para comprobar si el hashing abierto está vacío
bool HashingAdmins::hashingVacio()
{
    for (int i = 0; i < 13; i++)
	{
        if (tablaHash[i] != NULL)
            return false;
    }

    return true;
}

// Método que inserta un nuevo administrador en la tabla hash
void HashingAdmins::insertarAdmin(int cedula, string nombre, int codCiudad,	string telefono,
	string correo)
{
	// Verifica si el administrador ya existe
    if (adminRepetido(cedula))
	{
        cout << "\nEl administrador con cedula " << cedula << " ya existe.\n" << endl;
        return;
    }
    
    // Aplica la función de hashing
    int indice = funcionHash(cedula);

    pnodoAdmin nuevoAdmin = new NodoAdmin(cedula, nombre, codCiudad, telefono, correo);

    // Verifica si ya hay un nodo en esa posición
    if (tablaHash[indice] == NULL)
        tablaHash[indice] = nuevoAdmin;
    else
    {
        // Si ya hay un nodo, lo coloca al final de la lista
        pnodoAdmin actual = tablaHash[indice];

        while (actual->siguiente != NULL)
            actual = actual->siguiente;

        actual->siguiente = nuevoAdmin;
    }
    
    cout << "\nAdministrador insertado exitosamente." << endl;
    cout << "\nAdministrador insertado:" << endl;
    cout << indice << " -> Cedula: " << cedula << endl;
    cout << "     Nombre: " << nombre << endl;
    cout << "     CodCiudad: " << codCiudad << endl;
    cout << "     Telefono: " << telefono << endl;
    cout << "     Correo: " << correo << endl << endl;
}

bool HashingAdmins::adminRepetido(int cedula) 
{
    pnodoAdmin actual = tablaHash[funcionHash(cedula)];

	while (actual != NULL)
	{
        if (actual->cedula == cedula)
            return true; // Administrador repetido encontrado

        actual = actual->siguiente;
    }

    return false; // Administrador no repetido
}

void HashingAdmins::eliminarAdmin(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoAdmin actual = tablaHash[indice];
    pnodoAdmin anterior = NULL;

    while ((actual != NULL) && (actual->cedula != cedula))
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;

    if (anterior == NULL)
        tablaHash[indice] = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    delete actual;
}

pnodoAdmin HashingAdmins::buscarAdmin(int cedula)
{
    int indice = funcionHash(cedula);

    pnodoAdmin actual = tablaHash[indice];

    while ((actual != NULL) && (actual->cedula != cedula))
        actual = actual->siguiente;

    return actual;
}

void HashingAdmins::modificarAdmin(int cedula, string nombre, int codCiudad, string telefono,
	string correo, pnodoAdmin admin)
{
    admin->nombre = nombre;
    admin->codCiudad = codCiudad;
    admin->telefono = telefono;
    admin->correo = correo;
    
    cout << "\nAdministrador modificado exitosamente." << endl;
    cout << "\nAdministrador modificado:" << endl;
    cout << funcionHash(cedula) << " -> Cedula: " << cedula << endl;
    cout << "     Nombre: " << nombre << endl;
    cout << "     CodCiudad: " << codCiudad << endl;
    cout << "     Telefono: " << telefono << endl;
    cout << "     Correo: " << correo << endl << endl;
}

string HashingAdmins::mostrarHash()
{
    stringstream ss; // Construye la salida como una cadena

	for (int i = 0; i < 13; i++)
    {
        ss << i;
        pnodoAdmin actual = tablaHash[i];
        bool primerNodo = true;

        while (actual != NULL)
        {
            if (!primerNodo)
                ss << "  -> ";
            else
            {
                primerNodo = false;
                ss << " -> ";
            }

            ss << actual->cedula << "; " << actual->nombre << "; "
                << actual->codCiudad << "; " << actual->telefono << "; " << actual->correo << endl;

            if (actual->siguiente == NULL)
                ss << "     -------------------------------------------------------------";
            else
            	ss << "     -------------------------------------------------------------" << endl;

            actual = actual->siguiente;
        }

        ss << endl << endl;
    }

    return ss.str();
}

bool HashingAdmins::loginAdmin(int cedula)
{
    pnodoAdmin admin = buscarAdmin(cedula);

    return ((admin != NULL) && (admin->cedula == cedula));
}


class ListaCircularCiudades
{
public:
    ListaCircularCiudades() { primero = NULL; }
    ~ListaCircularCiudades();

    void InsertarInicio(int codCiudad, string nombre);
    void InsertarFinal(int codCiudad, string nombre);
    void InsertarPos(int codCiudad, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void BorrarInicio();
    void BorrarFinal();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void insertarCiudad(int codCiudad, string nombre);
    bool ciudadRepetida(int codCiudad);    
    void eliminarCiudad(int codCiudad, HashingClientes& hashClientes,
		HashingAdmins& hashAdmins);
    pnodoCiudad buscarCiudad(int codCiudad);
    void modificarCiudad(int codCiudad, string nombre);
    void reporteCiudades();

private:
    pnodoCiudad primero;
};

void ListaCircularCiudades::insertarCiudad(int codCiudad, string nombre)
{
    // Valida si el codCiudad no está repetido
    if (!ciudadRepetida(codCiudad))
    {
        InsertarInicio(codCiudad, nombre);
        
        cout << "\nCiudad insertada exitosamente." << endl;
        cout << "\nCiudad insertada:" << endl;
        cout << "-> CodCiudad: " << codCiudad << endl;
        cout << "   Nombre: " << nombre << endl << endl;
    }
    else
        cout << "\nLa ciudad ya existe en la lista.\n" << endl;
}

bool ListaCircularCiudades::ciudadRepetida(int codCiudad)
{
    if (ListaVacia())
        return false; // La lista está vacía, no hay ciudades repetidas

    pnodoCiudad aux = primero;

    do
    {
        if (aux->codCiudad == codCiudad)
            // El código de ciudad ya existe en la lista
            return true;

        aux = aux->siguiente;
    } while (aux != primero);

    // El código de ciudad no está repetido en la lista
    return false;
}

void ListaCircularCiudades::eliminarCiudad(int codCiudad, HashingClientes& hashClientes,
	HashingAdmins& hashAdmins)
{
    if (ListaVacia())
    {
        cout << "\nLa lista esta vacia.\n" << endl;
        return;
    }

    pnodoCiudad actual = primero;
    int pos = 1;

    do
    {
        if (actual->codCiudad == codCiudad)
        {
        	for (int i = 0; i < 13; ++i)
			{
		        pnodoCliente actualCte = hashClientes.tablaHash[i];
		        
				while (actualCte != NULL)
				{
		            if (actualCte->getCodCiudad() == codCiudad)
		                hashClientes.eliminarCliente(actualCte->getCedula());

		            actualCte = actualCte->siguiente;
		        }
		    }
		    
		    for (int j = 0; j < 13; ++j)
			{
		        pnodoAdmin actualAdmin = hashAdmins.tablaHash[j];
		        
		        while (actualAdmin != NULL)
				{
		            if (actualAdmin->getCodCiudad() == codCiudad)
		                hashAdmins.eliminarAdmin(actualAdmin->getCedula());

		            actualAdmin = actualAdmin->siguiente;
		        }
		    }

            // Se encontró el nodo con el codCiudad dado, borrar en esa posición
            BorrarPosicion(pos);
            cout << "\nCiudad eliminada exitosamente.\n" << endl;
            return;
        }

        actual = actual->siguiente;
        pos++;
    } while (actual != primero);
}

pnodoCiudad ListaCircularCiudades::buscarCiudad(int codCiudad)
{
    if (ListaVacia())
    {
        cout << "\nLa lista de inventario esta vacia.\n" << endl;
        return NULL;
    }

    pnodoCiudad aux = primero;

    do
    {
        if (aux->codCiudad == codCiudad)
            return aux;

        aux = aux->siguiente;
    } while (aux != primero);

    return NULL;
}

void ListaCircularCiudades::modificarCiudad(int codCiudad, string nombre)
{
    // Busca la ciudad con el código dado
    pnodoCiudad ciudad = buscarCiudad(codCiudad);

    // Verifica si la ciudad no existe
    if (ciudad == NULL)
    {
        cout << "\nCiudad no encontrada.\n" << endl;
        return;
    }

    // Modifica los atributos de la ciudad encontrado
    ciudad->nombre = nombre;

    cout << "\nCiudad modificada: " << endl;
    cout << "-> CodCiudad: " << codCiudad << endl;
    cout << "   Nombre: " << nombre << endl << endl;
}

ListaCircularCiudades::~ListaCircularCiudades()
{
    if (primero != NULL)
    {
        pnodoCiudad aux = primero->siguiente;
        primero->siguiente = NULL; // Corta el enlace circular
        primero = aux;

        while (aux != NULL)
        {
            pnodoCiudad temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }
}

void ListaCircularCiudades::InsertarInicio(int codCiudad, string nombre)
{
    pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero->siguiente;
        primero->siguiente = nuevo;
    }
}

void ListaCircularCiudades::InsertarFinal(int codCiudad, string nombre)
{
    pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);

    if (ListaVacia())
    {
        primero = nuevo;
        primero->siguiente = primero; // Enlace circular
    }
    else
    {
        nuevo->siguiente = primero->siguiente;
        primero->siguiente = nuevo;
        primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaCircularCiudades::InsertarPos(int codCiudad, string nombre, int pos)
{
    if (ListaVacia() || (pos <= 1))
        InsertarInicio(codCiudad, nombre);
    else
    {
        pnodoCiudad aux = primero;
        int i = 2;

        while ((i != pos) && (aux->siguiente != primero))
        {
            i++;
            aux = aux->siguiente;
        }

        pnodoCiudad nuevo = new NodoCiudad(codCiudad, nombre);
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;

        if (aux == primero)
            primero = nuevo; // Actualiza el puntero al último elemento
    }
}

void ListaCircularCiudades::BorrarInicio()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoCiudad aux = primero;

            while (aux->siguiente != primero)
                aux = aux->siguiente;

            pnodoCiudad temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            delete temp;
        }
    }
}

void ListaCircularCiudades::BorrarFinal()
{
    if (ListaVacia())
        cout << "\nNo hay elementos en la lista.\n" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            delete primero;
            primero = NULL;
        }
        else
        {
            pnodoCiudad aux = primero;

            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;

            pnodoCiudad temp = aux->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void ListaCircularCiudades::BorrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        if (pos == 1)
            BorrarInicio();
        else
        {
            int cont = 2;
            pnodoCiudad aux = primero;

            while (cont < pos)
            {
                aux = aux->siguiente;
                cont++;
            }

            pnodoCiudad temp = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;

            if (temp == primero)
                primero = aux; // Actualiza el puntero al último elemento

            delete temp;
        }
    }
}

void ListaCircularCiudades::Mostrar()
{
    if (ListaVacia())
        cout << "\nLa lista esta vacia.\n" << endl;
    else
    {
        pnodoCiudad aux = primero;

        do
        {
            cout << "-> " << aux->codCiudad << "; " << aux->nombre << endl << endl;

            aux = aux->siguiente;
        } while (aux != primero);
    }
}

int ListaCircularCiudades::largoLista()
{
    if (ListaVacia())
        return 0;
    else
    {
        int cont = 0;
        pnodoCiudad aux = primero;

        do
        {
            aux = aux->siguiente;
            cont++;
        } while (aux != primero);

        return cont;
    }
}



int stringAInt(string str)
{
    istringstream iss(str);
    int res;
    
    if (!(iss >> res))
	{
        cout << "\nNo se pudo convertir la cadena a entero.\n" << endl;
        return 0;
    }
    
    return res;
}

string intAString(int num)
{
    ostringstream convertir;  // Objeto de stringstream para la conversión

    // Agrega el número a la secuencia de caracteres de la stringstream
    convertir << num;

    // Convierte la secuencia de caracteres en un string y devolverlo
    return convertir.str();
}

// Función que convierte "1" o "0" a booleano
bool stringABool(string str)
{
    istringstream iss(str);
    bool res;

    if (str == "1")
        return true;
    else if (str == "0")
        return false;
    else
    {
        cout << "\nNo se puede convertir la cadena a bool.\n" << endl;
        return false;
    }
}



void crearListaPasillos(ListaSimplePasillos& listaPasillos)
{
	ifstream archivo("Pasillos.txt");

    if (!archivo)
	{
        cout << "\nNo se pudo abrir el archivo Pasillos.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
	{
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, nombre;

        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;

		// Inserta en la lista simple de pasillos después de las validaciones
        listaPasillos.insertarPasillo(stringAInt(codPasillo), nombre);
    }

    archivo.close();
}

void crearListaProductosPasillo(ListaDobleProductosPasillo& listaProductosPasillo, ListaSimplePasillos& listaPasillos)
{
    ifstream archivo("ProductosPasillos.txt");

    if (!archivo)
    {
        cout << "\nNo se pudo abrir el archivo ProductosPasillos.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, codProducto, nombre;
        
        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, codProducto, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;

        // Inserta en la lista doble de productos después de las validaciones
        listaProductosPasillo.insertarProducto(stringAInt(codPasillo), stringAInt(codProducto),
            nombre, listaPasillos);
    }

    archivo.close();
}

void crearListaMarcaProductos(ListaDCMarcaProductos& listaMarcas, ListaSimplePasillos& listaPasillos,
	ListaDobleProductosPasillo& listaProductosPasillo)
{
    ifstream archivo("MarcasProductos.txt");

    if (!archivo)
    {
        cout << "\nNo se pudo abrir el archivo MarcasProductos.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, codProducto, codMarca, nombre, cantGondola, precio;
        
        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, codProducto, ';'); ss >> ws;
        getline(ss, codMarca, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, cantGondola, ';'); ss >> ws;
        getline(ss, precio, ';'); ss >> ws;

        // Inserta en la lista circular doble de marcas después de las validaciones
        listaMarcas.insertarMarcaProducto(stringAInt(codPasillo), stringAInt(codProducto),
            stringAInt(codMarca), nombre, stringAInt(cantGondola), stringAInt(precio),
            listaPasillos, listaProductosPasillo);
    }

    archivo.close();
}

void crearListaInventarios(ListaDobleInventarios& listaInventarios, ListaSimplePasillos& listaPasillos,
    ListaDobleProductosPasillo& listaProductosPasillo, ListaDCMarcaProductos& listaMarcas)
{
	ifstream archivo("Inventario.txt");

    if (!archivo)
    {
        cout << "\nNo se pudo abrir el archivo Inventario.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta;
        
        getline(ss, codPasillo, ';'); ss >> ws;
        getline(ss, codProducto, ';'); ss >> ws;
        getline(ss, codMarca, ';'); ss >> ws;
        getline(ss, codInventario, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, cantStock, ';'); ss >> ws;
        getline(ss, codCanasta, ';'); ss >> ws;

        // Inserta en la lista doble de inventario después de las validaciones
        listaInventarios.insertarInventario(stringAInt(codPasillo), stringAInt(codProducto),
            stringAInt(codMarca), stringAInt(codInventario), nombre, stringAInt(cantStock),
            stringABool(codCanasta), listaPasillos, listaProductosPasillo, listaMarcas);
    }

    archivo.close();
}

void crearHashingClientes(HashingClientes& hashClientes, ListaCircularCiudades& listaCiudades)
{
    ifstream archivo("Clientes.txt");

    if (!archivo)
	{
        cout << "\nNo se pudo abrir el archivo Clientes.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
	{
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string cedula, nombre, codCiudad, telefono, correo;

        getline(ss, cedula, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, codCiudad, ';'); ss >> ws;
        getline(ss, telefono, ';'); ss >> ws;
        getline(ss, correo, ';'); ss >> ws;

        if (listaCiudades.ciudadRepetida(stringAInt(codCiudad)))
			// Inserta en el hash de clientes después de las validaciones
	        hashClientes.insertarCliente(stringAInt(cedula), nombre, stringAInt(codCiudad),
				telefono, correo);
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}

void crearHashingAdmins(HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
    ifstream archivo("Administradores.txt");

    if (!archivo)
	{
        cout << "\nNo se pudo abrir el archivo Administradores.txt\n" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
	{
        // Ignora líneas vacías
        if (linea == "")
            continue;

        istringstream ss(linea);
        string cedula, nombre, codCiudad, telefono, correo;
        
        getline(ss, cedula, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;
        getline(ss, codCiudad, ';'); ss >> ws;
        getline(ss, telefono, ';'); ss >> ws;
        getline(ss, correo, ';'); ss >> ws;

		if (listaCiudades.ciudadRepetida(stringAInt(codCiudad)))
			// Inserta en el hash de administradores después de las validaciones
	        hashAdmins.insertarAdmin(stringAInt(cedula), nombre, stringAInt(codCiudad),
				telefono, correo);
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}


void crearListaCiudades(ListaCircularCiudades& listaCiudades)
{
	ifstream archivo("Ciudades.txt");
	
	if (!archivo)
	{
	    cout << "\nNo se pudo abrir el archivo Ciudades.txt\n" << endl;
	    return;
	}

	string linea;
	
	while (getline(archivo, linea))
	{
	    // Ignora líneas vacías
	    if (linea == "")
	        continue;

        istringstream ss(linea); ss >> ws;
        string codCiudad, nombre;
        
        getline(ss, codCiudad, ';'); ss >> ws;
        getline(ss, nombre, ';'); ss >> ws;

        // Inserta en la lista circular simple de ciudades después de las validaciones
        listaCiudades.insertarCiudad(stringAInt(codCiudad), nombre);
	}
}



void crearReporte(string nombreReporte, string distintivo, string texto)
{
	ofstream archivoNuevo;
	
	string titulo = "Reporte-" + nombreReporte + distintivo + ".txt";
	
	archivoNuevo.open(titulo.c_str(), ios::out);
	
	// Comprueba si el archivo se abrió correctamente
    if (!archivoNuevo.is_open())
    {
        cout << "\nError al abrir el archivo para escritura.\n" << endl;
        return;
    }
	
	archivoNuevo << "Reporte: ";
	archivoNuevo << nombreReporte << endl << endl;
	archivoNuevo << texto << endl;
	
	cout << "Reporte " << nombreReporte << " creado con exito.\n" << endl;
	
	archivoNuevo.close();
}

void ListaSimplePasillos::reportePasillos()
{
    string nombreReporte = "Pasillos";
    string texto = "";

    // Itera sobre la lista de pasillos y guarda en el archivo
    pnodoPasillo temp = primero;

	while (temp != NULL)
	{
        texto += "-> " + intAString(temp->codPasillo) + "; " + temp->nombre + "\n\n";

        temp = temp->siguiente;
    }

    if (!ListaVacia())
    {
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay pasillos registrados.\n" << endl;
}

void ListaDobleProductosPasillo::reporteProductosPasillo()
{
    int codigoPasillo;
    cout << "Ingrese el codigo del pasillo: ";
    cin >> codigoPasillo;

	string nombreReporte = "Productos de Pasillo";
    string texto = "";

    pnodoProductoPasillo temp = primero;
    bool productoEncontrado = false;

    while (temp != NULL)
    {
        if (temp->codPasillo == codigoPasillo)
        {
            productoEncontrado = true;

            texto += "-> " + intAString(temp->codPasillo) + "; " +
					intAString(temp->codProducto) + "; " + temp->nombre + "\n\n";
        }

        temp = temp->siguiente;
    }

    if (productoEncontrado)
    {
        cout << "\nReporte: " << nombreReporte << endl << endl;
        cout << texto; // Muestra en consola
        crearReporte(nombreReporte, ("-" + intAString(codigoPasillo)), texto); // Escribe en el archivo
    }
    else
        cout << "\nNo se encontraron productos en el pasillo.\n" << endl;
}

void ListaDCMarcaProductos::reporteMarcaProductos()
{
    int codigoPasillo, codigoProducto;
    cout << "Ingrese el codigo del pasillo: ";
    cin >> codigoPasillo;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoProducto;

    string nombreReporte = "Marca de Productos";
    string texto = "";
    string distintivo = "";

    pnodoMarcaProducto temp = primero;
    bool marcaEncontrada = false;

    // Avanza hasta el último nodo de la lista circular
    while (temp->siguiente != primero)
        temp = temp->siguiente;

    // Recorre la lista en sentido inverso para encontrar el pasillo y el producto
    do
	{
        if ((temp->codPasillo == codigoPasillo) && (temp->codProducto == codigoProducto))
		{
            marcaEncontrada = true;

            texto += "-> " + intAString(temp->codPasillo) + "; " +
					intAString(temp->codProducto) + "; " + intAString(temp->codMarca) + "; " +
                    temp->nombre + "; " + intAString(temp->cantGondola) + "; " +
					intAString(temp->precio) + "\n\n";
			
			distintivo = temp->nombre;
        }

        temp = temp->anterior;
    } while (temp != primero->anterior);

    if (marcaEncontrada)
    {
        cout << "\nReporte: " << nombreReporte << endl << endl;
        cout << texto; // Muestra en consola
        crearReporte(nombreReporte, ("-" + distintivo), texto); // Escribe en el archivo
    }
    else
        cout << "\nNo se encontraron marcas asociadas al producto.\n" << endl;
}

void HashingClientes::reporteClientes()
{
	string nombreReporte = "Clientes";
    string texto = mostrarHash();

	if (!hashingVacio())
	{
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay clientes registrados.\n" << endl;
}

void HashingAdmins::reporteAdmins()
{
	string nombreReporte = "Administradores";
	string texto = mostrarHash();

	if (!hashingVacio())
	{
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay administradores registrados.\n" << endl;
}

void ListaCircularCiudades::reporteCiudades()
{
	string nombreReporte = "Ciudades";
    string texto = "";

    pnodoCiudad temp = primero;

	// Itera sobre la lista de ciudades y guarda en el archivo
	if (temp != NULL)
    {
        pnodoCiudad inicio = temp;

        do
        {
            texto += "-> " + intAString(temp->codCiudad) + "; " + temp->nombre + "\n\n";

            temp = temp->siguiente;
        } while (temp != inicio);
    }

    if (!ListaVacia())
    {
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay ciudades registradas.\n" << endl;
}

void ListaSimplePasillos::reportePasilloMasVisitado()
{
    string nombreReporte = "Pasillo(s) mas visitado(s)";
    string texto = "";

    pnodoPasillo temp = primero;
    int maxVisitas = 0;

    // Encuentra el número máximo de visitas
    while (temp != NULL)
	{
        if (temp->contVisitas > maxVisitas)
            maxVisitas = temp->contVisitas;

        temp = temp->siguiente;
    }

    temp = primero;

    // Agrega al texto los pasillos más visitados
    while (temp != NULL)
	{
        if (temp->contVisitas == maxVisitas)
		{
            texto += "CodPasillo: " + intAString(temp->codPasillo) +
                    "\nNombre: " + temp->nombre +
                    "\nCantidad de visitas: " + intAString(temp->contVisitas) +
					"\n--------------------------\n\n";
        }

        temp = temp->siguiente;
    }

    if (maxVisitas > 0)
	{
        cout << "Reporte: " << nombreReporte << endl << endl;
        cout << texto; // Imprime en consola
        crearReporte(nombreReporte, "", texto); // Escribe en el archivo
    }
	else
        cout << "No hay pasillos mas visitados.\n" << endl;
}

void ListaSimplePasillos::reportePasilloMenosVisitado()
{
    string nombreReporte = "Pasillo(s) menos visitado(s)";
    string texto = "";

    pnodoPasillo temp = primero;
    int minVisitas = -1;

    // Encuentra el número mínimo de visitas
    while (temp != NULL)
	{
        if (temp->contVisitas >= 1)
		{
            if ((minVisitas == -1) || (temp->contVisitas < minVisitas))
                minVisitas = temp->contVisitas;
        }

        temp = temp->siguiente;
    }

    temp = primero;

	// Agrega al texto los pasillos menos visitados
    while (temp != NULL)
	{
        if (temp->contVisitas == minVisitas)
		{
            texto += "CodPasillo: " + intAString(temp->codPasillo) +
                    "\nNombre: " + temp->nombre +
                    "\nCantidad de visitas: " + intAString(temp->contVisitas) +
					"\n--------------------------\n\n";
        }

        temp = temp->siguiente;
    }

    if (minVisitas != -1)
	{
        cout << "Reporte: " << nombreReporte << endl << endl;
        cout << texto; // Imprime en consola
        crearReporte(nombreReporte, "", texto); // Escribe en el archivo
    }
	else
        cout << "No hay pasillos menos visitados.\n" << endl;
}

void ListaDobleProductosPasillo::reporteProductoMasBuscado(ListaSimplePasillos& listaPasillos)
{
    string nombreReporte = "Producto(s) mas buscado(s)";
    string texto = "";

    pnodoProductoPasillo temp = primero;
    int maxBusquedas = 0;

    // Encuentra el número máximo de búsquedas
    while (temp != NULL)
	{
        if (temp->contBusquedas > maxBusquedas)
            maxBusquedas = temp->contBusquedas;

        temp = temp->siguiente;
    }

    temp = primero;

	// Agrega al texto los productos más buscados
    while (temp != NULL)
	{
        if (temp->contBusquedas == maxBusquedas)
		{
            texto += "Pasillo: " + intAString(temp->codPasillo) + "; " +
					listaPasillos.buscarPasillo(temp->codPasillo)->getNombre() +
            		"\nProducto: " + intAString(temp->codProducto) + "; " + temp->nombre +
                    "\nCantidad de busquedas: " + intAString(temp->contBusquedas) +
					"\n--------------------------\n\n";
        }

        temp = temp->siguiente;
    }

    if (maxBusquedas > 0)
	{
        cout << "Reporte: " << nombreReporte << endl << endl;
        cout << texto; // Imprime en consola
        crearReporte(nombreReporte, "", texto); // Escribe en el archivo
    }
    else
        cout << "No hay productos mas buscados.\n" << endl;
}

void ListaDCMarcaProductos::reporteMarcaMasBuscada(ListaSimplePasillos& listaPasillos,
	ListaDobleProductosPasillo& listaProductosPasillo)
{
    string nombreReporte = "Marca(s) mas buscada(s)";
    string texto = "";

    pnodoMarcaProducto temp = primero;
    int maxBusquedas = 0;

    // Encuentra el número máximo de búsquedas
    do
	{
        if (temp->contBusquedas > maxBusquedas)
            maxBusquedas = temp->contBusquedas;

        temp = temp->siguiente;
    } while (temp != primero);

    temp = primero;

    // Agrega al texto las marcas más buscadas
    do
	{
        if (temp->contBusquedas == maxBusquedas)
		{
            texto += "Pasillo: " + intAString(temp->codPasillo) + "; " +
					listaPasillos.buscarPasillo(temp->codPasillo)->getNombre() +
            		"\nProducto: " + intAString(temp->codProducto) + "; " +
					listaProductosPasillo.buscarProducto(temp->codProducto)->getNombre() +
                    "\nMarca: " + intAString(temp->codMarca) + "; " + temp->nombre +
                    "\nCantidad de busquedas: " + intAString(temp->contBusquedas) +
					"\n--------------------------\n";
        }

        temp = temp->siguiente;
    } while (temp != primero);

    if (maxBusquedas > 0)
	{
        cout << "Reporte: " << nombreReporte << endl << endl;
        cout << texto; // Imprime en consola
        crearReporte(nombreReporte, "", texto); // Escribe en el archivo
    }
	else if (temp->contBusquedas == 0)
        cout << "No hay marca mas buscadas.\n" << endl;
}



void menuCliente()
{
    cout << "************MENU************" << endl;
    cout << "1. Buscar" << endl;
    cout << "2. Algunos reportes" << endl;
    cout << "3. Salir" << endl;
}

void menuAdiministrador()
{
	cout << "************MENU************" << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Modificar" << endl;
    cout << "5. Listar" << endl;
    cout << "6. Reportes" << endl;
    cout << "7. Salir" << endl;
}


void menuInsertar(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos, ListaDobleInventarios& listaInventarios,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************INSERTAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
			{
                int codPasillo;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
		    	cout << "Ingrese el nombre del pasillo: ";
				cin.ignore();
				getline(cin, nombre);
                
				listaPasillos.insertarPasillo(codPasillo, nombre); 
				break;
			}

            case 2:
            {
                int codPasillo, codProducto;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
                cout << "Ingrese el codigo del producto: ";
				cin >> codProducto;
                cout << "Ingrese el nombre del producto: ";
				cin.ignore();
				getline(cin, nombre);
                
				listaProductosPasillo.insertarProducto(codPasillo, codProducto, nombre, listaPasillos); 
				break;
			}

            case 3:
            {
                int codPasillo, codProducto, codMarca, cantGondola, precio;
                string nombre;
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
                cout << "Ingrese el codigo del producto: ";
				cin >> codProducto;
                cout << "Ingrese el codigo de la marca: ";
				cin >> codMarca;
                cout << "Ingrese el nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese la cantidad en gondola: ";
				cin >> cantGondola;
                cout << "Ingrese el precio del producto: ";
				cin >> precio;
                
				listaMarcaProductos.insertarMarcaProducto(codPasillo, codProducto, codMarca,
					nombre, cantGondola, precio, listaPasillos, listaProductosPasillo); 
				break;
			}

            case 4:
            {
                int codPasillo, codProducto, codMarca, codInventario, cantStock;
                string nombre;
                bool codCanasta;
                
                cout << "Ingrese el codigo del pasillo: ";
				cin >> codPasillo;
                cout << "Ingrese el codigo del producto: ";
				cin >> codProducto;
                cout << "Ingrese el codigo de la marca: ";
				cin >> codMarca;
                cout << "Ingrese el codigo de inventario: ";
				cin >> codInventario;
                cout << "Ingrese el nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese la cantidad de stock: ";
				cin >> cantStock;
                cout << "Ingrese el codigo de canasta: ";
				cin >> codCanasta;
                
				listaInventarios.insertarInventario(codPasillo, codProducto, codMarca,
					codInventario, nombre, cantStock, codCanasta, listaPasillos, listaProductosPasillo,
					listaMarcaProductos); 
				break;
			}

            case 5:
            {
                int cedula, codCiudad;
                string nombre, telefono, correo;

                cout << "Ingrese la cedula del cliente: ";
				cin >> cedula;
                cout << "Ingrese el nombre del cliente: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el codigo de la ciudad: ";
				cin >> codCiudad;
                cout << "Ingrese el telefono del cliente: ";
				cin >> telefono;
                cout << "Ingrese el correo del cliente: ";
				cin >> correo;

				if (!listaCiudades.ciudadRepetida(codCiudad))
				{
					cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
					break;
				}            		

				hashClientes.insertarCliente(cedula, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 6:
            {
                int cedula, codCiudad;
                string nombre, telefono, correo;

				cout << "Ingrese la cedula del administrador: ";
				cin >> cedula;
                cout << "Ingrese el nombre del administrador: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el codigo de la ciudad: ";
				cin >> codCiudad;
                cout << "Ingrese el telefono del administrador: ";
				cin >> telefono;
                cout << "Ingrese el correo del administrador: ";
				cin >> correo;

				if (!listaCiudades.ciudadRepetida(codCiudad))
				{
					cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
					break;
				}

				hashAdmins.insertarAdmin(cedula, nombre, codCiudad, telefono, correo);
                break;
            }
            
            case 7:
            {
                int codCiudad;
                string nombre;
                
                cout << "Ingrese el codigo de la ciudad: ";
				cin >> codCiudad;
                cout << "Ingrese el nombre de la ciudad: ";
				cin.ignore();
				getline(cin, nombre);
                
				listaCiudades.insertarCiudad(codCiudad, nombre); 
				break;
			}
            
            case 8:
				system("cls");
				break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuEliminar(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos, ListaDobleInventarios& listaInventarios,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************ELIMINAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
            	int codPasilloAEliminar;
				
				cout << "Ingrese el codigo del pasillo a eliminar: ";
				cin >> codPasilloAEliminar;
				
				pnodoPasillo pasilloEncontrado = listaPasillos.buscarPasillo(codPasilloAEliminar);
				
                if (pasilloEncontrado != NULL)
                {
					listaPasillos.eliminarPasillo(codPasilloAEliminar);
					listaProductosPasillo.eliminarProductosPasillo(codPasilloAEliminar);
				}
				else
    				cout << "\nNo se encontro el pasillo con el codigo dado.\n" << endl;
                break;
            }

            case 2:
            {
            	int codProductoAEliminar;
				
                cout << "Ingrese el codigo del producto a eliminar: ";
				cin >> codProductoAEliminar;
                
                pnodoProductoPasillo productoEncontrado = listaProductosPasillo.buscarProducto(codProductoAEliminar);
                
                if (productoEncontrado != NULL)
					listaProductosPasillo.eliminarProducto(codProductoAEliminar);
				else
    				cout << "\nNo se encontro el producto con el codigo dado.\n" << endl;
                break;
			}

            case 3:
            {
				listaMarcaProductos.eliminarMarcasProductos();
                break;
			}

            case 4:
            {
            	int codInventarioAEliminar;

				cout << "Ingrese el codigo del inventario a eliminar: ";
				cin >> codInventarioAEliminar;
				
				pnodoInventario inventarioEncontrado = listaInventarios.buscarInventario(codInventarioAEliminar);
                
                if (inventarioEncontrado != NULL)
					listaInventarios.eliminarInventario(codInventarioAEliminar, listaPasillos);
				else
    				cout << "\nNo se encontro el producto con el codigo de inventario dado.\n" << endl;
                break;
			}

            case 5:
            {
                int cedulaAEliminar;
                
				cout << "Ingrese la cedula del cliente a eliminar: ";
				cin >> cedulaAEliminar;

				pnodoCliente clienteEncontrado = hashClientes.buscarCliente(cedulaAEliminar);

				if (clienteEncontrado != NULL)
				{
					hashClientes.eliminarCliente(cedulaAEliminar);
					cout << "\nCliente eliminado existosamente.\n" << endl;
				}
				else
					cout << "\nCliente no encontrado.\n" << endl;
                break;
            }

            case 6:
        	{
                int cedulaAEliminar;
                
				cout << "Ingrese la cedula del administrador a eliminar: ";
				cin >> cedulaAEliminar;
                
				pnodoAdmin adminEncontrado = hashAdmins.buscarAdmin(cedulaAEliminar);

				if (adminEncontrado != NULL)
				{
					hashAdmins.eliminarAdmin(cedulaAEliminar);
					cout << "\nAdministrador eliminado existosamente.\n" << endl;
				}
				else
					cout << "\nAdministrador no encontrado.\n" << endl;
                break;
            }

            case 7:
            {
            	int codCiudadAEliminar;

				cout << "Ingrese el codigo de la ciudad a eliminar: ";
				cin >> codCiudadAEliminar;

                pnodoCiudad ciudadEncontrada = listaCiudades.buscarCiudad(codCiudadAEliminar);

                if (ciudadEncontrada != NULL)
					listaCiudades.eliminarCiudad(codCiudadAEliminar, hashClientes, hashAdmins);
				else
    				cout << "\nNo se encontro la ciudad con el codigo dado.\n" << endl;
                break;
			}

            case 8:
				system("cls");
				break;

            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuBuscarClientes(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos)
{
	do
    {
        cout << "************BUSCAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
            	int codPasilloABuscar;
                
				cout << "Ingrese el codigo del pasillo a buscar: ";
				cin >> codPasilloABuscar;
                
				pnodoPasillo pasilloBuscado = listaPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
				{
                    cout << "\nPasillo encontrado:" << endl;
                    cout << "CodPasillo: " << pasilloBuscado->getCodPasillo() << endl;
                    cout << "Nombre: " << pasilloBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codPasilloABuscar << " no encontrado.\n" << endl;
                break;
			}
			
            case 2:
            {
            	int codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProductoPasillo productoBuscado = listaProductosPasillo.buscarProducto(codProductoABuscar);
				
                if (productoBuscado != NULL)
				{
                    cout << "\nProducto encontrado:" << endl;
                    cout << "CodPasillo: " << productoBuscado->getCodPasillo() << endl;
                    cout << "CodProducto: " << productoBuscado->getCodProducto() << endl;
                    cout << "Nombre: " << productoBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codProductoABuscar << " no encontrado.\n" << endl;
                break;
			}

            case 3:
            {
            	int codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: ";
				cin >> codMarcaABuscar;
                
				pnodoMarcaProducto marcaBuscada = listaMarcaProductos.buscarMarcaProducto(codMarcaABuscar);
				
                if (marcaBuscada != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "CodPasillo: " << marcaBuscada->getCodPasillo() << endl;
		            cout << "CodProducto: " << marcaBuscada->getCodProducto() << endl;
		            cout << "CodMarca: " << marcaBuscada->getCodMarca() << endl;
		            cout << "Nombre: " << marcaBuscada->getNombre() << endl;
		            cout << "CantGondola: " << marcaBuscada->getCantGondola() << endl;
		            cout << "Precio: " << marcaBuscada->getPrecio() << endl << endl;
                }
				else
                    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada.\n" << endl;
                break;
			}

            case 4:
				system("cls");
				break;

            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 4);
}

void menuBuscarAdmins(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos, ListaDobleInventarios& listaInventarios,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************BUSCAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
            	int codPasilloABuscar;
                
				cout << "Ingrese el codigo del pasillo a buscar: ";
				cin >> codPasilloABuscar;
                
				pnodoPasillo pasilloBuscado = listaPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
				{
                    cout << "\nPasillo encontrado:" << endl;
                    cout << "CodPasillo: " << pasilloBuscado->getCodPasillo() << endl;
                    cout << "Nombre: " << pasilloBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codPasilloABuscar << " no encontrado.\n" << endl;
                break;
			}
			
            case 2:
            {
            	int codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProductoPasillo productoBuscado = listaProductosPasillo.buscarProducto(codProductoABuscar);
				
                if (productoBuscado != NULL)
				{
                    cout << "\nProducto encontrado:" << endl;
                    cout << "CodPasillo: " << productoBuscado->getCodPasillo() << endl;
                    cout << "CodProducto: " << productoBuscado->getCodProducto() << endl;
                    cout << "Nombre: " << productoBuscado->getNombre() << endl << endl;
                }
				else
                    cout << "\nPasillo con codigo " << codProductoABuscar << " no encontrado.\n" << endl;
                break;
			}

            case 3:
            {
            	int codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: ";
				cin >> codMarcaABuscar;
                
				pnodoMarcaProducto marcaBuscada = listaMarcaProductos.buscarMarcaProducto(codMarcaABuscar);
				
                if (marcaBuscada != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "CodPasillo: " << marcaBuscada->getCodPasillo() << endl;
		            cout << "CodProducto: " << marcaBuscada->getCodProducto() << endl;
		            cout << "CodMarca: " << marcaBuscada->getCodMarca() << endl;
		            cout << "Nombre: " << marcaBuscada->getNombre() << endl;
		            cout << "CantGondola: " << marcaBuscada->getCantGondola() << endl;
		            cout << "Precio: " << marcaBuscada->getPrecio() << endl << endl;
                }
				else
                    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada.\n" << endl;
                break;
			}

            case 4:
            {
            	int codInventarioABuscar;
                
				cout << "Ingrese el codigo del inventario a buscar: ";
				cin >> codInventarioABuscar;
                
				pnodoInventario inventarioBuscado = listaInventarios.buscarInventario(codInventarioABuscar);
				
                if (inventarioBuscado != NULL)
				{
					cout << "\nMarca encontrada:" << endl;
                    cout << "CodPasillo: " << inventarioBuscado->getCodPasillo() << endl;
		            cout << "CodProducto: " << inventarioBuscado->getCodProducto() << endl;
		            cout << "CodMarca: " << inventarioBuscado->getCodMarca() << endl;
		            cout << "CodInventario: " << inventarioBuscado->getCodInventario() << endl;
		            cout << "Nombre: " << inventarioBuscado->getNombre() << endl;
		            cout << "CantStock: " << inventarioBuscado->getCantStock() << endl;
		            cout << "CodCanasta: " << inventarioBuscado->getCodCanasta() << endl << endl;
                }
				else
                    cout << "\nInventario con codigo " << codInventarioABuscar << " no encontrado.\n" << endl;
                break;
			}
            
            case 5:
            {
	            int cedulaABuscar;
	            
				cout << "Ingrese la cedula del cliente a buscar: ";
				cin >> cedulaABuscar;
	            
				pnodoCliente clienteBuscado = hashClientes.buscarCliente(cedulaABuscar);
				
	            if (clienteBuscado != NULL)
				{
	                cout << "\nCliente encontrado:" << endl;
	                cout << hashClientes.funcionHash(cedulaABuscar) << " -> Cedula: "
						<< clienteBuscado->getCedula() << endl;
	                cout << "     Nombre: " << clienteBuscado->getNombre() << endl;
	                cout << "     Ciudad: " << clienteBuscado->getCodCiudad() << endl;
	                cout << "     Telefono: " << clienteBuscado->getTelefono() << endl;
	                cout << "     Correo: " << clienteBuscado->getCorreo() << endl << endl;
	            }
				else
	                cout << "\nCliente con cedula " << cedulaABuscar << " no encontrado.\n" << endl;
	            break;
	        }
            
            case 6:
            {
                int cedulaABuscar;
                
				cout << "Ingrese la cedula del administrador a buscar: ";
				cin >> cedulaABuscar;
                
				pnodoAdmin adminBuscado = hashAdmins.buscarAdmin(cedulaABuscar);
				
                if (adminBuscado != NULL)
				{
                    cout << "\nAdministrador encontrado:" << endl;
                    cout << hashAdmins.funcionHash(cedulaABuscar) << " -> Cedula: "
						<< adminBuscado->getCedula() << endl;
                    cout << "     Nombre: " << adminBuscado->getNombre() << endl;
                    cout << "     Ciudad: " << adminBuscado->getCodCiudad() << endl;
                    cout << "     Telefono: " << adminBuscado->getTelefono() << endl;
                    cout << "     Correo: " << adminBuscado->getCorreo() << endl << endl;
                }
				else
                    cout << "\nAdministrador con cedula " << cedulaABuscar << " no encontrado.\n" << endl;
                break;
            }
            
            case 7:
            {
            	int codCiudadABuscar;
                
				cout << "Ingrese el codigo de la ciudad a buscar: ";
				cin >> codCiudadABuscar;
                
				pnodoCiudad ciudadBuscada = listaCiudades.buscarCiudad(codCiudadABuscar);
				
                if (ciudadBuscada != NULL)
				{
                    cout << "\nCiudad encontrada:" << endl;
                    cout << "CodCiudad: " << ciudadBuscada->getCodCiudad() << endl;
                    cout << "Nombre: " << ciudadBuscada->getNombre() << endl << endl;
                }
				else
                    cout << "\nCiudad con codigo " << codCiudadABuscar << " no encontrada.\n" << endl;
                break;
			}
            
            case 8:
				system("cls");
				break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuModificar(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos, ListaDobleInventarios& listaInventarios,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************MODIFICAR:************" << endl;
	    cout << "1. Pasillo" << endl;
	    cout << "2. Producto" << endl;
	    cout << "3. Marca" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Cliente" << endl;
	    cout << "6. Administrador" << endl;
	    cout << "7. Ciudad" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
            	int codPasillo;
				string nombre;

				cout << "Ingrese el codigo de pasillo a modificar: ";
				cin >> codPasillo;
		    	cout << "Ingrese el nuevo nombre del pasillo: ";
				cin.ignore();
				getline(cin, nombre);

				listaPasillos.modificarPasillo(codPasillo, nombre);
				break;
			}

            case 2:
            {
            	int codProducto;
				string nombre;
				
				cout << "Ingrese el codigo del producto a modificar: ";
				cin >> codProducto;
		    	cout << "Ingrese el nuevo nombre del producto: ";
				cin.ignore();
				getline(cin, nombre);
            	
            	listaProductosPasillo.modificarProducto(codProducto, nombre);
                break;
            }

            case 3:
            {
            	int codMarca, cantGondola, precio;
				string nombre;
				
				cout << "Ingrese el codigo de la marca a modificar: ";
				cin >> codMarca;
				cout << "Ingrese el nuevo nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
		        cout << "Ingrese la nueva cantidad de producto en la gondola: ";
				cin >> cantGondola;
		    	cout << "Ingrese el nuevo precio del producto: ";
				cin >> precio;

            	listaMarcaProductos.modificarMarcaProducto(codMarca, nombre, cantGondola, precio);
                break;
            }

            case 4:
            {
            	int codInventario, cantStock;
				string nombre;
				bool codCanasta;
			
				cout << "Ingrese el codigo del inventario a modificar: ";
				cin >> codInventario;
		        cout << "Ingrese el nuevo nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
		        cout << "Ingrese la nueva cantidad de stock: ";
				cin >> cantStock;
		        cout << "Ingrese el codigo de canasta basica: ";
				cin >> codCanasta;

            	listaInventarios.modificarInventario(codInventario, nombre, cantStock, codCanasta);
                break;
            }

            case 5:
            {
                int cedulaAModificar, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del cliente a modificar: ";
				cin >> cedulaAModificar;
                cout << "Ingrese el nuevo nombre del cliente: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el nuevo codigo de la ciudad del cliente: ";
				cin >> codCiudad;
                cout << "Ingrese el nuevo telefono del cliente: ";
				cin >> telefono;
                cout << "Ingrese el nuevo correo del cliente: ";
				cin >> correo;
				
				pnodoCliente clienteEncontrado = hashClientes.buscarCliente(cedulaAModificar);

			    if (clienteEncontrado == NULL)
			    {
			        cout << "\nCliente no encontrado.\n" << endl;
			        break;
			    }
				
				if (!listaCiudades.ciudadRepetida(codCiudad))
				{
					cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
					break;
				}
                
                hashClientes.modificarCliente(cedulaAModificar, nombre,	codCiudad, telefono,
					correo, clienteEncontrado);
                break;
            }
            
            case 6:
            {
                int cedulaAModificar, codCiudad;
                string nombre, telefono, correo;
                
                cout << "Ingrese la cedula del administrador a modificar: ";
				cin >> cedulaAModificar;
                cout << "Ingrese el nuevo nombre del administrador: ";
				cin.ignore();
				getline(cin, nombre);
                cout << "Ingrese el nuevo codigo de la ciudad del administrador: ";
				cin >> codCiudad;
                cout << "Ingrese el nuevo telefono del administrador: ";
				cin >> telefono;
                cout << "Ingrese el nuevo correo del administrador: ";
				cin >> correo;
				
				pnodoAdmin adminEncontrado = hashAdmins.buscarAdmin(cedulaAModificar);

			    if (adminEncontrado == NULL)
			    {
			        cout << "\nAdministrador no encontrado.\n" << endl;
			        break;
			    }
				
				if (!listaCiudades.ciudadRepetida(codCiudad))
				{
					cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
					break;
				}
                
                hashAdmins.modificarAdmin(cedulaAModificar, nombre, codCiudad, telefono,
					correo, adminEncontrado);
                break;
            }
            
            case 7:
            {
            	int codCiudad;
				string nombre;
				
				cout << "Ingrese el codigo de la ciudad a modificar: ";
				cin >> codCiudad;
				cout << "Ingrese el nuevo nombre de la ciudad: ";
		    	cin.ignore();
		    	getline(cin, nombre);

            	listaCiudades.modificarCiudad(codCiudad, nombre);
                break;
            }
            
            case 8:
				system("cls");
				break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuListar(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos, ListaDobleInventarios& listaInventarios,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************LISTAR:************" << endl;
	    cout << "1. Pasillos" << endl;
	    cout << "2. Productos" << endl;
	    cout << "3. Marcas" << endl;
	    cout << "4. Inventario" << endl;
	    cout << "5. Clientes" << endl;
	    cout << "6. Administradores" << endl;
	    cout << "7. Ciudades" << endl;
	    cout << "8. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
            	system("cls");
            	cout << "Pasillos:\n" << endl;
                listaPasillos.Mostrar();
                break;

            case 2:
            	system("cls");
            	cout << "Productos:\n" << endl;
                listaProductosPasillo.Mostrar();
                break;

            case 3:
            	system("cls");
            	cout << "Marcas de Productos:\n" << endl;
                listaMarcaProductos.Mostrar();
                break;

            case 4:
            	system("cls");
            	cout << "Inventario:\n" << endl;
                listaInventarios.Mostrar();
                break;
            
            case 5:
            	system("cls");
            	cout << "Clientes:\n\n" << hashClientes.mostrarHash();
                break;
            
            case 6:
            	system("cls");
            	cout << "Administradores:\n\n" << hashAdmins.mostrarHash();
                break;
            
            case 7:
            	system("cls");
            	cout << "Ciudades:\n" << endl;
                listaCiudades.Mostrar();
                break;
            
            case 8:
				system("cls");
				break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuReportesClientes(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos)
{
	do
    {
        cout << "************REPORTES:************" << endl;
	    cout << "1. Pasillos" << endl;
	    cout << "2. Productos" << endl;
	    cout << "3. Marcas" << endl;
	    cout << "4. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
				system("cls");
				listaPasillos.reportePasillos();
				break;

            case 2:
				system("cls");
				listaProductosPasillo.reporteProductosPasillo();
				break;

            case 3:
				system("cls");
            	listaMarcaProductos.reporteMarcaProductos();
				break;

            case 4:
				system("cls");
				break;

            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 4);
}

void menuReportesAdmins(int opcion, ListaSimplePasillos& listaPasillos, ListaDobleProductosPasillo& listaProductosPasillo,
	ListaDCMarcaProductos& listaMarcaProductos, ListaDobleInventarios& listaInventarios,
	HashingClientes& hashClientes, HashingAdmins& hashAdmins, ListaCircularCiudades& listaCiudades)
{
	do
    {
        cout << "************REPORTES:************" << endl;
	    cout << "1. Pasillos" << endl;
	    cout << "2. Productos" << endl;
	    cout << "3. Marcas" << endl;
	    cout << "4. Clientes" << endl;
	    cout << "5. Administradores" << endl;
	    cout << "6. Ciudades" << endl;
	    cout << "7. Pasillo mas visitado" << endl;
	    cout << "8. Pasillo menos visitado" << endl;
	    cout << "9. Producto mas buscado" << endl;
	    cout << "10. Marcas mas buscadas" << endl;
	    cout << "11. Volver" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
				system("cls");
				listaPasillos.reportePasillos();
				break;

            case 2:
				system("cls");
				listaProductosPasillo.reporteProductosPasillo();
				break;

            case 3:
				system("cls");
            	listaMarcaProductos.reporteMarcaProductos();
				break;

            case 4:
				system("cls");
            	hashClientes.reporteClientes();
				break;
            
            case 5:
				system("cls");
            	hashAdmins.reporteAdmins();
				break;
            
            case 6:
				system("cls");
            	listaCiudades.reporteCiudades();
				break;
			
			case 7:
				system("cls");
            	listaPasillos.reportePasilloMasVisitado();
				break;
				
			case 8:
				system("cls");
            	listaPasillos.reportePasilloMenosVisitado();
				break;
				
			case 9:
				system("cls");
				listaProductosPasillo.reporteProductoMasBuscado(listaPasillos);
				break;
			
			case 10:
				system("cls");
				listaMarcaProductos.reporteMarcaMasBuscada(listaPasillos, listaProductosPasillo);
				break;
            
            case 11:
				system("cls");
				break;
            
            default:
				system("cls");
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 11);
}



int main()
{
    ListaSimplePasillos listaPasillos;
    ListaDobleProductosPasillo listaProductosPasillo;
    ListaDCMarcaProductos listaMarcaProductos;
    ListaDobleInventarios listaInventarios;
    ListaCircularCiudades listaCiudades;

    crearListaPasillos(listaPasillos);
    crearListaProductosPasillo(listaProductosPasillo, listaPasillos);
    crearListaMarcaProductos(listaMarcaProductos, listaPasillos, listaProductosPasillo);
    crearListaInventarios(listaInventarios, listaPasillos, listaProductosPasillo, listaMarcaProductos);
    crearListaCiudades(listaCiudades);
    
    HashingClientes hashClientes(13);
    crearHashingClientes(hashClientes, listaCiudades);
    HashingAdmins hashAdmins(13);
    crearHashingAdmins(hashAdmins, listaCiudades);
    
    int cedula, opcion, opcion2, opcion3;
    
    bool salirPrograma = false;
    bool credencialesValidas = false;
    
    do
    {
    	system("cls");
        cout << "************BIENVENID(@)************\n" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Salir del programa" << endl;
		cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
		{
            case 1: // Loguearse
            {
                credencialesValidas = false;

				do
				{
					cout << "\nIngrese su numero de cedula para ingresar." << endl;
			        cout << "Ingrese su cedula: ";
					cin >> cedula;

                    if (hashClientes.loginCliente(cedula))
                    {
				    	system("cls");
						cout << "Bienvenid(@) estimad(@) cliente, "
							<< hashClientes.buscarCliente(cedula)->getNombre() << endl << endl;
					    credencialesValidas = true;

				        do
						{
					        menuCliente();
					        cout << "\nIngrese la opcion deseada: ";
							cin >> opcion2;
					
					        switch (opcion2)
							{
								case 1: // Buscar
									system("cls");
					        		menuBuscarClientes(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos);
					            	break;
					
					            case 2: // Algunos reportes
					            	system("cls");
					                menuReportesClientes(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos);
					            	break;
					
					            case 3: // Salir
									break;

					            default:
					            	system("cls");
									cout << "Ingrese una opcion valida.\n" << endl;
							}
					    } while (opcion2 != 3);
					    
					    credencialesValidas = true;
                    }
                    else if (hashAdmins.loginAdmin(cedula))
				    {
				    	system("cls");
				    	cout << "Bienvenid(@), administrador(@) "
							<< hashAdmins.buscarAdmin(cedula)->getNombre() << endl << endl;
					    credencialesValidas = true;

				        do
						{
					        menuAdiministrador();
					        cout << "\nIngrese la opcion deseada: ";
							cin >> opcion2;
					
					        switch (opcion2)
							{
								case 1: // Insertar
					        		system("cls");
					                menuInsertar(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos, listaInventarios, hashClientes,
										hashAdmins, listaCiudades);
					                break;
					
					            case 2: // Eliminar
					            	system("cls");
					                menuEliminar(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos, listaInventarios, hashClientes,
										hashAdmins, listaCiudades);
					                break;
					
					            case 3: // Buscar
					            	system("cls");
					                menuBuscarAdmins(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos, listaInventarios, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 4: // Modificar
					            	system("cls");
					                menuModificar(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos, listaInventarios, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 5: // Listar
					            	system("cls");
					                menuListar(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos, listaInventarios, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 6: // Reportes
					            	system("cls");
					                menuReportesAdmins(opcion3, listaPasillos, listaProductosPasillo,
										listaMarcaProductos, listaInventarios, hashClientes,
										hashAdmins, listaCiudades);
					            	break;
					
					            case 7: // Salir
									break;
					
					            default:
					            	system("cls");
									cout << "Ingrese una opcion valida.\n" << endl;
							}
					    } while (opcion2 != 7);
					}
					else
						cout << "\nNombre de usuario o cedula incorrectos. Intente nuevamente." << endl;
			    } while (!credencialesValidas); break;
			}
			
            case 2: // Salir del programa
                cout << "Saliendo del programa..." << endl;
                salirPrograma = true;
                break;

            default:
                cout << "Ingrese una opción válida.\n" << endl;
                break;
        }
	} while (!salirPrograma);

    return 0;
}

