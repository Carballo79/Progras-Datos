// Estudiantes: José Carballo Martínez

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Define un comando para limpiar/borrar la terminal
#ifdef _WIN32 // Si se compila en Windows
    #define LIMPIAR "cls"
#else // Si se compila en Linux
    #define LIMPIAR "clear"
#endif

using namespace std;


class NodoABBPasillo
{
public:
    NodoABBPasillo() {}

    NodoABBPasillo(string _codPasillo, string _nombre) :
        codPasillo(_codPasillo), nombre(_nombre), contVisitas(0), Hizq(NULL),
		Hder(NULL), siguiente(NULL) {}

    void InsertaBinario(string codPasillo, string nombre);

    string getCodPasillo() const { return codPasillo; }
	string getNombre() { return nombre; }

private:
    string codPasillo, nombre;
    int contVisitas;
    NodoABBPasillo* Hizq, * Hder, * siguiente;
    
    friend class ArbolBBPasillos;
};

typedef NodoABBPasillo* pnodoPasillo;
typedef NodoABBPasillo* pnodoABBPasillo;


class NodoAVLProducto
{
public:
    NodoAVLProducto(string _codPasillo, string _codProducto, string _nombre) :
        codPasillo(_codPasillo), codProducto(_codProducto), nombre(_nombre),
        contBusquedas(0), FB(0), Hizq(NULL), Hder(NULL), siguiente(NULL) {}

    string getCodPasillo() const { return codPasillo; }
    string getCodProducto() const { return codProducto; }
	string getNombre() { return nombre; }

private:
    string codPasillo, codProducto, nombre;
    int contBusquedas, FB;
    NodoAVLProducto* Hizq, * Hder, * siguiente;
    
    friend class ArbolAVLProductos;
};

typedef NodoAVLProducto* pnodoProducto;
typedef NodoAVLProducto* pnodoAVLProducto;


class NodoARNMarca
{
public:
    NodoARNMarca(string _codPasillo, string _codProducto, string _codMarca,
            string _nombre, string _cantGondola, string _precio, NodoARNMarca* _padre) :
        codPasillo(_codPasillo), codProducto(_codProducto), codMarca(_codMarca),
        nombre(_nombre), cantGondola(_cantGondola), precio(_precio), padre(_padre),
        Hizq(NULL), Hder(NULL), siguiente(NULL), color(1) {}

    string getCodPasillo() const { return codPasillo; }
    string getCodProducto() const { return codProducto; }
    string getCodMarca() const { return codMarca; }
    string getNombre() { return nombre; }
    string getCantGondola() const { return cantGondola; }
    string getPrecio() const { return precio; }

private:
    string codPasillo, codProducto, codMarca, nombre, cantGondola, precio;
    NodoARNMarca* padre, * Hizq, * Hder, * siguiente;
    int color;

    friend class ArbolRNMarcas;
};

typedef NodoARNMarca* pnodoMarca;
typedef NodoARNMarca* pnodoARNMarca;


class NodoAAInventario
{
public:
    NodoAAInventario(string _codPasillo, string _codProducto, string _codMarca, string _codInventario,
            string _nombre, string _cantStock, string _codCanasta) :
        codPasillo(_codPasillo), codProducto(_codProducto), codMarca(_codMarca),
        codInventario(_codInventario), nombre(_nombre), cantStock(_cantStock),
        codCanasta(_codCanasta), nivel(1), Hizq(NULL), Hder(NULL), siguiente(NULL) {}

    string getCodPasillo() const { return codPasillo; }
    string getCodProducto() const { return codProducto; }
    string getCodMarca() const { return codMarca; }
    string getCodInventario() const { return codInventario; }
    string getNombre() { return nombre; }
    string getCantStock() const { return cantStock; }
    string getCodCanasta() const { return codCanasta; }

private:
    string codPasillo, codProducto, codMarca, codInventario, nombre, cantStock, codCanasta;
    int nivel;
    NodoAAInventario* Hizq, * Hder, * siguiente;

    friend class ArbolAAInventarios;
};

typedef NodoAAInventario* pnodoInventario;
typedef NodoAAInventario* pnodoAAInventario;


class NodoABUsuario
{
public:
    NodoABUsuario(string valor) : esHoja(true) { valores.push_back(valor); }

    vector<string> getValores() { return valores; }
    vector<NodoABUsuario*> getHijo() { return hijos; }
    bool getEsHoja() { return esHoja; }

private:
    vector<string> valores;
    vector<NodoABUsuario*> hijos;
    bool esHoja;

    friend class ArbolBUsuarios;
};


class NodoABBCiudad
{
public:
    NodoABBCiudad() {}

    NodoABBCiudad(string _codCiudad, string _nombre, NodoABBCiudad* _Hizq = NULL,
            NodoABBCiudad* _Hder = NULL, NodoABBCiudad* _siguiente = NULL,
            NodoABBCiudad* _anterior = NULL):
        codCiudad(_codCiudad), nombre(_nombre), Hizq(_Hizq), Hder(_Hder),
        siguiente(_siguiente), anterior(_anterior) {}

    void InsertaBinario(string codCiudad, string nombre);

    string getCodCiudad() const { return codCiudad; }
	string getNombre() { return nombre; }

private:
    string codCiudad, nombre;
    NodoABBCiudad* Hizq, * Hder, * siguiente, * anterior;
    
    friend class ArbolBBCiudades;
};

typedef NodoABBCiudad* pnodoCiudad;
typedef NodoABBCiudad* pnodoABBCiudad;



static int stringAInt(string str)
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

static string intAString(int num)
{
    ostringstream convertir;

    convertir << num;

    return convertir.str();
}

