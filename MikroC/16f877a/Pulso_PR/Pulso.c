void main() {
     TRISB = 0x00;
     while (1){
     RB0_bit=1;
     Delay_ms(50);
     RB0_bit=0;
     Delay_ms(50);}
     
}