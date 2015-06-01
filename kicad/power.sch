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
LIBS:special
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
LIBS:lp2992
LIBS:NRF24L01
LIBS:CHIP_ANTENNA
LIBS:IRFML8244
LIBS:BAT54
LIBS:molexNoHole
LIBS:IMU-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L FT232RQ IC?
U 1 1 5547D04A
P 3100 3800
AR Path="/5547D04A" Ref="IC?"  Part="1" 
AR Path="/5547C5DB/5547D04A" Ref="IC1"  Part="1" 
F 0 "IC1" H 2500 4850 50  0000 L BNN
F 1 "FT232RQ" H 3100 3800 50  0000 L BNN
F 2 "Housings_DFN_QFN:QFN-32-1EP_5x5mm_Pitch0.5mm" H 3100 3950 50  0001 C CNN
F 3 "" H 3100 3800 60  0000 C CNN
	1    3100 3800
	1    0    0    -1  
$EndComp
$Comp
L MICRO-B_USB U4
U 1 1 5547D051
P 900 3200
F 0 "U4" H 900 2900 50  0000 C CNN
F 1 "MICRO-B_USB" H 900 3500 50  0000 C CNN
F 2 "open-project:MICRO-B_USB" H 900 3200 60  0001 C CNN
F 3 "" H 900 3200 60  0000 C CNN
	1    900  3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR039
U 1 1 5547D05A
P 2800 5200
F 0 "#PWR039" H 2800 4950 60  0001 C CNN
F 1 "GND" H 2800 5050 60  0000 C CNN
F 2 "" H 2800 5200 60  0000 C CNN
F 3 "" H 2800 5200 60  0000 C CNN
	1    2800 5200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR040
U 1 1 5547D060
P 1350 2750
F 0 "#PWR040" H 1350 2600 60  0001 C CNN
F 1 "+5V" H 1350 2890 60  0000 C CNN
F 2 "" H 1350 2750 60  0000 C CNN
F 3 "" H 1350 2750 60  0000 C CNN
	1    1350 2750
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR041
U 1 1 5547D066
P 3200 1950
F 0 "#PWR041" H 3200 1800 60  0001 C CNN
F 1 "+5V" H 3200 2090 60  0000 C CNN
F 2 "" H 3200 1950 60  0000 C CNN
F 3 "" H 3200 1950 60  0000 C CNN
	1    3200 1950
	1    0    0    -1  
$EndComp
$Comp
L C C21
U 1 1 5547D06C
P 1850 2500
F 0 "C21" H 1850 2600 40  0000 L CNN
F 1 "100n" H 1856 2415 40  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 1888 2350 30  0001 C CNN
F 3 "" H 1850 2500 60  0000 C CNN
	1    1850 2500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR042
U 1 1 5547D073
P 1850 2750
F 0 "#PWR042" H 1850 2500 60  0001 C CNN
F 1 "GND" H 1850 2600 60  0000 C CNN
F 2 "" H 1850 2750 60  0000 C CNN
F 3 "" H 1850 2750 60  0000 C CNN
	1    1850 2750
	1    0    0    -1  
$EndComp
$Comp
L C C22
U 1 1 5547D079
P 3500 2300
F 0 "C22" H 3500 2400 40  0000 L CNN
F 1 "100n" H 3506 2215 40  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 3538 2150 30  0001 C CNN
F 3 "" H 3500 2300 60  0000 C CNN
	1    3500 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR043
U 1 1 5547D080
P 3500 2550
F 0 "#PWR043" H 3500 2300 60  0001 C CNN
F 1 "GND" H 3500 2400 60  0000 C CNN
F 2 "" H 3500 2550 60  0000 C CNN
F 3 "" H 3500 2550 60  0000 C CNN
	1    3500 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR044
