// board_configuration.cpp - custom F405 board for Pedro
#include "pch.h"
#include "engine_configuration.h"
#include "gpio.h"

void boardDefaultConfiguration() {
    // Injectors
    engineConfiguration->injectionPins[0] = Gpio::PB7;
    engineConfiguration->injectionPins[1] = Gpio::PB6;
    engineConfiguration->injectionPins[2] = Gpio::PB5;
    engineConfiguration->injectionPins[3] = Gpio::PB4;

    // Ignition / coils
    engineConfiguration->ignitionPins[0] = Gpio::PB9;  // coil1
    engineConfiguration->ignitionPins[1] = Gpio::PB8;  // coil2
    engineConfiguration->ignitionPins[2] = Gpio::PB3;  // coil3
    engineConfiguration->ignitionPins[3] = Gpio::PA15; // coil4

    // Analog inputs
    engineConfiguration->tps1_1 = Gpio::A2;
    engineConfiguration->map.sensorPin = Gpio::A3;
    engineConfiguration->iat.sensorPin = Gpio::A0;
    engineConfiguration->clt.sensorPin = Gpio::A1;
    engineConfiguration->o2.sensorPin = Gpio::A8;
    engineConfiguration->vbattAdcChannel = Gpio::A4;

    // Baro uses MAP
    engineConfiguration->baroSensorPin = engineConfiguration->map.sensorPin;

    // Outputs
    engineConfiguration->tachOutputPin = Gpio::PB1;
    engineConfiguration->idle.solenoidPin = Gpio::PB2;
    engineConfiguration->stepperDirectionPin = Gpio::PB10;
    engineConfiguration->stepperStepPin = Gpio::PB2;
    engineConfiguration->boostPin = Gpio::PA6;
    engineConfiguration->fuelPumpPin = Gpio::PA8;
    engineConfiguration->fanPin = Gpio::PA5;

    // Trigger / interrupts
    engineConfiguration->triggerInputPins[0] = Gpio::PC13;
    engineConfiguration->triggerInputPins[1] = Gpio::PC15;
    engineConfiguration->flexPin = Gpio::PC14;

    // Tweak counts if needed
    engineConfiguration->maxInjectors = 4;
    engineConfiguration->maxCylinders = 4;
}
