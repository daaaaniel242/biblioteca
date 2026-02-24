#include <iostream>
//Se incluye para poder nombrarlo solamente con std
using namespace std;

//Plantilla para listas genéricas
template<typename T>

class Lista{
    private:
        T elementos [50];
        int posicion;
    public:
        Lista() : posicion(0) {}
    //Metodo Añadir elemento
    void agregar(T elemento){
            if (posicion < 50){
                elementos[posicion] = elemento;
                posicion++;
            }else
            {
                std::cout<<"La lista está completa, no se puede añadir nada más"<<std::endl;
            }
        }
        //Sacar elemento de la lista
        void eliminar(T elemento){
            for (int i = 0; i < posicion; i++)
            {
                if (elementos[i] == elemento){
                    for (int k = i; k < posicion - 1; k++)
                    {
                        elementos[k] = elementos[k + 1];
                    }
                    posicion--;
                }
            }
        }
        //Obtener elemento por índice
        T& obtener(int indice)
        {
            if (indice >= 0 && indice < posicion)
            {
                return elementos[indice];
            }
            return elementos[0];
        }
        //Tamaño de la lista
        int tamano()
        {
            return posicion;
        }
        //Ver si está vacía la lista
        bool vacia()
        {
            return posicion == 0;
        }
        //Limpiar la lista
        void limpiar()
        {
            posicion = 0;
        }
        //Buscar elemento
        bool contiene(T& elemento){
            for (int i = 0; i < posicion; i++){
                if (elementos[i] == elemento){
                    return true;
                }
            }
            return false;
        }
        //Mostrar todos los elementos
        void mostrar()
        {
            for (int i = 0; i < posicion; i++)
            {
                cout << elementos[i] << endl;
            }
            cout << endl;
        }
};
    class Libro{
        private:
            //Declaramos las variables de la clase
            int id;
            string titulo;
            string autor;
            string categoria;
            bool disponible;
            string usuarioActual;
        public:
            // Constructor por defecto con valores vacios
            Libro() : id(0), titulo(""), autor(""), categoria(""), disponible(true), usuarioActual("") {}

            // Constructor con parámetros
            Libro(int id, string titulo, string autor, string categoria)
                : id(id), titulo(titulo), autor(autor), categoria(categoria),
                  disponible(true), usuarioActual("") {}
            // Getters
            int getId() const{return id;}
            string getTitulo() const{return titulo;}
            string getAutor() const{return autor;}
            string getCategoria() const{return categoria;}
            bool getDisponible() const{return disponible;}
            string getUsuarioActual() const{return usuarioActual;}

            //Comprobar si esta disponible
            bool estaDisponible() {
                return disponible;
            }

            // Prestar libro (asignar libro a una persona)
            void prestar(string dni) {
                disponible = false;
                usuarioActual = dni;
            }

            // Devolver libro (desasignar libro a una persona)
            void devolver() {
                disponible = true;
                usuarioActual = "";
            }
            //Metodo para mostrar información
            void mostrarInfo()
            {
                cout << "->Titulo: " <<titulo <<" || Autor: " << autor << " || Categoria: " <<categoria<<" || Disponible"<< disponible << endl;
                if (!disponible) {
                    cout<<"No está disponible el usuario: "<<usuarioActual <<"tiene el libro"<<endl;
                }
            }
    };
    class Usuario {
        private:
            //Declaramos las variables de la clase
            string nombre;
            string apellidos;
            string dni;
            Lista<string> librosActuales;
            Lista<string> historialdeLibros;
        public:
            // Constructor por defecto con valores vacios
            Usuario() : nombre(""), apellidos(""), dni("") {}
            // Constructor con parámetros
            Usuario(string nombre, string apellidos, string dni)
                : nombre(nombre), apellidos(apellidos), dni(dni) {}
            // Getters
            string getNombre() const { return nombre; }
            string getApellido() const { return apellidos; }
            string getDNI() const { return dni; }

            //Metodo sacarLibro
            void sacarLibro(string tituloLibro) {
                librosActuales.agregar(tituloLibro);
            }
            //Metodo devolverLibro
            void devolverLibro(string tituloLibro) {
                librosActuales.eliminar(tituloLibro);
                // Solo se añade al historial si no estaba ya
                if (!historialdeLibros.contiene(tituloLibro))
                    historialdeLibros.agregar(tituloLibro);
            }
            //Metodo mostrarLibrosActuales del usuario
            void mostrarLibrosActuales() {
                cout << "LIBROS ACTUALES DE: " << nombre << " " << apellidos << endl;
                if (librosActuales.vacia()) {
                    cout << "  No tiene libros" << endl;
                } else {
                    for (int i = 0; i < librosActuales.tamano(); i++)
                        cout << "  - " << librosActuales.obtener(i) << endl;
                }
            }
            //Metodo mostrarHistorial de libros de un usuario
            void mostrarHistorial() {
                cout << "HISTORIAL DE LIBROS DE: " << nombre << " " << apellidos << endl;
                if (historialdeLibros.vacia()) {
                    cout << "  No ha devuelto ningun libro" << endl;
                } else {
                    for (int i = 0; i < historialdeLibros.tamano(); i++)
                        cout << "  - " << historialdeLibros.obtener(i) << endl;
                }
            }
            //Metodo tiene libro , booleana si tiene , no tiene
            bool tieneLibro(string tituloLibro) {
                return librosActuales.contiene(tituloLibro);
            }

    };

    //FUNCIONES PRINCIPALES DE LA BIBLIOTECA

    //Función para inicializar los libros
    void inicializarLibro(Lista<Libro>& libros)
    {
        //Libros de acción
        libros.agregar(Libro(1,"El codigo Da Vinci","Dan Brown","Accion"));
        libros.agregar(Libro(2,"La chica del tren","Paula Hawkins","Accion"));
        libros.agregar(Libro(3,"Inferno","Dan Brown","Accion"));
        libros.agregar(Libro(4,"El juego de Ender","Orson Scott Card","Accion"));
        //Libros de aventuras
        libros.agregar(Libro(5,"El hobbit","J.R.R. Tolkien","Aventuras"));
        libros.agregar(Libro(6,"La isla del tesoro","R.L. Stevenson","Aventuras"));
        libros.agregar(Libro(7,"Las aventuras de Tom Sawyer","Mark Twain","Aventuras"));
        libros.agregar(Libro(8,"Viaje al centro de la Tierra","Julio Verne","Aventuras"));
        //Libros de drama
        libros.agregar(Libro(9,"Cien anos de soledad","Garcia Marquez","Drama"));
        libros.agregar(Libro(10,"La casa de los espiritus","Isabel Allende","Drama"));
        libros.agregar(Libro(11,"Crimen y castigo","Dostoyevski","Drama"));
        libros.agregar(Libro(12,"Los miserables","Victor Hugo","Drama"));
        //Libros de comedia
        libros.agregar(Libro(13,"El diario de Bridget Jones","Helen Fielding","Comedia"));
        libros.agregar(Libro(14,"Tres hombres en un bote","Jerome K. Jerome","Comedia"));
        libros.agregar(Libro(15,"La tia Julia y el escribidor","Mario Vargas Llosa","Comedia"));
        libros.agregar(Libro(16,"Historias de cronopios","Julio Cortazar","Comedia"));
        //Libros de romanticismo
        libros.agregar(Libro(17,"Orgullo y prejuicio","Jane Austen","Romanticismo"));
        libros.agregar(Libro(18,"Cumbres borrascosas","Emily Bronte","Romanticismo"));
        libros.agregar(Libro(19,"Jane Eyre","Charlotte Bronte","Romanticismo"));
        libros.agregar(Libro(20,"Romeo y Julieta","Shakespeare","Romanticismo"));
    }
    //Función para inicializar los usuarios
    void inicializarUsuarios(Lista<Usuario>& usuarios)
    {
        usuarios.agregar(Usuario("Daniel","Gonzalez Garrote","12345632A"));
        usuarios.agregar(Usuario("Gerardo","Dieguez Serpa","12348732X"));
        usuarios.agregar(Usuario("Laura","Flores Lalueta","12345321B"));
        usuarios.agregar(Usuario("Domingo","Garcia Mendez","12752632P"));
        usuarios.agregar(Usuario("Paco","Gonzalez Sanz","12345632A"));
        usuarios.agregar(Usuario("Maria","Gutierrez Labrador","12345632A"));
    }
    //Función 1: Mostrar libros disponibles
    void mostrarLibrosDisponibles(Lista<Libro>& libros)
    {
        cout << "---Libros disponibles---" << endl;
        bool disponible = false;
        string categoriaActual = "";
        //Recorremos todos los libros
        for ( int i = 0; i<libros.tamano(); i++)
        {
            //Comprobamos si está disponible
            if (libros.obtener(i).getDisponible())
            {
                //Si está disponible, y la categoria es distinta entonces mostramos la actual
                if (libros.obtener(i).getCategoria() != categoriaActual)
                {
                    categoriaActual = libros.obtener(i).getCategoria();
                    cout << "\n ----" << categoriaActual << "----" <<  endl;
                }
                libros.obtener(i).mostrarInfo();
                disponible = true;
            }
        }
        //Si no está disponible
        if (!disponible)
        {
            cout << "Libros no disponibles" << endl;
        }
    }
    //Función para mostrar todos los libros
    void mostrarTodosLosLibros(Lista<Libro>& libros)
    {
        cout << "---Libros disponibles---" << endl;
        string categoriaAct = "";
        //Recorremos los libros y actualiza la categoria actual de los libros
        for (int i = 0; i<libros.tamano(); i++)
        {
            //Si la categoria actual es distinta, se muestra la actual
            if (libros.obtener(i).getCategoria() != categoriaAct)
            {
                categoriaAct = libros.obtener(i).getCategoria();
                cout << "---La categoria actual es:" << categoriaAct << "---" <<endl;

            }
            //Mostramos la información del libro
            libros.obtener(i).mostrarInfo();
        }
    }
    //Función 2: Historial de un usuario
    void historialUsuario(Lista<Usuario>& usuarios)
    {
        //Declaramos las variables que vamos a usar en el metodo
        string dni;
        cout << "---Escribe el dni del usuario---" << endl;
        //Recogemos el dato escrito por el usuario
        cin >> dni;
        //Declaramos una valiable a -1
        int indice = -1;
        //Bucle para recorrer la lista de libros desde la posición 0
        for ( int i = 0; i<usuarios.tamano(); i++)
        {
            //Si el DNI de la posicion i , es igual al dni que queremos
            if (usuarios.obtener(i).getDNI() == dni)
            {
                indice = i;
                break;
            }
        }
        if (indice == -1)
        {
            cout << "No hemos encontrado ningun usuario con ese DNI" << endl;
            return;
        }
        //Mostramos los libros actuales del usuario y mostramos el historial
        usuarios.obtener(indice).mostrarLibrosActuales();
        usuarios.obtener(indice).mostrarHistorial();
    }
    //Función 3: Ver si una persona tiene un libro
    void verificarLibroEnUsuario(Lista<Libro>& libros,Lista<Usuario>& usuarios)
    {
        //Declaramos las variables que vamos a usar en el metodo
        string dni;
        string tituloLibro;
        cout << "---Escribe el dni del usuario---" << endl;
        cin >> dni;
        cin.ignore();//Lo ponemos para quitar carácteres no deseados, y aseguramos que se lea bien
        cout << "---Escribe el titulo del libro--" << endl;
        getline(cin, tituloLibro);//Se utila para que podamos leer los espacios en blanco
        //Iniciamos en -1 , que será para indicar que no se ha encontrado
        int indiceUsuario = -1;
        //Bucle para recorrer la lista de libros desde la posición 0
        for ( int i = 0; i<usuarios.tamano(); i++)
        {
            //Si el DNI de la posicion i , es igual al dni que queremos
            if (usuarios.obtener(i).getDNI() == dni)
            {
                indiceUsuario = i;
                break;
            }
        }
        //Iniciamos en -1 , que será para indicar que no se ha encontrado
        int indiceLibro = -1;
        //Bucle para recorrer la lista de libros desde la posición 0
        for ( int i = 0; i<libros.tamano(); i++)
        {
            //Si el título de la posicion i , es igual al titulo que queremos
            if (libros.obtener(i).getTitulo() == tituloLibro)
            {
                indiceLibro = i;
                break;
            }
        }
        //Comprobamos si es información no existe
        if (indiceUsuario == -1){ cout << "---El usuario no se ha encontrado--" << endl; return;}
        if (indiceLibro == -1){cout << "---El libro no se ha encontrado--" << endl; return;}
        if (!libros.obtener(indiceLibro).getDisponible())
        {
            cout << "---El libro no se ha encontrado--" << endl;
            return;
        }
        //Comprobamos si es información existe
        if (usuarios.obtener(indiceUsuario).tieneLibro(tituloLibro))
        {
            cout << usuarios.obtener(indiceUsuario).getNombre() << " si tiene el libro: " << tituloLibro << endl;
        }else
        {
            cout << usuarios.obtener(indiceUsuario).getNombre() << " no tiene el libro: " << tituloLibro << endl;
        }
    }

    //Función 4: Sacar libros
    void sacarLibro(Lista<Libro>& libros,Lista<Usuario>& usuarios)
    {
        //Declaramos las variables que vamos a usar en el metodo
        string dni;
        string tituloLibro;
        cout << "---Escribe el dni del usuario---" << endl;
        cin >> dni;
        cin.ignore();//Lo ponemos para quitar carácteres no deseados, y aseguramos que se lea bien
        cout << "---Escribe el titulo del libro--" << endl;
        getline(cin, tituloLibro);//Se utila para que podamos leer los espacios en blanco
        //Iniciamos en -1 , que será para indicar que no se ha encontrado
        int indiceUsuario = -1;
        //Bucle para recorrer la lista de usuarios desde la posición 0
        for ( int i = 0; i<usuarios.tamano(); i++)
        {
            //Si el DNI de la posicion i , es igual al dni que queremos
            if (usuarios.obtener(i).getDNI() == dni)
            {
                indiceUsuario = i;
                break;
            }
        }
        //Iniciamos en -1 , que será para indicar que no se ha encontrado
        int indiceLibro = -1;
        //Bucle para recorrer la lista de libros desde la posición 0
        for ( int i = 0; i<libros.tamano(); i++)
        {
            //Si el título de la posicion i , es igual al titulo que queremos
            if (libros.obtener(i).getTitulo() == tituloLibro)
            {
                indiceLibro = i;
                break;
            }
        }
        //Comprobamos si es información no existe
        if (indiceUsuario == -1){ cout << "---El usuario no se ha encontrado--" << endl; return;}
        if (indiceLibro == -1){cout << "---El libro no se ha encontrado--" << endl; return;}
        if (!libros.obtener(indiceLibro).getDisponible())
        {
            cout << "---El libro no se ha encontrado--" << endl;
            return;
        }
        //Obtenemos el libro en la posición indiceLibro
        libros.obtener(indiceLibro).prestar(dni);
        //Obtenemos el libro en la posición indiceUsuario
        usuarios.obtener(indiceUsuario).sacarLibro(tituloLibro);

        cout << "---SE HA SACADO EL LIBRO--" << endl;
        cout << "El usuario: " << usuarios.obtener(indiceUsuario).getNombre() <<
            "se ha llevado el libro "<< libros.obtener(indiceLibro).getTitulo()<< endl;

    }

    //Función 5: Devolver libros , se tiene que mostrar en hostorial
    void devolverLibro(Lista<Libro>& libros, Lista<Usuario>& usuarios)
    {
        //Declaramos las variables que vamos a usar en el metodo
        string dni;
        string tituloLibro;
        cout << "---Escribe el dni del usuario---" << endl;
        //Recogemos la información que nos proporciona el usuario
        cin >> dni;
        cin.ignore(); // Lo ponemos para quitar carácteres no deseados, y aseguramos que se lea bien
        cout << "---Escribe el titulo del libro--" << endl;
        getline(cin, tituloLibro);//Se utila para que podamos leer los espacios en blanco

        //Iniciamos en -1 , que será para indicar que no se ha encontrado
        int indiceUsuario = -1;
        //Bucle para recorrer la lista de usuarios desde la posición 0
        for ( int i = 0; i<usuarios.tamano(); i++)
        {
            //Si el DNI de la posicion i , es igual al dni que queremos
            if (usuarios.obtener(i).getDNI() == dni)
            {
                indiceUsuario = i;
                break;
            }
        }
        //Iniciamos en -1 , que será para indicar que no se ha encontrado
        int indiceLibro = -1;
        //Bucle para recorrer la lista de libros desde la posición 0
        for ( int i = 0; i<libros.tamano(); i++)
        {
            //Si el título de la posicion i , es igual al titulo que queremos
            if (libros.obtener(i).getTitulo() == tituloLibro)
            {
                indiceLibro = i;
                break;
            }
        }
        //Comprobamos si es información no existe
        if (indiceUsuario == -1){ cout << "---El usuario no se ha encontrado--" << endl; return;}
        if (indiceLibro == -1){cout << "---El libro no se ha encontrado--" << endl; return;}
        if (!usuarios.obtener(indiceUsuario).tieneLibro(tituloLibro))
        {
            cout << "---El usuario no tiene ese libro--" << endl;
            return;
        }
        //Obtenemos el libro en la posición indiceLibro e indicamos el metodo devolver
        libros.obtener(indiceLibro).devolver();
        //Obtenemos el libro en la posición indiceUsuario y devolvemos el libro con el titulo
        usuarios.obtener(indiceUsuario).devolverLibro(tituloLibro);

        cout << "---SE HA DEVUELTO EL LIBRO--" << endl;
        cout << "El usuario: " << usuarios.obtener(indiceUsuario).getNombre() <<
            "ha devuelto el libro "<< libros.obtener(indiceLibro).getTitulo()<< endl;

    }

    //Función para mostrar el menú por pantalla
    void inicioMenu()
    {
        cout << "------MENU DE GESTION DE BIBLIOTECA-------" << endl;
        cout << "||| 1. Mostrar libros disponibles       |||" << endl;
        cout << "||| 2. Historial de un usuario          |||" << endl;
        cout << "||| 3. Ver si una persona tiene un libro|||" << endl;
        cout << "||| 4. Sacar un libro                   |||" << endl;
        cout << "||| 5. Devolver un libro                |||" << endl;
        cout << "||| 0. Salir                            |||" << endl;
        cout << "------------------------------------------" << endl;
    }


