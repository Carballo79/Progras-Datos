#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <unordered_set>
#include <windows.h>
#include <sstream>

using namespace std;

//Marck Mora Sebastian Ceciliano 

string BuscarCedulaArchivo(string valorBuscado) {
    ifstream archivo("Clientes.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo Clientes.txt" << endl;
        return "";
    }

    string linea;
    while (getline(archivo, linea)) {
        string valorLinea = linea.substr(0, linea.find(';'));
        if (valorLinea == valorBuscado) {
            archivo.close();
            return linea;
        }
    }

    archivo.close();
    cout << "No se encontrÃ³ el valor " << valorBuscado << " en el archivo." << endl;
    return "";
}



//ARBOL BINARIO DE BUSQUEDA
struct Nodo {
    string codigo;
    Nodo* izquierdo;
    Nodo* derecho;
};

class ArbolBinario {

public:
    Nodo* raiz;
    ArbolBinario() : raiz(nullptr) {}

    Nodo* crearNodo(string codigoIngreso) {
        Nodo* nuevo_nodo = new Nodo();
        if (!nuevo_nodo) {
            cout << "Error al crear un nuevo nodo" << endl;
            return nullptr;
        }
        nuevo_nodo->codigo = codigoIngreso;
        nuevo_nodo->izquierdo = nuevo_nodo->derecho = nullptr;
        return nuevo_nodo;
    }

    void insertar(string codigoIngreso) {
        raiz = insertar(raiz, codigoIngreso);
    }

    void ingresarIndice() {
        ifstream archivo("Indices.txt");
        if (!archivo) {
            cout << "No se pudo abrir el archivo Indices.txt" << endl;
            return;
        }

        string linea;
        while (getline(archivo, linea)) {
            insertar(linea);
        }

        archivo.close();
    }

    bool buscar(int valorBuscado) {
        return buscar(raiz, valorBuscado);
    }
    string buscarIndiceR(int valorBuscado) {
        return buscarIndiceR(raiz, valorBuscado);
    }


    void PreordenR(Nodo* R)
    {
        if (R == NULL)
        {
            return;
        }
        else
        {
            cout << R->codigo << "->";
            PreordenR(R->izquierdo);
            PreordenR(R->derecho);
        }
    }

    ~ArbolBinario() {
        destruirArbol(raiz);
        raiz = NULL;
    }

    void EliminarNodo(int valor) {
        raiz = EliminarNodoRecursivo(raiz, valor);
    }

private:
    Nodo* EliminarNodoRecursivo(Nodo* nodo, int valor) {
        if (nodo == NULL) {
            return NULL;
        }

        if (valor < stoi(nodo->codigo.substr(nodo->codigo.find(';') + 1))) {
            nodo->izquierdo = EliminarNodoRecursivo(nodo->izquierdo, valor);
        }
        else if (valor > stoi(nodo->codigo.substr(nodo->codigo.find(';') + 1))) {
            nodo->derecho = EliminarNodoRecursivo(nodo->derecho, valor);
        }
        else { // Encontramos el nodo a eliminar
            if (nodo->izquierdo == NULL) {
                Nodo* temp = nodo->derecho;
                delete nodo;
                return temp;
            }
            else if (nodo->derecho == NULL) {
                Nodo* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }

            // Nodo con dos hijos, obtener su sucesor inmediato
            Nodo* sucesor = ObtenerSucesor(nodo->derecho);
            nodo->codigo = sucesor->codigo;
            nodo->derecho = EliminarNodoRecursivo(nodo->derecho, stoi(sucesor->codigo.substr(sucesor->codigo.find(';') + 1)));
        }
        return nodo;
    }

    Nodo* ObtenerSucesor(Nodo* nodo) {
        Nodo* actual = nodo;
        while (actual && actual->izquierdo != NULL) {
            actual = actual->izquierdo;
        }
        return actual;
    }




    Nodo* insertar(Nodo* nodo, string codigoIngreso) {
        if (nodo == NULL) {
            return crearNodo(codigoIngreso);
        }

        int nodo_val = stoi(nodo->codigo.substr(nodo->codigo.find(';') + 1));
        int nuevo_val = stoi(codigoIngreso.substr(codigoIngreso.find(';') + 1));

        if (nuevo_val < nodo_val) {
            nodo->izquierdo = insertar(nodo->izquierdo, codigoIngreso);
        }
        else if (nuevo_val > nodo_val) {
            nodo->derecho = insertar(nodo->derecho, codigoIngreso);
        }
        else {
            cout << "El valor ya existe en el Arbol." << endl;
        }

        return nodo;
    }

