#line 1 "D:/IGNACIO/Programacion/Microcontroladores/MikroC/parpadeo_led/parpadeo_led.c"
void main() {
 TRISB = 0x00;
 if (RB0_bit == 0){ RB0_bit = 1;}
 else {RB0_bit = 0;}
 delay_ms(500);
}
