#include <16F877A.h>
#device ADC=16
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(crystal=20000000)

#use FAST_IO(B)

long cont;
long comp1;
//#INT_RTCC
//void  RTCC_isr(void) 
//{

//}
//----------------------------------
#INT_RTCC
void RTCC_isr() //function interrupción TMR0
   {   
   output_toggle(PIN_B2);
   set_TIMER0(5); //inicializa el timer0 para que cuente 0.2 us
   cont++;
   //Giro en un sentido
   if(input(PIN_B0)==1){
      if ((int16)cont==(int16)10){ cont=0;
            output_high(PIN_B3);}
      if((int16)comp1==(int16)cont){
            output_low(PIN_B3);}
   }
   if (input(PIN_B0)==0)
   output_low(PIN_B3);
    //--------------Giro opuesto----------------
       if(input(PIN_B1)==1){
      if ((int16)cont==(int16)10){ cont=0;
            output_high(PIN_B4);}
      if((int16)comp1==(int16)cont){
            output_low(PIN_B4);}
   }
   if (input(PIN_B1)==0)
   output_low(PIN_B4);
    
   }

 
   



//---------------------------------
   void main()
{  //#byte TRISB=0b11000000;
   set_TIMER0(5); //inicializa el timer0 para que cuente 0.2 us
   SET_TRIS_B(0xC0);    //configura PORTB entrada / 0=salida / 1=entrada
   OUTPUT_D(0x00);   //inicializando PORTD en 0x00
   //#byte PORTB=0x00;
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);//|RTCC_8_bit);      //51.2 us overflow
  // setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);      //13.1 ms overflow

  // setup_ccp1(CCP_COMPARE_SET_ON_MATCH);

  // enable_interrupts(INT_RTCC);
   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
   cont=0;
   comp1=0;

   while(TRUE)
   {

   set_adc_channel(0);
   delay_us(20);//tiempo  de offset necesario
   comp1=((read_adc())*10.0/1024.0); 
   delay_us(20);//tiempo  de offset necesario
 
   }

}

