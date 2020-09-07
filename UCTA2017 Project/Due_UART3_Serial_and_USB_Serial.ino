

#include <DueFlashStorage.h>
DueFlashStorage dueFlashStorage;
long i=0;
uint8_t data = 0;
long address=0;
const int pin=66;   //DAC0
double mul=0.8;


void setup(){

  Serial.begin(9600);
  Serial3.begin(9600);
  analogWriteResolution(8);
  String c;
}

void loop() {
  if (Serial3.available())
  {
  if (Serial3.readStringUntil('\n')=="d")
  {

 
  {   
    /* NodeMCU USART Recieve Commands and Store in a Character Variable */
    
 
   
    if(Serial.available())
    {
      Serial.write ('S');
      for(long i=0; i<80000; i++)
      {
      data = Serial.read();
      dueFlashStorage.write(address,data);
      address++;
      Serial.write('N');
      }
    }
    }
  }
    else if (Serial3.readStringUntil('\n')=="p")
    {
    for(long i=0; i<80000; i++)
      {
        if(Serial3.readStringUntil('\n')=="s")
        {
        address=0;
        }
      
    
   else if (Serial3.readStringUntil('\n')=="a")
    {
      //set vol 100
     mul=1;
    }
     else if (Serial3.readStringUntil('\n')=="b")
    {
      //set vol 50
    mul=0.5;
    } 
   else if (Serial3.readStringUntil('\n')=="c")
    {
      //set vol 0
      mul=0;
    }
      else 
      {
        byte dac = dueFlashStorage.read(address);
        analogWrite(pin, dac*mul ); 
        address++;
        delayMicroseconds(123); // evaluating DAC write time without Timer interupt 
      }
    }
     
       
  } 
}
}
  


