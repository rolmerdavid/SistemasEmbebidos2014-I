#INCLUDE <16f877a.h>
#DEVICE ICD=TRUE
#DEVICE adc=10
#FUSES HS,NOWDT,NOPROTECT,NOLVP  
#USE FAST_IO(A) 
#USE FAST_IO(B)

#use delay(crystal=20000000)

void main()
{
   SET_TRIS_B(0x00);
   while(TRUE)
   {
      output_high(PIN_B0);
      delay_ms(50);
      output_low(PIN_B0);
      delay_ms(50);
   }

}
