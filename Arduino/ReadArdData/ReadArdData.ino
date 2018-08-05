
/*Circuit connection:
    A1: connect voltage potentiometer to read voltage and control output signal frequency
    A0 connect amplifier circuit output to collect output voltage
    Pin2: impulse output. Frequency can be changed by changing A1 value
    Pin3: PWM output. Duty circuit can be changed by changing A1 value
*/


#include <io.h>
#include <interrupt.h>
#define icpPin 8                        // PB0 ICP D8  Interrupt input

volatile uint16_t T1Ovs1, T1Ovs2;       //OVERFLOW COUNTERS 
volatile uint16_t Capt1, Capt2;  //VARIABLES TO HOLD TIMESTAMPS 
volatile uint8_t Flag;                  //CAPTURE FLAG
float deltatime;

int voltage=0;
const int voltage_Pin0=A0;
const int voltage_Pin1=A1;
const int Freq_Pin=A5;
const int outputPin=3;
const int digitOutPin=2;
unsigned char time=0;
int remainder=0;
int freq=0;
 volatile uint8_t FINALTIME;          //VARIABLE TO HOLD THE FINAL TIME 

/*--------------------------------------------------------------------------------------------------
INTIALIZING TIMER
---------------------------------------------------------------------------------------------------*/
void InitTimer1(void)
{
   TCNT1=0;                         //SETTING INTIAL TIMER VALUE
   TCCR1B|=(1<<ICES1);              //SETTING FIRST CAPTURE ON RISING EDGE ,(TCCR1B = TCCR1B | (1<<ICES1)
   TIMSK1|=(1<<ICIE1)|(1<<TOIE1);   //ENABLING INPUT CAPTURE AND OVERFLOW INTERRUPTS 
}
/*--------------------------------------------------------------------------------------------------
STARTING TIMER
---------------------------------------------------------------------------------------------------*/
void StartTimer1(void)
{
    TCCR1B|=(1<<CS11)|(1<<CS10);    //STARTING TIMER WITH PRESCALER 64
//   TCCR1B|=(1<<CS12);              //STARTING TIMER WITH PRESCALER 256
//    TCCR1B|=(1<<CS12)|(1<<CS10);    //STARTING TIMER WITH PRESCALER 1024
   sei();                          //ENABLING GLOBAL INTERRUPTS 
}
/*--------------------------------------------------------------------------------------------------
CAPTURE ISR
---------------------------------------------------------------------------------------------------*/
ISR(TIMER1_CAPT_vect)
{
//  TCNT1 = 0;
 if (Flag==0)
     {
       TCCR1B&=~(1<<ICES1);  //CHANGE CAPTURE ON FALLING EDGE
     }
 if (Flag==1)
     {
       TCCR1B|=(1<<ICES1);    //CHANGING CAPTURE ON RISING EDGE
     }
        voltage=analogRead(A2);
        voltage=map(voltage,0,1023,0,253);
        Serial.write(253);
        Serial.write(voltage);

   Flag++;                          //INCREMENTING FLAG
   if(Flag>=2)
     Flag=0;
}
/*--------------------------------------------------------------------------------------------------
OVERFLOW ISR
---------------------------------------------------------------------------------------------------*/
ISR(TIMER1_OVF_vect)
{
//     T1Ovs2++;//INCREMENTING OVERFLOW COUNTER
}
/*--------------------------------------------------------------------------------------------------
MAIN FUNCTION
---------------------------------------------------------------------------------------------------*/


void setup()
{
      Serial.begin(115200);
      pinMode(outputPin,OUTPUT);
      pinMode(digitOutPin,OUTPUT);
     
      pinMode(icpPin,INPUT);
      digitalWrite(icpPin,HIGH);           //pull up                              
      InitTimer1();                        //CALLING FUNCTION INITTIMER1 TO INITIALIZE TIMER 1
      StartTimer1();                       //CALLING FUNCTION STARTTIMER1 TO START TIMER 1
}


void loop(){
  //ADC Channel 0
  //read and rectify the voltage data
  Serial.write(253);  //start signal of packet
  // Serial.println(255);
  voltage=analogRead(A0);
  voltage=map(voltage,0,1023,0,253);
  Serial.write(voltage);
  //Serial.println(voltage);
  delay(0.1);
 
  //ADC Channel 1
  Serial.write(254);
  //Serial.println(254);
  voltage=analogRead(A1);
  voltage=map(voltage,0,1023,0,253);
  Serial.write(voltage);
  //Serial.println(voltage);
  delay(0.1);
  
   voltage=analogRead(A2);
   voltage=map(voltage,0,1023,0,253);
   Serial.write(255);
   Serial.write(voltage);
   delay(0.1);
   
  //read ADC value as impulse frequency
  freq=analogRead(Freq_Pin);
  freq=map(freq,0,1023,0,255);
  //set PWM output, default frequency of PWM=500HZ
  analogWrite(outputPin,freq);
  delay(0.1);

}

