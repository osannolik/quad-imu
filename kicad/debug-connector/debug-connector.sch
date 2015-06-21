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
LIBS:debug-connector-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_02X05 P?
U 1 1 5586E97E
P 5750 3450
F 0 "P?" H 5750 3750 50  0000 C CNN
F 1 "CONN_02X05" H 5750 3150 50  0000 C CNN
F 2 "DF23C-10DP-0.5V:DF23C-10DS-0.5V" H 5750 2250 60  0001 C CNN
F 3 "" H 5750 2250 60  0000 C CNN
	1    5750 3450
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P?
U 1 1 5586EEE2
P 6950 2150
F 0 "P?" H 6950 2450 50  0000 C CNN
F 1 "CONN_02X05" H 6950 1850 50  0000 C CNN
F 2 "molexNoHole:molexNoHole-87832-10" H 6950 950 60  0001 C CNN
F 3 "" H 6950 950 60  0000 C CNN
	1    6950 2150
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X10 P?
U 1 1 5586FF1D
P 4450 2000
F 0 "P?" H 4450 2550 50  0000 C CNN
F 1 "CONN_02X10" V 4450 2000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x10" H 4450 800 60  0001 C CNN
F 3 "" H 4450 800 60  0000 C CNN
	1    4450 2000
	1    0    0    -1  
$EndComp
Text Label 5350 1550 2    60   ~ 0
VAPP
Text Label 3550 1550 0    60   ~ 0
VAPP
Wire Wire Line
	3550 1550 4200 1550
Wire Wire Line
	4700 1550 5350 1550
Text Label 3550 1650 0    60   ~ 0
TRST
Text Label 3550 1750 0    60   ~ 0
TDI
Text Label 3550 1850 0    60   ~ 0
TMS_SWDIO
Text Label 3550 1950 0    60   ~ 0
TCK_SWCLK
Text Label 3550 2150 0    60   ~ 0
TDO_SWO
Text Label 3550 2250 0    60   ~ 0
NRST
Wire Wire Line
	3550 1650 4200 1650
Wire Wire Line
	4200 1750 3550 1750
Wire Wire Line
	3550 1850 4200 1850
Wire Wire Line
	4200 1950 3550 1950
Wire Wire Line
	3550 2150 4200 2150
Wire Wire Line
	4200 2250 3550 2250
$Comp
L GND #PWR?
U 1 1 558703B2
P 4850 2550
F 0 "#PWR?" H 4850 2300 50  0001 C CNN
F 1 "GND" H 4850 2400 50  0000 C CNN
F 2 "" H 4850 2550 60  0000 C CNN
F 3 "" H 4850 2550 60  0000 C CNN
	1    4850 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 1650 4850 2550
Wire Wire Line
	4850 2450 4700 2450
Wire Wire Line
	4700 2350 4850 2350
Connection ~ 4850 2450
Wire Wire Line
	4700 2250 4850 2250
Connection ~ 4850 2350
Wire Wire Line
	4700 2150 4850 2150
Connection ~ 4850 2250
Wire Wire Line
	4700 2050 4850 2050
Connection ~ 4850 2150
Wire Wire Line
	4700 1950 4850 1950
Connection ~ 4850 2050
Wire Wire Line
	4700 1850 4850 1850
Connection ~ 4850 1950
Wire Wire Line
	4700 1750 4850 1750
Connection ~ 4850 1850
Wire Wire Line
	4700 1650 4850 1650
Connection ~ 4850 1750
Text Label 6050 1950 0    60   ~ 0
VAPP
Wire Wire Line
	6050 1950 6700 1950
$Comp
L GND #PWR?
U 1 1 5587065C
P 6550 2050
F 0 "#PWR?" H 6550 1800 50  0001 C CNN
F 1 "GND" H 6550 1900 50  0000 C CNN
F 2 "" H 6550 2050 60  0000 C CNN
F 3 "" H 6550 2050 60  0000 C CNN
	1    6550 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 2050 6700 2050
Wire Wire Line
	6700 2150 6600 2150
Wire Wire Line
	6600 2150 6600 2050
Connection ~ 6600 2050
Text Label 7850 1950 2    60   ~ 0
TMS_SWDIO
Text Label 7850 2050 2    60   ~ 0
TCK_SWCLK
Text Label 7850 2150 2    60   ~ 0
TDI
Text Label 7850 2250 2    60   ~ 0
TDO_SWO
Text Label 7850 2350 2    60   ~ 0
NRST
Wire Wire Line
	7850 1950 7200 1950
Wire Wire Line
	7200 2050 7850 2050
Wire Wire Line
	7850 2150 7200 2150
Wire Wire Line
	7200 2250 7850 2250
Wire Wire Line
	7850 2350 7200 2350
Text Label 6050 2250 0    60   ~ 0
UART_TX
Text Label 6050 2350 0    60   ~ 0
UART_RX
Wire Wire Line
	6050 2250 6700 2250
Wire Wire Line
	6700 2350 6050 2350
$Comp
L CONN_01X02 P?
U 1 1 558708C9
P 6950 1300
F 0 "P?" H 6950 1450 50  0000 C CNN
F 1 "CONN_01X02" V 7050 1300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 6950 1300 60  0001 C CNN
F 3 "" H 6950 1300 60  0000 C CNN
	1    6950 1300
	1    0    0    -1  
$EndComp
Text Label 6050 1250 0    60   ~ 0
UART_TX
Text Label 6050 1350 0    60   ~ 0
UART_RX
Wire Wire Line
	6050 1350 6750 1350
Wire Wire Line
	6750 1250 6050 1250
$EndSCHEMATC