U 1 1 5547D086
P 1350 3550
F 0 "#PWR044" H 1350 3300 60  0001 C CNN
F 1 "GND" H 1350 3400 60  0000 C CNN
F 2 "" H 1350 3550 60  0000 C CNN
F 3 "" H 1350 3550 60  0000 C CNN
	1    1350 3550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR045
U 1 1 5547D094
P 5800 2950
F 0 "#PWR045" H 5800 2800 60  0001 C CNN
F 1 "+5V" H 5800 3090 60  0000 C CNN
F 2 "" H 5800 2950 60  0000 C CNN
F 3 "" H 5800 2950 60  0000 C CNN
	1    5800 2950
	1    0    0    -1  
$EndComp
$Comp
L LED D5
U 1 1 5547D09A
P 7000 2700
F 0 "D5" H 7000 2800 50  0000 C CNN
F 1 "LED" H 7000 2600 50  0000 C CNN
F 2 "LEDs:LED-0603" H 7000 2700 60  0001 C CNN
F 3 "" H 7000 2700 60  0000 C CNN
	1    7000 2700
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5547D0A1
P 8450 4350
F 0 "R1" V 8530 4350 40  0000 C CNN
F 1 "560k" V 8457 4351 40  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 8380 4350 30  0001 C CNN
F 3 "" H 8450 4350 30  0000 C CNN
	1    8450 4350
	1    0    0    -1  
$EndComp
$Comp
L LTC3553 U5
U 1 1 5547D0A8
P 7250 3900
F 0 "U5" H 6900 2850 60  0000 C CNN
F 1 "LTC3553" H 7600 2850 60  0000 C CNN
F 2 "Housings_DFN_QFN:UQFN-20-1EP_3x3mm_Pitch0.4mm" H 7000 3000 60  0001 C CNN
F 3 "" H 7000 3000 60  0000 C CNN
	1    7250 3900
	1    0    0    -1  
$EndComp
$Comp
L C C23
U 1 1 5547D0AF
P 5800 3350
F 0 "C23" H 5800 3450 40  0000 L CNN
F 1 "10u" H 5806 3265 40  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5838 3200 30  0001 C CNN
F 3 "" H 5800 3350 60  0000 C CNN
	1    5800 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR046
U 1 1 5547D0B6
P 5800 3600
F 0 "#PWR046" H 5800 3350 60  0001 C CNN
F 1 "GND" H 5800 3450 60  0000 C CNN
F 2 "" H 5800 3600 60  0000 C CNN
F 3 "" H 5800 3600 60  0000 C CNN
	1    5800 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR047
U 1 1 5547D0BC
P 6400 3700
F 0 "#PWR047" H 6400 3450 60  0001 C CNN
F 1 "GND" H 6400 3550 60  0000 C CNN
F 2 "" H 6400 3700 60  0000 C CNN
F 3 "" H 6400 3700 60  0000 C CNN
	1    6400 3700
	0    1    1    0   
$EndComp
Text Notes 5650 5700 0    60   ~ 0
SUSP=0 activates input current limitation as per HPWR (1->500mA, 0->100mA)\nSEQ=1 sets LDO to start before Buck
$Comp
L +5V #PWR048
U 1 1 5547D0C4
P 5800 4300
F 0 "#PWR048" H 5800 4150 60  0001 C CNN
F 1 "+5V" H 5800 4440 60  0000 C CNN
F 2 "" H 5800 4300 60  0000 C CNN
F 3 "" H 5800 4300 60  0000 C CNN
	1    5800 4300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR049
U 1 1 5547D0CA
P 6400 4700
F 0 "#PWR049" H 6400 4450 60  0001 C CNN
F 1 "GND" H 6400 4550 60  0000 C CNN
F 2 "" H 6400 4700 60  0000 C CNN
F 3 "" H 6400 4700 60  0000 C CNN
	1    6400 4700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR050