// Función que convierte "1" o "0" a booleano
static bool stringABool(string str)
{
    istringstream iss(str);
    bool res = false;

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


static void crearReporte(string nombreReporte, string distintivo, string texto)
{
	ofstream archivoNuevo;
	
	string titulo = "Reporte-" + nombreReporte + distintivo + ".txt";
	
	archivoNuevo.open(titulo.c_str(), ios::out);
	
	// Comprueba si el archivo se abró correctamente
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



class ArbolBBPasillos
{
public:
    ArbolBBPasillos(): raiz(NULL) {}
    ~ArbolBBPasillos();

    bool ArbolVacio() const { return raiz == NULL; }
    void insertarPasillo(string codPasillo, string nombre);
    bool pasilloRepetido(string codPasillo) const { return buscarPasillo(codPasillo) != NULL; }
    pnodoABBPasillo buscarPasillo(string codPasillo) const;
    void modificarPasillo(string codPasillo, string nombre) const;
    void mostrarPasillos(pnodoABBPasillo raiz, int count);
    void reportePasillos() const;
    void reportePasilloMasVisitado() const;
    void reportePasilloMenosVisitado() const;

    pnodoABBPasillo getRaiz() const { return raiz; }

private:
    pnodoABBPasillo raiz;
};

ArbolBBPasillos::~ArbolBBPasillos()
{
    pnodoPasillo act;

    while (raiz)
    {
        act = raiz;
        raiz = raiz->siguiente;
        delete act;
    }

    raiz = NULL;
}

void NodoABBPasillo::InsertaBinario(string llave, string nombre)
{
    if (llave < codPasillo)
    {
        if (Hizq == NULL)
        {
            Hizq = new NodoABBPasillo(llave, nombre);
            cout << "\nPasillo insertado exitosamente." << endl;
            cout << "\nPasillo nuevo:\n" << llave << "; " << nombre << endl << endl;
        }
        else
            Hizq->InsertaBinario(llave, nombre);
    }
    else
    {
        if (Hder == NULL)
        {
            Hder = new NodoABBPasillo(llave, nombre);
            cout << "\nPasillo insertado exitosamente." << endl;
            cout << "\nPasillo nuevo:\n" << llave << "; " << nombre << endl << endl;
        }
        else
            Hder->InsertaBinario(llave, nombre);
    }
}

void ArbolBBPasillos::insertarPasillo(string llave, string nombre)
{
    if (raiz == NULL)
    {
        raiz = new NodoABBPasillo(llave, nombre);
        cout << "\nPasillo insertado exitosamente." << endl;
        cout << "\nPasillo nuevo:\n" << llave << "; " << nombre << endl << endl;
    }
    else
        raiz->InsertaBinario(llave, nombre);
}

pnodoABBPasillo ArbolBBPasillos::buscarPasillo(string codPasillo) const
{
    if (ArbolVacio())
    {
        cout << "\nEl arbol de pasillos esta vacio.\n" << endl;
        return NULL;
    }

    pnodoABBPasillo act = raiz;

    while (act != NULL)
    {
        if (codPasillo == act->getCodPasillo())
            return act;
        else if (codPasillo < act->getCodPasillo())
            act = act->Hizq;
        else
            act = act->Hder;
    }

    return NULL;
}

void ArbolBBPasillos::modificarPasillo(string codPasillo, string nombre) const
{
	pnodoABBPasillo pasillo = buscarPasillo(codPasillo);
	
	if (pasillo != NULL)
    {
        pasillo->codPasillo = codPasillo;
        pasillo->nombre = nombre;

        cout << "\nPasillo modificado exitosamente.\n" << endl;
        cout << "\nPasillo modificado:\n" << codPasillo << "; " << nombre << endl << endl;
    }
    else
		cout << "\nEl pasillo no existe en el arbol.\n";
}

void ArbolBBPasillos::mostrarPasillos(pnodoABBPasillo raiz, int cont)
{
    if (raiz != NULL)
    {
        mostrarPasillos(raiz->Hder, cont + 1);

        for (int i = 0; i < cont; i++)
            cout << "   ";

        cout << raiz->codPasillo << "; " << raiz->nombre << endl << endl;

        mostrarPasillos(raiz->Hizq, cont + 1);
    }
}

void ArbolBBPasillos::reportePasillos() const
{
    string nombreReporte = "Pasillos";
    string texto = "";

    // Itera sobre la lista de pasillos y guarda en el archivo
    pnodoPasillo temp = raiz;

	while (temp != NULL)
	{
        texto += "-> " + temp->codPasillo + "; " + temp->nombre + "\n\n";

        temp = temp->siguiente;
    }

    if (!ArbolVacio())
    {
	    cout << "Reporte: " << nombreReporte << endl << endl;
	    cout << texto; // Imprime en consola
	    crearReporte(nombreReporte, "", texto); // Escribe en el archivo
	}
	else
		cout << "No hay pasillos registrados.\n" << endl;
}

void ArbolBBPasillos::reportePasilloMasVisitado() const
{
    string nombreReporte = "Pasillo(s) mas visitado(s)";
    string texto = "";

    pnodoPasillo temp = raiz;
    int maxVisitas = 0;

    // Encuentra el número máximo de visitas
    while (temp != NULL)
	{
        if (temp->contVisitas > maxVisitas)
            maxVisitas = temp->contVisitas;

        temp = temp->siguiente;
    }

    temp = raiz;

    // Agrega al texto los pasillos mï¿½s visitados
    while (temp != NULL)
	{
        if (temp->contVisitas == maxVisitas)
		{
            texto += "CodPasillo: " + temp->codPasillo +
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

void ArbolBBPasillos::reportePasilloMenosVisitado() const
{
    string nombreReporte = "Pasillo(s) menos visitado(s)";
    string texto = "";

    pnodoPasillo temp = raiz;
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

    temp = raiz;

	// Agrega al texto los pasillos menos visitados
    while (temp != NULL)
	{
        if (temp->contVisitas == minVisitas)
		{
            texto += "CodPasillo: " + temp->codPasillo +
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


class ArbolAVLProductos
{
public:
    ArbolAVLProductos() { raiz = NULL; }
    ~ArbolAVLProductos();

    bool ArbolVacio() const { return raiz == NULL; }
    void Equilibrar1(pnodoAVLProducto n, bool Hh);
    void Equilibrar2(pnodoAVLProducto n, bool Hh);
    void insertarProducto(string codPasillo, string llave, string nombre);
    void InsertarBalanceado(pnodoAVLProducto& ra, bool Hh, string codPasillo,
        string codProducto, string nombre);
    bool productoRepetido(string codProducto) const { return buscarProducto(codProducto) != NULL; }
    pnodoProducto buscarProducto(string codProducto) const;
    void modificarProducto(string codProducto, string nombre) const;
    void reporteProductosPasillo() const;
    void reporteProductoMasBuscado(ArbolBBPasillos& arbolPasillos) const;
    void mostrarProductos(pnodoAVLProducto raiz, int cont);
    void RotacionDobleIzquierda(pnodoAVLProducto n1, pnodoAVLProducto n2);
    void RotacionDobleDerecha(pnodoAVLProducto n1, pnodoAVLProducto n2);
    void RotacionSimpleIzquierda(pnodoAVLProducto n1, pnodoAVLProducto n2);
    void RotacionSimpleDerecha(pnodoAVLProducto n1, pnodoAVLProducto n2);

    pnodoProducto getRaiz() const { return raiz; }
    bool getHh() const { return Hh; }

private:
    pnodoProducto raiz;
    bool Hh;
};

ArbolAVLProductos::~ArbolAVLProductos()
{
    pnodoProducto aux;

    while (raiz)
    {
        aux = raiz;
        raiz = raiz->siguiente;
        delete aux;
    }

    raiz = NULL;
}

void ArbolAVLProductos::Equilibrar1(pnodoAVLProducto n, bool Hh)
{
    pnodoAVLProducto n1;

    switch (n->FB)
    {
        case -1:
            n->FB = 0;
            break;

        case 0:
            n->FB = 1;
            Hh = false;
            break;

        case 1:
            n1 = n->Hder;

            if (n1->FB >= 0)
            {
                if (n1->FB == 0)
                {
                    Hh = false;
                    RotacionSimpleDerecha(n, n1);
                }
                else
                    RotacionDobleDerecha(n, n1);
            }
    }
}

void ArbolAVLProductos::Equilibrar2(pnodoAVLProducto n, bool Hh)
{
    pnodoAVLProducto n1;

    switch (n->FB)
    {
        case 1:
            n->FB = 0;
            break;

        case 0:
            n->FB = 1;
            Hh = false;
            break;

        case -1:
            n1 = n->Hizq;

            if (n1->FB <= 0)
            {
                if (n1->FB == 0)
                {
                    Hh = false;
                    RotacionSimpleIzquierda(n, n1);
                }
                else
                    RotacionDobleIzquierda(n, n1);
            }
    }
}

void ArbolAVLProductos::insertarProducto(string codPasillo, string llave, string nombre)
{
    InsertarBalanceado(raiz, false, codPasillo, llave, nombre);
}

void ArbolAVLProductos::InsertarBalanceado(pnodoAVLProducto& ra, bool Hh, string codPasillo,
	string llave, string nombre)
{
	if (ra == NULL)
	{
        ra = new NodoAVLProducto(codPasillo, llave, nombre);
        Hh = true;
        
        cout << "\nProducto insertado exitosamente." << endl;
        cout << "\nProducto nuevo:\n" << codPasillo << "; " << llave << "; "
			<< nombre << endl << endl;
    }
	else
	{
		if (llave < ra->codProducto)
		{
	        InsertarBalanceado(ra->Hizq, Hh, codPasillo, llave, nombre);
	        
	        if (Hh) // Hubo crecimiento en la altura del subárbol izquierdo
				Equilibrar2(ra, Hh);
	    }
	    else if (llave > ra->codProducto)
		{
	        InsertarBalanceado(ra->Hder, Hh, codPasillo, llave, nombre);
	        
	        if (Hh) // Hubo crecimiento en la altura del subárbol derecho
				Equilibrar1(ra, Hh);
	    }
	    else
        	Hh = false; // La altura no cambió
	}
}

pnodoAVLProducto ArbolAVLProductos::buscarProducto(string codProducto) const
{
    if (ArbolVacio())
	{
        cout << "\nEl arbol de productos esta vacio.\n" << endl;
        return NULL;
    }

    pnodoAVLProducto act = raiz;

    while (act != NULL)
    {
        if (codProducto == act->codProducto)
            return act;
        else if (codProducto < act->codProducto)
            act = act->Hizq;
        else
            act = act->Hder;
    }

    return NULL; // Producto no encontrado
}

void ArbolAVLProductos::modificarProducto(string codProducto, string nombre) const
{
    pnodoAVLProducto productoPasillo = buscarProducto(codProducto);

    if (productoPasillo == NULL)
    {
        cout << "El producto a modificar no existe en el arbol." << endl;
        return;
    }

    productoPasillo->codProducto = codProducto;
    productoPasillo->nombre = nombre;

    cout << "\nProducto modificado exitosamente." << endl;
    cout << "\nProducto modificado:\n" << codProducto << "; " << nombre << endl << endl;
}

void ArbolAVLProductos::mostrarProductos(pnodoAVLProducto raiz, int cont)
{
    if (raiz != NULL)
    {
        mostrarProductos(raiz->Hder, cont + 1);

        for (int i = 0; i < cont; i++)
            cout << "   ";

        cout << raiz->codPasillo << "; " << raiz->codProducto << "; "
			<< raiz->nombre << endl << endl;

        mostrarProductos(raiz->Hizq, cont + 1);
    }
}

void ArbolAVLProductos::reporteProductosPasillo() const
{
    string codigoPasillo;
    cout << "Ingrese el codigo del pasillo: ";
    cin >> codigoPasillo;

	string nombreReporte = "Productos de Pasillo";
    string texto = "";

    pnodoAVLProducto temp = raiz;
    bool productoEncontrado = false;

    while (temp != NULL)
    {
        if (temp->codPasillo == codigoPasillo)
        {
            productoEncontrado = true;

            texto += "-> " + temp->codPasillo + "; " +
					temp->codProducto + "; " + temp->nombre + "\n\n";
        }

        temp = temp->siguiente;
    }

    if (productoEncontrado)
    {
        cout << "\nReporte: " << nombreReporte << endl << endl;
        cout << texto; // Muestra en consola
        crearReporte(nombreReporte, ("-" + codigoPasillo), texto); // Escribe en el archivo
    }
    else
        cout << "\nNo se encontraron productos en el pasillo.\n" << endl;
}

void ArbolAVLProductos::reporteProductoMasBuscado(ArbolBBPasillos& arbolPasillos) const
{
    string nombreReporte = "Producto(s) mas buscado(s)";
    string texto = "";

    pnodoAVLProducto temp = raiz;
    int maxBusquedas = 0;

    // Encuentra el número máximo de búsquedas
    while (temp != NULL)
	{
        if (temp->contBusquedas > maxBusquedas)
            maxBusquedas = temp->contBusquedas;

        temp = temp->siguiente;
    }

    temp = raiz;

	// Agrega al texto los productos más buscados
    while (temp != NULL)
	{
        if (temp->contBusquedas == maxBusquedas)
		{
            texto += "Pasillo: " + temp->codPasillo + "; " +
					arbolPasillos.buscarPasillo(temp->codPasillo)->getNombre() +
            		"\nProducto: " + temp->codProducto + "; " + temp->nombre +
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

void ArbolAVLProductos::RotacionDobleIzquierda(pnodoAVLProducto n, pnodoAVLProducto n1)
{
    pnodoAVLProducto n2;

    n2 = n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder = n;
    n1->Hder = n2->Hizq;
    n2->Hizq = n1;

    if (n2->FB == 1)
        n1->FB = -1;
    else
        n1->FB = 0;
    
    if (n2->FB == -1)
        n->FB = 1;
    else
        n->FB=0;

    n2->FB = 0;
    n = n2;
}

void ArbolAVLProductos::RotacionDobleDerecha(pnodoAVLProducto n, pnodoAVLProducto n1)
{
    pnodoAVLProducto n2;

    n2 = n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq = n;
    n1->Hizq = n2->Hder;
    n2->Hder = n1;

    if (n2->FB == 1)
        n->FB = -1;
    else
        n->FB = 0;

    if (n2->FB == -1)
        n1->FB = 1;
    else
        n1->FB = 0;

    n2->FB = 0;
    n = n2;
}

void ArbolAVLProductos::RotacionSimpleDerecha(pnodoAVLProducto n, pnodoAVLProducto n1)
{
    n->Hder = n1->Hizq;
    n1->Hizq = n;

    if (n1->FB == 1)
    {
        n->FB = 0;
        n1->FB = 0;
    }
    else
    {
        n->FB = 1;
        n1->FB = -1;
    }

    n = n1;
}

void ArbolAVLProductos::RotacionSimpleIzquierda(pnodoAVLProducto n, pnodoAVLProducto n1)
{
    n->Hizq = n1->Hder;
    n1->Hder = n;

    if (n1->FB == -1)
    {
        n->FB = 0;
        n1->FB = 0;
    }
    else
    {
        n->FB = -1;
        n1->FB = -1;
    }

    n = n1;
}


class ArbolRNMarcas
{
public:
    ArbolRNMarcas() { raiz = NULL; }
    ~ArbolRNMarcas();

    bool ArbolVacio() const { return raiz == NULL; }
    void insertarMarca(string codPasillo, string codProducto, string codMarca,
        string nombre, string cantGondola, string precio);
    void InsertarBalanceado(pnodoMarca NodoEva);
    bool marcaRepetida(string codMarca) { return buscarMarca(raiz, codMarca) != NULL; }
    pnodoARNMarca buscarMarca(pnodoARNMarca marca, string codMarca);
    void modificarMarca(string codMarca, string nombre, string cantGondola, string precio);
    void mostrarMarcas(pnodoARNMarca raiz, int cont);
    void RotacionIzquierda(pnodoARNMarca nodo);
    void RotacionDerecha(pnodoARNMarca nodo);

    pnodoMarca getRaiz() const { return raiz; }

private:
    pnodoMarca raiz;
};

ArbolRNMarcas::~ArbolRNMarcas()
{
    pnodoMarca aux;

    while (raiz)
    {
        aux = raiz;
        raiz = raiz->siguiente;
        delete aux;
    }

    raiz = NULL;
}

void ArbolRNMarcas::insertarMarca(string codPasillo, string codProducto, string llave,
    string nombre, string cantGondola, string precio)
{
    pnodoMarca nuevo = new NodoARNMarca(codPasillo, codProducto, llave,
        nombre, cantGondola, precio, NULL);

    if (raiz == NULL)
    {
        raiz = nuevo;
        raiz->color = 0; // Color negro para la raíz

        cout << "\nMarca insertada exitosamente." << endl;
        cout << "\nMarca insertada:\n" << codPasillo << "; " << codProducto << "; "
            << llave << "; " << nombre << "; " << cantGondola << "; "
            << precio << endl << endl;
    }
    else
    {
        pnodoMarca padre = NULL;
        pnodoMarca actual = raiz;

        while (actual != NULL)
        {
            padre = actual;

            if (nuevo->getCodMarca() < actual->getCodMarca())
                actual = actual->Hizq;

            else if (nuevo->getCodMarca() > actual->getCodMarca())
                actual = actual->Hder;

            else
            {
                // Si la marca ya existe, no hacemos nada
                delete nuevo;
                return;
            }
        }

        nuevo->padre = padre;

        if (nuevo->getCodMarca() < padre->getCodMarca())
            padre->Hizq = nuevo;

        else
            padre->Hder = nuevo;


        // Insertar balanceado
        InsertarBalanceado(nuevo);

        cout << "\nMarca insertada exitosamente." << endl;
        cout << "\nMarca insertada:\n" << codPasillo << "; " << codProducto << "; "
            << llave << "; " << nombre << "; " << cantGondola << "; "
            << precio << endl << endl;
    }
}

void ArbolRNMarcas::InsertarBalanceado(pnodoMarca marca)
{
    while (marca->padre != NULL && marca->padre->color == 1)
    {
        if (marca->padre == marca->padre->padre->Hizq)
        {
            pnodoMarca uValor = marca->padre->padre->Hder;

            if (uValor != NULL && uValor->color == 1)
            {
                uValor->color = 0;
                marca->padre->color = 0;
                marca->padre->padre->color = 1;
                marca = marca->padre->padre;
            }
            else
            {
                if (marca == marca->padre->Hder)
                {
                    marca = marca->padre;
                    RotacionIzquierda(marca);
                }

                marca->padre->color = 0;
                marca->padre->padre->color = 1;
                RotacionDerecha(marca->padre->padre);
            }
        }
        else
        {
            pnodoMarca uValor = marca->padre->padre->Hizq;

            if (uValor != NULL && uValor->color == 1)
            {
                uValor->color = 0;
                marca->padre->color = 0;
                marca->padre->padre->color = 1;
                marca = marca->padre->padre;
            }
            else
            {
                if (marca == marca->padre->Hizq)
                {
                    marca = marca->padre;
                    RotacionDerecha(marca);
                }

                marca->padre->color = 0;
                marca->padre->padre->color = 1;
                RotacionIzquierda(marca->padre->padre);
            }
        }
    }

    raiz->color = 0;
}

pnodoARNMarca ArbolRNMarcas::buscarMarca(pnodoARNMarca marca, string codMarca)
{
    if (ArbolVacio())
    {
        cout << "\nEl arbol de marcas esta vacio.\n" << endl;
        return NULL;
    }

    if (marca == NULL || codMarca == marca->codMarca)
        return marca;

    if (codMarca < marca->codMarca)
        return buscarMarca(marca->Hizq, codMarca);
    
    return buscarMarca(marca->Hder, codMarca);
}

void ArbolRNMarcas::modificarMarca(string codMarca, string nombre, string cantGondola, string precio)
{
    pnodoMarca marca = buscarMarca(raiz, codMarca);

    if (marca == NULL)
    {
        cout << "\nMarca de producto no encontrada.\n" << endl;
        return;
    }

    marca->codMarca = codMarca;
    marca->nombre = nombre;
    marca->cantGondola = cantGondola;
    marca->precio = precio;

    cout << "\nMarca modificada exitosamente." << endl;
    cout << "\nMarca modificada:\n" << codMarca << "; " << nombre << "; " << cantGondola << "; "
        << precio << endl << endl;
}

void ArbolRNMarcas::RotacionIzquierda(pnodoARNMarca nodo)
{
    pnodoARNMarca y = nodo->Hder;
    nodo->Hder = y->Hizq;
    
    if (y->Hizq != NULL)
        y->Hizq->padre = nodo;
    
    y->padre = nodo->padre;
    
    if (nodo->padre == NULL)
        this->raiz = y;
    else if (nodo == nodo->padre->Hizq)
        nodo->padre->Hizq = y;
    else
        nodo->padre->Hder = y;
    
    y->Hizq = nodo;
    nodo->padre = y;
}

void ArbolRNMarcas::RotacionDerecha(pnodoARNMarca nodo)
{
    pnodoARNMarca y = nodo->Hizq;
    nodo->Hizq = y->Hder;

    if (y->Hder != NULL)
        y->Hder->padre = nodo;
    
    y->padre = nodo->padre;

    if (nodo->padre == NULL)
        this->raiz = y;
    else if (nodo == nodo->padre->Hder)
        nodo->padre->Hder = y;
    else
        nodo->padre->Hizq = y;

    y->Hder = nodo;
    nodo->padre = y;
}

void ArbolRNMarcas::mostrarMarcas(pnodoARNMarca raiz, int cont)
{
    if (raiz != NULL)
    {
        string sColor = raiz->color ? "Rojo" : "Negro";

        mostrarMarcas(raiz->Hder, cont + 1);

        for (int i = 0; i < cont; i++)
            cout << "     ";

        cout << raiz->codPasillo << "; " << raiz->codProducto << "; " << raiz->codMarca << "; "
            << raiz->nombre << "; " << raiz->cantGondola << "; " << raiz->precio
            << " (" << sColor << ")" << endl << endl;

        mostrarMarcas(raiz->Hizq, cont + 1);
    }
}


class ArbolAAInventarios
{
public:
    ArbolAAInventarios() { raiz = NULL; }
    ~ArbolAAInventarios();

    bool ArbolVacio() const { return raiz == NULL; }
    pnodoAAInventario insertHelper(pnodoAAInventario nodo, string codPasillo, string codProducto,
        string codMarca, string codInventario, string nombre, string cantStock, string codCanasta);
    void insertarInventario(string codPasillo, string codProducto, string codMarca, string codInventario,
        string nombre, string cantStock, string codCanasta);
    bool inventarioRepetido(string codInventario) const { return buscarInventario(codInventario) != NULL; }
    bool productoRepetidoEnInventario(string codProducto);
    bool marcaRepetidaEnInventario(string codMarca);
    pnodoAAInventario buscarInventario(string codInventario) const;
    void modificarInventario(string codInventario, string nombre, string cantStock, string codCanasta) const;
    void mostrarInventarios(pnodoAAInventario raiz, int cont);
    pnodoAAInventario skew(pnodoAAInventario x);
    pnodoAAInventario split(pnodoAAInventario x);

    pnodoInventario getRaiz() const { return raiz; }

private:
    pnodoInventario raiz;
};

ArbolAAInventarios::~ArbolAAInventarios()
{
    pnodoInventario aux;

    while (raiz)
    {
        aux = raiz;
        raiz = raiz->siguiente;
        delete aux;
    }

    raiz = NULL;
}

pnodoAAInventario ArbolAAInventarios::skew(pnodoAAInventario x)
{
    // cout << "Rotacion derecha" << endl;

    if (x == NULL || x->Hizq == NULL)
        return x;

    if (x->Hizq->nivel == x->nivel)
    {
        pnodoAAInventario izq = x->Hizq;
        x->Hizq = izq->Hder;
        izq->Hder = x;

        return izq;
    }

    return x;
}

pnodoAAInventario ArbolAAInventarios::split(pnodoAAInventario x)
{
    // cout << "Rotacion izquierda" << endl;

    if (x == NULL || x->Hder == NULL || x->Hder->Hder == NULL)
        return x;

    if (x->nivel == x->Hder->Hder->nivel)
    {
        pnodoAAInventario der = x->Hder;
        x->Hder = der->Hizq;
        der->Hizq = x;
        der->nivel++;

        return der;
    }

    return x;
}

pnodoAAInventario ArbolAAInventarios::insertHelper(pnodoAAInventario nodo, string codPasillo,
    string codProducto, string codMarca, string llave, string nombre, string cantStock, string codCanasta)
{
    if (nodo == NULL)
    {
        nodo = new NodoAAInventario(codPasillo, codProducto, codMarca, llave, nombre,
            cantStock, codCanasta);
        cout << "\nInventario insertado exitosamente." << endl;
        cout << "\nInventario nuevo:\n" << codPasillo << "; " << codProducto << "; "
            << codMarca << "; " << llave << "; " << nombre << "; " << cantStock << "; "
            << codCanasta << endl << endl;
    }
    else if (llave < nodo->codInventario)
        nodo->Hizq = insertHelper(nodo->Hizq, codPasillo, codProducto, codMarca, llave, nombre,
            cantStock, codCanasta);
    else if (llave > nodo->codInventario)
        nodo->Hder = insertHelper(nodo->Hder, codPasillo, codProducto, codMarca, llave, nombre,
            cantStock, codCanasta);

    nodo = skew(nodo);
    nodo = split(nodo);

    return nodo;
}

void ArbolAAInventarios::insertarInventario(string codPasillo, string codProducto, string codMarca,
    string codInventario, string nombre, string cantStock, string codCanasta)
{
    raiz = insertHelper(raiz, codPasillo, codProducto, codMarca, codInventario, nombre,
        cantStock, codCanasta);
}

pnodoAAInventario ArbolAAInventarios::buscarInventario(string codInventario) const
{
    if (ArbolVacio())
    {
        cout << "\nEl arbol de inventarios esta vacia.\n" << endl;
        return NULL;
    }

    pnodoAAInventario act = raiz;

    while (act != NULL)
    {
        if (codInventario < act->codInventario)
            act = act->Hizq;
        else if (codInventario > act->codInventario)
            act = act->Hder;
        else
            return act;
    }

    return NULL; // No se encontró el inventario en el árbol
}

void ArbolAAInventarios::modificarInventario(string codInventario, string nombre,
    string cantStock, string codCanasta) const
{
    pnodoInventario inventario = buscarInventario(codInventario);

    if (inventario == NULL)
    {
        cout << "\nInventario no encontrado en el arbol.\n" << endl;
        return;
    }

    inventario->codInventario = codInventario;
    inventario->nombre = nombre;
    inventario->cantStock = cantStock;
    inventario->codCanasta = codCanasta;

    cout << "\nInventario modificado exitosamente." << endl;
    cout << "\nInventario modificado:\n" << codInventario << "; " << nombre << "; "
        << cantStock << "; " << codCanasta << endl << endl;
}

void ArbolAAInventarios::mostrarInventarios(pnodoAAInventario arbol, int cont)
{
    if (arbol != NULL)
    {
        mostrarInventarios(arbol->Hder, cont + 1);

        for (int i = 0; i < cont; i++)
            cout << "     ";

        /*cout << arbol->codPasillo << "; " << arbol->codProducto << "; " << arbol->codMarca << "; "
            << arbol->codInventario << "; " << arbol->nombre << "; " << arbol->cantStock << "; "
            << arbol->codCanasta << endl << endl;*/

        cout << arbol->codInventario << endl << endl;

        mostrarInventarios(arbol->Hizq, cont + 1);
    }
}


class ArbolBUsuarios
{
public:
    ArbolBUsuarios(int grado) : grado(grado), raiz(NULL) {}

    void insertarUsuario(string valor);
    bool buscarUsuario(string valor) { return buscarNodo(raiz, valor); }
    void mostrarUsuarios();
    bool loginUsuario(string cedula);

    NodoABUsuario* insertarNodo(NodoABUsuario* nodo, string valor);
    NodoABUsuario* dividirNodo(NodoABUsuario* nodo);
    bool buscarNodo(NodoABUsuario* nodo, string valor);
    int buscarConsultarIndice(NodoABUsuario* nodo, string valor);
    NodoABUsuario* buscarConsultar(NodoABUsuario* nodo, string valor);
    void mostrarNodo(NodoABUsuario* nodo);

    NodoABUsuario* getRaiz() { return raiz; }

private:
    NodoABUsuario* raiz;
    int grado;
};

void ArbolBUsuarios::insertarUsuario(string valor)
{
    if (raiz == NULL)
        raiz = new NodoABUsuario(valor);
    else
    {
        NodoABUsuario* nodo = insertarNodo(raiz, valor);

        if (nodo != NULL)
        {
            NodoABUsuario* antiguaRaiz = raiz;
            raiz = new NodoABUsuario("");
            raiz->valores.push_back(nodo->valores[0]);
            raiz->hijos.push_back(antiguaRaiz);
            raiz->hijos.push_back(nodo);
            raiz->esHoja = false;
        }
    }
}

void ArbolBUsuarios::mostrarUsuarios()
{
    mostrarNodo(raiz);
    cout << endl;
}

bool ArbolBUsuarios::loginUsuario(string cedula)
{
    NodoABUsuario* usuario = buscarConsultar(raiz, cedula);

    if (usuario != NULL)
    {
        for (string dato : usuario->valores)
        {
            int pos = dato.find(";");
            string codigo = dato.substr(0, pos);

            if (codigo == cedula)
                return true; // Usuario encontrado
        }
    }

    return false; // Usuario no encontrado
}

NodoABUsuario* ArbolBUsuarios::insertarNodo(NodoABUsuario* nodo, string valor)
{
    int i = 0;

    while (i < nodo->valores.size() && stringAInt(valor) > stringAInt(nodo->valores[i]))
        i++;

    if (nodo->esHoja)
    {
        nodo->valores.insert(nodo->valores.begin() + i, valor);

        if (nodo->valores.size() >= grado - 1)
            return dividirNodo(nodo);
        else
            return NULL;
    }
    else
    {
        NodoABUsuario* nuevoNodo = insertarNodo(nodo->hijos[i], valor);

        if (nuevoNodo != NULL)
        {
            nodo->valores.insert(nodo->valores.begin() + i, nuevoNodo->valores[0]);
            nodo->hijos.insert(nodo->hijos.begin() + i + 1, nuevoNodo);

            if (nodo->valores.size() >= grado - 1)
                return dividirNodo(nodo);
        }

        return NULL;
    }
}

NodoABUsuario* ArbolBUsuarios::dividirNodo(NodoABUsuario* nodo)
{
    int mid = (nodo->valores.size() + 1) / 2;
    NodoABUsuario* nuevoNodo = new NodoABUsuario(nodo->valores[mid]);
    nuevoNodo->esHoja = nodo->esHoja;

    nodo->valores.erase(nodo->valores.begin() + mid, nodo->valores.end());

    if (!nodo->esHoja)
    {
        nuevoNodo->hijos.assign(nodo->hijos.begin() + mid + 1, nodo->hijos.end());
        nodo->hijos.erase(nodo->hijos.begin() + mid, nodo->hijos.end());
    }

    return nuevoNodo;
}

bool ArbolBUsuarios::buscarNodo(NodoABUsuario* nodo, string valor)
{
    if (nodo == NULL)
        return false;

    for (int i = 0; i < nodo->valores.size(); i++)
    {
        int pos = nodo->valores[i].find(";");
        string codigo = nodo->valores[i].substr(0, pos);

        if (codigo == valor)
            return true;
        else if (valor < codigo)
        {
            if (i < nodo->hijos.size())
                return buscarNodo(nodo->hijos[i], valor);

            return false;
        }
    }

    if (!nodo->esHoja && nodo->hijos.size() > nodo->valores.size())
        return buscarNodo(nodo->hijos.back(), valor);

    return false;
}

int ArbolBUsuarios::buscarConsultarIndice(NodoABUsuario* nodo, string valor)
{
    if (nodo == NULL)
        return -1;

    for (int i = 0; i < nodo->valores.size(); i++)
    {
        int pos = nodo->valores[i].find(";");
        string codigo = nodo->valores[i].substr(0, pos);

        if (codigo == valor)
            return i;
        else if (valor < codigo)
        {
            if (i < nodo->hijos.size())
                return buscarNodo(nodo->hijos[i], valor);

            return -1;
        }
    }

    if (!nodo->esHoja && nodo->hijos.size() > nodo->valores.size())
        return buscarNodo(nodo->hijos.back(), valor);

    return -1;
}

NodoABUsuario* ArbolBUsuarios::buscarConsultar(NodoABUsuario* nodo, string valor)
{
    if (nodo == NULL)
        return nodo;

    for (int i = 0; i < nodo->valores.size(); i++)
    {
        int pos = nodo->valores[i].find(";");
        string codigo = nodo->valores[i].substr(0, pos);

        if (codigo == valor)
            return nodo;
        else if (valor < codigo)
        {
            if (i < nodo->hijos.size())
                return buscarConsultar(nodo->hijos[i], valor);

            return nodo;
        }
    }

    if (!nodo->esHoja && nodo->hijos.size() > nodo->valores.size())
        return buscarConsultar(nodo->hijos.back(), valor);

    return nodo;
}

void ArbolBUsuarios::mostrarNodo(NodoABUsuario* nodo)
{
    if (nodo != NULL)
    {
        for (int i = 0; i < nodo->hijos.size(); i++)
        {
            mostrarNodo(nodo->hijos[i]);

            if (i < nodo->valores.size())
                cout << nodo->valores[i] << " ";
        }
    }
}


class ArbolBBCiudades
{
public:
    ArbolBBCiudades(): raiz(NULL) {}
    ~ArbolBBCiudades();

    bool ArbolVacio() const { return raiz == NULL; }
    void insertarCiudad(string codCiudad, string nombre);
    bool ciudadRepetida(string codCiudad) const { return buscarCiudad(codCiudad) != NULL; }
    pnodoABBCiudad buscarCiudad(string codCiudad) const;
    void modificarCiudad(string codCiudad, string nombre) const;
    void mostrarCiudades(pnodoABBCiudad, int);

    pnodoABBCiudad getRaiz() const { return raiz; }

private:
    pnodoABBCiudad raiz;
};

ArbolBBCiudades::~ArbolBBCiudades()
{
    pnodoCiudad act;

    while (raiz)
    {
        act = raiz;
        raiz = raiz->siguiente;
        delete act;
    }

    raiz = NULL;
}

void NodoABBCiudad::InsertaBinario(string llave, string nombre)
{
    if (llave < codCiudad)
    {
        if (Hizq == NULL)
        {
            Hizq = new NodoABBCiudad(llave, nombre);
            cout << "\nCiudad insertada exitosamente." << endl;
            cout << "\nCiudad nueva:\n" << llave << "; " << nombre << endl << endl;
        }
        else
            Hizq->InsertaBinario(llave, nombre);
    }
    else if (llave > codCiudad)
    {
        if (Hder == NULL)
        {
            Hder = new NodoABBCiudad(llave, nombre);
            cout << "\nCiudad insertada exitosamente." << endl;
            cout << "\nCiudad nueva:\n" << llave << "; " << nombre << endl << endl;
        }
        else
            Hder->InsertaBinario(llave, nombre);
    }
    else
        cout << "\nLa ciudad ya existe en el arbol.\n" << endl;
}

void ArbolBBCiudades::insertarCiudad(string llave, string nombre)
{
    if (raiz == NULL)
    {
        raiz = new NodoABBCiudad(llave, nombre);
        cout << "\nCiudad insertada exitosamente." << endl;
        cout << "\nCiudad nueva:\n" << llave << "; " << nombre << endl << endl;
    }
    else
        raiz->InsertaBinario(llave, nombre);
}

pnodoABBCiudad ArbolBBCiudades::buscarCiudad(string codCiudad) const
{
    if (ArbolVacio())
    {
        cout << "\nEl arbol de pasillos esta vacio.\n" << endl;
        return NULL;
    }

    pnodoABBCiudad act = raiz;

    while (act != NULL)
    {
        if (codCiudad == act->codCiudad)
            return act;
        else if (codCiudad < act->codCiudad)
            act = act->Hizq;
        else
            act = act->Hder;
    }

    return NULL;
}

void ArbolBBCiudades::modificarCiudad(string codCiudad, string nombre) const
{
	pnodoABBCiudad ciudad = buscarCiudad(codCiudad);
	
	if (ciudad != NULL)
    {
        ciudad->codCiudad = codCiudad;
        ciudad->nombre = nombre;

        cout << "\nCiudad modificada exitosamente." << endl;
        cout << "\nCiudad modificada:\n" << codCiudad << "; " << nombre << endl << endl;
    }
    else
		cout << "\nCiudad no encontrada.\n";
}

void ArbolBBCiudades::mostrarCiudades(pnodoABBCiudad arbol, int cont)
{
    if (arbol != NULL)
    {
        mostrarCiudades(arbol->Hder, cont + 1);

        for (int i = 0; i < cont; i++)
            cout << "   ";

        cout << arbol->codCiudad << "; " << arbol->nombre << endl << endl;

        mostrarCiudades(arbol->Hizq, cont + 1);
    }
}



static void crearArbolPasillos(ArbolBBPasillos& arbolPasillos)
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

        getline(ss, codPasillo, ';');
        ss >> ws;
        getline(ss, nombre, ';');
        ss >> ws;

        if (arbolPasillos.buscarPasillo(codPasillo) == NULL)
            // Inserta en el árbol de pasillos después de las validaciones
            arbolPasillos.insertarPasillo(codPasillo, nombre);
        else
            cout << "\nEl pasillo ya existe en el arbol.\n" << endl;
    }

    archivo.close();
}

static void crearArbolProductos(ArbolAVLProductos& arbolProductos, ArbolBBPasillos& arbolPasillos)
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
        
        getline(ss, codPasillo, ';');
        ss >> ws;
        getline(ss, codProducto, ';');
        ss >> ws;
        getline(ss, nombre, ';');
        ss >> ws;
        
        if (arbolPasillos.buscarPasillo(codPasillo) != NULL
                || arbolProductos.buscarProducto(codProducto) == NULL)
            // Inserta en el árbol AVL después de las validaciones
            arbolProductos.insertarProducto(codPasillo, codProducto, nombre);
        else
            cout << "\nEl pasillo no existe o el producto ya existe en el arbol.\n" << endl;
    }

    archivo.close();
}

void crearArbolMarcas(ArbolRNMarcas& arbolMarcas, ArbolBBPasillos& arbolPasillos,
    ArbolAVLProductos& arbolProductos)
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

        if (arbolPasillos.buscarPasillo(codPasillo) != NULL
                || arbolProductos.buscarProducto(codProducto) != NULL
                || arbolMarcas.buscarMarca(arbolMarcas.getRaiz(), codMarca) == NULL)
            // Inserta en el árbol RN de marcas después de las validaciones
            arbolMarcas.insertarMarca(codPasillo, codProducto, codMarca, nombre, cantGondola, precio);
        else
            cout << "\nEl pasillo o el producto no existen o la marca ya existe.\n" << endl;
    }

    archivo.close();
}

static void crearArbolInventarios(ArbolAAInventarios& arbolInventarios, ArbolBBPasillos& arbolPasillos,
    ArbolAVLProductos& arbolProductos, ArbolRNMarcas& arbolMarcas)
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

        if (arbolPasillos.buscarPasillo(codPasillo) != NULL
            || arbolProductos.buscarProducto(codProducto) != NULL
            || arbolMarcas.buscarMarca(arbolMarcas.getRaiz(), codMarca) != NULL
            || arbolInventarios.buscarInventario(codInventario) == NULL)
            // Inserta en el árbol AA de inventarios después de las validaciones
            arbolInventarios.insertarInventario(codPasillo, codProducto, codMarca, codInventario,
                nombre, cantStock, codCanasta);
        else
            cout << "\nEl pasillo o el producto o la marca no existen o el inventario ya existe.\n" << endl;
    }

    archivo.close();
}

static void crearArbolClientes(ArbolBUsuarios& arbolClientes, ArbolBBCiudades& arbolCiudades)
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

        getline(ss, cedula, ';');
        ss >> ws;
        getline(ss, nombre, ';');
        ss >> ws;
        getline(ss, codCiudad, ';');
        ss >> ws;
        getline(ss, telefono, ';');
        ss >> ws;
        getline(ss, correo, ';');
        ss >> ws;

        string cliente = cedula + "; " + nombre + "; " + codCiudad + "; " + telefono + "; " + correo;

        if (arbolCiudades.ciudadRepetida(codCiudad))
        {
			// Inserta en el árbol B de clientes después de las validaciones
            arbolClientes.insertarUsuario(cliente);

            cout << "\nCliente insertado exitosamente." << endl;
            cout << "\nCliente insertado:\n" << cliente << endl << endl;
        }
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}

static void crearArbolAdmins(ArbolBUsuarios& arbolAdmins, ArbolBBCiudades& arbolCiudades)
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
        
        getline(ss, cedula, ';');
        ss >> ws;
        getline(ss, nombre, ';');
        ss >> ws;
        getline(ss, codCiudad, ';');
        ss >> ws;
        getline(ss, telefono, ';');
        ss >> ws;
        getline(ss, correo, ';');
        ss >> ws;

        string admin = cedula + "; " + nombre + "; " + codCiudad + "; " + telefono + "; " + correo;

		if (arbolCiudades.ciudadRepetida(codCiudad))
        {
			// Inserta en el árbol B de administradores después de las validaciones
            arbolAdmins.insertarUsuario(admin);

            cout << "\nAdministrador insertado exitosamente." << endl;
            cout << "\nAdministrador insertado:\n" << admin << endl << endl;
        }
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}

static void crearArbolCiudades(ArbolBBCiudades& arbolCiudades)
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

        istringstream ss(linea);
        string codCiudad, nombre;
        
        getline(ss, codCiudad, ';');
        ss >> ws;
        getline(ss, nombre, ';');
        ss >> ws;

        // Inserta en el árbol de ciudades después de las validaciones
        arbolCiudades.insertarCiudad(codCiudad, nombre);
	}
}



