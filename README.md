# Medidor-de-horas-Frente-al-monitor-
Este Repositorio muestra el proyecto del desarrollo de un dispositivo dentro de un sistema IoT, el cual premite monitorear las horas de un usuario frente al monitor.

## Introducción

El siguiente documento tiene como propósito exteriorizar la propuesta de un dispositivo prototipo, el cual monitoreara las horas frente a un monitor de computadora, dentro de ambientes principalmente laborales y de hogar, este considera problemáticas de exposición excesiva a monitores que a su vez pueden generar daños a la salud.  El proyecto propuesto, utilizando tecnologías avanzadas, monitoreo con cámara, comunicación por medio de IoT a una base de datos.

## Problemática

El uso excesivo de computadoras y el estar expuesto a monitores por horas prolongadas, conlleva problemas para la salud como; daño a la visión, disminución de capacidad cognitiva, problemas de postura, privación del sueño, habilidades sociales alteradas, entre otras. Esto solo hablando en cuestiones individuales, pero, para un corporativo ya sea en oficina o para el “home office”, todas estas afecciones antes mencionadas tienen como consecuencia bajo rendimiento laboral y gastos médicos aumentados.

## Solución propuesta

Con ayuda del módulo ESP32-CAM se plantea un dispositivo de monitoreo, el cual le notifique al usuario por medio de un buffer, cuando excedió el tiempo máximo recomendado de uso de monitor.

## Objetivos específicos

- Desarrollar un dispositivo para el monitoreo del tiempo de uso de monitores, de personales dentro de una oficina o casa. 
- Prevenir el deterioro de la salud por uso prolongado de monitores, notificando al usuario para no exceder el tiempo recomendado de usanza. 
- Recopilar información sobre el tiempo que los consumidores de tecnologías con monitores pasan frente a estos.

## Materiales necesarios

- ESP32-CAM.
- Buffer 3.3V.
- Raspberry pi 4 mo. B 8Gb ram.
- 2 Micro push button.
- 3 Resistencias 220 ohms.
- Led rojo. 
- Led verde. 

## Servicios
 
1. Registro de actividad: Se registrará el inicio y el final de actividades frente al monitor con una fotografía.  
2. Tiempo de uso: Se contabilizará el tiempo de uso del dispositivo con monitor para el usuario. 
3. Base de datos: Se realizará una base de datos con la información captada. 

## Resultados esperados

Al implementar el dispositivo, se espera la reducción de problemas de salud por medio de pequeños descansos del uso del monitor y se obtendrá un histórico sobre el tiempo de exposición de la persona. 

## Conclusiones

El prototipo presenta una solución innovadora para abordar problemáticas de salud en el ámbito laborar y de hogar.


