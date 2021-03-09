# SEMINARIO 1

## Realizado por Irene Muñoz Domingo y Juan Carlos Pineda Muñoz

### Ejercicio 1
Una vez instalado el software en Ubuntu, hemos probado a ejecutar el siguiente juego:

![c1](capturas/c1.png)

Y, como se puede ver, se ejecuta satisfactoriamente.

### Ejercicio 2
Para ello, hay que añadir la configuración correspondiente al archivo `~/.dosbox/dosbox-0.74.conf` , que será la siguiente:

![c2](capturas/c2.png)

![c3](capturas/c3.jpeg)

En ella, en la primera línea monta en la unidad c: el directorio donde se encuentra el entorno de programación Borland C, luego cambia la configuración del teclado a español, añade a la variable path el directorio “bin” donde se encuentra el ejecutable BC.EXE, y por último cambia a la unidad c:.

### Ejercicio 3
Primero, hemos realizado el ejemplo "hola", con el siguiente [código](codigo/hola.asm), que imprimirá "hola" por pantalla:

![c4](capturas/c4.png)

Y luego, modificando este [código](codigo/hola7.asm) añadiendo un bucle, mostrará por pantalla el mensaje "hola" 7 veces:

![c5](capturas/c5.png)

El resultado de la ejecución es el siguiente:

![c6](capturas/c6.png)