static void menuAdiministrador()
{
	cout << "************MENU************" << endl;
    cout << "1. Mantenimiento de la base de Datos" << endl;
    cout << "2. Facturar" << endl;
    cout << "3. Revisar gondolas" << endl;
    cout << "4. Verificar inventario" << endl;
    cout << "5. Reportes" << endl;
    cout << "6. Salir" << endl;
}

static void menuClienteRegistrado()
{
	cout << "************MENU************" << endl;
    cout << "1. Consultar precio" << endl;
    cout << "2. Consultar descuento" << endl;
    cout << "3. Consultar productos" << endl;
    cout << "4. Comprar" << endl;
    cout << "5. Salir" << endl;
}

static void menuClienteNoRegistrado()
{
	cout << "************MENU************" << endl;
    cout << "1. Consultar precio" << endl;
    cout << "2. Consultar productos" << endl;
    cout << "3. Salir" << endl;
}

static void menuInsertar(int opcion, ArbolBBPasillos& arbolPasillos, ArbolAVLProductos& arbolProductos,
    ArbolRNMarcas& arbolMarcas, ArbolAAInventarios& arbolInventarios, ArbolBUsuarios& arbolClientes,
    ArbolBUsuarios& arbolAdmins, ArbolBBCiudades& arbolCiudades)
{
    string codPasillo, codProducto, codMarca, codInventario, cedula, codCiudad, nombre, cantGondola,
        precio, cantStock, codCanasta, telefono, correo;

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
                cout << "Ingrese el codigo del pasillo: "; cin >> codPasillo;

                if (arbolPasillos.buscarPasillo(codPasillo) == NULL)
                {
                    cout << "Ingrese el nombre del pasillo: "; cin >> nombre;

                    arbolPasillos.insertarPasillo(codPasillo, nombre);
                }
                else
                    cout << "\nEl pasillo ya existe en el arbol.\n" << endl;
				break;
			}

            case 2:
            {
                cout << "Ingrese el codigo del pasillo: ";
                cin >> codPasillo;

                if (arbolPasillos.buscarPasillo(codPasillo) != NULL)
                {
                    cout << "Ingrese el codigo del producto: ";
                    cin >> codProducto;
                    
                    if (arbolProductos.buscarProducto(codProducto) == NULL)
                    {
                        cout << "Ingrese el nombre del producto: "; cin >> nombre;

                        arbolProductos.insertarProducto(codPasillo, codProducto, nombre);
                    }
                    else
                        cout << "\nEl producto ya existe en el arbol.\n" << endl;
                }
                else
                    cout << "\nEl pasillo no existe en el arbol.\n" << endl;
				break;
			}

            case 3:
            {
                cout << "Ingrese el codigo del pasillo: "; cin >> codPasillo;

                if (arbolPasillos.buscarPasillo(codPasillo) != NULL)
                {
                    cout << "Ingrese el codigo del producto: "; cin >> codProducto;

                    if (arbolProductos.buscarProducto(codProducto) != NULL)
                    {
                        cout << "Ingrese el codigo de la marca: "; cin >> codMarca;

                        if (arbolMarcas.buscarMarca(arbolMarcas.getRaiz(), codMarca) == NULL)
                        {
                            cout << "Ingrese el nombre de la marca: "; cin >> nombre;
                            cout << "Ingrese la cantidad en gondola: "; cin >> cantGondola;
                            cout << "Ingrese el precio del producto: "; cin >> precio;

                            arbolMarcas.insertarMarca(codPasillo, codProducto, codMarca,
                                nombre, cantGondola, precio);
                        }
                        else
                            cout << "\nLa marca ya existe en el arbol.\n" << endl;
                    }
                    else
                        cout << "\nEl producto ya existe en el arbol.\n" << endl;
                }
                else
                    cout << "\nEl pasillo no existe en el arbol.\n" << endl;
                break;
			}

            case 4:
            {
                cout << "Ingrese el codigo del pasillo: "; cin >> codPasillo;

                if (arbolPasillos.buscarPasillo(codPasillo) != NULL)
                {
                    cout << "Ingrese el codigo del producto: "; cin >> codProducto;

                    if (arbolProductos.buscarProducto(codProducto) != NULL)
                    {
                        cout << "Ingrese el codigo de la marca: "; cin >> codMarca;

                        if (arbolMarcas.buscarMarca(arbolMarcas.getRaiz(), codMarca) != NULL)
                        {
                            cout << "Ingrese el codigo de inventario: "; cin >> codInventario;

                            if (arbolInventarios.buscarInventario(codInventario) == NULL)
                            {
                                cout << "Ingrese el nombre de la marca: "; cin >> nombre;
                                cout << "Ingrese la cantidad de stock: "; cin >> cantStock;
                                cout << "Ingrese el codigo de canasta: "; cin >> codCanasta;

                                arbolInventarios.insertarInventario(codPasillo, codProducto, codMarca,
                                    codInventario, nombre, cantStock, codCanasta);
                            }
                            else
                                cout << "\nEl inventario ya existe en el arbol.\n" << endl;
                        }
                        else
                            cout << "\nLa marca ya existe en el arbol.\n" << endl;
                    }
                    else
                        cout << "\nEl producto ya existe en el arbol.\n" << endl;
                }
                else
                    cout << "\nEl pasillo no existe en el arbol.\n" << endl;
				break;
			}

            case 5:
            {
                cout << "Ingrese la cedula del cliente: "; cin >> cedula;

                if (!arbolClientes.buscarUsuario(cedula))
                {
                    cout << "Ingrese el nombre del cliente: "; cin >> nombre;
                    cout << "Ingrese el codigo de la ciudad: "; cin >> codCiudad;

                    if (arbolCiudades.buscarCiudad(codCiudad) != NULL)
                    {
                        cout << "Ingrese el telefono del cliente: "; cin >> telefono;
                        cout << "Ingrese el correo del cliente: "; cin >> correo;

                        string cliente = cedula + "; " + nombre + "; " + codCiudad + "; " + telefono + "; " + correo;

                        arbolClientes.insertarUsuario(cliente);

                        cout << "\nCliente insertado exitosamente." << endl;
                        cout << "\nCliente insertado:\n" << cliente << endl;
                    }
                    else
                        cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
                }
                else
                    cout << "\nEl cliente ya esta registrado.\n" << endl;
                break;
            }
            
            case 6:
            {
                cout << "Ingrese la cedula del admininistrador: "; cin >> cedula;

                if (!arbolAdmins.buscarUsuario(cedula))
                {
                    cout << "Ingrese el nombre del admininistrador: "; cin >> nombre;
                    cout << "Ingrese el codigo de la ciudad: "; cin >> codCiudad;

                    if (arbolCiudades.buscarCiudad(codCiudad) != NULL)
                    {
                        cout << "Ingrese el telefono del admininistrador: "; cin >> telefono;
                        cout << "Ingrese el correo del admininistrador: "; cin >> correo;

                        string admin = cedula + "; " + nombre + "; " + codCiudad + "; " + telefono + "; " + correo;

                        arbolAdmins.insertarUsuario(admin);

                        cout << "\nAdministrador insertado exitosamente." << endl;
                        cout << "\nAdministrador insertado:\n" << admin << endl;
                    }
                    else
                        cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
                }
                else
                    cout << "\nEl admininistrador ya esta registrado.\n" << endl;
                break;
            }
            
            case 7:
            {
                cout << "Ingrese el codigo de la ciudad: "; cin >> codCiudad;

                if (!arbolClientes.buscarUsuario(cedula))
                {
                    cout << "Ingrese el nombre de la ciudad: "; cin >> nombre;
                    
                    arbolCiudades.insertarCiudad(codCiudad, nombre); 
                }
                else
                    cout << "\nLa ciudad ya existe en el arbol.\n" << endl;
				break;
			}
            
            case 8:
                system(LIMPIAR);
				break;
            
            default:
                system(LIMPIAR);
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

