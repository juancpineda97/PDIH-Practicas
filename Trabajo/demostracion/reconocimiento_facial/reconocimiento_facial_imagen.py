# -*- coding: latin-1 -*-
"""
    Código 2.1 - Reconocimiento facial en una imagen estática
    Este programa identifica varios rostros de físicos famosos en fotografías.
 
    Escrito por Glare y Transductor
    www.robologs.net
"""
import cv2
import face_recognition
 
#Cargamos las imagenes con los rostros que queremos identificar:
imagen_messi = face_recognition.load_image_file("messi.jpg")
imagen_neymar = face_recognition.load_image_file("neymar.jpg")
imagen_suarez = face_recognition.load_image_file("luis_suarez.jpg")
 
 
#El siguiente paso es extraer los 'encodings' de cada imagen.
#Los encodings son las características únicas de cada rostro que permiten diferenciarlo de otros.
messi_encodings = face_recognition.face_encodings(imagen_messi)[0]
neymar_encodings = face_recognition.face_encodings(imagen_neymar)[0]
suarez_encodings = face_recognition.face_encodings(imagen_suarez)[0]
 
 
#Creamos un array con los encodings y otro con sus respectivos nombres:
encodings_conocidos = [
    messi_encodings,
    neymar_encodings,
    suarez_encodings
]
nombres_conocidos = [
    "Leo Messi",
    "Neymar",
    "Luis Suarez"
]
 
 
#Cargamos una fuente de texto:
font = cv2.FONT_HERSHEY_COMPLEX
 
 
#Cargamos la imagen donde hay que identificar los rostros:
img = face_recognition.load_image_file('ejemplo.jpeg')
#(Para probar la segunda imagen hay que cambiar el argumento de la función por 'imagen_input2.jpg')
 
 
 
# Definir tres arrays, que servirán para guardar los parámetros de los rostros que se encuentren en la imagen:
loc_rostros = [] #Localizacion de los rostros en la imagen (contendrá las coordenadas de los recuadros que las contienen)
encodings_rostros = [] #Encodings de los rostros
nombres_rostros = [] #Nombre de la persona de cada rostro
 
 
#Localizamos cada rostro de la imagen y extraemos sus encodings:
loc_rostros = face_recognition.face_locations(img)
encodings_rostros = face_recognition.face_encodings(img, loc_rostros)
 
 
#Recorremos el array de encodings que hemos encontrado:
for encoding in encodings_rostros:
 
    #Buscamos si hay alguna coincidencia con algún encoding conocido:
    coincidencias = face_recognition.compare_faces(encodings_conocidos, encoding)
 
    #El array 'coincidencias' es ahora un array de booleanos.
    #Si contiene algun 'True', es que ha habido alguna coincidencia:
    if True in coincidencias:
        #Buscamos el nombre correspondiente en el array de nombres conocidos:
        nombre = nombres_conocidos[coincidencias.index(True)]
 
    #Si no hay ningún 'True' en el array 'coincidencias', no se ha podido identificar el rostro:
    else:
        nombre = "???"
 
    #Añadimos el nombre de la persona identificada en el array de nombres:
    nombres_rostros.append(nombre)
 
 
#Dibujamos un recuadro rojo alrededor de los rostros desconocidos, y uno verde alrededor de los conocidos:
for (top, right, bottom, left), nombre in zip(loc_rostros, nombres_rostros):
 
    #Cambiar el color segun el nombre:
    if nombre != "???":
        color = (0,255,0) #Verde
    else:
        color = (0,0,255) #Rojo
 
    #Dibujar los recuadros alrededor del rostro:
    cv2.rectangle(img, (left, top), (right, bottom), color, 2)
    cv2.rectangle(img, (left, bottom - 20), (right, bottom), color, -1)
 
    #Escribir el nombre de la persona:
    cv2.putText(img, nombre, (left, bottom - 6), font, 0.6, (0,0,0), 1)
 
#Abrimos una ventana con el resultado:
cv2.imshow('Output', img)
print("\nMostrando resultado. Pulsa cualquier tecla para salir.\n")
cv2.waitKey(0)
cv2.destroyAllWindows()
