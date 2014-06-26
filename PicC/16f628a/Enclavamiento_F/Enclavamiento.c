#include <16F628A.h>

#FUSES HS,NOWDT,NOPROTECT,NOLVP
#use delay(internal=4000000)

#USE FAST_IO(B)   //Puerto B
#USE FAST_IO(A)   //Puerto D
//#BIT RBIF = 0x0B.0


// *****************************************************************
// Declaracino de Variables
int1 RB4_ant;
int1 RB5_ant;
int1 RB6_ant;
int1 RB7_ant;
//******************************************************************

// *****************************************************************
// Declaracion de Funciones
void Configuracion();
void Configurar_interrupciones();
void Variar_led();
void Verificar_RB();

//******************************************************************

// *****************************************************************
// Declaracion de las Interrupciones
#INT_EXT       //Sentencias de la interrupcion RB0
void ext_isr(){
   Variar_led();
}

#INT_RB
void RB_isr() {
   Variar_led();
   //RBIF = 0;
}

//******************************************************************

// *****************************************************************
// Funcion Prinipal
void main()
{
   Configuracion();
   Configurar_interrupciones();
   while(TRUE)
   {
     Verificar_RB();
     delay_ms(50);
   }

}
//*****************************************************************

// ****************************************************************
// Definicion de Funciones
void Configuracion(){
   SET_TRIS_B(0xFF);    //configura PORTB entrada / 0=salida / 1=entrada
   SET_TRIS_A(0x00);    //configura PORTD salida  
   OUTPUT_A(0x00);   //inicializando PORTD en 0x00
   RB4_ant = input(PIN_B4);
   RB5_ant = input(PIN_B5);
   RB6_ant = input(PIN_B6);
   RB7_ant = input(PIN_B7);
}

void Configurar_interrupciones(){

   enable_interrupts(INT_EXT);    // Habilita la interrupcion RB0
   //enable_interrupts(INT_RB);    // Habilita la interrupcion RB
   ext_int_edge(H_TO_L);         // Flag INTF si flanco de bajada / H_TO_L bajada
   enable_interrupts(GLOBAL);

}

void Variar_led(){
   if (input(PIN_A0) == 1 ){
         output_low(PIN_A0);   //establece la salida del PORTD
      }else {
         output_high(PIN_A0);
      }
}

void Verificar_RB(){
   if (input(PIN_B4) == 1 && RB4_ant == 0){
      Variar_led();
   }
   if (input(PIN_B5) == 1 && RB5_ant == 0){
      Variar_led();
   }
   if (input(PIN_B6) == 1 && RB6_ant == 0){
      Variar_led();
   }
   if (input(PIN_B7) == 1 && RB7_ant == 0){
      Variar_led();
   }
   RB4_ant = input(PIN_B4);
   RB5_ant = input(PIN_B5);
   RB6_ant = input(PIN_B6);
   RB7_ant = input(PIN_B7);
}
//****************************************************************
