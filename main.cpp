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
    bool entregadoAct; // 0 = sí ha entregado; 1 = no ha entregado;
    int expediente;
    int nivelC; // 0 = piltrafilla; 1 = nivel dios;
    int year;
    int mes;
    string fechaCreacion;
    string horaCreacion;
    string fechaActual;
    alumno *siguiente = NULL;
};

alumno *inicio = NULL;
alumno *final = NULL;
int numeroAlumnos;
ifstream fin("../alumnos.tsv.tsv"); // Declaramos fin como variable de entrada
ofstream fout("../alumnos_resultado.txt"); // Declaramos fout como variable de salida

void Mostrar()
{
    alumno *aux = inicio;
    while (aux != final)
    {
        fout << aux -> horaCreacion << " " << aux -> correo << " " << aux -> nombre << " " << aux -> apellido << " " << aux -> esRepetidor << " " << aux -> expediente << " " << aux -> gitHub << " " << aux -> nivelC << " " << aux -> haPresentado << " " << aux -> entregadoAct << " " << aux -> mes << " " << aux -> year << " " << aux -> estaPresencial << endl;
        aux = aux -> siguiente;
    }
    fout << aux -> horaCreacion << " " << aux -> correo << " " << aux -> nombre << " " << aux -> apellido << " " << aux -> esRepetidor << " " << aux -> expediente << " " << aux -> gitHub << " " << aux -> nivelC << " " << aux -> haPresentado << " " << aux -> entregadoAct << " " << aux -> mes << " " << aux -> year << " " << aux -> estaPresencial << endl;
    fout << endl;
}
void AlumnoMasViejo()
{
    alumno *aux = inicio, *viejo;
    viejo = inicio;
    while (aux != NULL)
    {
        if (aux -> year == viejo -> year)
        {
            if (aux -> mes < viejo -> mes)
            {
                viejo = aux;
            }
        }
        else if (aux -> year < viejo -> mes)
        {
            viejo = aux;
        }
        aux = aux -> siguiente;
    }
    fout << "El alumno mas viejo es " << viejo -> nombre << " " << viejo -> apellido;
    fout << endl << endl;
}
void CumplesEnNoviembre()
{
    alumno *aux = inicio;
    int numeroCumples = 0;
    fout << "Estas son las personas que cumplen en noviembre: " << endl << endl;
    while (aux != NULL)
    {
        if (aux -> mes == 11)
        {
            fout << aux -> nombre << " " << aux -> apellido << endl;
            numeroCumples++;
        }
        aux = aux -> siguiente;
    }
    if (numeroCumples == 1) { fout << "1 alumno cumple este mes" << endl; }
    else { fout << numeroCumples << " alumnos cumplen este mes" << endl; }
    fout << endl;
}
void ExpedientesImpar()
{
    alumno *aux = inicio;
    fout << "Estas son las personas que tienen un numero de expediente impar: " << endl << endl;
    while (aux != NULL)
    {
        if (aux -> expediente % 2 != 0)
        {
            fout << aux -> nombre << " " << aux -> apellido << " -> " << aux -> expediente << endl;
        }
        aux = aux -> siguiente;
    }
    fout << endl;
}
void ExpedientesPar()
{
    alumno *aux = inicio;
    fout << "Estas son las personas que tienen un numero de expediente impar: " << endl << endl;
    while (aux != NULL)
    {
        if (aux -> expediente % 2 == 0)
        {
            fout << aux -> nombre << " " << aux -> apellido << " -> " << aux -> expediente << endl;
        }
        aux = aux -> siguiente;
    }
    fout << endl;
}
void PorcentajeEntregadosA1()
{
    float porcentaje;
    alumno *aux = inicio;

    while (aux != NULL)
    {
        if (aux -> entregadoAct == 0)
        {
            porcentaje++;
        }
        aux = aux -> siguiente;
    }
    porcentaje = (porcentaje * 100) / numeroAlumnos;
    fout << "El " << porcentaje << "% de los alumnos han entregado la actividad 1" << endl << endl;
}
void ListaPresencialidad()
{
    int num = 0;
    alumno *aux = inicio;
    fout << "Estos somos los valientes que acudimos presencialmente: " << endl << endl;
    while (aux != NULL)
    {
        if (aux -> estaPresencial == 0)
        {
            fout << aux -> nombre << " " << aux -> apellido << endl;
            num++;
        }
        aux = aux -> siguiente;
    }
    fout << endl << "Eramos " << num << " en clase" << endl;
    fout << endl << "Estos son los alumnos que se siguieron la clase desde la camita: " << endl << endl;
    aux = inicio;
    num = 0;
    while (aux != NULL)
    {
        if (aux -> estaPresencial == 1)
        {
            fout << aux -> nombre << " " << aux -> apellido << endl;
            num++;
        }
        aux = aux -> siguiente;
    }
    fout << endl << "Eran " << num << " en casa" << endl << endl;
    fout << endl;
}
void LeerArchivo()
{
    alumno *aux;
    int totalUsuarios = 0;

    ofstream fbin("../alumnos_resultado.tsv", ios::out | ios::binary); // Variable binaria
    fin >> aux -> fechaCreacion; // leemos un campo para saber si estamos en fin de archivo
    try
    {
        while(!fin.eof())
        {
            numeroAlumnos++;
            aux = new alumno;
            fin >> aux -> horaCreacion >> aux -> correo >> aux -> nombre >> aux -> apellido >> aux -> esRepetidor
                >> aux -> expediente >> aux -> gitHub >> aux -> nivelC >> aux -> haPresentado >> aux -> entregadoAct
                >> aux -> mes >> aux -> year >> aux -> estaPresencial;

            // fbin.write(reinterpret_cast<const char *>(&nombre), sizeof(string)); // Hacemos cast y escribimos en alumnos_pruebas.tsv
            // fbin.write(reinterpret_cast<const char *>(&expediente), sizeof(string));
            // fbin.write(reinterpret_cast<const char *>(&correo), sizeof(string));
            fin >> aux->fechaCreacion; // Leemos para saber si estamos en fin de archivo

            if (inicio == NULL && final == NULL)
            {
                inicio = aux;
                final = aux;
                aux->siguiente = NULL;
            }
            else
            {
                final -> siguiente = aux;
                final = aux;
            }
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
int main()
{
    numeroAlumnos = 0;
    LeerArchivo();
    Mostrar();
    AlumnoMasViejo();
    CumplesEnNoviembre();
    ExpedientesImpar();
    ExpedientesPar();
    PorcentajeEntregadosA1();
    ListaPresencialidad();
}