static void menuBuscarClientes(int opcion, ArbolBBPasillos& arbolPasillos, ArbolAVLProductos& arbolProductos)
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
            	string codPasilloABuscar;
                
				cout << "Ingrese el codigo del pasillo a buscar: ";
				cin >> codPasilloABuscar;
                
				pnodoPasillo pasilloBuscado = arbolPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
				    cout << "\nPasillo encontrado:\n" << pasilloBuscado->getCodPasillo() << "; "
                        << pasilloBuscado->getNombre() << endl << endl;
				else
                    cout << "\nPasillo con codigo " << codPasilloABuscar << " no encontrado.\n" << endl;
                break;
			}
			
            case 2:
            {
            	string codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProducto productoBuscado = arbolProductos.buscarProducto(codProductoABuscar);
				
                if (productoBuscado != NULL)
				    cout << "\nProducto encontrado:\n" << productoBuscado->getCodPasillo() << "; "
                        << productoBuscado->getCodProducto() << "; " << productoBuscado->getNombre() << endl << endl;
				else
                    cout << "\nPasillo con codigo " << codProductoABuscar << " no encontrado.\n" << endl;
                break;
			}

            case 3:
            {
            	int codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: ";
				cin >> codMarcaABuscar;
                
				/*pnodoMarcaProducto marcaBuscada = listaMarcaProductos.buscarMarcaProducto(codMarcaABuscar);
				
                if (marcaBuscada != NULL)
				    cout << "\nMarca encontrada:\n" << marcaBuscada->getCodPasillo() << "; "
                        << marcaBuscada->getCodProducto() << "; " << marcaBuscada->getCodMarca() << "; "
                        << marcaBuscada->getNombre() << "; " << marcaBuscada->getCantGondola() << "; "
                        << marcaBuscada->getPrecio() << endl << endl;
				else
                    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada.\n" << endl;*/
                break;
			}

            case 4:
                system(LIMPIAR);
				break;

            default:
                system(LIMPIAR);
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 4);
}