int main(){
    //Iniciamos las dos listas de Libros y Usuarios
    Lista<Libro> libros;
    Lista<Usuario> usuarios;
    //Cargamos los libros y los usuarios, que hemos creado
    inicializarLibro(libros);
    inicializarUsuarios(usuarios);
    //Creamos menú, creamos variable opción
    int opcion;
    do
    {
        //Inicializamos el menú,llamando a la función inicioMenu()
        inicioMenu();
        cin >> opcion;
        switch (opcion)
        {
            //Primer caso: llamamos a la primera funcion ( mostrarLibrosDisponibles )
            case 1:
                mostrarLibrosDisponibles(libros);
            break;
            //Segundo caso: llamamos a la primera funcion (  historialUsuario )
            case 2:
                historialUsuario(usuarios);
            break;
            //Tercer caso: llamamos a la primera funcion ( verificarLibroEnUsuario )
            case 3:
                verificarLibroEnUsuario(libros,usuarios);
            break;
            //Cuarto caso: llamamos a la primera funcion (  sacarLibro )
            case 4:
                sacarLibro(libros,usuarios);
            break;
            //Quinto caso: llamamos a la primera funcion ( devolverLibro )
            case 5:
                devolverLibro(libros,usuarios);
            break;
            //Si pulsa 0,saldrá del bucle
            case 0:
                cout<<"Saliendo de la biblioteca, HASTA OTRO DIA DE LECTURA !" << endl;
            break;
            //Si se pulsa otra opción que no existe, se muestra el siguiente mensaje
            default:
                cout<<"La opción que has escogido, no es válida, prueba otra vez"<<endl;
        }
     //Mientras sea distinto de 0 el bucle continua
    }while(opcion != 0);

    return 0;
}