U 1 1 5547D0D0
P 6400 4300
F 0 "#PWR050" H 6400 4050 60  0001 C CNN
F 1 "GND" H 6400 4150 60  0000 C CNN
F 2 "" H 6400 4300 60  0000 C CNN
F 3 "" H 6400 4300 60  0000 C CNN
	1    6400 4300
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5547D0D6
P 8450 4950
F 0 "R2" V 8530 4950 40  0000 C CNN
F 1 "180k" V 8457 4951 40  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 8380 4950 30  0001 C CNN
F 3 "" H 8450 4950 30  0000 C CNN
	1    8450 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR051
U 1 1 5547D0DD
P 8450 5250
F 0 "#PWR051" H 8450 5000 60  0001 C CNN
F 1 "GND" H 8450 5100 60  0000 C CNN
F 2 "" H 8450 5250 60  0000 C CNN
F 3 "" H 8450 5250 60  0000 C CNN
	1    8450 5250
	1    0    0    -1  
$EndComp
$Comp
L C C26
U 1 1 5547D0E9
P 8700 4350
F 0 "C26" H 8700 4450 40  0000 L CNN
F 1 "4u7" H 8706 4265 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8738 4200 30  0001 C CNN
F 3 "" H 8700 4350 60  0000 C CNN
	1    8700 4350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR052
U 1 1 5547D0F0
P 8700 5250
F 0 "#PWR052" H 8700 5000 60  0001 C CNN
F 1 "GND" H 8700 5100 60  0000 C CNN
F 2 "" H 8700 5250 60  0000 C CNN
F 3 "" H 8700 5250 60  0000 C CNN
	1    8700 5250
	1    0    0    -1  
$EndComp
Text Notes 8800 4050 0    60   ~ 0
VDD = 0.8(R1/R2+1)
$Comp
L R R15
U 1 1 5547D0F7
P 7600 2700
F 0 "R15" V 7680 2700 40  0000 C CNN
F 1 "2k2" V 7607 2701 40  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 7530 2700 30  0001 C CNN
F 3 "" H 7600 2700 30  0000 C CNN
	1    7600 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 4600 4500 4600
Wire Wire Line
	4000 2900 4500 2900
Wire Wire Line
	4000 3000 4500 3000
Wire Wire Line
	2000 3200 2000 3400
Wire Wire Line
	2000 3400 2200 3400
Wire Wire Line
	2800 5100 2800 5200
Wire Wire Line
	2100 5150 3400 5150
Wire Wire Line
	3400 5150 3400 5100
Connection ~ 2800 5150
Wire Wire Line
	3000 5150 3000 5100
Connection ~ 3000 5150
Wire Wire Line
	3200 5100 3200 5150
Connection ~ 3200 5150
Wire Wire Line
	3200 1950 3200 2600
Wire Wire Line
	1350 2750 1350 3000
Wire Wire Line
	1350 3000 1100 3000
Wire Wire Line
	2200 2900 2100 2900
Wire Wire Line
	2100 2900 2100 2250
Wire Wire Line
	1850 2250 1850 2300
Wire Wire Line
	1850 2750 1850 2700
Wire Wire Line
	2200 4700 2100 4700
Wire Wire Line
	2100 4700 2100 5150
Wire Wire Line
	3500 2100 3500 2050
Wire Wire Line
	3500 2050 3200 2050
Connection ~ 3200 2050
Wire Wire Line
	3500 2550 3500 2500
Wire Wire Line
	1100 3400 1350 3400
Wire Wire Line
	1350 3400 1350 3550
Wire Wire Line
	5800 2950 5800 3150
Wire Wire Line
	5800 3550 5800 3600
Wire Wire Line
	5800 4800 6500 4800
Wire Wire Line
	5800 4200 5800 4800
Wire Wire Line
	6500 4700 6400 4700
Wire Wire Line
	6500 4500 5800 4500
Connection ~ 5800 4500
Wire Wire Line
	6400 4300 6500 4300
Wire Wire Line
	6500 4400 6450 4400
Wire Wire Line
	6450 4400 6450 4300