    bool buscar(Nodo* nodo, int valorBuscado) {
        if (nodo == nullptr) {
            return false;
        }

        int valorNodo = stoi(nodo->codigo.substr(nodo->codigo.find(';') + 1));

        if (valorBuscado == valorNodo) {
            return true;
        }
        else if (valorBuscado < valorNodo) {
            return buscar(nodo->izquierdo, valorBuscado);
        }
        else {
            return buscar(nodo->derecho, valorBuscado);
        }
    }
    string buscarIndiceR(Nodo* nodo, int valorBuscado) {
        if (nodo == nullptr) {
            return "";
        }

        int valorNodo = stoi(nodo->codigo.substr(nodo->codigo.find(';') + 1));

        if (valorBuscado == valorNodo) {
            return nodo->codigo.substr(0, nodo->codigo.find(';'));
        }
        else if (valorBuscado < valorNodo) {
            return buscarIndiceR(nodo->izquierdo, valorBuscado);
        }
        else {
            return buscarIndiceR(nodo->derecho, valorBuscado);
        }
    }

    void destruirArbol(Nodo* nodo) {
        if (nodo != NULL) {
            destruirArbol(nodo->izquierdo);
            destruirArbol(nodo->derecho);
            delete nodo;
        }
    }

};


class nodo { // Constructores
public:


    nodo(string v)//6  nodo(string)  nodo(int x
    {
        valor = v;
        siguiente = NULL;
    }

    nodo(string v, nodo* signodo)    // nodo(nodo *signodo,int v)
    {
        valor = v;
        siguiente = signodo;
    }


private:
    string valor = " ";
    nodo* siguiente;// Clase Autoreferencia


    friend class Lista;
    friend class ArbolBinario;
};

typedef nodo* pnodo; //Alias  


class Lista {
public:
    Lista() { primero = NULL; }//constructor
    ~Lista();//destructor

    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void BorrarInicio();
    void BorrarFinal();
    void BorrarDeLista(string codigo);
    string Retornar();
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BusquedaEnCache(Lista& Indices, string indice,ArbolBinario& arbol);
    void BusquedaEnCacheBorrado(Lista& Indices, string indice);
    bool BuscarIndice(string indice);
    void CargarNuevosIndices(Lista& Indices, string indice,ArbolBinario& arbol);
    int largoLista();

private:
    pnodo primero;

};

