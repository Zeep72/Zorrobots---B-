Hola chicos soy Zeep, a veces programo, este es un prototipo de documentacion muy mala para explicar como funcioan el test

Este programa está diseñado para controlar un servo y un motor DC mediante un ESP32.

El servo se controla con la librería ESP32Servo.h, que permite generar señales PWM compatibles con servos estándar.
El motor DC se controla usando dos pines digitales para la dirección y un canal PWM (LEDC) para la velocidad.
El código realiza una prueba básica: mueve el servo a posiciones predefinidas (izquierda, centro, derecha) mientras hace girar el motor en distintas direcciones.

basicamente tenemos:

1 - DC Motor para avanzar y retroceder
2 - Servo de direccion GObilda 180° Torque

DC - Motor diagrama raro ->

Chip L298N 
---------------------   GND       
| EN -> Pin         | - - - -  /-------------\
| IN1 -> Pin        |          |  DC motor     -------
| IN2 ->  33        | - - - -  |_____________/
---------------------   +6v

PWM variables raras
freq = 1000 Hz → frecuencia del PWM.
pwmChannel = 3 → canal LEDC asignado.
resolution = 8 → resolución de 8 bits (valores de 0–255).
dutyCycle = 200 → ciclo útil inicial (no se usa mucho, se fuerza a 255). (also la potencia del motor)


Servo motor diagrama raro


----------------
|              | +5V -> Pin 5v esp32
|  ( )         | GND -> GND Esp32
|              | Datos -> Pin 2 
----------------

fin :), ayudenme la wro es mañana y literalmente no tenemos nada xddd, esto lo hicimos ayer, necesito cafe, tengo 2 horas de sueño. 
