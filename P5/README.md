# Práctica 5

## Realizada por [Irene Muñoz Domingo](https://github.com/irenchuchu) y [Juan Carlos Pineda Muñoz](https://github.com/juancpineda97)

Para realizar esta práctica, se ha usado un [script](P5.R) en `R`, que realiza todas las funciones pedidas. El script es el siguiente:

![c1.png](img/c1.png)

![c2.png](img/c2.png)

En el script, para leer los ficheros de sonido, se ha usado la función `readWave` para leer archivos .wav y la función `readMP3` para leer archivos .mp3. Para mostrar la forma de onda de los sonidos, se ha usado la función `plot`, la cuál muestra el siguiente resultado en el archivo *perro.wav*:

![perro](img/perro.png)

Y para el archivo *gato.mp3*:

![gato](img/gato.png)

Luego, para obtener la información de las cabeceras, se ha usado la función  `str`, y, para unirlos, la función `pastew`. La forma de onda de la mezcla de *perro.wav* y *gato.mp3* es la siguiente:

![mezcla](img/mezcla.png)

Por último, para aplicar un filtro de frecuencias se ha usado la función `bwfilter`, para aplicar eco la función `eco`, y para dar la vuelta al sonido, la función `revw`. Para acabar, los nuevos sonidos se pueden guardar en archivos con la función `writeWave`.