# Medidor-de-horas-Frente-al-monitor-
Este Repositorio muestra el proyecto del desarrollo de un dispositivo dentro de un sistema IoT, el cual premite monitorear las horas de un usuario frente al monitor.

## Introducción 

El presente documento tiene como propósito exponer la propuesta de un dispositivo prototipo diseñado para monitorear el tiempo de exposición frente a la pantalla de una computadora, principalmente en entornos laborales y domésticos. Este proyecto aborda las problemáticas asociadas con la exposición excesiva a las pantallas, que pueden generar daños para la salud. La propuesta utiliza tecnologías avanzadas, como monitoreo con cámara y comunicación a través de IoT con una base datos.

## Problemática

En la era digital actual, la exposición prolongada a las pantallas de computadora se ha convertido en una realidad cotidiana para muchas personas, tanto en el ámbito laboral como en el hogar. Sin embargo, esta exposición excesiva puede tener consecuencias negativas para la salud, como fatiga visual, dolores de cabeza, problemas de sueño, entre otros. Ante este escenario, surge la necesidad de desarrollar soluciones innovadoras que permitan monitorear y controlar el tiempo de exposición frente a las pantallas, promoviendo un uso más saludable y responsable de la tecnología. Es en este contexto que se presenta la propuesta de un dispositivo prototipo que busca abordar esta problemática.

## Solución propuesta

Con ayuda del módulo ESP32-CAM se plantea un dispositivo de monitoreo, el cual le notifique al usuario por medio de un buffer, cuando excedió el tiempo máximo recomendado de uso de monitor

## Objetivos específicos

- Desarrollar un dispositivo para el monitoreo del tiempo de uso de monitores, de personales dentro de una oficina o casa. 
- Prevenir el deterioro de la salud por uso prolongado de monitores, notificando al usuario para no exceder el tiempo recomendado de usanza. 
- Recopilar información sobre el tiempo que los consumidores de tecnologías con monitores pasan frente a estos.   

## Materiales necesarios

- ESP32-CAM.
- Buffer 3.3V.
- Raspberry pi 4 mo. B 8Gb ram.
- Micro push button.
- Resistencias.

## Servicios
 
Registro de actividad: Se registrará el inicio y el final de actividades frente al monitor con una fotografía. 
Tiempo de uso: Se contabilizará el tiempo de uso del dispositivo con monitor para el usuario. 
Base de datos: Se realizará una base de datos con la información captada. 

## Resultados esperados

Al implementar el dispositivo, se espera la reducción de problemas de salud por medio de pequeños descansos del uso del monitor y se obtendrá un histórico sobre el tiempo de exposición de la persona. 

## Conclusiones

El prototipo presenta una solución innovadora para abordar problemáticas de salud en el ámbito laborar y de hogar.


