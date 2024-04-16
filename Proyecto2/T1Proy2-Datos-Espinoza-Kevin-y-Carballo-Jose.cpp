// Estudiantes: José Carballo Martínez y Kevin Espinoza Barrantes

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

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

    NodoABBPasillo(int _codPasillo, string _nombre, NodoABBPasillo *_Hizq = NULL,
            NodoABBPasillo *_Hder = NULL, NodoABBPasillo *_siguiente = NULL,
            NodoABBPasillo *_anterior = NULL):
        codPasillo(_codPasillo), nombre(_nombre), contVisitas(0), Hizq(_Hizq), Hder(_Hder),
        siguiente(_siguiente), anterior(_anterior) {}

    void InsertaBinario(int codPasillo, string nombre);

	int getCodPasillo() { return codPasillo; }
	string getNombre() { return nombre; }

private:
    int codPasillo;
    string nombre;
    int contVisitas;
    NodoABBPasillo *Hizq, *Hder, *siguiente, *anterior;

    friend class PilaPasillos;
    friend class ABBPasillos;
};

typedef NodoABBPasillo *pnodoPasillo;
typedef NodoABBPasillo *pnodoABBPasillo;


class PilaPasillos
{
public:
    PilaPasillos(): plista(NULL) {}

    void Push(pnodoPasillo);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoPasillo Pop();
    int Size();
    
    pnodoPasillo plista;
};


class NodoAVLProPasillo
{
public:
    NodoAVLProPasillo(int _codPasillo, int _codProducto, string _nombre,
            NodoAVLProPasillo *_Hizq = NULL, NodoAVLProPasillo *_Hder = NULL,
            NodoAVLProPasillo *_siguiente = NULL, NodoAVLProPasillo *_anterior = NULL):
        codPasillo(_codPasillo), codProducto(_codProducto), nombre(_nombre),
        contBusquedas(0), FB(0), Hizq(_Hizq), Hder(_Hder), siguiente(_siguiente),
        anterior(_anterior) {}
    
    void InsertaBinario(int codPasillo, int codProducto, string nombre);

    int getCodPasillo() { return codPasillo; }
	int getCodProducto() { return codProducto; }
	string getNombre() { return nombre; }

private:
    int codPasillo;
    int codProducto;
    string nombre;
    int contBusquedas;
    int FB;
    NodoAVLProPasillo *Hizq, *Hder, *siguiente, *anterior;
    
    friend class PilaProPasillo;
    friend class AVLProPasillo;
};

typedef NodoAVLProPasillo* pnodoProPasillo;
typedef NodoAVLProPasillo* pnodoAVLProPasillo;


class PilaProPasillo
{
public:
    PilaProPasillo() : plista(NULL) {}

    void Push(pnodoProPasillo);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoProPasillo Pop();
    int Size();
    
    pnodoProPasillo plista;
};


class NodoCliente
{
public:
    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono,
            string _correo):
        cedula(_cedula), nombre(_nombre), codCiudad(_codCiudad), telefono(_telefono),
        correo(_correo), siguiente(NULL) {}

    NodoCliente(int _cedula, string _nombre, int _codCiudad, string _telefono,
            string _correo, NodoCliente* _siguiente):
        cedula(_cedula), nombre(_nombre), codCiudad(_codCiudad), telefono(_telefono),
        correo(_correo), siguiente(_siguiente) {}
    
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

typedef NodoCliente *pnodoCliente;


class NodoAdmin
{
public:
    NodoAdmin(int _cedula, string _nombre, int _codCiudad, string _telefono,
            string _correo):
        cedula(_cedula), nombre(_nombre), codCiudad(_codCiudad), telefono(_telefono),
        correo(_correo), siguiente(NULL) {}

    NodoAdmin(int _cedula, string _nombre, int _codCiudad, string _telefono,
            string _correo, NodoAdmin* _siguiente):
        cedula(_cedula), nombre(_nombre), codCiudad(_codCiudad), telefono(_telefono),
        correo(_correo), siguiente(_siguiente) {}
    
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

typedef NodoAdmin *pnodoAdmin;


class NodoABBCiudad
{
public:
    NodoABBCiudad() {}

    NodoABBCiudad(int _codCiudad, string _nombre, NodoABBCiudad *_Hizq = NULL,
            NodoABBCiudad *_Hder = NULL, NodoABBCiudad *_siguiente = NULL,
            NodoABBCiudad *_anterior = NULL):
        codCiudad(_codCiudad), nombre(_nombre), Hizq(_Hizq), Hder(_Hder),
        siguiente(_siguiente), anterior(_anterior) {}

    void InsertaBinario(int codCiudad, string nombre);

	int getCodCiudad() { return codCiudad; }
	string getNombre() { return nombre; }

private:
    int codCiudad;
    string nombre;
    NodoABBCiudad *Hizq, *Hder, *siguiente, *anterior;

    friend class PilaCiudades;
    friend class ABBCiudades;
};

typedef NodoABBCiudad *pnodoCiudad;
typedef NodoABBCiudad *pnodoABBCiudad;


class PilaCiudades
{
public:
    PilaCiudades() : plista(NULL) {}