Connection ~ 6450 4300
Wire Wire Line
	8050 3000 9100 3000
Wire Wire Line
	8450 5200 8450 5250
Wire Wire Line
	8450 4600 8450 4700
Connection ~ 8450 4650
Wire Wire Line
	8050 4000 8700 4000
Wire Wire Line
	8450 4000 8450 4100
Wire Wire Line
	8700 3900 8700 4150
Connection ~ 8450 4000
Connection ~ 8700 4000
Wire Wire Line
	8700 5250 8700 4550
Wire Wire Line
	6500 3100 5800 3100
Connection ~ 5800 3100
Wire Wire Line
	7200 2700 7350 2700
Wire Wire Line
	6800 2700 6450 2700
Wire Wire Line
	6450 2700 6450 3000
Wire Wire Line
	6450 3000 6500 3000
Wire Wire Line
	7850 2700 8450 2700
Wire Wire Line
	8450 2700 8450 3900
Wire Wire Line
	8450 4650 8250 4650
Wire Wire Line
	8250 4650 8250 4300
Wire Wire Line
	8250 4300 8050 4300
Wire Wire Line
	8450 3900 8050 3900
Connection ~ 8450 3000
Wire Wire Line
	6400 3700 6500 3700
Wire Wire Line
	6500 3400 6450 3400
Wire Wire Line
	6450 3400 6450 3700
Connection ~ 6450 3700
$Comp
L R R3
U 1 1 5547D149
P 6200 3950
F 0 "R3" V 6280 3950 40  0000 C CNN
F 1 "3k6" V 6207 3951 40  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 6130 3950 30  0001 C CNN
F 3 "" H 6200 3950 30  0000 C CNN
	1    6200 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	6450 3950 6500 3950
$Comp
L GND #PWR053
U 1 1 5547D151
P 5850 3950
F 0 "#PWR053" H 5850 3700 60  0001 C CNN
F 1 "GND" H 5850 3800 60  0000 C CNN
F 2 "" H 5850 3950 60  0000 C CNN
F 3 "" H 5850 3950 60  0000 C CNN
	1    5850 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 3950 5850 3950
Text Notes 5000 4000 0    60   ~ 0
Ichg=750/R3
$Comp
L C C25
U 1 1 5547D159
P 8700 3250
F 0 "C25" H 8700 3350 40  0000 L CNN
F 1 "10u" H 8706 3165 40  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8738 3100 30  0001 C CNN
F 3 "" H 8700 3250 60  0000 C CNN
	1    8700 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR054
U 1 1 5547D160
P 8700 3500
F 0 "#PWR054" H 8700 3250 60  0001 C CNN
F 1 "GND" H 8700 3350 60  0000 C CNN
F 2 "" H 8700 3500 60  0000 C CNN
F 3 "" H 8700 3500 60  0000 C CNN
	1    8700 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3500 8700 3450
Wire Wire Line
	8700 3000 8700 3050
$Comp
L +BATT #PWR055
U 1 1 5547D168
P 8200 3300
F 0 "#PWR055" H 8200 3150 60  0001 C CNN
F 1 "+BATT" H 8200 3440 60  0000 C CNN
F 2 "" H 8200 3300 60  0000 C CNN
F 3 "" H 8200 3300 60  0000 C CNN
	1    8200 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 3300 8200 3450
Wire Wire Line
	8200 3450 8050 3450
$Comp
L CONN_01X02 P10
U 1 1 5547D170
P 7100 1750
F 0 "P10" H 7100 1900 50  0000 C CNN
F 1 "CONN_01X02" V 7200 1750 50  0000 C CNN
F 2 "w_conn_jst-ph:b2b-ph-kl" H 7100 1750 60  0001 C CNN
F 3 "" H 7100 1750 60  0000 C CNN
	1    7100 1750
	-1   0    0    -1  
