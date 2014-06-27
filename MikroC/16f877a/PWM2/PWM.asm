
_InitMain:

;PWM.c,3 :: 		void InitMain() {
;PWM.c,4 :: 		PORTA = 255;
	MOVLW      255
	MOVWF      PORTA+0
;PWM.c,5 :: 		TRISA = 255;                        // configure PORTA pins as input
	MOVLW      255
	MOVWF      TRISA+0
;PWM.c,6 :: 		PORTB = 0;                          // set PORTB to 0
	CLRF       PORTB+0
;PWM.c,7 :: 		TRISB = 0;                          // designate PORTB pins as output
	CLRF       TRISB+0
;PWM.c,8 :: 		PORTC = 0;                          // set PORTC to 0
	CLRF       PORTC+0
;PWM.c,9 :: 		TRISC = 0;                          // designate PORTC pins as output
	CLRF       TRISC+0
;PWM.c,10 :: 		PWM1_Init(10000);                    // Initialize PWM1 module at 5KHz
	BSF        T2CON+0, 0
	BCF        T2CON+0, 1
	MOVLW      124
	MOVWF      PR2+0
	CALL       _PWM1_Init+0
;PWM.c,11 :: 		PWM2_Init(10000);                    // Initialize PWM2 module at 5KHz}
	BSF        T2CON+0, 0
	BCF        T2CON+0, 1
	MOVLW      124
	MOVWF      PR2+0
	CALL       _PWM2_Init+0
;PWM.c,12 :: 		}
	RETURN
; end of _InitMain

_main:

;PWM.c,14 :: 		void main() {
;PWM.c,15 :: 		InitMain();
	CALL       _InitMain+0
;PWM.c,16 :: 		current_duty  = 200;                 // initial value for current_duty
	MOVLW      200
	MOVWF      _current_duty+0
;PWM.c,17 :: 		current_duty1 = 200;                 // initial value for current_duty1
	MOVLW      200
	MOVWF      _current_duty1+0
;PWM.c,18 :: 		TRISA  = 0xFF;              // PORTA is input
	MOVLW      255
	MOVWF      TRISA+0
;PWM.c,19 :: 		TRISB = 0xFF;                             // Set PORTB as input
	MOVLW      255
	MOVWF      TRISB+0
;PWM.c,21 :: 		PWM1_Start();                       // start PWM1
	CALL       _PWM1_Start+0
;PWM.c,22 :: 		PWM2_Start();                       // start PWM2
	CALL       _PWM2_Start+0
;PWM.c,23 :: 		PWM1_Set_Duty(0);        // Set current duty for PWM1
	CLRF       FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;PWM.c,24 :: 		PWM2_Set_Duty(0);       // Set current duty for PWM2
	CLRF       FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
;PWM.c,25 :: 		adcon1 = 0b1000010;
	MOVLW      66
	MOVWF      ADCON1+0
;PWM.c,26 :: 		while (1) {                         // endless loop
L_main0:
;PWM.c,28 :: 		temp_res = ADC_Read(0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	MOVF       R0+0, 0
	MOVWF      _temp_res+0
	MOVF       R0+1, 0
	MOVWF      _temp_res+1
	CLRF       _temp_res+2
	CLRF       _temp_res+3
;PWM.c,29 :: 		temp_res=temp_res*255.0/1024.0;
	MOVF       _temp_res+0, 0
	MOVWF      R0+0
	MOVF       _temp_res+1, 0
	MOVWF      R0+1
	MOVF       _temp_res+2, 0
	MOVWF      R0+2
	MOVF       _temp_res+3, 0
	MOVWF      R0+3
	CALL       _Longword2Double+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      127
	MOVWF      R4+2
	MOVLW      134
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      0
	MOVWF      R4+2
	MOVLW      137
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	CALL       _Double2Longword+0
	MOVF       R0+0, 0
	MOVWF      _temp_res+0
	MOVF       R0+1, 0
	MOVWF      _temp_res+1
	MOVF       R0+2, 0
	MOVWF      _temp_res+2
	MOVF       R0+3, 0
	MOVWF      _temp_res+3
;PWM.c,30 :: 		newduty=temp_res;
	MOVF       R0+0, 0
	MOVWF      _newduty+0
;PWM.c,31 :: 		if(RB0_bit==1 && RB1_bit==0){
	BTFSS      RB0_bit+0, 0
	GOTO       L_main4
	BTFSC      RB1_bit+0, 1
	GOTO       L_main4
L__main12:
;PWM.c,32 :: 		PWM1_Set_Duty(newduty);
	MOVF       _newduty+0, 0
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;PWM.c,33 :: 		PWM2_Set_Duty(0);
	CLRF       FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
;PWM.c,34 :: 		}else if(RB0_bit==0 && RB1_bit==1){
	GOTO       L_main5
L_main4:
	BTFSC      RB0_bit+0, 0
	GOTO       L_main8
	BTFSS      RB1_bit+0, 1
	GOTO       L_main8
L__main11:
;PWM.c,35 :: 		PWM1_Set_Duty(0);
	CLRF       FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;PWM.c,36 :: 		PWM2_Set_Duty(newduty);
	MOVF       _newduty+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
;PWM.c,37 :: 		}
	GOTO       L_main9
L_main8:
;PWM.c,39 :: 		PWM1_Set_Duty(0);
	CLRF       FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
;PWM.c,40 :: 		PWM2_Set_Duty(0);
	CLRF       FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
;PWM.c,41 :: 		}
L_main9:
L_main5:
;PWM.c,44 :: 		Delay_ms(5);                      // slow down change pace a little
	MOVLW      33
	MOVWF      R12+0
	MOVLW      118
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
	NOP
;PWM.c,45 :: 		}
	GOTO       L_main0
;PWM.c,46 :: 		}
	GOTO       $+0
; end of _main
