#include <iostream>
#include <fstream>
using namespace std;

void Mostrar(string horaCreacion, string correo, string nombre, string apellido, bool esRepetidor, int expediente, string gitHub, int nivelC, bool haPresentado, bool entregadoAct, int mesNacimiento, int yearNacimiento, bool estaPresencial)
{
    //ofstream fout("../alumnos_resultado.txt"); // Declaramos fout como variable de salida
    cout << horaCreacion << correo << nombre << apellido << esRepetidor << expediente << gitHub <<
         nivelC << haPresentado << entregadoAct << mesNacimiento << yearNacimiento << estaPresencial;
}
void AlumnoMasViejo()
{

}
void CumplesEnNoviembre()
{

}
void ExpedientesImpar()
{

}
void ExpedientesPar()
{

}
void PorcentajeEntregadosA1()
{

}
void ListaPresencialidad()
{

}
int main()
{
    string nombre;
    string apellido;
    string correo;
    string gitHub;
    bool esRepetidor; // 0 = repetidor; 1 = nuevo alumno;
    bool estaPresencial; // 0 = presencial; 1 = online
    bool haPresentado; // 0 = ya ha expuesto; 1 = pendiente de exponer;
    bool entregadoAct; // 0 = sí ha entregado; 1 = no ha entregado;
    int expediente;
    int nivelC; // 0 = piltrafilla; 1 = nivel dios;
    int yearNacimiento;
    int mesNacimiento;
    string fechaCreacion;
    string horaCreacion;
    int totalUsuarios = 0;
    string fechaActual;

    ifstream fin("../alumnos.tsv"); // Declaramos fin como variable de entrada
    ofstream fout("../alumnos_resultado.txt"); // Declaramos fout como variable de salida
    ofstream fbin("../alumnos_resultado.tsv", ios::out | ios::binary); // Variable binaria
    fin >> fechaCreacion; // leemos un campo para saber si estamos en fin de archivo
    try
    {
        while(!fin.eof())
        {
            fin >> horaCreacion >> correo >> nombre >> apellido >> esRepetidor >> expediente >> gitHub >>
            nivelC >> haPresentado >> entregadoAct >> mesNacimiento >> yearNacimiento >> estaPresencial;

            Mostrar(horaCreacion, correo, nombre, apellido, esRepetidor, expediente, gitHub, nivelC, haPresentado, entregadoAct, mesNacimiento, yearNacimiento, estaPresencial);

            // fbin.write(reinterpret_cast<const char *>(&nombre), sizeof(string)); // Hacemos cast y escribimos en alumnos_pruebas.tsv
            // fbin.write(reinterpret_cast<const char *>(&expediente), sizeof(string));
            // fbin.write(reinterpret_cast<const char *>(&correo), sizeof(string));
            fin >> fechaCreacion; // Leemos para saber si estamos en fin de archivo
        }
    } // Cerramos archivos de texto y binarios
    catch(...) // Captura todas las excepciones posibles
    {
        fbin.close();
        fin.close();
        fout.close();
        cout<< "FIN DE ARCHIVO / Se ha generado el archivo binario de aceptados" << endl;
    }
}