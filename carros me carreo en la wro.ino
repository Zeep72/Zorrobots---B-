#include <ESP32Servo.h>
//centro izquierda derecha del servo
const int IZQ = 53;
const int CEN = 96;
const int DER = 130;

Servo carrosayuda;
const int pinServo = 2;

int motor1Pin1 = 25;
int motor1Pin2 = 33;
int enable1Pin = 32;

//ledc params
const int freq = 1000;
const int pwmChannel = 3;
const int resolution = 8;
int dutyCycle = 200;

void setup() {
    //servo setup
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    carrosayuda.setPeriodHertz(50);
    carrosayuda.attach(pinServo, 544, 2400);

    //motor void pin
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);

    //ledc setup, me lo robe de una web random por ahi
    ledcSetup(pwmChannel, freq, resolution);
    ledcAttachPin(enable1Pin, pwmChannel);

    Serial.begin(115200);
    Serial.println("Servo + Motor init");

    carrosayuda.write(93);
    delay(1000);
}

void loop() { //motor y servo test 1st time
    carrosayuda.write(CEN); 
    
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    ledcWrite(pwmChannel, 255);
    delay(2000);
    carrosayuda.write(IZQ);

    Serial.println("Motor stopped");
    ledcWrite(pwmChannel, 0);
    delay(1000);
    carrosayuda.write(CEN);


    Serial.println("Moving Backwards");
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    ledcWrite(pwmChannel, 255);
    delay(2000);
    carrosayuda.write(DER);


    Serial.println("Motor stopped");
    ledcWrite(pwmChannel, 0);
    delay(1000);
}