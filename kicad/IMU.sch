EESchema Schematic File Version 2
LIBS:74xgxx
LIBS:74xx
LIBS:ac-dc
LIBS:actel
LIBS:adc-dac
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:brooktre
LIBS:cmos_ieee
LIBS:cmos4000
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:dc-dc
LIBS:device
LIBS:digital-audio
LIBS:display
LIBS:dsp
LIBS:elec-unifil
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:intel
LIBS:interface
LIBS:ir
LIBS:linear
LIBS:logo
LIBS:memory
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:microchip
LIBS:microcontrollers
LIBS:motorola
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:opto
LIBS:philips
LIBS:power
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:regul
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:siliconi
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:texas
LIBS:transf
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:video
LIBS:xilinx
LIBS:ft232r
LIBS:stm32f40x
LIBS:open-project
LIBS:ltc3553
LIBS:icm20608
LIBS:FERRITEBEAD
LIBS:NRF24L01
LIBS:CHIP_ANTENNA
LIBS:IRFML8244
LIBS:BAT54
LIBS:molexNoHole
LIBS:tlv70033
LIBS:IMU-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 7400 1800 1050 1450
U 5547C4E8
F0 "Mems and Radio" 60
F1 "mems_radio.sch" 60
F2 "MEMS_SCLK" I L 7400 1900 60 
F3 "MEMS_MOSI" I L 7400 2000 60 
F4 "MEMS_MISO" O L 7400 2100 60 
F5 "MEMS_INT" O L 7400 2200 60 
F6 "NRF24_MOSI" I L 7400 2600 60 
F7 "NRF24_MISO" O L 7400 2700 60 
F8 "NRF24_SCK" I L 7400 2500 60 
F9 "NRF24_CSN" I L 7400 2900 60 
F10 "NRF24_CE" I L 7400 3000 60 
F11 "NRF24_IRQ" O L 7400 2800 60 
F12 "NRF24_OSC" I L 7400 3100 60 
F13 "MEMS_CS" I L 7400 2300 60 
$EndSheet
$Sheet
S 4350 1800 1550 1450
U 5547C6EF
F0 "Microcontroller" 60
F1 "mcu.sch" 60
F2 "MCU_TXD" O L 4350 2000 60 
F3 "MCU_RXD" I L 4350 1900 60 
F4 "PWREN#" I L 4350 2200 60 
F5 "MEMS_SCLK" O R 5900 1900 60 
F6 "MEMS_MOSI" O R 5900 2000 60 
F7 "MEMS_MISO" I R 5900 2100 60 
F8 "MEMS_INT" I R 5900 2200 60 
F9 "NRF24_MOSI" O R 5900 2600 60 
F10 "NRF24_MISO" I R 5900 2700 60 
F11 "NRF24_SCK" O R 5900 2500 60 
F12 "NRF24_CSN" O R 5900 2900 60 
F13 "NRF24_CE" O R 5900 3000 60 
F14 "NRF24_IRQ" I R 5900 2800 60 
F15 "NRF24_OSC" O R 5900 3100 60 
F16 "HPWR" O L 4350 2300 60 
F17 "MEMS_CS" O R 5900 2300 60 
F18 "LDO_ON" O L 4350 2400 60 
F19 "~ON" B L 4350 2500 60 
$EndSheet
$Sheet
S 2250 1800 1050 850 
U 5547C5DB
F0 "Power" 60
F1 "power.sch" 60
F2 "FTDI_TXD" O R 3300 1900 60 
F3 "FTDI_RXD" I R 3300 2000 60 
F4 "PWREN#" O R 3300 2200 60 
F5 "HPWR" I R 3300 2300 60 
F6 "~ON" B R 3300 2500 60 
F7 "LDO_ON" I R 3300 2400 60 
$EndSheet
Wire Wire Line
	3300 1900 4350 1900
Wire Wire Line
	3300 2000 4350 2000
Wire Wire Line
	4350 2200 3300 2200
Wire Wire Line
	5900 1900 7400 1900
Wire Wire Line
	7400 2000 5900 2000
Wire Wire Line
	5900 2100 7400 2100
Wire Wire Line
	7400 2200 5900 2200
Wire Wire Line
	4350 2300 3300 2300
Wire Wire Line
	5900 2500 7400 2500
Wire Wire Line
	7400 2600 5900 2600
Wire Wire Line
	5900 2700 7400 2700
Wire Wire Line
	7400 2800 5900 2800
Wire Wire Line
	5900 2900 7400 2900
Wire Wire Line
	7400 3000 5900 3000
Wire Wire Line
	5900 3100 7400 3100
Wire Wire Line
	5900 2300 7400 2300
Wire Wire Line
	4350 2500 3300 2500
Wire Wire Line
	3300 2400 4350 2400
$EndSCHEMATC