static void menuBuscarAdmins(int opcion, ArbolBBPasillos& arbolPasillos, ArbolAVLProductos& arbolProductos,
    ArbolRNMarcas& arbolMarcas, ArbolAAInventarios& arbolInventarios, ArbolBUsuarios& arbolClientes,
    ArbolBUsuarios& arbolAdmins, ArbolBBCiudades& arbolCiudades)
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
            	string codPasilloABuscar;
                
				cout << "Ingrese el codigo del pasillo a buscar: ";
				cin >> codPasilloABuscar;
                
				pnodoPasillo pasilloBuscado = arbolPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
                    cout << "\nPasillo encontrado:\n" << pasilloBuscado->getCodPasillo() << "; "
                        << pasilloBuscado->getNombre() << endl << endl;
				else
                    cout << "\nPasillo no encontrado en el arbol.\n" << endl;
                break;
			}
			
            case 2:
            {
            	string codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProducto productoBuscado = arbolProductos.buscarProducto(codProductoABuscar);
				
                if (productoBuscado != NULL)
                    cout << "\nProducto encontrado:\n" << productoBuscado->getCodPasillo() << "; "
                        << productoBuscado->getCodProducto() << "; " << productoBuscado->getNombre() << endl << endl;
				else
                    cout << "\nProducto no encontrado en el arbol.\n" << endl;
                break;
			}

            case 3:
            {
            	string codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: ";
				cin >> codMarcaABuscar;
                
				pnodoMarca marcaBuscada = arbolMarcas.buscarMarca(arbolMarcas.getRaiz(), codMarcaABuscar);
				
                if (marcaBuscada != NULL)
                    cout << "\nMarca encontrada:\n" << marcaBuscada->getCodPasillo() << "; "
                        << marcaBuscada->getCodProducto() << "; " << marcaBuscada->getCodMarca() << "; "
                        << marcaBuscada->getNombre() << "; " << marcaBuscada->getCantGondola() << "; "
                        << marcaBuscada->getPrecio() << endl << endl;
				else
                    cout << "\nMarca no encontrada en el arbol.\n" << endl;
                break;
			}

            case 4:
            {
            	string codInventarioABuscar;
                
				cout << "Ingrese el codigo del inventario a buscar: ";
				cin >> codInventarioABuscar;
                
				pnodoInventario inventarioBuscado = arbolInventarios.buscarInventario(codInventarioABuscar);
				
                if (inventarioBuscado != NULL)
				    cout << "\nInventario encontrado:\n" << inventarioBuscado->getCodPasillo() << "; "
                        << inventarioBuscado->getCodProducto() << "; " << inventarioBuscado->getCodMarca() << "; "
                        << inventarioBuscado->getCodInventario() << "; " << inventarioBuscado->getNombre() << "; "
                        << inventarioBuscado->getCantStock() << "; " << inventarioBuscado->getCodCanasta()
                        << endl << endl;
				else
                    cout << "\nInventario no encontrado en el arbol.\n" << endl;
                break;
			}
            
            case 5:
            {
	            string cedulaABuscar;
	            
				cout << "Ingrese la cedula del cliente a buscar: ";
				cin >> cedulaABuscar;
	            
                bool clienteExiste = arbolClientes.buscarUsuario(cedulaABuscar);

                if (clienteExiste)
                {
                    NodoABUsuario* clienteBuscado = arbolClientes.buscarConsultar(arbolClientes.getRaiz(), cedulaABuscar);
				
                    int i = arbolClientes.buscarConsultarIndice(arbolClientes.getRaiz(), cedulaABuscar);

                    if (clienteBuscado != NULL)
                    {
                        int posPrimero = clienteBuscado->getValores()[i].find(';');
                        int posSegundo = clienteBuscado->getValores()[i].find(';', posPrimero + 1);
                        int posTercero = clienteBuscado->getValores()[i].find(';', posSegundo + 1);
                        int posCuarto = clienteBuscado->getValores()[i].find(';', posTercero + 1);
                        
                        cout << "\nCliente encontrado:\n" << cedulaABuscar << "; "
                            << clienteBuscado->getValores()[i].substr(posPrimero + 1, posSegundo - posPrimero - 1) << "; "
                            << clienteBuscado->getValores()[i].substr(posSegundo + 1, posTercero - posSegundo - 1) << "; "
                            << clienteBuscado->getValores()[i].substr(posTercero + 1, posCuarto - posTercero - 1) << "; "
                            << clienteBuscado->getValores()[i].substr(posCuarto + 1) << endl << endl;
                    }
                    else
                        cout << "\nCliente no encontrado en el arbol.\n";
                }
                break;
	        }
            
            case 6:
            {
                string cedulaABuscar;
	            
				cout << "Ingrese la cedula del administrador a buscar: ";
				cin >> cedulaABuscar;
	            
                bool adminExiste = arbolAdmins.buscarUsuario(cedulaABuscar);

                if (adminExiste)
                {
                    NodoABUsuario* adminBuscado = arbolClientes.buscarConsultar(arbolClientes.getRaiz(), cedulaABuscar);
				
                    int i = arbolAdmins.buscarConsultarIndice(arbolAdmins.getRaiz(), cedulaABuscar);

                    if (adminBuscado != NULL)
                    {
                        int posPrimero = adminBuscado->getValores()[i].find(';');
                        int posSegundo = adminBuscado->getValores()[i].find(';', posPrimero + 1);
                        int posTercero = adminBuscado->getValores()[i].find(';', posSegundo + 1);
                        int posCuarto = adminBuscado->getValores()[i].find(';', posTercero + 1);
                        
                        cout << "\nAdministrador encontrado:\n" << cedulaABuscar << "; "
                            << adminBuscado->getValores()[i].substr(posPrimero + 1, posSegundo - posPrimero - 1) << "; "
                            << adminBuscado->getValores()[i].substr(posSegundo + 1, posTercero - posSegundo - 1) << "; "
                            << adminBuscado->getValores()[i].substr(posTercero + 1, posCuarto - posTercero - 1) << "; "
                            << adminBuscado->getValores()[i].substr(posCuarto + 1) << endl << endl;
                    }
                    else
                        cout << "\nAdministrador no encontrado en el arbol.\n";
                }
                break;
            }
            
            case 7:
            {
            	string codCiudadABuscar;
                
				cout << "Ingrese el codigo de la ciudad a buscar: ";
				cin >> codCiudadABuscar;
                
				pnodoCiudad ciudadBuscada = arbolCiudades.buscarCiudad(codCiudadABuscar);
				
                if (ciudadBuscada != NULL)
                    cout << "\nCiudad encontrada:\n" << ciudadBuscada->getCodCiudad() << "; "
                        << ciudadBuscada->getNombre() << endl << endl;
                else
                    cout << "\nCiudad no encontrada.\n" << endl;
                break;
			}
            
            case 8:
                system(LIMPIAR);
				break;
            
            default:
                system(LIMPIAR);
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