    void Push(pnodoCiudad);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoCiudad Pop();
    int Size();
    
    pnodoCiudad plista;
};



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
    ostringstream convertir;

    convertir << num;

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



class ABBPasillos
{
public:
    ABBPasillos(): raiz(NULL) {}
    ~ABBPasillos();

    bool ArbolVacio() { return raiz == NULL; }
    void insertarPasillo(int codPasillo, string nombre);
    bool pasilloRepetido(int codPasillo) { return buscarPasillo(codPasillo) != NULL; }
    pnodoABBPasillo buscarPasillo(int codPasillo);
    void modificarPasillo(int codPasillo, string nombre);
    void mostrarPasillos(pnodoABBPasillo, int);
    void reportePasillos();
    void reportePasilloMasVisitado();
    void reportePasilloMenosVisitado();
    void PreordenI();
    void InordenI();
    void PostordenI();

    pnodoABBPasillo getRaiz() { return raiz; }

private:
    pnodoABBPasillo raiz;
};

ABBPasillos::~ABBPasillos()
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

void NodoABBPasillo::InsertaBinario(int llave, string nombre)
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
    else if (llave > codPasillo)
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
    else
        cout << "\nEl pasillo ya existe en el arbol.\n" << endl;
}

void ABBPasillos::insertarPasillo(int llave, string nombre)
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

