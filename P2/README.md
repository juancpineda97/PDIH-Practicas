# PRÁCTICA 2

## Realizada por [Irene Muñoz Domingo](https://github.com/irenchuchu) y [Juan Carlos Pineda Muñoz](https://github.com/juancpineda97)

### Ejercicio 1: 
##### Instalación de la librería: 

![c1](capturas/1.png)

##### Comrpobación de que funcionan los ejemplos propuestos: 

![c2](capturas/2.png)

![c3](capturas/3.png)

![c4](capturas/4.jpeg)

![c5](capturas/5.jpeg)

![c6](capturas/6.jpeg)

### Ejercicio 2: Crear un juego sencillo tipo “pong” partiendo del ejemplo del movimiento de la pelotita. Al iniciar el juego debe mostrarse un recuadro en una pantalla de bienvenida explicando los controles de juego. Tras una pausa se inicia el juego en sí mismo. 

El enlace al código es el siguiente: [pong.c](pong.c)

#### Adjuntamos algunas capturas del código:

- Primero una captura de las funciones auxiliares usadas para dibujar en pantalla:

![c9](capturas/9.png)

- Luego, el bucle principal en el que se desarrolla el juego: 

![c10](capturas/10.png)

- El switch que determinará la siguiente dirección de la bola:

![c11](capturas/11.png)

![c12](capturas/12.png)

![c13](capturas/13.png)

![c14](capturas/14.png)

- Después, en función de la siguiente dirección, se modificarán las coordenadas de la bola o se contabilizará el punto:

![c15](capturas/15.png)

- Por último se capturará la pulsación de las teclas de movimiento, se imprimirá la bola y se esperará un tiempo para volver a ejecutar el bucle:

![c16](capturas/16.png)

#### Capturas del funcionamiento del juego:

![c7](capturas/7.png)

Como se observa, incrementamos el contador cada vez que se marca un punto:

![c8](capturas/8.png)