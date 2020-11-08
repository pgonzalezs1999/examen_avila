#include <iostream>
#include <fstream>
using namespace std;

struct alumno
{
    string nombre;
    string apellido;
    string correo;
    string gitHub;
    bool esRepetidor; // 0 = repetidor; 1 = nuevo alumno;
    bool estaPresencial; // 0 = presencial; 1 = online
    bool haPresentado; // 0 = ya ha expuesto; 1 = pendiente de exponer;
    bool entregadoActividad; // 0 = sí ha entregado; 1 = no ha entregado;
    int expediente;
    int nivelC; // 0 = piltrafilla; 1 = nivel dios;
    int yearNacimiento;
    int mesNacimiento;
    string fechaCreacion;
    string horaCreacion;
    alumno *siguiente = NULL;
};

alumno *inicio = NULL;
alumno *final = NULL;

void Mostrar()
{
    alumno *aux = inicio;
    if (inicio == NULL)
    {
        cout << endl << "Su lista esta vacia." << endl;
    }
    else
    {
        cout << endl << "Su lista es: ";
        cout << aux -> nombre;
        aux = aux -> siguiente;

        while (aux != inicio)
        {
            cout << " -> " << aux -> nombre;
            aux = aux -> siguiente;
        }
        cout << endl;
    }
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

    int totalUsuarios = 0;
    string fechaActual;
    alumno *aux = new alumno;

    ifstream fin("../alumnos.tsv"); // Declaramos fin como variable de entrada
    ofstream fout("../alumnos_pruebas.txt"); // Declaramos fout como variable de salida
    ofstream fbin("../alumnos_pruebas.tsv", ios::out | ios::binary); // Variable binaria
    fin >> aux -> fechaCreacion; // leemos un campo para saber si estamos en fin de archivo
    try
    {
        while(!fin.eof())
        {

            fin >> aux -> horaCreacion >> aux -> correo >> aux -> nombre >> aux -> apellido >>
            aux -> esRepetidor >> aux -> expediente >> aux -> gitHub >> aux -> nivelC >>aux -> haPresentado >>
            aux -> entregadoActividad >> aux -> mesNacimiento >> aux -> yearNacimiento >> aux -> estaPresencial;

            if (inicio == NULL) { inicio = aux; }
            if (final == NULL) { final == aux; }
            else
            {
                final -> siguiente = aux;
                final = aux;
            }

            //cout << "ACEPTADO: " << nombre << ", con renta " << renta << " y nota "
                 //<< nota << endl; // Imprimimos los aceptados
            fout << aux -> nombre << " " << aux -> expediente << " " << aux -> estaPresencial << endl;
            // Hacemos cast y escribimos en alumnos_pruebas.tsv
            fbin.write(reinterpret_cast<const char *>(&aux->nombre), sizeof(string));
            fbin.write(reinterpret_cast<const char *>(&aux->expediente), sizeof(string));
            fbin.write(reinterpret_cast<const char *>(&aux->correo), sizeof(string));

            cout << "Llego hasta aqui" << endl;
            totalUsuarios++;
            fin >> aux -> fechaCreacion; // Leemos para saber si estamos en fin de archivo
        }

        Mostrar();

    } // Cerramos archivos de texto y binarios
    catch(...) // Captura todas las excepciones posibles
    {
        fbin.close();
        fin.close();
        fout.close();
        cout<< "FIN DE ARCHIVO / Se ha generado el archivo binario de aceptados" << endl;
    }
}