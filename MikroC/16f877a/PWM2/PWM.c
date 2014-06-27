unsigned short current_duty, old_duty, current_duty1, old_duty1,newduty;
unsigned long temp_res;
void InitMain() {
  PORTA = 255;
  TRISA = 255;                        // configure PORTA pins as input
  PORTB = 0;                          // set PORTB to 0
  TRISB = 0;                          // designate PORTB pins as output
  PORTC = 0;                          // set PORTC to 0
  TRISC = 0;                          // designate PORTC pins as output
  PWM1_Init(10000);                    // Initialize PWM1 module at 5KHz
  PWM2_Init(10000);                    // Initialize PWM2 module at 5KHz}
  }

void main() {
  InitMain();
  current_duty  = 200;                 // initial value for current_duty
  current_duty1 = 200;                 // initial value for current_duty1
  TRISA  = 0xFF;              // PORTA is input
  TRISB = 0xFF;                             // Set PORTB as input
  //PORTB = 0x00;
  PWM1_Start();                       // start PWM1
  PWM2_Start();                       // start PWM2
  PWM1_Set_Duty(0);        // Set current duty for PWM1
  PWM2_Set_Duty(0);       // Set current duty for PWM2
  adcon1 = 0b1000010;
  while (1) {                         // endless loop

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
    

    Delay_ms(5);                      // slow down change pace a little
  }
}