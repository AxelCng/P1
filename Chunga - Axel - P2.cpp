//Problema 2

#include <iostream>
#include <conio.h>
using namespace std;

struct alumno{
    char nombre[50];
    int nota[8];
    int falta;
}alumnos[8];

int main() {
    int numero, total_faltas = 0;
    float porcentaje_faltas, promedio_general = 0;
    float promedio_asignatura[8] ={0}; 
    float promedio_a[8] = {0};  
    cout << "Ingrese el numero de alumnos: ";
    cin >> numero;
    cout<<endl;
    while (numero <= 0) {
        cout << "El numero de alumnos no es valido." << endl;
        cout << "Ingrese el numero de alumnos: ";
        cin >> numero;
    }
    for (int i = 0; i < numero; i++) {
        fflush(stdin);
        cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
        cin.ignore();
        cin.getline(alumnos[i].nombre, 20);
        int suma_notas = 0, total_faltas_alumno = 0;
        for (int j = 0; j < 8; j++) {
            cout << "Ingrese la nota del curso " << j + 1 << ": ";
            cin >> alumnos[i].nota[j];
            while (alumnos[i].nota[j] < 0 || alumnos[i].nota[j] > 20) {
                cout << "La nota ingresada no es valida." << endl;
                cout << "Ingrese la nota del curso " << j + 1 << ": ";
                cin >> alumnos[i].nota[j];
            }
            if (alumnos[i].nota[j] == 0) {
                total_faltas_alumno++;
            }
            suma_notas += alumnos[i].nota[j];
            promedio_asignatura[j] += alumnos[i].nota[j];
        }
        alumnos[i].falta = total_faltas_alumno;
        promedio_a[i] = suma_notas / 8;
        promedio_general += promedio_a[i];
        total_faltas += total_faltas_alumno;
    }
    promedio_general /= numero;
    for (int i = 0; i < 8; i++) {
        promedio_asignatura[i] /= numero;
    }
    cout << "\nPromedio general de la clase: " << promedio_general << endl;
    cout<<endl;
	for (int i = 0; i<8; i++) {
        cout << "Promedio de la asignatura " << i + 1 << ": " << promedio_asignatura[i] << endl;
    }
    for (int i = 0; i<numero; i++) {
        porcentaje_faltas = (float(alumnos[i].falta) * 100) / 8;
        cout << "\nEl porcentaje de faltas del alumno " <<i+1<< " es: " << porcentaje_faltas << "%" << endl;
    }
    getch();
    return 0;
}