static void menuModificar(int opcion, ArbolBBPasillos& arbolPasillos, ArbolAVLProductos& arbolProductos,
    ArbolRNMarcas& arbolMarcas, ArbolAAInventarios& arbolInventarios, ArbolBUsuarios& arbolClientes,
    ArbolBUsuarios& arbolAdmins, ArbolBBCiudades& arbolCiudades)
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
            	string codPasillo, nombre;

				cout << "Ingrese el codigo de pasillo a modificar: ";
				cin >> codPasillo;
		    	cout << "Ingrese el nuevo nombre del pasillo: ";
				cin.ignore();
				getline(cin, nombre);

				arbolPasillos.modificarPasillo(codPasillo, nombre);
				break;
			}

            case 2:
            {
            	string codProducto, nombre;
				
				cout << "Ingrese el codigo del producto a modificar: ";
				cin >> codProducto;
		    	cout << "Ingrese el nuevo nombre del producto: ";
				cin.ignore();
				getline(cin, nombre);
            	
                arbolProductos.modificarProducto(codProducto, nombre);
                break;
            }

            case 3:
            {
            	string codMarca, nombre, cantGondola, precio;
				
				cout << "Ingrese el codigo de la marca a modificar: ";
				cin >> codMarca;
				cout << "Ingrese el nuevo nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
		        cout << "Ingrese la nueva cantidad de producto en la gondola: ";
				cin >> cantGondola;
		    	cout << "Ingrese el nuevo precio del producto: ";
				cin >> precio;

            	arbolMarcas.modificarMarca(codMarca, nombre, cantGondola, precio);
                break;
            }

            case 4:
            {
            	string codInventario, nombre, cantStock, codCanasta;
			
				cout << "Ingrese el codigo del inventario a modificar: ";
				cin >> codInventario;
		        cout << "Ingrese el nuevo nombre de la marca: ";
				cin.ignore();
				getline(cin, nombre);
		        cout << "Ingrese la nueva cantidad de stock: ";
				cin >> cantStock;
		        cout << "Ingrese el codigo de canasta basica: ";
				cin >> codCanasta;

            	arbolInventarios.modificarInventario(codInventario, nombre, cantStock, codCanasta);
                break;
            }

            case 5:
            {
                string cedulaAModificar, codCiudad, nombre, telefono, correo;
                
                cout << "Ingrese la cedula del cliente a modificar: "; cin >> cedulaAModificar;

                bool clienteExiste = arbolClientes.buscarUsuario(cedulaAModificar);
                
                if (clienteExiste)
                {
                    cout << "Ingrese el nuevo nombre del cliente: "; cin >> nombre;
                    cout << "Ingrese el nuevo codigo de la ciudad del cliente: "; cin >> codCiudad;

                    if (arbolCiudades.buscarCiudad(codCiudad))
                    {
                        cout << "Ingrese el nuevo telefono del cliente: "; cin >> telefono;
                        cout << "Ingrese el nuevo correo del cliente: "; cin >> correo;

                        NodoABUsuario* clienteBuscado = arbolClientes.buscarConsultar(arbolClientes.getRaiz(), cedulaAModificar);
                        int i = arbolClientes.buscarConsultarIndice(arbolClientes.getRaiz(), cedulaAModificar);

                        clienteBuscado->getValores()[i] = cedulaAModificar + "; " + nombre + "; " + codCiudad + "; " + telefono + "; " + correo;
                        cout << "\nCliente modificado exitosamente." << endl;
                        cout << "\nCliente modificado:\n" << clienteBuscado->getValores()[i];
                    }
                    else
                        cout << "\nCiudad no registrada en el sistema.\n" << endl;
                }
                else
                    cout << "\nCliente no encontrado en el arbol.\n" << endl;
                break;
            }
            
            case 6:
            {
                string cedulaAModificar, codCiudad, nombre, telefono, correo;
                
                cout << "Ingrese la cedula del administrador a modificar: "; cin >> cedulaAModificar;

                bool adminExiste = arbolAdmins.buscarUsuario(cedulaAModificar);
                
                if (adminExiste)
                {
                    cout << "Ingrese el nuevo nombre del administrador: "; cin >> nombre;
                    cout << "Ingrese el nuevo codigo de la ciudad del administrador: "; cin >> codCiudad;

                    if (arbolCiudades.buscarCiudad(codCiudad))
                    {
                        cout << "Ingrese el nuevo telefono del administrador: "; cin >> telefono;
                        cout << "Ingrese el nuevo correo del administrador: "; cin >> correo;

                        NodoABUsuario* adminBuscado = arbolClientes.buscarConsultar(arbolClientes.getRaiz(), cedulaAModificar);
                        int i = arbolClientes.buscarConsultarIndice(arbolClientes.getRaiz(), cedulaAModificar);

                        adminBuscado->getValores()[i] = cedulaAModificar + "; " + nombre + "; " + codCiudad + "; " + telefono + "; " + correo;
                        cout << "\nAdministrador modificado exitosamente." << endl;
                        cout << "\nAdministrador modificado:\n" << adminBuscado->getValores()[i];
                    }
                    else
                        cout << "\nCiudad no registrada en el sistema.\n" << endl;
                }
                else
                    cout << "\nAdministrador no encontrado en el arbol.\n" << endl;
                break;
            }
            
            case 7:
            {
            	string codCiudad, nombre;
				
				cout << "Ingrese el codigo de la ciudad a modificar: ";
				cin >> codCiudad;
				cout << "Ingrese el nuevo nombre de la ciudad: ";
		    	cin.ignore();
		    	getline(cin, nombre);

            	arbolCiudades.modificarCiudad(codCiudad, nombre);
                break;
            }
            
            case 8:
                system(LIMPIAR);
				break;
            
            default:
                system(LIMPIAR);
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

