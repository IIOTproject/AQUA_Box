#include "SIGFOX.h"
static const String device = "UNABIZ_DevKit_1";
static const bool useEmulator = false;
static const bool echo = true;
static const Country country = COUNTRY_TW; // set this to your country to configure the Sigfox transmission frequencies
static UnaShieldV2S transceiver(country, useEmulator, device, echo);

volatile int NbTopsFan; //measuring the rising edges of the signal

#define hallsensor 2 //The pin location of the sensor，藍色
#define sensor_tb  A0 //橘色
#define sensor_rain A2 //白色
#define level_1 10//黃色短
#define level_2 11//黃色長

uint8_t level_val,new_level_val;
int  tb_value =0,new_tb_value=0;
uint16_t  rain_ad =0,new_speed_value=0,speed_value=0;
float new_tb_ad =0;

uint16_t minsec_flag=0;
uint8_t sec_flag =0,min_flag =0,alarm_flag =5 , one_time=0; 
char rain_val [3] ;
char rain [2];
String level, rai;


void rpm () //This is the function that the interupt calls
{
  NbTopsFan++; //This function measures the rising and falling edge of the

}
// The setup() method runs once, when the sketch starts
void setup() 
{
   Serial.begin(9600); //This is  setup function where the serial port is
   Serial.println(F("Running setup..."));
   if (!transceiver.begin()){
      stop(F("Unable to init SIGFOX module, may be missing"));
   } 
   //transceiver.sendMessage("0102030405060708090a0b0c");
   //envoyer message, Totale message constrained in 12 bytes
   
   pinMode(hallsensor, INPUT_PULLUP); //initializes digital pin 2 as an input
   pinMode(sensor_tb,INPUT);
   pinMode(sensor_rain,INPUT_PULLUP);
   pinMode(level_1,INPUT_PULLUP);
   pinMode(level_2,INPUT_PULLUP);
   
   attachInterrupt(0, rpm, RISING); //and the interrupt is attached
   Serial.println(F("Waiting 10 seconds..."));
   //sei(); //Enables interrupts
}

void loop ()
{
   //sei(); //Enables interrupts
   delay (1); //Wait 1 minsecond
   minsec_flag +=1;
    if (alarm_flag  == 5)
       {
       
          if (new_tb_value >700 && level_val ==3 )
          {
            Serial.println("alarm");
            transceiver.sendMessage("01++3++");
            
            
            alarm_flag = 0;
          }
          
       }
   if(minsec_flag >=1000)
   {
       minsec_flag =0;
       sec_flag += 1; 
      //cli(); //Disable interrupts
    
       new_level_val=water_level();
       rain_ad = analogRead(sensor_rain);   
       new_tb_ad = analogRead(sensor_tb);
       Serial.print("1.sensor_tb_ad1:");
       Serial.println(new_tb_ad); 
       new_tb_ad=new_tb_ad * (5.0 / 1024.0);
       //new_tb_ad = new_tb_ad -0.25;
       Serial.print("2.sensor_tb_ad2:");
       Serial.println(new_tb_ad); 
       new_tb_value=-(1120.4*(new_tb_ad*new_tb_ad))+5742.3*new_tb_ad-4352.9 ;
       Serial.print("3.sensor_tb_ad3:");
       Serial.println(new_tb_value); 
       new_speed_value = (NbTopsFan * 60 / 7.5); //(Pulse frequency x 60) / 7.5Q, = flow rate
       NbTopsFan = 0; //Set NbTops to 0 ready for calculations
       level_add_rain (rain_ad,new_level_val);
       Serial.print("4.sensor_speed_value:");
       Serial.print (new_speed_value, DEC); //Prints the number calculated above
       Serial.println (" L/hour\r\n"); //Prints "L/hour" and returns a new line
       Serial.print("5.senso_level_tb_ad_value:");
       Serial.println(new_level_val);
       Serial.print("6.senso_rain:");
       Serial.println(rain_ad);

      
          speed_value =new_speed_value ;
          tb_value = new_tb_value;
          level_val=new_level_val;
       
      /* Serial.println(rain_ad);
       Serial.println(level_rain_val);
       Serial.print("***");
       Serial.println(rain);*/
      /* Serial.print("1.sensor_rain:");
       Serial.println(rain_ad);*/
       
      /* Serial.print("sensor_tb_ad:");
       Serial.println(tb_value); 
       Serial.print("sensor_tb_ad_m:");
       Serial.println(tb_value);*/
      /* Serial.print("2.sensor_tb_ad_value:");
       Serial.println(tb_value);
       
       
       Serial.print("3.sensor_speed_value:");
       Serial.print (speed_value, DEC); //Prints the number calculated above
       Serial.println (" L/hour\r\n"); //Prints "L/hour" and returns a new line
    
       /*Serial.print("4.sensor_level_value:");
       Serial.println (level_val);
       Serial.print("5.sensor_level_rain:");
       Serial.println (level_rain_val);*/
       //sei(); //Enables interrupts
       /*Serial.print("3.sensor_speed_value:");
       Serial.print (new_speed_value, DEC); //Prints the number calculated above
       Serial.println (" L/hour\r\n"); //Prints "L/hour" and returns a new line*/
       
   }
   if(sec_flag == 60)
   {
      sec_flag =0;
      min_flag +=1;
   }
   if(min_flag == 1)
   {
      //cli();
       min_flag=0;
       static int counter = 0, successCount = 0, failCount = 0;
       Serial.print(F("\nRunning loop #"));
       Serial.println(counter);
       Message msg(transceiver);  //  Will contain the structured sensor data.
       msg.addField("tur", int(new_tb_value));  //  4 bytes pour le temp.
       msg.addField("spd", int(new_speed_value));  //  4 bytes for the counter.
       msg.addField(rai,level);  //  4 bytes for the voltage.
       //envoyé un message
       if (msg.send())
       {
          successCount++; // si il est succès, counter le message qui il est envoyé
          Serial.println("Successful!");
       } 
       else
       {
          failCount++;
          Serial.println("Unable to send");
       }
        counter++;
       if (counter % 2 == 0)digitalWrite(LED_BUILTIN,HIGH);
       else digitalWrite(LED_BUILTIN,LOW);
       if (counter >= 10)stop(String(F("Message sent successfully: ")) + successCount + F(", failed:") + failCount);
       Serial.println("Waiting 1 minutes...");//attendre 1 minute */
   }
   if(min_flag == 5)
   {
      alarm_flag = 5;
   }
}

uint8_t water_level()
{

    if (digitalRead(level_2) == LOW)return 2;
    else 
    {
      if (digitalRead(level_1) == LOW)return 1;
      else  return 0;
    }
  
}
void level_add_rain(int a ,uint8_t b)
{
  
  rain_val[0]= (a /100)+0x30;
  rain_val[1]= ((a /10)%10)+0x30;
  rain_val[2]= (a%10)+0x30;
  level = String(b); //water level,0,1,2
  
  //rain[0]= (a %10)+0x30;
  rai = String(rain_val); //rain messurement
}