$EndComp
$Comp
L +BATT #PWR056
U 1 1 5547D177
P 7400 1350
F 0 "#PWR056" H 7400 1200 60  0001 C CNN
F 1 "+BATT" H 7400 1490 60  0000 C CNN
F 2 "" H 7400 1350 60  0000 C CNN
F 3 "" H 7400 1350 60  0000 C CNN
	1    7400 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR057
U 1 1 5547D17D
P 7400 2150
F 0 "#PWR057" H 7400 1900 60  0001 C CNN
F 1 "GND" H 7400 2000 60  0000 C CNN
F 2 "" H 7400 2150 60  0000 C CNN
F 3 "" H 7400 2150 60  0000 C CNN
	1    7400 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 1800 7400 1800
Wire Wire Line
	7400 1800 7400 2150
Wire Wire Line
	7400 1700 7300 1700
Wire Wire Line
	7400 1350 7400 1700
$Comp
L GND #PWR058
U 1 1 5547D187
P 7250 5250
F 0 "#PWR058" H 7250 5000 60  0001 C CNN
F 1 "GND" H 7250 5100 60  0000 C CNN
F 2 "" H 7250 5250 60  0000 C CNN
F 3 "" H 7250 5250 60  0000 C CNN
	1    7250 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 5250 7250 5100
$Comp
L VDD #PWR059
U 1 1 5547D18E
P 8700 3900
F 0 "#PWR059" H 8700 3750 60  0001 C CNN
F 1 "VDD" H 8700 4050 60  0000 C CNN
F 2 "" H 8700 3900 60  0000 C CNN
F 3 "" H 8700 3900 60  0000 C CNN
	1    8700 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 3100 2200 3100
Wire Wire Line
	2000 3200 1100 3200
Text HLabel 4500 2900 2    60   Output ~ 0
FTDI_TXD
Text HLabel 4500 3000 2    60   Input ~ 0
FTDI_RXD
Text HLabel 4500 4600 2    60   Output ~ 0
PWREN#
Text HLabel 6300 3300 0    60   Input ~ 0
HPWR
Wire Wire Line
	6300 3300 6500 3300
Wire Wire Line
	1850 2250 3000 2250
Connection ~ 2100 2250
Wire Wire Line
	3000 2250 3000 2600
$Comp
L LP2992 U6
U 1 1 554CDDB8
P 9650 3100
F 0 "U6" H 9400 2850 60  0000 C CNN
F 1 "LP2992" H 9850 2850 60  0000 C CNN
F 2 "Housings_SOT-23_SOT-143_TSOT-6:SOT-23-5" H 9700 2650 60  0001 C CNN
F 3 "" H 9700 2650 60  0000 C CNN
	1    9650 3100
	1    0    0    -1  
$EndComp
$Comp
L C C27
U 1 1 554CE13A
P 10550 3400
F 0 "C27" H 10550 3500 40  0000 L CNN
F 1 "10n" H 10556 3315 40  0000 L CNN
F 2 "Capacitors_SMD:C_0402" H 10588 3250 30  0001 C CNN
F 3 "" H 10550 3400 60  0000 C CNN
	1    10550 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 3100 10550 3100
Wire Wire Line
	10550 3100 10550 3200
$Comp
L C C28
U 1 1 554CE24C
P 10800 3400
F 0 "C28" H 10800 3500 40  0000 L CNN
F 1 "10u" H 10806 3315 40  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 10838 3250 30  0001 C CNN
F 3 "" H 10800 3400 60  0000 C CNN
	1    10800 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 3000 10800 3000
Wire Wire Line
	10800 2850 10800 3200
$Comp
L GND #PWR060
U 1 1 554CE33C
P 10350 3850
F 0 "#PWR060" H 10350 3600 60  0001 C CNN
F 1 "GND" H 10350 3700 60  0000 C CNN
F 2 "" H 10350 3850 60  0000 C CNN
F 3 "" H 10350 3850 60  0000 C CNN
	1    10350 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 3200 10350 3200
