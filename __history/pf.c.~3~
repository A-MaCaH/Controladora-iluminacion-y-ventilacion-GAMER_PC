#INCLUDE<16f887.h>
#USE DELAY(CLOCK=4000000)
#FUSES XT,PROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#DEFINE SW PORTA,1
#DEFINE LED PORTB,0
#BYTE PORTA= 5
#BYTE PORTB= 6
MAIN()
{
   SET_TRIS_A(0B10);          //Configura el puerto A
   SET_TRIS_B(0B11111110);    //Configura el puerto B
   WHILE(TRUE)                // Haga por siempre
   {
      IF(BIT_TEST(SW))        // Si SW esta activado
      {
         BIT_SET(LED);        // Active el led
      }
      ELSE                    // Sino, es decir si SW esta desactivado
      {
         BIT_CLEAR(LED);      // Apagar led
      }
   }
}