static void menuListar(int opcion, ArbolBBPasillos& arbolPasillos, ArbolAVLProductos& arbolProductos,
    ArbolRNMarcas& arbolMarcas, ArbolAAInventarios& arbolInventarios, ArbolBUsuarios& arbolClientes,
    ArbolBUsuarios& arbolAdmins, ArbolBBCiudades& arbolCiudades)
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
                system(LIMPIAR);
            	cout << "Arbol de Pasillos:\n" << endl;
                arbolPasillos.mostrarPasillos(arbolPasillos.getRaiz(), 0);
                break;

            case 2:
                system(LIMPIAR);
            	cout << "Productos:\n" << endl;
                arbolProductos.mostrarProductos(arbolProductos.getRaiz(), 0);
                break;

            case 3:
                system(LIMPIAR);
            	cout << "Marcas de Productos:\n" << endl;
                arbolMarcas.mostrarMarcas(arbolMarcas.getRaiz(), 0);
                break;

            case 4:
                system(LIMPIAR);
            	cout << "Inventarios:\n" << endl;
                arbolInventarios.mostrarInventarios(arbolInventarios.getRaiz(), 0);
                break;
            
            case 5:
                system(LIMPIAR);
            	cout << "Clientes:\n\n";
                arbolClientes.mostrarUsuarios();
                break;
            
            case 6:
                system(LIMPIAR);
            	cout << "Administradores:\n\n";
                arbolAdmins.mostrarUsuarios();
                break;
            
            case 7:
                system(LIMPIAR);
            	cout << "Ciudades:\n" << endl;
                arbolCiudades.mostrarCiudades(arbolCiudades.getRaiz(), 0);
                break;
            
            case 8:
                system(LIMPIAR);
				break;
            
            default:
                system(LIMPIAR);
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 8);
}

