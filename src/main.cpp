#include <Arduino.h>

int SENSOR = 2;   // salida de KY-033 a pin digital 2
int VALOR;        // almacena valor leido del sensor
int ANTERIOR = 1; // almacena ultimo valor leido del sensor

void setup()
{
    Serial.begin(9600);     // inicializa comunicacion serie a 9600 bps
    pinMode(SENSOR, INPUT); // pin 2 como entrada
}

void loop()
{
    VALOR = digitalRead(SENSOR); // lee valor de sensor y asigna a variable VALOR
    if (VALOR != ANTERIOR)
    {                                // si el valor es distinto del ultimo
        if (VALOR == HIGH)           // si VALOR tiene un nivel alto es linea negra
            Serial.println("Linea"); // imprime en monitor serial la palabra Linea
        else                         // si VALOR tiene un nivel bajo es fuera de linea
            Serial.println("Fuera"); // imprime en monitor serial la palabra Fuera
        ANTERIOR = VALOR;            // actualiza variable ANTERIOR con el actual de VALOR
    }
    delay(50); // espera entre lectura y lectura
}