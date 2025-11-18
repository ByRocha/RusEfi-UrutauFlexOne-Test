#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}

// board-specific configuration setup
static void customBoardDefaultConfiguration() {
    // engineConfiguration->injectionPins[0] = Gpio::F13;
    // engineConfiguration->ignitionPins[0] = Gpio::E15;

//   engineConfiguration->triggerInputPins[0] = Gpio::B1;
//	engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;

//	engineConfiguration->map.sensor.hwChannel = EFI_ADC_3;

//	engineConfiguration->clt.adcChannel = EFI_ADC_1;

//	engineConfiguration->iat.adcChannel = EFI_ADC_2;


    	// 5.6k high side/10k low side = 1.56 ratio divider
  //  	engineConfiguration->analogInputDividerCoefficient = 1.56f;

    	// 6.34k high side/ 1k low side
//    	engineConfiguration->vbattDividerCoeff = (6.34 + 1) / 1;

	engineConfiguration->adcVcc = 3.3f;

    engineConfiguration->clt.config.bias_resistor = 2490;
    engineConfiguration->iat.config.bias_resistor = 2490;


	// Battery sense on PA0
//	engineConfiguration->vbattAdcChannel = EFI_ADC_0;
     // ----------------------
    // INJETORES
    // ----------------------
    engineConfiguration->injectionPins[0] = Gpio::B7;
    engineConfiguration->injectionPins[1] = Gpio::B6;
    engineConfiguration->injectionPins[2] = Gpio::B5;
    engineConfiguration->injectionPins[3] = Gpio::B4;

    // ----------------------
    // IGNIÇÃO
    // ----------------------
    engineConfiguration->ignitionPins[0] = Gpio::B9;
    engineConfiguration->ignitionPins[1] = Gpio::B8;
    engineConfiguration->ignitionPins[2] = Gpio::B3;
    engineConfiguration->ignitionPins[3] = Gpio::A15;

    // ----------------------
    // ANALÓGICOS (ADC)
    // ----------------------
    // TPS = A2
    engineConfiguration->tps1_1AdcChannel = EFI_ADC_2;
	

    // MAP = A3
    engineConfiguration->map.sensor.hwChannel = EFI_ADC_3;

    // IAT = A0
    engineConfiguration->iat.AdcChannel = EFI_ADC_0;

    // CLT = A1
    engineConfiguration->clt.AdcChannel = EFI_ADC_1;

    // O2 = A8 -> precisa confirmar canal ADC!
    engineConfiguration->afr.hwChannel = EFI_ADC_8;

    // BATT = A4
    engineConfiguration->vbattAdcChannel = EFI_ADC_4;

    // BARO = MAP
    engineConfiguration->baroSensor.hwChannel = engineConfiguration->map.sensor.hwChannel;


    // ----------------------
    // SAÍDAS
    // ----------------------
    engineConfiguration->tachOutputPin = Gpio::B1;
    engineConfiguration->idle.solenoidPin = Gpio::B2;
    //engineConfiguration->boostPin = Gpio::A6;
    engineConfiguration->fuelPumpPin = Gpio::A8;
    engineConfiguration->fanPin = Gpio::A5;

    // ----------------------
    // TRIGGERS
    // ----------------------
    engineConfiguration->triggerInputPins[0] = Gpio::C13;
    engineConfiguration->triggerInputPins[1] = Gpio::C15;

    // Flex
    //engineConfiguration->flexPin = Gpio::C14;


}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
