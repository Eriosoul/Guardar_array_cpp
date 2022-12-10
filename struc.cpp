#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <fstream>
#include <cctype>
#define FILM 50
using namespace std;

struct estudiantes {
    string nombre;
    string apellido;
    string dni;
    string nota;
};
int n, np;
struct estudiantes aula[FILM];
bool encontrado = false;

void AgregaAlumno();
void ColsultarLista();

void AgregaAlumno(){
    system("cls");
    int i;
    cout << " En caso de que usted disponga de 2 Nombres u 2 Apellidos por favor escribalos con un guion enlazandolos." << endl;
    cout << " Ejemplo Nombre: Ana-Belen Sanchez-Perezado" << endl; 
    string linea, texto;
    string n1, n2, n3, n4;
    cout << "Nombre: ";
    cin >> aula[np].nombre;
    n1 = aula[np].nombre;
    cout << "Apellido: ";
    cin >> aula[np].apellido;
    n2 = aula[np].apellido;
    cout << "Dni: ";
    cin >> aula[np].dni;
    n3 = aula[np].dni;
    cout << "Nota: ";
    cin >> aula[np].nota;
    n4 = aula[np].nota;
    cout << "\n";
    // Metodo de la lectura del fichero y no borrar datos de el 
    ifstream archivo("document.txt");
    while (getline(archivo,linea))
    {
        texto= texto+linea+"\n";
    }
    archivo.close();
    // Metodo de escritrua en ficher
    ofstream archivo2("document.txt"); 
    archivo2 << texto<< n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    np++;
    
}

void ColsultarLista(){
    system("cls");
    int i;
    string linea, texto;
    cout <<"\n";
    // Metodo de recorrer el array, pero resulta inservible ya que leemos directamente las lineas del fichero
    /*
    for (i=0; i<np; i++){
        cout << aula[i].nombre << +" "+ aula[i].apellido << +" "+ aula[i].dni << +" "+ aula[i].nota <<"\n";
    }
    */
    ifstream archivo("document.txt");
    while (getline(archivo,linea))
    {
        texto= texto+linea+"\n";
    }
    archivo.close();
    cout << "Nombre - Apellido - DNI -- Nota" <<endl;
    cout << texto << endl;
}

void mostrarAlumno(ifstream &Lec){
    system("cls");
    Lec.open("document.txt", ios::in);// archivo lectura
    string nom, ape, dni, nota, dnicomprobante;
    bool exist = false;
    cout << "Introduzca el dni para buscar el alumno: ";
    cin >> dnicomprobante;
    Lec>> nom;
    while (!Lec.eof()&& !exist) // mientras nuestra lectura tenga algo y exista la
    {
        Lec >>ape;
        Lec >> dni;
        Lec >> nota;
        if (dni == dnicomprobante)
        {
            cout << "Nombre ----: " << nom << endl;
            cout << "Apellido --: " << ape << endl;
            cout << "Dni -------: " << dni << endl;
            cout << "Nota ------: " << nota << endl;
            exist = true;
        }
        Lec >> nom;
    }
    Lec.close();
    if (!exist)
    {
        cout << "Dato inexistente" << endl;
    }
    
}

void modificar(ifstream &Lec) // pasamos el fichero pro referencia
{
    system("cls");
    string nom, ape, dni, nota, notacambiar, dnicomprobante;
    Lec.open("document.txt", ios::in);// el in es para indicar que es de lectura
    ofstream aux("soporte.txt", ios::out);// escribiremos en el
    if (Lec.is_open())
    {
        cout << "Introduzca el DNI del alumo: ";
        cin >> dnicomprobante;
        Lec>> nom;
        while (!Lec.eof())// eof es end of file
        {  
            Lec >> ape;
            Lec >> dni;
            Lec >> nota;
            if (dni == dnicomprobante)
            {
                cout << "Nueva nota ----: ";
                cin >> notacambiar;
                aux << nom << " " << ape << " " << dni << " "<< notacambiar<< "\n";
                cout << " Datos guardados" << endl;
            }else{
                aux << nom << " " << ape << " " << dni << " "<< nota<< "\n";
            }
            Lec >> nom;
        }
        Lec.close();
        aux.close();
    }else
        cout << "ERROR No se encontro el fichero" << endl;
    remove("document.txt");
    rename("soporte.txt", "document.txt");    
}

int main ()
{
    ifstream Lec;
    int menu;
    do
    {
        cout << "1. Agregar alumno." <<"\n";
	    cout << "2. Consultar listado de alumnos." <<"\n";
	    cout << "3. Mostrar un alumno." <<"\n";
        cout << "4. Modificar datos del alumno."<<"\n\n";
        cout <<" Teclea para la opcion deseada: "; cin>>menu;
        cout << "\n";
        switch (menu)
        {
        case 1:
            AgregaAlumno();
            break;
        
        case 2:
            ColsultarLista();
            break;
        case 3:
            mostrarAlumno(Lec);
            break;
        case 4:
            modificar(Lec);
            break;
        default:
            break;
        }
    } while (menu!=5);
      
    return 0;
}