pnodoABBPasillo ABBPasillos::buscarPasillo(int codPasillo)
{
    if (ArbolVacio())
    {
        cout << "\nEl arbol de pasillos esta vacia.\n" << endl;
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

void ABBPasillos::modificarPasillo(int codPasillo, string nombre)
{
	pnodoABBPasillo pasillo = buscarPasillo(codPasillo);
	
	if (pasillo != NULL)
    {
        pasillo->codPasillo = codPasillo;
        pasillo->nombre = nombre;

        cout << "\nPasillo modificado exitosamente." << endl;
        cout << "\nPasillo modificado:\n" << codPasillo << "; " << nombre << endl << endl;
    }
    else
		cout << "\nPasillo no encontrado.\n";
}

void ABBPasillos::mostrarPasillos(pnodoABBPasillo arbol, int cont)
{
    if (arbol != NULL)
    {
        mostrarPasillos(arbol->Hder, cont + 1);

        for (int i = 0; i < cont; i++)
            cout << "   ";

        cout << arbol->codPasillo << "; " << arbol->nombre << endl << endl;

        mostrarPasillos(arbol->Hizq, cont + 1);
    }
}

void ABBPasillos::reportePasillos()
{
    string nombreReporte = "Pasillos";
    string texto = "";

    // Itera sobre la lista de pasillos y guarda en el archivo
    pnodoPasillo temp = raiz;

	while (temp != NULL)
	{
        texto += "-> " + intAString(temp->codPasillo) + "; " + temp->nombre + "\n\n";

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

void ABBPasillos::reportePasilloMasVisitado()
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

void ABBPasillos::reportePasilloMenosVisitado()
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

void ABBPasillos::PreordenI()
{
    pnodoABBPasillo act = raiz;
    PilaPasillos p;
    
    while ((p.Vacia() == false) || (act != NULL))
    {
        if (act != NULL)
        {
            cout << act->codPasillo << "; " << act->nombre << " - ";
            p.Push(act);
            act = act->Hizq;
        }
        else
        {
            act = p.Pop();
            act = act->Hder;
        }
    }
}

void ABBPasillos::InordenI()
{
    pnodoABBPasillo act = raiz;
    PilaPasillos p;
    bool band = true;

    while(band)
    {
        while(act != NULL)
        {
            p.Push(act);
            act = act->Hizq;
        }

        if (!p.Vacia())
        {
            act = p.Pop();
            cout << act->codPasillo << "; " << act->nombre <<" - ";
            act = act->Hder;          
        }

        if (p.Vacia() && (act == NULL))
            break;
    }
}

void ABBPasillos::PostordenI()
{
    pnodoABBPasillo act = raiz;
    PilaPasillos p1, p2;

    while(!p1.Vacia() || (act != NULL))
    {
        if (act != NULL)
        {
            p2.Push(new NodoABBPasillo(act->codPasillo, act->nombre));            
            p2.Push(act);
            act = act->Hder;
        }
        else
        {
            act = p1.Pop();
            act = act->Hizq;
        }
    }

    while(!p2.Vacia())
    {
        pnodoABBPasillo salida = p2.Pop();
        cout<< salida->codPasillo << "; " << salida->nombre << " - ";
    }
}

void PilaPasillos::Push(pnodoPasillo v)
{
    if (Vacia())
        plista = v;
    else
    {
        pnodoPasillo aux = plista;
        while (aux->siguiente)
            aux = aux->siguiente;

        aux->siguiente = v;
        v->anterior = aux;
    }
}

pnodoPasillo PilaPasillos::Pop()
{
    pnodoABBPasillo borrar;
    pnodoABBPasillo salida;

    if (Vacia())
        cout<<"Pila Vacia"<<endl;
    else
    {
        borrar = plista;

        while(borrar->siguiente)
            borrar = borrar->siguiente;

        if (Size() > 1)
        {
            salida = borrar;
            borrar->anterior->siguiente = NULL;
            borrar = NULL;
            delete borrar;
        }
        else
        {
            salida =plista;        
            plista = NULL;
        }
    }
    
    return salida;
}

int PilaPasillos::Size()
{
    while(plista && plista->anterior)
        plista = plista->anterior;

    int cont = 0;
    pnodoABBPasillo aux;
    aux = plista;
    
    while(aux)
    {
        cont++;
        aux = aux->siguiente;
    }

    return cont;
}

void PilaPasillos::Mostrar()
{
    if (Vacia())
        cout << "La pila esta vacia." << endl;

    pnodoABBPasillo aux = plista;

    while (aux)
    {
        cout << aux->codPasillo << "; " << aux->nombre <<" - ";

        aux = aux->siguiente;
    }
}


class AVLProPasillo
{
public:
    AVLProPasillo() { raiz = NULL; }
    ~AVLProPasillo();

    bool ArbolVacio() { return raiz == NULL; }
    void Equilibrar1(pnodoAVLProPasillo n, bool);
    void Equilibrar2(pnodoAVLProPasillo n, bool);
    void insertarProducto(pnodoAVLProPasillo ra, bool Hh, int codPasillo,
        int codProducto, string nombre, ABBPasillos &arbolPasillos);
    bool productoRepetido(int codProducto) { return buscarProducto(codProducto) != NULL; }
    pnodoProPasillo buscarProducto(int codProducto);
    void modificarProducto(int codProducto, string nombre);
    void reporteProductosPasillo();
    void reporteProductoMasBuscado(ABBPasillos &arbolPasillos);
    void mostrarProductos(pnodoAVLProPasillo arbol, int cont);
    void RotacionDobleIzquierda(pnodoAVLProPasillo n1, pnodoAVLProPasillo n2);
    void RotacionDobleDerecha(pnodoAVLProPasillo n1, pnodoAVLProPasillo n2);
    void RotacionSimpleIzquierda(pnodoAVLProPasillo n1, pnodoAVLProPasillo n2);
    void RotacionSimpleDerecha(pnodoAVLProPasillo n1, pnodoAVLProPasillo n2);
    void PreordenI();
    void InordenI();
    void PostordenI();

    pnodoProPasillo getRaiz() { return raiz; }
    bool getHh() { return Hh; }

private:
    pnodoProPasillo raiz;
    bool Hh;
};

AVLProPasillo::~AVLProPasillo()
{
    pnodoProPasillo aux;

    while (raiz)
    {
        aux = raiz;
        raiz = raiz->siguiente;
        delete aux;
    }

    raiz = NULL;
}

void AVLProPasillo::Equilibrar1(pnodoAVLProPasillo n, bool Hh)
{
    pnodoAVLProPasillo n1;

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

void AVLProPasillo::Equilibrar2(pnodoAVLProPasillo n, bool Hh)
{
    pnodoAVLProPasillo n1;

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


void NodoAVLProPasillo::InsertaBinario(int codPasillo, int llave, string nombre)
{
    if (llave < codPasillo)
    {
        if (Hizq == NULL)
        {
            Hizq = new NodoAVLProPasillo(codPasillo, llave, nombre);
            cout << "\nProducto insertado exitosamente." << endl;
            cout << "\nProducto nuevo:\n" << codPasillo << "; " << llave << "; " << nombre << endl;
        }
        else
            Hizq->InsertaBinario(codPasillo, llave, nombre);
    }
    else if (llave > codPasillo)
    {
        if (Hder == NULL)
        {
            Hder = new NodoAVLProPasillo(codPasillo, llave, nombre);
            cout << "\nProducto insertado exitosamente." << endl;
            cout << "\nProducto nuevo:\n" << codPasillo << "; " << llave << "; " << nombre << endl;
        }
        else
            Hder->InsertaBinario(codPasillo, llave, nombre);
    }
    else
        cout << "\nEl pasillo ya existe en el arbol.\n" << endl;
}


void AVLProPasillo::insertarProducto(pnodoAVLProPasillo ra, bool Hh, int codPasillo,
                                     int llave, string nombre, ABBPasillos &arbolPasillos)
{
    pnodoAVLProPasillo n1;

    if (raiz == NULL)
    {
        ra = new NodoAVLProPasillo(codPasillo, llave, nombre);
        Hh = true;
        cout << "\nProducto insertado exitosamente." << endl;
        cout << "\nProducto nuevo:\n" << codPasillo << "; " << llave << "; " << nombre << endl;
    }
    else
    {
        if (llave < ra->codProducto)
        {
            insertarProducto(ra->Hizq, Hh, codPasillo, llave, nombre, arbolPasillos);

            if (Hh)
            {
                switch (ra->codProducto)
                {
                    case 1:
                        ra->FB = 0;
                        Hh = false;
                        break;

                    case 0:
                        ra->FB  = -1;
                        break;

                    case -1:
                        n1 = ra->Hizq;

                        if (n1->FB == -1)
                            RotacionSimpleIzquierda(ra, n1);
                        else
                            RotacionDobleIzquierda(ra,n1);

                        Hh = false;
                        break;
                }
            }
        }
        else
        {
            if (llave > ra->codProducto)
            {
                insertarProducto(ra->Hder, Hh, codPasillo, llave, nombre, arbolPasillos);

                if (Hh)
                {
                    switch(ra->FB)
                    {
                        case -1:
                            ra->FB = 0;
                            Hh = false;
                            break;

                        case 0:
                            ra->FB = 1;
                            break;

                        case 1:
                            n1 = ra->Hder;

                            if (n1->FB == 1)
                                RotacionSimpleDerecha(ra, n1);
                            else
                                RotacionDobleDerecha(ra, n1);

                            Hh = false;
                            break;
                    }
                }
            }
        }
    }
}

pnodoProPasillo AVLProPasillo::buscarProducto(int codProducto)
{
    if (ArbolVacio())
	{
        cout << "\nEl arbol de pasillos esta vacia.\n" << endl;
        return NULL;
    }

    pnodoAVLProPasillo act = raiz;

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

void AVLProPasillo::modificarProducto(int codProducto, string nombre)
{
	pnodoProPasillo productoPasillo = buscarProducto(codProducto);

    if (productoPasillo == NULL)
    {
        cout << "El producto no existe en el arbol." << endl;
        return;
    }

    productoPasillo->codProducto = codProducto;
    productoPasillo->nombre = nombre;

    cout << "\nProducto modificado exitosamente." << endl;
    cout << "\nProducto modificado:\n" << codProducto << "; " << nombre << endl << endl;
}

void AVLProPasillo::mostrarProductos(pnodoAVLProPasillo arbol, int cont)
{
    if (arbol != NULL)
    {
        mostrarProductos(arbol->Hder, cont + 1);

        for (int i = 0; i < cont; i++)
            cout << "   ";

        cout << arbol->codPasillo << "; " << arbol->codProducto << "; "
            << arbol->nombre << endl << endl;

        mostrarProductos(arbol->Hizq, cont + 1);
    }
}

void AVLProPasillo::reporteProductosPasillo()
{
    int codigoPasillo;
    cout << "Ingrese el codigo del pasillo: ";
    cin >> codigoPasillo;

	string nombreReporte = "Productos de Pasillo";
    string texto = "";

    pnodoProPasillo temp = raiz;
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

void AVLProPasillo::reporteProductoMasBuscado(ABBPasillos &arbolPasillos)
{
    string nombreReporte = "Producto(s) mas buscado(s)";
    string texto = "";

    pnodoProPasillo temp = raiz;
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
            texto += "Pasillo: " + intAString(temp->codPasillo) + "; " +
					arbolPasillos.buscarPasillo(temp->codPasillo)->getNombre() +
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

void AVLProPasillo::RotacionDobleIzquierda(pnodoAVLProPasillo n, pnodoAVLProPasillo n1)
{
    pnodoAVLProPasillo n2;

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

void AVLProPasillo::RotacionDobleDerecha(pnodoAVLProPasillo n, pnodoAVLProPasillo n1)
{
    pnodoAVLProPasillo n2;

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

void AVLProPasillo::RotacionSimpleDerecha(pnodoAVLProPasillo n, pnodoAVLProPasillo n1)
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

void AVLProPasillo::RotacionSimpleIzquierda(pnodoAVLProPasillo n, pnodoAVLProPasillo n1)
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
    cout << "\nCliente nuevo:\n" << indice << " -> " << cedula << "; " << nombre << "; "
        << codCiudad << "; " << telefono << "; " << correo << endl << endl;
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
    cout << "\nCliente modificado:\n" << funcionHash(cedula) << " -> " << cedula << "; "
        << nombre << "; " << codCiudad << "; " << telefono << "; " << correo << endl << endl;
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

// Método para comprobar si el hashing abierto est� vac�o
bool HashingAdmins::hashingVacio()
{
    for (int i = 0; i < 13; i++)
	{
        if (tablaHash[i] != NULL)
            return false;
    }

    return true;
}

// M�todo que inserta un nuevo administrador en la tabla hash
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
    cout << "\nAdministrador nuevo:\n" << indice << " -> " << cedula << "; " << nombre << "; "
        << codCiudad << "; " << telefono << "; " << correo << endl << endl;
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
    cout << "\nAdministrador modificado:\n" << funcionHash(cedula) << " -> " << cedula << "; "
        << nombre << "; " << codCiudad << "; " << telefono << "; " << correo << endl << endl;
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


class ABBCiudades
{
public:
    ABBCiudades(): raiz(NULL) {}
    ~ABBCiudades();

    bool ArbolVacio() { return raiz == NULL; }
    void insertarCiudad(int codCiudad, string nombre);
    bool ciudadRepetida(int codCiudad) { return buscarCiudad(codCiudad) != NULL; }
    pnodoABBCiudad buscarCiudad(int codCiudad);
    void modificarCiudad(int codCiudad, string nombre);
    void mostrarCiudades(pnodoABBCiudad, int);
    void PreordenI();
    void InordenI();
    void PostordenI();

    pnodoABBCiudad getRaiz() { return raiz; }

private:
    pnodoABBCiudad raiz;
};

ABBCiudades::~ABBCiudades()
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

void NodoABBCiudad::InsertaBinario(int llave, string nombre)
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

void ABBCiudades::insertarCiudad(int llave, string nombre)
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

pnodoABBCiudad ABBCiudades::buscarCiudad(int codCiudad)
{
    if (ArbolVacio())
    {
        cout << "\nEl arbol de pasillos esta vacia.\n" << endl;
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

void ABBCiudades::modificarCiudad(int codCiudad, string nombre)
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

void ABBCiudades::mostrarCiudades(pnodoABBCiudad arbol, int cont)
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


void ABBCiudades::PreordenI()
{
    pnodoABBCiudad act = raiz;
    PilaCiudades p;
    
    while ((p.Vacia() == false) || (act != NULL))
    {
        if (act != NULL)
        {
            cout << act->codCiudad << "; " << act->nombre << " - ";
            p.Push(act);
            act = act->Hizq;
        }
        else
        {
            act = p.Pop();
            act = act->Hder;
        }
    }
}

void ABBCiudades::InordenI()
{
    pnodoABBCiudad act = raiz;
    PilaCiudades p;
    bool band = true;

    while(band)
    {
        while(act != NULL)
        {
            p.Push(act);
            act = act->Hizq;
        }

        if (!p.Vacia())
        {
            act = p.Pop();
            cout << act->codCiudad << "; " << act->nombre <<" - ";
            act = act->Hder;          
        }

        if (p.Vacia() && (act == NULL))
            break;
    }
}

void ABBCiudades::PostordenI()
{
    pnodoABBCiudad act = raiz;
    PilaCiudades p1, p2;

    while(!p1.Vacia() || (act != NULL))
    {
        if (act != NULL)
        {
            p2.Push(new NodoABBCiudad(act->codCiudad, act->nombre));            
            p2.Push(act);
            act = act->Hder;
        }
        else
        {
            act = p1.Pop();
            act = act->Hizq;
        }
    }

    while(!p2.Vacia())
    {
        pnodoABBCiudad salida = p2.Pop();
        cout<< salida->codCiudad << "; " << salida->nombre << " - ";
    }
}

void PilaCiudades::Push(pnodoCiudad v)
{
    if (Vacia())
        plista = v;
    else
    {
        pnodoCiudad aux = plista;
        while (aux->siguiente)
            aux = aux->siguiente;

        aux->siguiente = v;
        v->anterior = aux;
    }
}

pnodoCiudad PilaCiudades::Pop()
{
    pnodoABBCiudad borrar;
    pnodoABBCiudad salida;

    if (Vacia())
        cout<<"Pila Vacia"<<endl;
    else
    {
        borrar = plista;

        while(borrar->siguiente)
            borrar = borrar->siguiente;

        if (Size() > 1)
        {
            salida = borrar;
            borrar->anterior->siguiente = NULL;
            borrar = NULL;
            delete borrar;
        }
        else
        {
            salida =plista;        
            plista = NULL;
        }
    }    
    return salida;
}

int PilaCiudades::Size()
{
    while(plista && plista->anterior)
        plista = plista->anterior;

    int cont = 0;
    pnodoABBCiudad aux;
    aux = plista;
    
    while(aux)
    {
        cont++;
        aux = aux->siguiente;
    }

    return cont;
}

void PilaCiudades::Mostrar()
{
    if (Vacia())
        cout << "La pila esta vacia." << endl;

    pnodoABBCiudad aux = plista;

    while (aux)
    {
        cout << aux->codCiudad << "; " << aux->nombre <<" - ";

        aux = aux->siguiente;
    }
}



void crearArbolPasillos(ABBPasillos &arbolPasillos)
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

        // Inserta en el árbol de pasillos después de las validaciones
        arbolPasillos.insertarPasillo(stringAInt(codPasillo), nombre);
    }

    archivo.close();
}

void crearArbolProPasillo(AVLProPasillo &arbolProPasillo, ABBPasillos &arbolPasillos)
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
        
        // Inserta en el árbol AVL después de las validaciones
        arbolProPasillo.insertarProducto(arbolProPasillo.getRaiz(), arbolProPasillo.getHh(),
            stringAInt(codPasillo), stringAInt(codProducto), nombre, arbolPasillos);
    }

    archivo.close();
}

void crearHashingClientes(HashingClientes &hashClientes, ABBCiudades &arbolCiudades)
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

        if (arbolCiudades.ciudadRepetida(stringAInt(codCiudad)))
			// Inserta en el hash de clientes después de las validaciones
	        hashClientes.insertarCliente(stringAInt(cedula), nombre, stringAInt(codCiudad),
				telefono, correo);
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}

void crearHashingAdmins(HashingAdmins &hashAdmins, ABBCiudades &arbolCiudades)
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

		if (arbolCiudades.ciudadRepetida(stringAInt(codCiudad)))
			// Inserta en el hash de administradores después de las validaciones
	        hashAdmins.insertarAdmin(stringAInt(cedula), nombre, stringAInt(codCiudad),
				telefono, correo);
		else
			cout << "\nEl codigo de la ciudad no existe.\n" << endl;
    }

    archivo.close();
}

void crearArbolCiudades(ABBCiudades &arbolCiudades)
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
        arbolCiudades.insertarCiudad(stringAInt(codCiudad), nombre);
	}
}



void menuAdiministrador()
{
	cout << "************MENU************" << endl;
    cout << "1. Mantenimiento de la base de Datos" << endl;
    cout << "2. Facturar" << endl;
    cout << "3. Revisar gondolas" << endl;
    cout << "4. Verificar inventario" << endl;
    cout << "5. Reportes" << endl;
    cout << "6. Salir" << endl;
}

void menuClienteRegistrado()
{
	cout << "************MENU************" << endl;
    cout << "1. Consultar precio" << endl;
    cout << "2. Consultar descuento" << endl;
    cout << "3. Consultar productos" << endl;
    cout << "4. Comprar" << endl;
    cout << "5. Salir" << endl;
}

void menuClienteNoRegistrado()
{
	cout << "************MENU************" << endl;
    cout << "1. Consultar precio" << endl;
    cout << "2. Consultar productos" << endl;
    cout << "3. Salir" << endl;
}

void menuInsertar(int opcion, ABBPasillos &arbolPasillos, AVLProPasillo &arbolProPasillo, ABBCiudades &arbolCiudades)
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
                
				arbolPasillos.insertarPasillo(codPasillo, nombre); 
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
                
				// Inserta en el árbol AVL después de las validaciones
                arbolProPasillo.insertarProducto(arbolProPasillo.getRaiz(), arbolProPasillo.getHh(),
                    codPasillo, codProducto, nombre, arbolPasillos);
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
                
				// listaMarcaProductos.insertarMarcaProducto(codPasillo, codProducto, codMarca,
				// 	nombre, cantGondola, precio, listaPasillos, listaProductosPasillo);
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
                
				// listaInventarios.insertarInventario(codPasillo, codProducto, codMarca,
				// 	codInventario, nombre, cantStock, codCanasta, listaPasillos, listaProductosPasillo,
				// 	listaMarcaProductos);
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

				if (!arbolCiudades.ciudadRepetida(codCiudad))
				{
				 	cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
				 	break;
				}            		

				// hashClientes.insertarCliente(cedula, nombre, codCiudad, telefono, correo);
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

				if (!arbolCiudades.ciudadRepetida(codCiudad))
				{
				 	cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
				 	break;
				} 

				// hashAdmins.insertarAdmin(cedula, nombre, codCiudad, telefono, correo);
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
                
				arbolCiudades.insertarCiudad(codCiudad, nombre); 
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

void menuBuscarClientes(int opcion, ABBPasillos &arbolPasillos, AVLProPasillo &arbolProPasillo)
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
            	int codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProPasillo productoBuscado = arbolProPasillo.buscarProducto(codProductoABuscar);
				
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
                
				// pnodoMarcaProducto marcaBuscada = listaMarcaProductos.buscarMarcaProducto(codMarcaABuscar);
				
                // if (marcaBuscada != NULL)
				// {
				// 	cout << "\nMarca encontrada:" << endl;
                //    cout << "CodPasillo: " << marcaBuscada->getCodPasillo() << endl;
		        //    cout << "CodProducto: " << marcaBuscada->getCodProducto() << endl;
		        //    cout << "CodMarca: " << marcaBuscada->getCodMarca() << endl;
		        //    cout << "Nombre: " << marcaBuscada->getNombre() << endl;
		        //    cout << "CantGondola: " << marcaBuscada->getCantGondola() << endl;
		        //    cout << "Precio: " << marcaBuscada->getPrecio() << endl << endl;
                // }
				// else
                //    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada.\n" << endl;
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

void menuBuscarAdmins(int opcion, ABBPasillos &arbolPasillos, AVLProPasillo &arbolProPasillo, ABBCiudades &arbolCiudades)
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
                
				pnodoPasillo pasilloBuscado = arbolPasillos.buscarPasillo(codPasilloABuscar);
				
                if (pasilloBuscado != NULL)
                    cout << "\nPasillo encontrado:\n" << pasilloBuscado->getCodPasillo() << "; "
                        << pasilloBuscado->getNombre() << endl << endl;
				else
                    cout << "\nPasillo no encontrado.\n" << endl;
                break;
			}
			
            case 2:
            {
            	int codProductoABuscar;
                
				cout << "Ingrese el codigo del producto a buscar: ";
				cin >> codProductoABuscar;
                
				pnodoProPasillo productoBuscado = arbolProPasillo.buscarProducto(codProductoABuscar);
				
                if (productoBuscado != NULL)
                    cout << "\nProducto encontrado:\n" << productoBuscado->getCodPasillo() << "; "
                        << productoBuscado->getCodProducto() << "; " << productoBuscado->getNombre() << endl << endl;
				else
                    cout << "\nPasillo no encontrado.\n" << endl;
                break;
			}

            case 3:
            {
            	int codMarcaABuscar;
                
				cout << "Ingrese el codigo de la marca a buscar: ";
				cin >> codMarcaABuscar;
                
				// pnodoMarcaProducto marcaBuscada = listaMarcaProductos.buscarMarcaProducto(codMarcaABuscar);
				
                // if (marcaBuscada != NULL)
				// {
				// 	cout << "\nMarca encontrada:" << endl;
                //    cout << "CodPasillo: " << marcaBuscada->getCodPasillo() << endl;
		        //    cout << "CodProducto: " << marcaBuscada->getCodProducto() << endl;
		        //    cout << "CodMarca: " << marcaBuscada->getCodMarca() << endl;
		        //    cout << "Nombre: " << marcaBuscada->getNombre() << endl;
		        //    cout << "CantGondola: " << marcaBuscada->getCantGondola() << endl;
		        //    cout << "Precio: " << marcaBuscada->getPrecio() << endl << endl;
                // }
				// else
                //    cout << "\nMarca con codigo " << codMarcaABuscar << " no encontrada.\n" << endl;
                break;
			}

            case 4:
            {
            	int codInventarioABuscar;
                
				cout << "Ingrese el codigo del inventario a buscar: ";
				cin >> codInventarioABuscar;
                
				// pnodoInventario inventarioBuscado = listaInventarios.buscarInventario(codInventarioABuscar);
				
                // if (inventarioBuscado != NULL)
				// {
				// 	cout << "\nMarca encontrada:" << endl;
                //    cout << "CodPasillo: " << inventarioBuscado->getCodPasillo() << endl;
		        //    cout << "CodProducto: " << inventarioBuscado->getCodProducto() << endl;
		        //    cout << "CodMarca: " << inventarioBuscado->getCodMarca() << endl;
		        //    cout << "CodInventario: " << inventarioBuscado->getCodInventario() << endl;
		        //    cout << "Nombre: " << inventarioBuscado->getNombre() << endl;
		        //    cout << "CantStock: " << inventarioBuscado->getCantStock() << endl;
		        //    cout << "CodCanasta: " << inventarioBuscado->getCodCanasta() << endl << endl;
                // }
				// else
                //    cout << "\nInventario con codigo " << codInventarioABuscar << " no encontrado.\n" << endl;
                break;
			}
            
            case 5:
            {
	            int cedulaABuscar;
	            
				cout << "Ingrese la cedula del cliente a buscar: ";
				cin >> cedulaABuscar;
	            
				// pnodoCliente clienteBuscado = hashClientes.buscarCliente(cedulaABuscar);
				
	            // if (clienteBuscado != NULL)
				// {
	            //    cout << "\nCliente encontrado:" << endl;
	            //    cout << hashClientes.funcionHash(cedulaABuscar) << " -> Cedula: "
				// 		<< clienteBuscado->getCedula() << endl;
	            //    cout << "     Nombre: " << clienteBuscado->getNombre() << endl;
	            //    cout << "     Ciudad: " << clienteBuscado->getCodCiudad() << endl;
	            //    cout << "     Telefono: " << clienteBuscado->getTelefono() << endl;
	            //    cout << "     Correo: " << clienteBuscado->getCorreo() << endl << endl;
	            // }
				// else
	            //    cout << "\nCliente con cedula " << cedulaABuscar << " no encontrado.\n" << endl;
	            break;
	        }
            
            case 6:
            {
                int cedulaABuscar;
                
				cout << "Ingrese la cedula del administrador a buscar: ";
				cin >> cedulaABuscar;
                
				// pnodoAdmin adminBuscado = hashAdmins.buscarAdmin(cedulaABuscar);
				
                // if (adminBuscado != NULL)
				// {
                //    cout << "\nAdministrador encontrado:" << endl;
                //    cout << hashAdmins.funcionHash(cedulaABuscar) << " -> Cedula: "
				// 		<< adminBuscado->getCedula() << endl;
                //    cout << "     Nombre: " << adminBuscado->getNombre() << endl;
                //    cout << "     Ciudad: " << adminBuscado->getCodCiudad() << endl;
                //    cout << "     Telefono: " << adminBuscado->getTelefono() << endl;
                //    cout << "     Correo: " << adminBuscado->getCorreo() << endl << endl;
                // }
				// else
                //    cout << "\nAdministrador con cedula " << cedulaABuscar << " no encontrado.\n" << endl;
                break;
            }
            
            case 7:
            {
            	int codCiudadABuscar;
                
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

void menuModificar(int opcion, ABBPasillos &arbolPasillos, AVLProPasillo &arbolProPasillo, ABBCiudades &arbolCiudades)
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

				arbolPasillos.modificarPasillo(codPasillo, nombre);
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
            	
            	arbolProPasillo.modificarProducto(codProducto, nombre);
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

            	// listaMarcaProductos.modificarMarcaProducto(codMarca, nombre, cantGondola, precio);
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

            	// listaInventarios.modificarInventario(codInventario, nombre, cantStock, codCanasta);
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
				
				// pnodoCliente clienteEncontrado = hashClientes.buscarCliente(cedulaAModificar);

			    // if (clienteEncontrado == NULL)
			    // {
			    //    cout << "\nCliente no encontrado.\n" << endl;
			    //    break;
			    // }
				
				// if (!listaCiudades.ciudadRepetida(codCiudad))
				// {
				// 	cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
				// 	break;
				// }
                
                // hashClientes.modificarCliente(cedulaAModificar, nombre,	codCiudad, telefono,
				// 	correo, clienteEncontrado);
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
				
				// pnodoAdmin adminEncontrado = hashAdmins.buscarAdmin(cedulaAModificar);

			    // if (adminEncontrado == NULL)
			    // {
			    //    cout << "\nAdministrador no encontrado.\n" << endl;
			    //    break;
			    // }
				
				// if (!listaCiudades.ciudadRepetida(codCiudad))
				// {
				// 	cout << "\nEl codigo de la ciudad no existe. Intente de nuevo.\n" << endl;
				// 	break;
				// }
                
                // hashAdmins.modificarAdmin(cedulaAModificar, nombre, codCiudad, telefono,
				// 	correo, adminEncontrado);
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

void menuListar(int opcion, ABBPasillos &arbolPasillos, AVLProPasillo &arbolProPasillo,
    HashingClientes &hashClientes, HashingAdmins &hashAdmins, ABBCiudades &arbolCiudades)
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
                arbolProPasillo.mostrarProductos(arbolProPasillo.getRaiz(), 0);
                break;

            case 3:
                system(LIMPIAR);
            	cout << "Marcas de Productos:\n" << endl;
                //listaMarcaProductos.Mostrar();
                break;

            case 4:
                system(LIMPIAR);
            	cout << "Inventario:\n" << endl;
                //listaInventarios.Mostrar();
                break;
            
            case 5:
                system(LIMPIAR);
            	cout << "Clientes:\n\n" << hashClientes.mostrarHash();
                break;
            
            case 6:
                system(LIMPIAR);
            	cout << "Administradores:\n\n" << hashAdmins.mostrarHash();
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

void menuMantenimientoBD(int opcion, ABBPasillos &arbolPasillos, AVLProPasillo &arbolProPasillo,
    HashingClientes &hashClientes, HashingAdmins &hashAdmins, ABBCiudades &arbolCiudades)
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
                menuInsertar(opcion, arbolPasillos, arbolProPasillo, arbolCiudades);
				break;

            case 2:
                system(LIMPIAR);
                menuBuscarAdmins(opcion, arbolPasillos, arbolProPasillo, arbolCiudades);
				break;

            case 3:
                system(LIMPIAR);
                menuModificar(opcion, arbolPasillos, arbolProPasillo, arbolCiudades);
				break;

            case 4:
                system(LIMPIAR);
                menuListar(opcion, arbolPasillos, arbolProPasillo, hashClientes, hashAdmins, arbolCiudades);
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

void menuReportes(int opcion, ABBPasillos &arbolPasillos, AVLProPasillo &arbolProPasillo, HashingClientes &hashClientes)
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
                arbolProPasillo.reporteProductosPasillo();
				break;

            case 12:
                system(LIMPIAR);
                hashClientes.reporteClientes();
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
    ABBPasillos arbolPasillos;
    AVLProPasillo arbolProPasillo;
    ABBCiudades arbolCiudades;

    crearArbolPasillos(arbolPasillos);
    crearArbolProPasillo(arbolProPasillo, arbolPasillos);
    crearArbolCiudades(arbolCiudades);
    
    HashingClientes hashClientes(13);
    crearHashingClientes(hashClientes, arbolCiudades);
    HashingAdmins hashAdmins(13);
    crearHashingAdmins(hashAdmins, arbolCiudades);
    
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

                if (hashAdmins.loginAdmin(cedula))
                {
                    system(LIMPIAR);
                    cout << "Bienvenid(@), administrador(@) "
                        << hashAdmins.buscarAdmin(cedula)->getNombre() << endl << endl;

                    do
                    {
                        menuAdiministrador();
                        cout << "\nIngrese la opcion deseada: ";
                        cin >> opcion2;
                
                        switch (opcion2)
                        {
                            case 1: // Mantenimiento de la Base de Datos
                                system(LIMPIAR);
                                menuMantenimientoBD(opcion3, arbolPasillos, arbolProPasillo, hashClientes,
                                    hashAdmins, arbolCiudades);
                                break;
                
                            case 2: // Facturar
                                system(LIMPIAR);
                                break;
                
                            case 3: // Revisar gondolas
                                system(LIMPIAR);
                                break;
                
                            case 4: // Verificar inventario
                                system(LIMPIAR);
                                break;
                
                            case 5: // Reportes
                                system(LIMPIAR);
                                menuReportes(opcion3, arbolPasillos, arbolProPasillo, hashClientes);
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

                    if (hashClientes.loginCliente(cedula))
                    {
                        system(LIMPIAR);
                        cout << "Bienvenid(@), cliente "
                            << hashClientes.buscarCliente(cedula)->getNombre() << endl << endl;

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