Lista::~Lista()
{
    nodo* aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

int Lista::largoLista() {
    int cont = 0;

    pnodo aux = primero;
    if (ListaVacia()) {
        return cont;
    }
    else {
        while (aux != NULL) {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
        cout << endl;
    }

}

void Lista::InsertarInicio(string v){
    if (ListaVacia()){

        primero = new nodo(v);
    }
    else{
        pnodo nuevo = new nodo(v);
        nuevo->siguiente = primero;
        primero = nuevo;
    }
}

void Lista::InsertarFinal(string v)
{
    if (ListaVacia())
        primero = new nodo(v);
    else
    {
        pnodo aux = primero;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        pnodo nuevo = new nodo(v);
        aux->siguiente = nuevo;
    }
}

void Lista::Mostrar() {
    pnodo aux = primero;
    if (primero == NULL) {
        cout << "No hay elementos en cache " << endl << endl;
    }
    else {
        aux = primero;
        while (aux)
        {
            size_t pos_punto_y_coma = aux->valor.find(';');
            string Indice = aux->valor.substr(0, pos_punto_y_coma);
            string Cedula = aux->valor.substr(pos_punto_y_coma + 1);
            string CedulaArchivo = BuscarCedulaArchivo(Cedula);
            cout << Indice << " | " << CedulaArchivo << endl;
            /*if (!(CedulaArchivo.find(";1") != string::npos)) {
                cout << Indice << " | " << CedulaArchivo << endl;
            }
            else {
                cout << " " << endl;
            }
            */
            aux = aux->siguiente;
            
        }
        cout << endl;
    }
}

bool Lista::BuscarIndice(string indice) {
    pnodo aux = primero;
    if (ListaVacia()) {
        return false;
    }
    else {
        while (aux != NULL) {
            size_t pos_punto_y_coma = aux->valor.find(';');
            string primer_valor = aux->valor.substr(0, pos_punto_y_coma);
            if (primer_valor == indice) {
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }
}


string Lista::Retornar() {
    pnodo aux = primero;
    if (ListaVacia()) {
        return "";
    }
    else {
        while (aux != NULL) {
              return aux->valor;
        }
        return "";
    }

}


void Lista::BorrarInicio() {
    if (ListaVacia()) {
        cout << "Sin Pasillos" << endl;
    }
    else {
        if (primero->siguiente == NULL) {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else {
            pnodo aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}

void Lista::BorrarFinal() {
    if (ListaVacia()) {
        cout << "Sin Pasillos" << endl;
    }
    else {
        if (primero->siguiente == NULL) {
            pnodo temp = primero;
            primero = NULL;
            delete temp;;
        }
        else {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;
            }
            pnodo temp = aux->siguiente;
            aux->siguiente = NULL;
            delete temp;
        }
    }
}

void Lista::BorrarDeLista(string codigo) {
    if (ListaVacia()) {
        cout << "Sin elementos" << endl;
        return;
    }
    pnodo aux = primero;
    int pos = 1;
    bool bandera = false;
    while (aux != NULL) {
        size_t pos_punto_y_coma = aux->valor.find(';');
        string valor_pasillo = aux->valor.substr(0,pos_punto_y_coma);
        if (valor_pasillo == codigo) {
            bandera = true;
            break;
        }
        aux = aux->siguiente;
        pos++;
    }
    if (!bandera) {
        cout << "No se encontro " << endl;
        return;
    }
    if (pos == 1) {
        BorrarInicio();
    }
    else {
        if (pos == largoLista()) {
            BorrarFinal();
        }
        else {
            int cont = 2;
            pnodo aux = primero;
            while (cont < pos) {
                aux = aux->siguiente;
                cont++;
            }
            pnodo temp = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;
            delete temp;
        }
    }
}

void Lista::CargarNuevosIndices(Lista& Indices, string indice,ArbolBinario& arbol) {
    ifstream archivo("Indices.txt"); // Abre el archivo para lectura
    string linea;
    bool encontrado = false;
    bool esUltimaLinea = false;
    while (getline(archivo, linea)) {
        size_t pos_punto_y_coma = linea.find(';');
        string primer_valor = linea.substr(0, pos_punto_y_coma);
        if (primer_valor == indice) {
            size_t pos_punto_y_coma = linea.find(';');
            string valorcedula = linea.substr(pos_punto_y_coma + 1);
            string cliente = BuscarCedulaArchivo(valorcedula);
            if ((cliente.find(";1") == string::npos)) {
                Indices.InsertarFinal(linea);
            }
            encontrado = true;
            if (archivo.peek() == EOF) { // Si la siguiente lectura alcanza el final del archivo
                esUltimaLinea = true;

            }
        }
        if (esUltimaLinea) {
            cout << "Ultimo indice buscado ->  Procedimiento Circular:"<<endl;
            ifstream archivo("Indices.txt");
            for (int i = 0; i < 19; i++) {
                if (getline(archivo, linea)) {
                    size_t pos_punto_y_coma = linea.find(';');
                    string valorcedula = linea.substr(pos_punto_y_coma + 1);
                    string cliente = BuscarCedulaArchivo(valorcedula);
                    if ((cliente.find(";1") == string::npos)) {
                        Indices.InsertarFinal(linea);
                    }else {
                      i--;
                     }

                }
                else {
                    cout << "No es el ultimo pero no alcanzo a rellenar los 20 campos" << endl << endl;
                    archivo.close();
                    break; // Salir del bucle si no se puede leer mÃ¡s lÃ­neas
                }
            }
            break;
        }
        else {
            if (encontrado) {
                for (int i = 0; i < 19; i++) {
                    if (getline(archivo, linea)) {
                        size_t pos_punto_y_coma = linea.find(';');
                        string valorcedula = linea.substr(pos_punto_y_coma + 1);
                        string cliente = BuscarCedulaArchivo(valorcedula);
                        if ((cliente.find(";1") == string::npos)) {
                            Indices.InsertarFinal(linea);
                        }
                        else {
                            i--;
                        }
                    }
                    else {
                        ///Si hay que hacer circular aunque no sea el ultimo modificar aca.
                        cout << "No es el ultimo pero no alcanzo a rellenar los 20 campos" << endl << endl;
                        archivo.close();
                        break; // Salir del bucle si no se puede leer mÃ¡s lÃ­neas
                    }
                }
                archivo.close();
                break;
            }
        }

    }
    archivo.close();
}
void Lista::BusquedaEnCache(Lista& Indices, string indice,ArbolBinario& arbol) {
    bool IndiceEncontrado;
    if (ListaVacia()) {
        cout << "La memoria cache esta limpia" << endl<< endl;
        cout << "Recargando la memoria..." << endl<< endl;
        Sleep(2000);
        Indices.CargarNuevosIndices(Indices, indice, arbol);
        Indices.Mostrar();
    }
    else {
        Indices.Mostrar();
        IndiceEncontrado = BuscarIndice(indice);
        if (IndiceEncontrado) {
            cout << "Se a encontrado el indice en la memoria cache(SIN CAMBIOS)" << endl;
        }
        else {
            cout << "No se a encontrado el indice en la memoria cache" << endl;
            cout << "Recargando la memoria..." << endl << endl;
            Indices.~Lista();
            Sleep(2000);
            Indices.CargarNuevosIndices(Indices, indice, arbol);
            Indices.Mostrar();
        }
    }
}



void Lista::BusquedaEnCacheBorrado(Lista& Indices, string indice) {
    bool IndiceEncontrado;
    if (ListaVacia()) {
        cout << "La memoria cache esta limpia" << endl << endl;
    }
    else {
        Indices.Mostrar();
        IndiceEncontrado = BuscarIndice(indice);
        if (IndiceEncontrado) {
            cout << "Se a encontrado el indice en la memoria cache(ELIMINANDO DE LA CACHE)" << endl;
            Indices.BorrarDeLista(indice);
            Indices.Mostrar();
        }
        else {
            cout << "No se a encontrado el indice en la memoria cache" << endl;
            cout << "NO SE REALIZAN CAMBIOS EN LA CACHE" << endl << endl;
            Indices.Mostrar();
        }
    }
}


//FUNCIONES APARTE
void crearIndice() {
    ifstream file("Clientes.txt");
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo Clientes.txt" << endl;
        return;
    }

    ofstream indices("Indices.txt");
    string line;
    int index = 1;

    while (getline(file, line)) {
        size_t pos = line.find(";");
        string codigo = line.substr(0, pos);

        indices << index << ";" << codigo << endl;
        index++;
    }

    file.close();
    indices.close();
}

void limpiarArchivo() {
    ifstream file("Clientes.txt");
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo clientes.txt" << endl;
        return;
    }

    ofstream temp("temp.txt");
    unordered_set<string> codigos;
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(";");
        string codigo = line.substr(0, pos);

        if (codigos.find(codigo) == codigos.end()) {
            temp << line << endl;
            codigos.insert(codigo);
        }
    }

    file.close();
    temp.close();

    remove("Clientes.txt");
    rename("temp.txt", "Clientes.txt");
}

void buscarYModificarCodigo(string nombreArchivo,string codigoBuscado) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    ofstream archivoTemp("temp.txt");
    if (!archivoTemp) {
        cout << "No se pudo crear el archivo temporal" << endl;
        archivo.close();
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(';');
        if (pos != string::npos && linea.substr(0, pos) == codigoBuscado) {
            archivoTemp << linea << ";1" << endl;
        }
        else {
            archivoTemp << linea << endl;
        }
    }

    archivo.close();
    archivoTemp.close();

    // Eliminar el archivo original
    remove(nombreArchivo.c_str());
    // Renombrar el archivo temporal al nombre original
    rename("temp.txt", nombreArchivo.c_str());
}


void Purgar(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    ofstream archivoTemp("temp.txt");
    if (!archivoTemp) {
        cout << "No se pudo crear el archivo temporal" << endl;
        archivo.close();
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        // Verificar si la línea termina con ";1"
        if (linea.size() >= 2 && linea.substr(linea.size() - 2) == ";1") {
            continue; // Saltar esta línea
        }
        archivoTemp << linea << endl;
    }

    archivo.close();
    archivoTemp.close();

    // Eliminar el archivo original
    remove(nombreArchivo.c_str());
    // Renombrar el archivo temporal al nombre original
    rename("temp.txt", nombreArchivo.c_str());
}

void AgregarLineaAlFinal(string linea,string destino) {
    ofstream archivo(destino, ios_base::app); // Abrir el archivo en modo de agregar al final
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    archivo << linea << endl; // Escribir la línea al final del archivo
    archivo.close(); // Cerrar el archivo
}

string ObtenerUltimaLinea(string destino) {
    ifstream archivo(destino);
    string ultimaLinea;

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return ultimaLinea; // Devolver cadena vacía en caso de error
    }

    string linea;
    while (std::getline(archivo, linea)) {
        ultimaLinea = linea; // Almacenar la línea actual
    }

    archivo.close();
    return ultimaLinea;
}


void InsertarListaInversa(string destino,Lista& ListaInversa) {
    ifstream archivo(destino);

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    string linea;
    while (std::getline(archivo, linea)) {
        ListaInversa.InsertarInicio(linea);
    }

    archivo.close();
    return;
}

void menuBusqueda(ArbolBinario& arbol, Lista& Indices) {
    string dataIngreso;
    arbol.PreordenR(arbol.raiz);
    cout << endl << endl;
    cout << "Ingrese el numero de cedula a buscar: ";
    cin >> dataIngreso;
    stringstream ss(dataIngreso);
    int cedula;
    if (ss >> cedula && ss.eof()) {
        bool encontrado = arbol.buscar(cedula);
        if (encontrado) {
            cout << "La cedula " << cedula << " se encuentra en el arbol." << endl<<endl;
            string indice = arbol.buscarIndiceR(cedula);
            Indices.BusquedaEnCache(Indices, indice, arbol);
        }
        else {
            cout << "La cedula " << cedula << " no se encuentra en el arbol." << endl<<endl;
        }
    }
    else {
        cout << "Por favor, ingrese un numero valido." << endl;
        menuBusqueda(arbol, Indices);
    }
    cout << "----------------" << endl << endl;
    int opcion;
    cout << "Desea buscar otra cedula? (1.SI/2.NO)?: ";
    cin >> opcion;
    if (opcion == 1) {
        menuBusqueda(arbol, Indices);
    }
    else if (opcion == 2) {
        cout << "Regresando..." << endl;
        Sleep(2000);
        return;
    }
    else {
        cout << "Opcion no valida." << endl;
        menuBusqueda(arbol, Indices);
    }
}

void menuIngreso(ArbolBinario& arbol, Lista& Indices, Lista& ListaInversa) {
    string nombreIngreso,indice,dataMemoria;
    int dataIngreso,largo,contador;
    arbol.PreordenR(arbol.raiz);
    cout << endl << endl;
    cout << "Ingrese el numero de cedula a ingresar: ";
    cin >> dataIngreso;
    cout << "Ingrese el nombre a ingresar: ";
    cin >> nombreIngreso;

    bool encontrado = arbol.buscar(dataIngreso);
    string cliente = to_string(dataIngreso) + ";" + nombreIngreso;
    if (!encontrado) {
        cout << "Agregando a Clientes.txt"<<endl;
        Sleep(1000);
        AgregarLineaAlFinal(cliente,"Clientes.txt");

        cout << "Agregando a Indice.txt"<<endl;
        Sleep(1000);
        crearIndice();
        indice = ObtenerUltimaLinea("Indices.txt");

        cout << "Agregando al arbol" << endl;
        Sleep(1000);
        arbol.insertar(indice);

        arbol.PreordenR(arbol.raiz);
        cout << endl << endl;

        cout << "Modificando la memoria cache" << endl;
        Sleep(1000);
        InsertarListaInversa("Indices.txt", ListaInversa);
        cout << "Memoria Anterior:" << endl << endl;
        Indices.Mostrar();
        Indices.~Lista();
        largo = ListaInversa.largoLista();

        if (largo > 20) {
            contador = 20;
        }else{
            contador = largo;
        }
        while (contador != 0) {
            dataMemoria = ListaInversa.Retornar();
            ListaInversa.BorrarInicio();
            Indices.InsertarInicio(dataMemoria);
            contador = contador - 1;
        }
        ListaInversa.~Lista();
        cout << "Memoria Nueva:" << endl << endl;
        Indices.Mostrar();

    }
    else {
        cout << "La cedula " << dataIngreso << " ya esta registrada" << endl << endl;
    }
    cout << "----------------" << endl << endl;
    int opcion;
    cout << "Desea ingresar otro cliente(1.SI/2.NO)?: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
        menuIngreso(arbol, Indices, ListaInversa);
        break;
    case 2:
        cout << "Regresando..." << endl;
        Sleep(2000);
        return;
    default:
        cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        return;
    }
}



