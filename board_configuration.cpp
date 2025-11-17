#include "pch.h"
#include "board_overrides.h"

// LEDs não usados
Gpio getCommsLedPin()    { return Gpio::Unassigned; }
Gpio getRunningLedPin()  { return Gpio::Unassigned; }
Gpio getWarningLedPin()  { return Gpio::Unassigned; }

// ***********************
//  CONFIGURAÇÃO DO SEU BOARD
// ***********************
static void customBoardDefaultConfiguration() {

    // --------------------------
    // INJETORAS
    // --------------------------
    engineConfiguration->injectionPins[0] = Gpio::PB7;
    engineConfiguration->injectionPins[1] = Gpio::PB6;
    engineConfiguration->injectionPins[2] = Gpio::PB5;
    engineConfiguration->injectionPins[3] = Gpio::PB4;

    // --------------------------
    // IGNIÇÃO
    // --------------------------
    engineConfiguration->ignitionPins[0] = Gpio::PB9;
    engineConfiguration->ignitionPins[1] = Gpio::PB8;
    engineConfiguration->ignitionPins[2] = Gpio::PB3;
    engineConfiguration->ignitionPins[3] = Gpio::PA15;

    // --------------------------
    // ENTRADAS ANALÓGICAS
    // --------------------------
    engineConfiguration->tps1_1 = Gpio::A2;
    engineConfiguration->map.sensorPin = Gpio::A3;
    engineConfiguration->iat.sensorPin = Gpio::A0;
    engineConfiguration->clt.sensorPin = Gpio::A1;
    engineConfiguration->o2.sensorPin = Gpio::A8;
    engineConfiguration->vbattAdcChannel = Gpio::A4;

    // baro usa o MAP
    engineConfiguration->baroSensorPin = engineConfiguration->map.sensorPin;

    // --------------------------
    // SAÍDAS DIVERSAS
    // --------------------------
    engineConfiguration->tachOutputPin = Gpio::PB1;
    engineConfiguration->idle.solenoidPin = Gpio::PB2;
    engineConfiguration->stepperDirectionPin = Gpio::PB10;
    engineConfiguration->stepperStepPin = Gpio::PB2;
    engineConfiguration->boostPin = Gpio::PA6;
    engineConfiguration->fuelPumpPin = Gpio::PA8;
    engineConfiguration->fanPin = Gpio::PA5;

    // --------------------------
    // TRIGGERS E FLEX
    // --------------------------
    engineConfiguration->triggerInputPins[0] = Gpio::PC13;
    engineConfiguration->triggerInputPins[1] = Gpio::PC15;
    engineConfiguration->flexPin = Gpio::PC14;

    // --------------------------
    // LIMITES
    // --------------------------
    engineConfiguration->maxInjectors = 4;
    engineConfiguration->maxCylinders = 4;
}

// ***************
// REGISTRA O BOARD
// ***************
void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
