
_main:

;Pulso.c,1 :: 		void main() {
;Pulso.c,2 :: 		TRISB = 0x00;
	CLRF       TRISB+0
;Pulso.c,3 :: 		while (1){
L_main0:
;Pulso.c,4 :: 		RB0_bit=1;
	BSF        RB0_bit+0, 0
;Pulso.c,5 :: 		Delay_ms(50);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;Pulso.c,6 :: 		RB0_bit=0;
	BCF        RB0_bit+0, 0
;Pulso.c,7 :: 		Delay_ms(50);}
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
	NOP
	GOTO       L_main0
;Pulso.c,9 :: 		}
	GOTO       $+0
; end of _main