void menuEliminar(ArbolBinario& arbol, Lista& Indices, Lista& ListaInversa) {
    string nombreIngreso, indice, dataMemoria,nuevadata;
    int dataIngreso, largo, contador;
    arbol.PreordenR(arbol.raiz);
    cout << endl << endl;
    Indices.Mostrar();
    cout << "Ingrese el numero de cedula a eliminar: ";
    cin >> dataIngreso;

    bool encontrado = arbol.buscar(dataIngreso);
    if (encontrado) {
        indice = arbol.buscarIndiceR(dataIngreso);
        arbol.EliminarNodo(dataIngreso);
        if (dataIngreso < 10) {
            nuevadata = "0" + to_string(dataIngreso);
        }
        else {
            nuevadata = to_string(dataIngreso);
        }
        buscarYModificarCodigo("Clientes.txt", nuevadata);
        arbol.PreordenR(arbol.raiz);
        cout << endl << endl;
        Indices.BusquedaEnCacheBorrado(Indices, indice);

    }
    else {
        cout << "La cedula " << dataIngreso << " no esta en el arbol" << endl << endl;
    }
    cout << "----------------" << endl << endl;
    int opcion;
    cout << "Desea eliminar otro cliente(1.SI/2.NO)?: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
        menuEliminar(arbol, Indices, ListaInversa);
        break;
    case 2:
        cout << "Regresando..." << endl;
        Sleep(2000);
        return;
    default:
        cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        return;
    }
}

