#line 1 "D:/IGNACIO/ProgramacionGitHub/SistemasEmbebidos2014-I/MikroC/16f877a/PWM1/PWM.c"
unsigned short current_duty, old_duty, current_duty1, old_duty1,newduty;
unsigned long temp_res;
void InitMain() {
 PORTA = 255;
 TRISA = 255;
 PORTB = 0;
 TRISB = 0;
 PORTC = 0;
 TRISC = 0;
 PWM1_Init(20000);
 PWM2_Init(20000);
 }

void main() {
 InitMain();
 current_duty = 200;
 current_duty1 = 200;
 TRISA = 0xFF;
 TRISB = 0xFF;

 PWM1_Start();
 PWM2_Start();
 PWM1_Set_Duty(0);
 PWM2_Set_Duty(0);
 adcon1 = 0b1000010;
 while (1) {

 temp_res = ADC_Read(0);
 temp_res=temp_res*255.0/1024.0;
 newduty=temp_res;
 if(RB0_bit==1 && RB1_bit==0){
 PWM1_Set_Duty(newduty);
 PWM2_Set_Duty(0);
 }else if(RB0_bit==0 && RB1_bit==1){
 PWM1_Set_Duty(0);
 PWM2_Set_Duty(newduty);
 }
 else{
 PWM1_Set_Duty(0);
 PWM2_Set_Duty(0);
 }


 Delay_ms(5);
 }
}
