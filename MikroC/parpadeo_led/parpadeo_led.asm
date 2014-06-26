
_main:

;parpadeo_led.c,1 :: 		void main() {
;parpadeo_led.c,2 :: 		TRISB = 0x00;
	CLRF       TRISB+0
;parpadeo_led.c,3 :: 		if (RB0_bit == 0){ RB0_bit = 1;}
	BTFSC      RB0_bit+0, 0
	GOTO       L_main0
	BSF        RB0_bit+0, 0
	GOTO       L_main1
L_main0:
;parpadeo_led.c,4 :: 		else {RB0_bit = 0;}
	BCF        RB0_bit+0, 0
L_main1:
;parpadeo_led.c,5 :: 		delay_ms(500);
	MOVLW      13
	MOVWF      R11+0
	MOVLW      175
	MOVWF      R12+0
	MOVLW      182
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
;parpadeo_led.c,6 :: 		}
	GOTO       $+0
; end of _main