void imprimirMenuPrincipal() {
    system("cls");
    cout << "\n------T3------ \n";
    cout << "1. Busqueda\n";
    cout << "2. Ingresar\n";
    cout << "3. Eliminar\n";
    cout << "4. Purgar\n";
    cout << "5. Reindexar\n";
    cout << "6. Arbol\n";
    cout << "7. Memoria Cache\n";
    cout << "0. Salir\n";
    cout << "Ingrese su opcion: ";
}

int main() {

    ArbolBinario arbol;
    Lista Indices,ListaInversa;
    int opcion;
    limpiarArchivo();
    cout << "Limpiando Archivo Clientes..." << endl;
    Sleep(1000);
    crearIndice();
    cout << "Creando archivo Indices.txt..." << endl;
    Sleep(1000);
    arbol.ingresarIndice();
    cout << "Ingresando datos al arbol..." << endl;
    Sleep(1000);
    cout << "Datos Ingresados correctamente" << endl;
    cout << "Ingresando al menu...." << endl;
    Sleep(1000);
    system("cls");

    do {
        imprimirMenuPrincipal();
        cin >> opcion;
        switch (opcion) {
        case 1:
            menuBusqueda(arbol, Indices);
            break;
        case 2:
            menuIngreso(arbol, Indices,ListaInversa);
            break;
        case 3:
            menuEliminar(arbol, Indices, ListaInversa);
            break;
        case 4:
            cout << "Arbol Binario Busqueda: " << endl << endl;
            arbol.PreordenR(arbol.raiz);
            Sleep(4000);
            cout << endl << endl;
            cout << "Memoria Cache: " << endl << endl;
            Indices.Mostrar();
            Sleep(4000);
            Purgar("Clientes.txt");
            cout << "Transfiriendo Datos No Borrados..." << endl;
            Sleep(2000);
            cout << "Purgado con exito";
            Sleep(2000);
            break;
        case 5:

            cout << "Arbol viejo: " << endl << endl;
            arbol.PreordenR(arbol.raiz);
            cout << endl << endl;
            arbol.~ArbolBinario();
            crearIndice();
            arbol.ingresarIndice();

            cout << "Arbol nuevo: " << endl << endl;
            arbol.PreordenR(arbol.raiz);
            cout << endl << endl;
            Sleep(4000);

            cout << "Memoria Cache: " << endl << endl;
            Indices.Mostrar();
            cout << "Reidexado con exito " << endl;
            Sleep(4000);
            break;
        case 6:
            cout << "Arbol Binario Busqueda: " << endl << endl;
            arbol.PreordenR(arbol.raiz);
            Sleep(4000);
            break;
        case 7:
            cout << "Memoria Cache: " << endl << endl;
            Indices.Mostrar();
            Sleep(4000);
            break;

        default:
            cout << "FIN.\n";
            break;
            }
    } while (opcion != 0);
    return 0;
}
