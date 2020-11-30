#include <iostream>
#include <fstream>
using namespace std;

struct municipio
{
    int codigo;
    string nombre;
    float poblacion;
    float altitud;
    float superficie;
    municipio *siguiente;
};

municipio *inicio = NULL;
municipio *final = NULL;
ifstream fin("../examen.tsv"); // Declaramos fin como variable de entrada
ofstream fout("../examen_resultado.txt"); // Declaramos fout como variable de salida

int LeerArchivo()
{
    int numMunicipios = 0;
    municipio *aux = new municipio;

    fin >> aux -> codigo; // leemos un campo para saber si estamos en fin de archivo

    try
    {
        while(!fin.eof())
        {
            aux = new municipio;

            fin >> aux -> nombre >> aux -> poblacion >> aux -> altitud >> aux -> superficie;
            numMunicipios++;

            fin >> aux -> codigo; // Leemos para saber si estamos en fin de archivo

            if (inicio == NULL && final == NULL)
            {
                inicio = aux;
                final = aux;
                aux -> siguiente = NULL;
            }
            else
            {
                final -> siguiente = aux;
                final = aux;
            }
        }
    } // Cerramos archivos de texto y binarios
    catch(...) // Captura todas las excepciones
    {
        fin.close();
        fout.close();
        cout << "FIN DE ARCHIVO / Se ha generado el archivo binario de aceptados" << endl;
    }
    fout << "Pregunta 1: Hay " << numMunicipios << " municipios en Avila" << endl;
}

void Mostrar()
{
    municipio *aux = inicio;
    while (aux != final)
    {
        fout << aux -> codigo << " " << aux -> nombre << " " << aux -> poblacion << " " << aux -> altitud << " " << aux -> superficie << endl;
        aux = aux -> siguiente;
    }
    fout << aux -> codigo << " " << aux -> nombre << " " << aux -> poblacion << " " << aux -> altitud << " " << aux -> superficie << endl;

    fout << endl;
}
void AlturaMedia()
{
    int alturaTotal = 0, numMunicipios = 0;
    municipio *aux = inicio;

    while(aux != final)
    {
        alturaTotal += aux -> altitud;
        numMunicipios++;
        aux = aux -> siguiente;
    }
    alturaTotal += aux -> altitud;
    numMunicipios++;
    fout << "Pregunta 2: La altura promedio es " << alturaTotal/numMunicipios << " metros" << endl << endl;
}
void Comparaciones()
{
    municipio *aux = new municipio;
    aux = inicio;
    string masAlto, menosAlto, masDenso, menosDenso, masPoblado, menosPoblado;

    int altMin = inicio -> altitud, altMax = inicio -> altitud;
    float densidadMax = aux -> poblacion / aux -> superficie;
    float densidadMin = aux -> poblacion / aux -> superficie;
    int pobMin = inicio -> poblacion, pobMax = inicio -> poblacion;

    while(aux != final)
    {
        if (aux -> altitud <= altMin)
        {
            altMin = aux -> altitud;
            menosAlto = aux -> nombre;
        }
        else if (aux -> altitud >= altMax)
        {
            altMax = aux -> altitud;
            masAlto = aux -> nombre;
        }
        if (aux -> poblacion / aux -> superficie >= densidadMax)
        {
            densidadMax = aux -> poblacion / aux -> superficie;
            masDenso = aux -> nombre;
        }
        else if (aux -> poblacion / aux -> superficie <= densidadMin)
        {
            densidadMin = aux -> poblacion / aux -> superficie;
            menosDenso = aux -> nombre;
        }
        if (aux -> poblacion <= pobMin)
        {
            menosPoblado = aux -> nombre;
            pobMin = aux -> poblacion;
        }
        else if (aux -> poblacion >= pobMax)
        {
            masPoblado = aux -> nombre;
            pobMax = aux -> poblacion;
        }
        aux = aux -> siguiente;
    }
    if (aux -> altitud <= altMin)
    {
        altMin = aux -> altitud;
        menosAlto = aux -> nombre;
    }
    else if (aux -> altitud >= altMax)
    {
        altMax = aux -> altitud;
        masAlto = aux -> nombre;
    }
    if (aux -> poblacion / aux -> superficie >= densidadMax)
    {
        densidadMax = aux -> poblacion / aux -> superficie;
        masDenso = aux -> nombre;
    }
    else if (aux -> poblacion / aux -> superficie <= densidadMin)
    {
        densidadMin = aux -> poblacion / aux -> superficie;
        menosDenso = aux -> nombre;
    }
    if (aux -> poblacion <= pobMin)
    {
        menosPoblado = aux -> nombre;
        pobMin = aux -> poblacion;
    }
    else if (aux -> poblacion >= pobMax)
    {
        masPoblado = aux -> nombre;
        pobMax = aux -> poblacion;
    }

    fout << "Pregunta 3: El municipio a mayor altitud es " << masAlto << ", a " << altMax << " metros" << endl << endl;
    fout << "Pregunta 4: El municipio a menor altitud es " << menosAlto <<  ", a " << altMin << " metros" << endl << endl;
    fout << "Pregunta 5: El municipio mas poblado es " << masPoblado << ", con " << pobMax << " habitantes" << endl << endl;
    fout << "Pregunta 6: El municipio menos poblado es " << menosPoblado << ", con " << pobMin << " habitantes" << endl << endl;
    fout << "Pregunta 7: El municipio mas denso es " << masDenso <<  ", con una densidad de " << densidadMax << endl << endl;
    fout << "Pregunta 8: El municipio menos denso es " << menosDenso <<  ", con una densidad de " << densidadMin << endl << endl;
}
void VecesPobMadrid()
{
    municipio *aux = inicio;
    float pobMadrid = 6507184, pobAvila = 0;
    while(aux != final)
    {
        pobAvila += aux -> poblacion;
        aux = aux -> siguiente;
    }
    pobAvila += aux -> poblacion;
    fout << "Pregunta 9: La poblacion de Madrid es " << pobMadrid / pobAvila  << " veces la de Avila" << endl << endl;
}
void CarentaHabs900m()
{
    fout << "Pregunta 10: A continuacion una lista con los municipios a mas de 900m con mas de 40 habitantes:" << endl;

    municipio *aux = inicio;
    int i = 1;
    while(aux != final && i <= 10)
    {
        if(aux -> poblacion > 40)
        {
            if (aux -> altitud > 900)
            {
                fout << i << ". " << aux -> nombre << " (" << aux -> poblacion << " habitantes, " << aux -> altitud << "m)" << endl;
                i++;
            }
        }
        aux = aux -> siguiente;
    }
}

int main()
{
    LeerArchivo();
    //Mostrar();
    AlturaMedia();
    Comparaciones();
    VecesPobMadrid();
    CarentaHabs900m();
}
/*1. Cuantos municipios hay
 * 2. Altura promedio
 * 3. municipio mas alto
 * 4. municipio mas bajo
 * 5. municipio menos poblado
 * 6. municipio mas poblado
 * 7. municipio mas denso
 * 8. municipio menos denso
 * 9. Cuantas veces supera la Comunidad de Madrid a la Provincia de Avila
 * 10. imprimir los 10 municipios con mas de 40 habs y a mas de 900m altura*/