Wire Wire Line
	10350 3200 10350 3850
Wire Wire Line
	10350 3750 10800 3750
Wire Wire Line
	10800 3750 10800 3600
Connection ~ 10350 3750
Wire Wire Line
	10550 3600 10550 3750
Connection ~ 10550 3750
$Comp
L VAA #PWR061
U 1 1 554CE50D
P 10800 2850
F 0 "#PWR061" H 10800 2700 60  0001 C CNN
F 1 "VAA" H 10800 3000 60  0000 C CNN
F 2 "" H 10800 2850 60  0000 C CNN
F 3 "" H 10800 2850 60  0000 C CNN
	1    10800 2850
	1    0    0    -1  
$EndComp
Connection ~ 10800 3000
Connection ~ 8700 3000
Wire Wire Line
	9050 3200 9100 3200
Wire Wire Line
	9050 3200 9050 3000
Connection ~ 9050 3000
$Comp
L C C24
U 1 1 554F7776
P 7650 1750
F 0 "C24" H 7650 1850 40  0000 L CNN
F 1 "22u" H 7656 1665 40  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 7688 1600 30  0001 C CNN
F 3 "" H 7650 1750 60  0000 C CNN
	1    7650 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 1450 7650 1450
Wire Wire Line
	7650 1450 7650 1550
Connection ~ 7400 1450
Wire Wire Line
	7400 2050 7650 2050
Wire Wire Line
	7650 2050 7650 1950
Connection ~ 7400 2050
$Comp
L LED D6
U 1 1 556C8853
P 4600 3700
F 0 "D6" H 4700 3600 50  0000 C CNN
F 1 "TXLED" H 4500 3600 50  0000 C CNN
F 2 "LEDs:LED-0603" H 4600 3700 60  0001 C CNN
F 3 "" H 4600 3700 60  0000 C CNN
	1    4600 3700
	0    1    1    0   
$EndComp
$Comp
L LED D7
U 1 1 556C8922
P 4800 3700
F 0 "D7" H 4900 3600 50  0000 C CNN
F 1 "RXLED" H 4700 3600 50  0000 C CNN
F 2 "LEDs:LED-0603" H 4800 3700 60  0001 C CNN
F 3 "" H 4800 3700 60  0000 C CNN
	1    4800 3700
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 556C8D94
P 4300 4000
F 0 "R20" V 4380 4000 40  0000 C CNN
F 1 "2k2" V 4307 4001 40  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4230 4000 30  0001 C CNN
F 3 "" H 4300 4000 30  0000 C CNN
	1    4300 4000
	0    -1   -1   0   
$EndComp
$Comp
L R R21
U 1 1 556C8DEC
P 4300 4200
F 0 "R21" V 4380 4200 40  0000 C CNN
F 1 "2k2" V 4307 4201 40  0000 C CNN
F 2 "Resistors_SMD:R_0402" V 4230 4200 30  0001 C CNN
F 3 "" H 4300 4200 30  0000 C CNN
	1    4300 4200
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR062
U 1 1 556C8FE1
P 4600 3300
F 0 "#PWR062" H 4600 3150 60  0001 C CNN
F 1 "+5V" H 4600 3440 60  0000 C CNN
F 2 "" H 4600 3300 60  0000 C CNN
F 3 "" H 4600 3300 60  0000 C CNN
	1    4600 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 4000 4050 4000
Wire Wire Line
	4000 4200 4050 4200
Wire Wire Line
	4550 4000 4600 4000
Wire Wire Line
	4600 4000 4600 3900
Wire Wire Line
	4550 4200 4800 4200
Wire Wire Line
	4800 4200 4800 3900
Wire Wire Line
	4600 3300 4600 3500
Wire Wire Line
	4600 3400 4800 3400
Wire Wire Line
	4800 3400 4800 3500
Connection ~ 4600 3400
$EndSCHEMATC
