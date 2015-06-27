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
L CONN_02X05 P2
U 1 1 5586E97E
P 4450 4350
F 0 "P2" H 4450 4650 50  0000 C CNN
F 1 "CONN_02X05" H 4450 4050 50  0000 C CNN
F 2 "DF23C-10DP-0.5V:DF23C-10DS-0.5V" H 4450 3150 60  0001 C CNN
F 3 "" H 4450 3150 60  0000 C CNN
	1    4450 4350
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P4
U 1 1 5586EEE2
P 6900 4350
F 0 "P4" H 6900 4650 50  0000 C CNN
F 1 "CONN_02X05" H 6900 4050 50  0000 C CNN
F 2 "molexNoHole:molexNoHole-87832-10" H 6900 3150 60  0001 C CNN
F 3 "" H 6900 3150 60  0000 C CNN
	1    6900 4350
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X10 P1
U 1 1 5586FF1D
P 4450 3200
F 0 "P1" H 4450 3750 50  0000 C CNN
F 1 "CONN_02X10" V 4450 3200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x10" H 4450 2000 60  0001 C CNN
F 3 "" H 4450 2000 60  0000 C CNN
	1    4450 3200
	1    0    0    -1  
$EndComp
Text Label 5350 2750 2    60   ~ 0
VAPP
Text Label 3550 2750 0    60   ~ 0
VAPP
Wire Wire Line
	3550 2750 4200 2750
Wire Wire Line
	4700 2750 5350 2750
Text Label 3550 2850 0    60   ~ 0
TRST
Text Label 3550 2950 0    60   ~ 0
TDI
Text Label 3550 3050 0    60   ~ 0
TMS_SWDIO
Text Label 3550 3150 0    60   ~ 0
TCK_SWCLK
Text Label 3550 3350 0    60   ~ 0
TDO_SWO
Text Label 3550 3450 0    60   ~ 0
NRST
Wire Wire Line
	3550 2850 4200 2850
Wire Wire Line
	4200 2950 3550 2950
Wire Wire Line
	3550 3050 4200 3050
Wire Wire Line
	4200 3150 3550 3150
Wire Wire Line
	3550 3350 4200 3350
Wire Wire Line
	4200 3450 3550 3450
$Comp
L GND #PWR01
U 1 1 558703B2
P 4850 3750
F 0 "#PWR01" H 4850 3500 50  0001 C CNN
F 1 "GND" H 4850 3600 50  0000 C CNN
F 2 "" H 4850 3750 60  0000 C CNN
F 3 "" H 4850 3750 60  0000 C CNN
	1    4850 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2850 4850 3750
Wire Wire Line
	4850 3650 4700 3650
Wire Wire Line
	4700 3550 4850 3550
Connection ~ 4850 3650
Wire Wire Line
	4700 3450 4850 3450
Connection ~ 4850 3550
Wire Wire Line
	4700 3350 4850 3350
Connection ~ 4850 3450
Wire Wire Line
	4700 3250 4850 3250
Connection ~ 4850 3350
Wire Wire Line
	4700 3150 4850 3150
Connection ~ 4850 3250
Wire Wire Line
	4700 3050 4850 3050
Connection ~ 4850 3150
Wire Wire Line
	4700 2950 4850 2950
Connection ~ 4850 3050
Wire Wire Line
	4700 2850 4850 2850
Connection ~ 4850 2950
Text Label 6000 4150 0    60   ~ 0
VAPP
Wire Wire Line
	6000 4150 6650 4150
$Comp
L GND #PWR02
U 1 1 5587065C
P 6500 4250
F 0 "#PWR02" H 6500 4000 50  0001 C CNN
F 1 "GND" H 6500 4100 50  0000 C CNN
F 2 "" H 6500 4250 60  0000 C CNN
F 3 "" H 6500 4250 60  0000 C CNN
	1    6500 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 4250 6650 4250
Wire Wire Line
	6650 4350 6550 4350
Wire Wire Line
	6550 4350 6550 4250
Connection ~ 6550 4250
Text Label 7800 4150 2    60   ~ 0
TMS_SWDIO
Text Label 7800 4250 2    60   ~ 0
TCK_SWCLK
Text Label 7800 4350 2    60   ~ 0
TDI
Text Label 7800 4450 2    60   ~ 0
TDO_SWO
Text Label 7800 4550 2    60   ~ 0
NRST
Wire Wire Line
	7800 4150 7150 4150
Wire Wire Line
	7150 4250 7800 4250
Wire Wire Line
	7800 4350 7150 4350
Wire Wire Line
	7150 4450 7800 4450
Wire Wire Line
	7800 4550 7150 4550
Text Label 6000 4450 0    60   ~ 0
UART_TX
Text Label 6000 4550 0    60   ~ 0
UART_RX
Wire Wire Line
	6000 4450 6650 4450
Wire Wire Line
	6650 4550 6000 4550
Text Label 6000 3050 0    60   ~ 0
UART_TX
Text Label 6000 3150 0    60   ~ 0
UART_RX
Wire Wire Line
	6000 3150 6700 3150
Wire Wire Line
	6700 3050 6000 3050
Text Label 3550 4550 0    60   ~ 0
NRST
Wire Wire Line
	3550 4550 4200 4550
$Comp
L GND #PWR03
U 1 1 55886B1A
P 4850 4650
F 0 "#PWR03" H 4850 4400 50  0001 C CNN
F 1 "GND" H 4850 4500 50  0000 C CNN
F 2 "" H 4850 4650 60  0000 C CNN
F 3 "" H 4850 4650 60  0000 C CNN
	1    4850 4650
	1    0    0    -1  
$EndComp
Text Label 3550 4450 0    60   ~ 0
UART_RX
Wire Wire Line
	3550 4450 4200 4450
Text Label 5350 4450 2    60   ~ 0
VAPP
Wire Wire Line
	5350 4450 4700 4450
Text Label 3550 4350 0    60   ~ 0
UART_TX
Wire Wire Line
	3550 4350 4200 4350
Text Label 3550 4250 0    60   ~ 0
TRST
Wire Wire Line
	3550 4250 4200 4250
Text Label 3550 4150 0    60   ~ 0
TDO_SWO
Wire Wire Line
	3550 4150 4200 4150
Text Label 5350 4150 2    60   ~ 0
TMS_SWDIO
Wire Wire Line
	5350 4150 4700 4150
Text Label 5350 4250 2    60   ~ 0
TCK_SWCLK
Wire Wire Line
	5350 4250 4700 4250
Text Label 5350 4350 2    60   ~ 0
TDI
Wire Wire Line
	5350 4350 4700 4350
Wire Wire Line
	4850 4650 4850 4550
Wire Wire Line
	4850 4550 4700 4550
$Comp
L CONN_01X04 P3
U 1 1 55886F42
P 6900 3200
F 0 "P3" H 6900 3450 50  0000 C CNN
F 1 "CONN_01X04" V 7000 3200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x02" H 6900 3200 60  0001 C CNN
F 3 "" H 6900 3200 60  0000 C CNN
	1    6900 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 55886FBD
P 6500 3350
F 0 "#PWR04" H 6500 3100 50  0001 C CNN
F 1 "GND" H 6500 3200 50  0000 C CNN
F 2 "" H 6500 3350 60  0000 C CNN
F 3 "" H 6500 3350 60  0000 C CNN
	1    6500 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 3350 6700 3350
Wire Wire Line
	6700 3250 6550 3250
Wire Wire Line
	6550 3250 6550 3350
Connection ~ 6550 3350
$EndSCHEMATC
