#include <16f887.h>
#fuses xt,nowdt,HS,NOWDT,NOPROTECT,NOLVP
#device ADC=8 
#use delay(crystal=4000000)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7,bits=8)
#BYTE PORTB=6
#BYTE PORTA= 5
int valor;

#int_RDA
RDA_isr()
{
  valor=getc();
  putc(valor);
}

void main()
{
int led1=0,led2=0;
int numLed=0;
int numLed2=0;
int secPorcolorV2=0;
int secPorcolorV1=0;
 SET_TRIS_B(0B00000000);          //Configura el Puerto B Como salidas
 PORTB=0; 
 SET_TRIS_A(0B00000000);          //Configura el Puerto B Como salidas
 PORTA=0; 
 
 enable_interrupts(INT_RDA);
 enable_interrupts(GLOBAL);
 setup_adc(ADC_CLOCK_DIV_32);      
 setup_ccp1(CCP_PWM);   // Configure CCP1 as a PWM
 setup_ccp2(CCP_PWM);                 // Configure CCP2 as a PWM
 delay_ms(100);                         // Wait 100ms
 setup_timer_2(T2_DIV_BY_16, 255, 1);   // Set PWM frequency to 488Hz
 
 
  while(TRUE){
     // función por lo que se obtiene de la
     //comunicación UART
     switch(valor){
         case 'a':
             set_pwm1_duty(250);
             set_pwm2_duty(250);
             delay_ms(1);
         break;
         case 'b':
             set_pwm1_duty(250);
             set_pwm2_duty(175);
             delay_ms(1);
         break;
         case 'c':
             set_pwm1_duty(250);
             set_pwm2_duty(100);
             delay_ms(1);
         break;
         case 'd':
             set_pwm1_duty(175);
             set_pwm2_duty(250);
             delay_ms(1);
         break;
         case 'e':
             set_pwm1_duty(175);
             set_pwm2_duty(175);
             delay_ms(1);
         break;
         case 'f':
             set_pwm1_duty(175);
             set_pwm2_duty(100);
             delay_ms(1);
         break;
         case 'g':
             set_pwm1_duty(100);
             set_pwm2_duty(250);
             delay_ms(1);
         break;
         case 'h':
             set_pwm1_duty(100);
             set_pwm2_duty(175);
             delay_ms(1);
         break;
         case 'i':
             set_pwm1_duty(100);
             set_pwm2_duty(100);
             delay_ms(1);
         break;
         //---------------------
         case 'j':
             secPorcolorV1=0;
             numLed=0;
             delay_ms(250);
         break;
         case 'k':
             secPorcolorV1=0;
             numLed=1;
             delay_ms(250);
         break;
         case 'l':
             secPorcolorV1=1;
             numLed=0;
             delay_ms(250);
         break;
         case 'm':
             secPorcolorV1=1;
             numLed=1;
             delay_ms(250);
         break;
         //--------------------------------------
         case 'n':
             secPorcolorV2=0;
             numLed2=0;
             delay_ms(250);
         break;
         case 'o':
             secPorcolorV2=0;
             numLed2=1;
             delay_ms(250);
         break;
         case 'p':
             secPorcolorV2=1;
             numLed2=0;
             delay_ms(250);
         break;
         case 'q':
             secPorcolorV2=1;
             numLed2=1;
             delay_ms(250);
         break;
         default:
             set_pwm1_duty(255);
             set_pwm2_duty(255);
             delay_ms(1);
     }
    // manejo de los led
    // SISTEMA DE LED VENTILADOR 1
   switch(secPorcolorV1){
      case 0:
         if(led1<8){
            led1=led1+1;
         }
         else{
            led1=0;
         }
      break;
      case 1:
         if(led1<4){
            led1=led1+1;
         }
         else{
            led1=0;
         }
      break;
   }
   
    // SISTEMA DE LED VENTILADOR 2
   switch(secPorcolorV2){
      case 0:
         if(led2<8){
            led2=led2+1;
         }
         else{
            led2=0;
         }
      break;
      case 1:
         if(led2<4){
            led2=led2+1;
         }
         else{
            led2=0;
         }
      break;
   }
   
   //Lo que manda el micro a la salida  para los led´s
     if(numLed==0){//DOS LED
         switch(led1){
         case 0:
            PORTA=0B00111000;
         break;
         case 1:
            PORTA=0B00000111;
         break;
         case 2:
            PORTA=0B00101000;
         break;
         case 3:
            PORTA=0B00000101;
         break;
         case 4:
            PORTA=0B00110000;
         break;
         case 5:
            PORTA=0B00000110;
         case 6:
            PORTA=0B00011000;
         break;
         case 7:
            PORTA=0B00000011;
            
         break;
         default:PORTA=0B00001000;
         }
     }
     else{//cuatro LED
         switch(led1){
         case 0:
            PORTA=0B0011111;
         break;
         case 1:
            PORTA=0B00110110;
         break;
         case 2:
            PORTA=0B00101101;
         break;
         case 3:
            PORTA=0B00100100;
         break;
         case 4:
            PORTA=0B00011011;
         break;
         case 5:
            PORTA=0B00001001;
         break;
         case 6:
            PORTA=0B00111011;
         break;
         case 7:
            PORTA=0B00010010;
         default:PORTA=0B00001001;}
     }
   if(numLed2==0){//DOS LED
         switch(led2){
         case 0:
            PORTB=0B00111000;
         break;
         case 1:
            PORTB=0B00000111;
         break;
         case 2:
            PORTB=0B00101000;
         break;
         case 3:
            PORTB=0B00000101;
         break;
         case 4:
            PORTB=0B00110000;
         break;
         case 5:
            PORTB=0B00000110;
         case 6:
            PORTB=0B00011000;
         break;
         case 7:
            PORTB=0B00000011;
            
         break;
         default:PORTB=0B00000001;}
     }
     else{//cuatro LED
         switch(led2){
         case 0:
            PORTB=0B0011111;
         break;
         case 1:
            PORTB=0B00110110;
         break;
         case 2:
            PORTB=0B00101101;
         break;
         case 3:
            PORTB=0B00100100;
         break;
         case 4:
            PORTB=0B00011011;
         break;
         case 5:
            PORTB=0B00001001;
         break;
         case 6:
            PORTB=0B00111011;
         break;
         case 7:
            PORTB=0B00010010;
         default:PORTB=0B00001001;}
     }
  }

}