void menuMantenimientoBD(int opcion, ArbolBBPasillos& arbolPasillos, ArbolAVLProductos& arbolProductos,
    ArbolRNMarcas& arbolMarcas, ArbolAAInventarios& arbolInventarios, ArbolBUsuarios& arbolClientes,
    ArbolBUsuarios& arbolAdmins, ArbolBBCiudades& arbolCiudades)
{
    do
    {
        cout << "************MANTENIMIENTO************" << endl;
        cout << "1. Inserciones" << endl;
        cout << "2. Consultas" << endl;
        cout << "3. Modificaciones" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Salir" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
                system(LIMPIAR);
                menuInsertar(opcion, arbolPasillos, arbolProductos, arbolMarcas, arbolInventarios,
                    arbolClientes, arbolAdmins, arbolCiudades);
				break;

            case 2:
                system(LIMPIAR);
                menuBuscarAdmins(opcion, arbolPasillos, arbolProductos, arbolMarcas, arbolInventarios,
                    arbolClientes, arbolAdmins, arbolCiudades);
				break;

            case 3:
                system(LIMPIAR);
                menuModificar(opcion, arbolPasillos, arbolProductos, arbolMarcas, arbolInventarios,
                    arbolClientes, arbolAdmins, arbolCiudades);
				break;

            case 4:
                system(LIMPIAR);
                menuListar(opcion, arbolPasillos, arbolProductos, arbolMarcas, arbolInventarios,
                    arbolClientes, arbolAdmins, arbolCiudades);
				break;

            case 5:
                system(LIMPIAR);
				break;

            default:
                system(LIMPIAR);
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 5);
}

static void menuReportes(int opcion, ArbolBBPasillos& arbolPasillos, ArbolAVLProductos& arbolProductos,
	ArbolBUsuarios& arbolClientes)
{
	do
    {
        cout << "************REPORTES:************" << endl;
	    cout << "1. Pasillo mas visitado" << endl;
	    cout << "2. Pasillo menos visitado" << endl;
	    cout << "3. Productos por pasillo mas vendidos" << endl;
	    cout << "4. Marcas mas vendidas" << endl;
	    cout << "5. Cliente que mas compro" << endl;
	    cout << "6. Cliente que menos compro" << endl;
	    cout << "7. Producto que mas se cargo en las gondolas" << endl;
	    cout << "8. Cliente que mas facturo" << endl;
	    cout << "9. Marcas de un producto" << endl;
	    cout << "10. Factura de mayor monto" << endl;
	    cout << "11. Productos de un pasillo" << endl;
	    cout << "12. Clientes del supermercado" << endl;
	    cout << "13. Pasillos del supermercado" << endl;
	    cout << "14. Inventario del supermercado" << endl;
	    cout << "15. Salir" << endl;
	    
	    cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
        {
            case 1:
                system(LIMPIAR);
                arbolPasillos.reportePasilloMasVisitado();
				break;

            case 2:
                system(LIMPIAR);
                arbolPasillos.reportePasilloMenosVisitado();
				break;

            case 3:
                system(LIMPIAR);
				break;

            case 4:
                system(LIMPIAR);
				break;
            
            case 5:
                system(LIMPIAR);
				break;
            
            case 6:
                system(LIMPIAR);
				break;
			
			case 7:
                system(LIMPIAR);
				break;
				
			case 8:
                system(LIMPIAR);
				break;
				
			case 9:
                system(LIMPIAR);
				break;
			
            case 10:
                system(LIMPIAR);
				break;

            case 11:
                system(LIMPIAR);
                arbolProductos.reporteProductosPasillo();
				break;

            case 12:
                system(LIMPIAR);
                // arbolClientes.reporteClientes();
				break;

            case 13:
                system(LIMPIAR);
                arbolPasillos.reportePasillos();
				break;

			case 14:
                system(LIMPIAR);
				break;
            
            case 15:
                system(LIMPIAR);
				break;
            
            default:
                system(LIMPIAR);
				cout << "Ingrese una opcion valida.\n" << endl;
        }
    } while (opcion != 15);
}



int main()
{
    ArbolBBPasillos arbolPasillos;
    ArbolAVLProductos arbolProductos;
    ArbolRNMarcas arbolMarcas;
    ArbolAAInventarios arbolInventarios;
    ArbolBBCiudades arbolCiudades;

    crearArbolPasillos(arbolPasillos);
    crearArbolProductos(arbolProductos, arbolPasillos);
    crearArbolMarcas(arbolMarcas, arbolPasillos, arbolProductos);
    crearArbolInventarios(arbolInventarios, arbolPasillos, arbolProductos, arbolMarcas);
    crearArbolCiudades(arbolCiudades);
    
    ArbolBUsuarios arbolClientes(5);
    crearArbolClientes(arbolClientes, arbolCiudades);
    ArbolBUsuarios arbolAdmins(5);
    crearArbolAdmins(arbolAdmins, arbolCiudades);
    
    int cedula, opcion, opcion2, opcion3;
    string respuesta;
    
    bool salirPrograma = false;

    // system(LIMPIAR);
    do
    {
        cout << "***********BIENVENID(@)************" << endl;
        cout << "Elija un tipo de usuario para loguearse:" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Salir del programa" << endl;
		cout << "\nIngrese la opcion deseada: ";
		cin >> opcion;

        switch (opcion)
		{
            case 1: // Administrador
            {
                cout << "\nIngrese su numero de cedula para ingresar." << endl;
                cout << "Ingrese su cedula: ";
                cin >> cedula;

                if (arbolAdmins.loginUsuario(intAString(cedula)))
                {
                    system(LIMPIAR);
                    cout << "Bienvenid(@), administrador(@)" << endl << endl;

                    do
                    {
                        menuAdiministrador();
                        cout << "\nIngrese la opcion deseada: ";
                        cin >> opcion2;
                
                        switch (opcion2)
                        {
                            case 1: // Mantenimiento de la Base de Datos
                                system(LIMPIAR);
                                menuMantenimientoBD(opcion3, arbolPasillos, arbolProductos, arbolMarcas,
                                    arbolInventarios, arbolClientes, arbolAdmins, arbolCiudades);
                                break;
                
                            case 2: // Facturar
                                system(LIMPIAR);
                                break;
                
                            case 3: // Revisar góndolas
                                system(LIMPIAR);
                                break;
                
                            case 4: // Verificar inventario
                                system(LIMPIAR);
                                break;
                
                            case 5: // Reportes
                                system(LIMPIAR);
                                menuReportes(opcion3, arbolPasillos, arbolProductos, arbolClientes);
                                break;
                
                            case 6: // Salir
                                system(LIMPIAR);
                                break;
                
                            default:
                                system(LIMPIAR);
                                cout << "Ingrese una opcion valida.\n" << endl;
                        }
                    } while (opcion2 != 6);
                }
                else
					cout << "\nNombre de usuario o cedula incorrectos. Intente nuevamente.\n" << endl;
                break;
			}

            case 2: // Cliente
            {
                cout << "\nIngrese \"S\" o \"N\" para iniciar sesion: ";
                cin >> respuesta;

                if ((respuesta == "S") || (respuesta == "s"))
                {
                    cout << "\nIngrese su numero de cedula para ingresar." << endl;
                    cout << "Ingrese su cedula: ";
                    cin >> cedula;

                    if (arbolClientes.loginUsuario(intAString(cedula)))
                    {
                        system(LIMPIAR);
                        cout << "Bienvenid(@), cliente" << endl << endl;

                        do
                        {
                            menuClienteRegistrado();
                            cout << "\nIngrese la opcion deseada: ";
                            cin >> opcion2;
                    
                            switch (opcion2)
                            {
                                case 1: // Consultar precio
                                system(LIMPIAR);
                                    break;
                    
                                case 2: // Consultar descuento
                                system(LIMPIAR);
                                    break;
                    
                                case 3: // Consultar producto
                                system(LIMPIAR);
                                    break;
                    
                                case 4: // Comprar
                                system(LIMPIAR);
                                    break;
                    
                                case 5: // Salir
                                system(LIMPIAR);
                                    break;
                    
                                default:
                                system(LIMPIAR);
                                    cout << "Ingrese una opcion valida.\n" << endl;
                            }
                        } while (opcion2 != 5);
                    }
                    else
                        cout << "\nNombre de usuario o cedula incorrectos. Intente nuevamente.\n" << endl;
                }
                else
                {
                    system(LIMPIAR);
                    do
                    {
                        menuClienteNoRegistrado();
                        cout << "\nIngrese la opcion deseada: ";
                        cin >> opcion2;
                
                        switch (opcion2)
                        {
                            case 1: // Consultar precio
                                system(LIMPIAR);
                                break;
                                
                            case 2: // Consultar producto
                                system(LIMPIAR);
                                break;
                                
                            case 3: // Salir
                                system(LIMPIAR);
                                break;
                                
                            default:
                                system(LIMPIAR);
                                cout << "Ingrese una opcion valida.\n" << endl;
                        }
                    } while (opcion2 != 3);
                }

                break;
            }
			
            case 3: // Salir del programa
                cout << "Saliendo del programa..." << endl;
                salirPrograma = true;
                break;

            default:
                cout << "\nIngrese una opcion valida.\n" << endl;
                break;
        }
	} while (!salirPrograma);

    return 0;
}

