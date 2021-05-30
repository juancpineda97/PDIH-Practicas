library(tuneR)
library(seewave)
library(audio)

setwd("/home/juancpineda97/Ingenieria_Informatica/Asignaturas/4º/PDIH/PDIH-Privado/P5")

# Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno
perro <- readWave('sonidos/perro.wav')
perro
gato  <- readMP3("sonidos/gato.mp3")
gato

# Dibujar la forma de onda de ambos sonidos
plot(perro)
plot(gato)

# Obtener la información de las cabeceras de ambos sonidos
str(perro)
str(gato)

# Unir ambos sonidos en uno nuevo
mezcla <- pastew(perro, gato, output="Wave")
mezcla

# Dibujar la forma de onda de la señal resultante
plot(mezcla)

# Pasarle un filtro de frecuencia para eliminar las frecuencias entre 10000Hz y 20000Hz
mezclafiltro <- bwfilter(mezcla,f=44100, channel=1, n=1, from=10000, to=20000, bandpass=TRUE, listen = FALSE, output = "Wave")

# Almacenar la señal obtenida como un fichero WAV denominado “mezcla.wav”
writeWave(mezclafiltro, file.path("mezcla.wav") )

# Cargar un nuevo archivo de sonido, aplicarle eco y a continuación darle la
# vuelta al sonido. Almacenar la señal obtenida como un fichero WAV
# denominado “alreves.wav”
hola <- readWave('sonidos/hola.wav')
str(hola)
holaECO <- echo(hola,f=22050,amp=c(0.8,0.4,0.2),delay=c(1,2,3),output="Wave")
holaECO@left <- 10000 * holaECO@left
alreves <- revw(holaECO, output="Wave")
writeWave(alreves, file.path("alreves.wav") )