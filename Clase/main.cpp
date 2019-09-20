#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
using unint = unsigned int;



enum Mes{
    enero, febrero, marzo, abril, mayo, junio, agosto, julio, septiembre, diciembre, noviembre, octubre
};

struct Fecha{
 int dia;
 int mes;
 int anyo;

 Fecha (int d, int m, int a){
     dia = d; mes = m; anyo = a;
 }


};

void escribirFecha(Fecha fecha){
    cout << fecha.dia
         << "/" << fecha.mes
         << "/" << fecha.anyo<<endl;
}
int main() {

    Fecha f1 = {1,2,3120}; // Lo guarda en la pila
    Fecha* f2 = new Fecha(1,3, 1920); //Lo guarda en el heap, en la pila está el puntero


    escribirFecha(*f2); //como es un puntero hay que poner el * para mandar la fecha en sí, no el puntero f2

    escribirFecha(f1);  //aqui se puede pasar directamente f1 porque incluye la fecha en sí, no un puntero

    delete f2; //Hay que borrar la memoria dinamica creada (Heap)
    f2 = nullptr; //Y liberar el puntero f2, que ahora lleva a una zona del heap que está borrada




    /////


    int datos[5] = {1,2,3,4,5}; //El array estatico es de tamaño  consante. No se comprueba si el indice es valido

    int datoss[5] {1,2,3,4,5}; //lo mismo

    int dato[] {1,2,3,4,5}; // lo mismo

    int datosnulos[5] = {}; //{0,0,0,0,0}

    int datosnulo[5] {}; // lo mismo

    int datosprimeros[5] = {1,2}; //{1,2,0,0,0}

    int cosa[] {};



    // LOS ARRAYS NO SE PUEDEN ASIGNAR

    int unos[]{1,2,3};
    int dos[3];

    // dos = unos; daria error, paso de parametros es por referencia

    int myarray[3] {10,20,30};
    for (int i = 0; i < 3; ++i)    ++myarray[i];
    for (int elem : myarray)   // int elem : myarray -->  range based loop -- para cada elemento (elem) de la secuencia (myarray)
        cout << elem << '\n';  // si quieres modificar el valor de elem dentro del bucle sería for (int &elem : myarray) es decir, pasado por referencia

    // se puede usar (y está bien usado)
    //
    //#include <array>
    array<int,3> myarraay {10,20,30};
    for (int i = 0; i < myarraay.size(); ++i)   ++myarray[i];
    for (int elem : myarray)    cout << elem << '\n';



    //Arrays multidimensionales

    int multidim[2][3][5];

    const int NUMFILAS = 50;
    const int NUMCOLS = 100;

    using Matriz = double[NUMFILAS][NUMCOLS];

    // o
    //typedef double Matriz[NUMFILAS][NUMCOLS];

    int cuads[5][2] = {1,1, 2,4, 3,9, 4,16};

    //Sort

    //sort(myarraay, myarraay + myarraay.size());
    //for (int elem : myarraay)    cout << elem << '\n';


    //tipo cstring horroroso
    char hola[8] = "hola";
    char adios[] = {'a', 'd', 'i', 'o', 's', '\0'};

    //Usar tipo string
    string holaa = "hola";
    string adioss = "a dio s";




    //ifstream file; // Flujo de entrada
    //string filename = "datos.txt";
    //file.open(filename.c_str()); // Apertura de fichero




    // Se puede ordenar un string utilizando
    string s = "hola";
    string b = "ahlo";
    sort(s.begin(), s.end());
    sort(b.begin(), b.end());



    cout << s <<endl;
    cout << b <<endl;

    if (s == b) cout << "igual" <<endl;



    int ap = 5;
    int* point = nullptr;

    point = &ap;
    cout << point <<endl;
    cout<< *point <<endl;

    int* p; *p =12;

    int* punt1; int* punt2;
    if (punt1 == punt2); //si apunta al mismo sitio
    if (*punt1 == *punt2); //si a lo que apunta cada uno tiene el mismo valor, aunque apunten a sitios distintos
    return 0;




}