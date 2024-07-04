# AyED-2024-String

AyED-2024-String

## Cadenas de caracteres (Strings) para lenguaje C

El lenguaje C, a diferencia de otros lenguajes, hace un manejo muy particular de las variables para

almacenar texto. Un texto no es más que una sucesión de caracteres. Una variable del tipo char

permite almacenar un único carácter, por lo tanto, para almacenar un texto se debe definir un

vector de caracteres con tantas posiciones como letras pueda tener el texto que se quiere

almacenar.

> Entonces, en un principio se podría decir que una variable del tipo string o cadena de caracteres, no es más que un vector de char

### Ejemplo

Si se quiere ingresar un nombre, no se sabe exactamente el largo del mismo por lo
tanto se define un vector con una cantidad suficiente de acuerdo al nombre más largo que se quiera guardar.

```char
char nombre[20]; 
```

Declara un vector de char de **20 posiciones**. Si en dicho vector se almacena un nombre corto, por ejemplo **“JUAN”**, dicho nombre solo ocupará 4 de los 20 caracteres, y por lo tanto, luego de la letra N se debe poner el carácter de fin de cadena indicando hasta donde llega dicho nombre

![](file://C:\Users\Ezequiel\AppData\Roaming\marktext\images\2024-07-04-12-30-49-image.png?msec=1720107049836)

## Inicialización de Strings

Al declarar la memoria del string es posible asignar un valor, para ello se le asigna una constante del tipo string que se escribe entre comillas. El carácter de fin de cadena se agrega automáticamente luego de la última letra.

```char
char nombre[20] = “ANA MARIA”;
```

![](file://C:\Users\Ezequiel\AppData\Roaming\marktext\images\2024-07-04-12-32-21-image.png?msec=1720107141905)

```
char nombre[] = “ANA MARIA”;
```

![](file://C:\Users\Ezequiel\AppData\Roaming\marktext\images\2024-07-04-12-33-37-image.png?msec=1720107217591)

Si no se especifica el tamaño automáticamente reserva la memoria mínima suficiente para almacenar el texto y el carácter de fin de cadena.

> Cuidado!! Si se le pone un tamaño al vector y se le asignan más
> caracteres de los definidos NO guardará el \0, y por lo tanto, ya
> no puede tratarse como un string ya que la función para mostrar
> no encontrará el fin de cadena

```char
char nombre[3] = “MARCELO”;
```

![](file://C:\Users\Ezequiel\AppData\Roaming\marktext\images\2024-07-04-12-35-51-image.png?msec=1720107351078)

## Biblioteca para el manejo de texto (string.h)

Debido a que los string son vectores con un carácter especial que indica el final de la cadena hay ciertas cosas como copiar uno a otro, comparar, etc que NO se pueden hacer directamente ya que no son un tipo de dato en sí mismos

### Dentro de string.h hay muchas funciones, veremos algunas de ellas:

| Funcion | Que hace cada uno |
| --- | --- |
| strlen | Determina la longitud de una cadena |
| strcpy | Copia una cadena a otra |
| strcat | Concatena dos cadenas dejando el resultado en la primera |
| strcmp | Compara dos cadenas |
| strcmpi | Compara dos cadenas ignorando si son mayúsculas o minúsculas |

**Función strlen:**

Determina la longitud de una cadena, sin contabilizar el carácter nulo de terminación de la misma.
Sintaxis: strlen (cadena)
La función retorna un entero indicando la cantidad de caracteres

**Función strcpy:**

Copia desde una cadena de origen hacia una cadena de destino.Sintaxis: strcpy (cadena destino, cadena origen) Ejemplo:

```char
char original [15], copia [15];
….
strcpy (copia, original);
```

También strcpy se puede usar para asignar una constante a un string cuando no se hace al Ejemplo:

```char
char texto [25];
strcpy(texto, "MENSAJE");
```

**Función strcat:**

Concatena (añade) una cadena detrás de otras quedando el resultado en la cadena que se encuentra en primer orden.
Sintaxis: strcat (cadena receptora, cadena a añadir)

```char
char receptor [40] = "Se agrego lo siguiente", dador [] =", me agregue";
strcat (receptor, dador);
```

Es importante asegurarse de que la cadena receptora tenga el espacio suficiente para guardar la cadena a añadir caso contrario sobrescribe memoria no asignada

**Función strcmp:**

Esta función compara dos cadenas y devuelve el resultado de la comparación.
Sintaxis: strcmp (cadena 1, cadena 2)
El valor que devuelve que será el resultado de la comparación es el siguiente:

| Condicion | Resultado |
| --- | --- |
| Si las cadenas son iguales | devolverá un cero (0) |
| Si la cadena 1 es mayor que la cadena 2 | devolverá un valor positivo |
| Si la cadena 1 es menor que la cadena 2 | devolverá un valor negativo |

Ejemplo:

```char
char cadena1[30], cadena2[30];
…
if (strcmp (cadena1, cadena2) == 0)
printf ("\nAmbas cadenas son iguales " );
else
if (strcmp (cadena1, cadena2) > 0 )
printf ("\nLa cadena1 es mayor que la cadena2");
else
printf ("\nLa cadena2 es mayor que la cadena1");
```

La comparación NO es por largo sino alfabética, comparando el peso en valor ASCII de cada una de las letras, posición a posición, hasta encontrar alguna diferencia. Hay que recordar que el ASCII de las minúsculas es mayor que el de las mayúsculas, por lo tanto, una palabra en minúsculas será mayor que una en mayúscula. A continuación se muestran algunos ejemplos:

| Cadena1 | Cadena2 | Mayor / iguales |
| --- | --- | --- |
| HOLA | HOLA | IGUALES |
| Hola | hola | Cadena2 |
| hola mundo | hola | Cadena1 |
| ana | anana | Cadena2 |
| teXto | texto | Cadena2 |

**Función strcmpi:**

Es exactamente igual a la función strcmp pero ignora si son mayúsculas o minúsculas es decir que el string “ANA” es igual al string “ana” y también es igual al string “anA” o cualquiera de sus variantes.