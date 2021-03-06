#include <16F877A.h>
#FUSES HS,NOWDT,NOPROTECT,NOLVP 

#USE delay(crystal=10000000)



#USE FAST_IO(B)   //Puerto B
#USE FAST_IO(D)   //Puerto D


// **********************************************
// Declaracion de las funciones
void Cargar_configuracion();
void Configurar_interrupciones();
void invertir_PORTD();
//***********************************************


// **********************************************
// Interrupciones
#INT_EXT             // Interrupcion RB0
void  EXT_isr(void) 
{
   invertir_PORTD();
}
#INT_RB
void  RB_isr(void) {
   if (input(PIN_B4) == 1 ){
      invertir_PORTD();
   } else if (input(PIN_B5) == 1){

   }else if (input(PIN_B6) == 1){

   }else if (input(PIN_B7) == 1){

   }
}

//***********************************************

// **********************************************
// Funcion Principal
void main()
{
   Cargar_configuracion();
   Configurar_interrupciones();
   while(TRUE)
   {
      //TODO: User Code
   }

}
//**********************************************


// *********************************************
// Definicion de las funciones

void Cargar_configuracion() {
   SET_TRIS_B(0xFF);    //configura PORTB entrada / 0=salida / 1=entrada
   SET_TRIS_D(0x00);    //configura PORTD salida
   OUTPUT_D(0xFF);   //inicializando PORTD en 0x00
}
void Configurar_interrupciones(){
   enable_interrupts(INT_EXT);   // habilitar interrupcion del RB0 /INTE
   ext_int_edge(L_TO_H);         // Flag INTF si flanco de bajada / H_TO_L bajada
   enable_interrupts(INT_RB);    // habilita interrupcion del RB 
   enable_interrupts(GLOBAL);
}

void invertir_PORTD(){
   if (input(PIN_D0) == 1 ){ 
      output_low(PIN_D0);
   }else {
      output_high(PIN_D0);
   }
}
//**********************************************
