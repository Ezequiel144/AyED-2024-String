#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char nombre[9] = "Ezequiel";
    char copyChar[] = "";
    int length = strlen(nombre);

    char cadena1[20] = "Hola me ";
    char cadena2[10] = "llamo eze";

    char comparate1[] = "1";
    char comparate2[] = "ADIOS";

    cout << "Longitud de la cadena(strlen): " << length << endl;
    /* Copia de cadenas de char */
    strcpy(copyChar, nombre);
    cout << "Cadena copiada(strcpy): " << copyChar << endl;
    /* Concatena 2 cadenas dando el resultado de una sola */
    strcat(cadena1, cadena2);
    cout << "Concatenacion de 2 cadenas(strcat): " << cadena1 << endl;
    /* comparacion de 2 cadenas */
    int value = strcmp(comparate1, comparate2);
    cout << "Comparacion: " << endl;
    cout << "comparacion 1 -> " << comparate1 << endl;
    cout << "comparacion 2 -> " << comparate2 << endl;
    if (value > 0)
    {
        cout << "Cadena 1 es mayor a cadena 2" << endl;
    }
    else if (value < 0)
    {
        cout << "Cadena 1 es menor a cadena 2" << endl;
    }
    else
    {
        cout << "Son iguales" << endl;
    }

    string text;
    cout << "Escribir algo de texto getline(): " << endl;
    getline(cin,text);
    cout << text << endl;

    char text2[] = "";
    cout << "Escribir algun texto para el cin.getline(): " << endl;
    cin.getline(text2,50);
    cout << text2;
    return 0;
}