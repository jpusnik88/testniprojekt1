/*author: Janko Pušnik
 * RGB led
 * LED on/off
 * LED brightness++. brightness -- za belo barvo
 * 
 * 
 * 
 * 
*/
// constants won't change. They're used here to
// set pin numbers:
const int buttonPin1 = 2;     // on /off
const int buttonPin2 = 8;     // svetlost ++
const int buttonPin3 = 5;     // svetlost --
const int buttonPin4 = 7;     // barva ++
const int buttonPin5 = 4;     // barva --
const int buttonPin6 = 6;     // special

const int redPin = 10;
const int greenPin = 11;
const int bluePin = 9;


const int ledPin =  12;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
bool vklop = false;





int rdeca = 127;   // spremenljivka za rdeco barvo
int Stored_oranznaR = 127;
int Stored_oranznaG = 63;
int Stored_rumenaR = 127;
int Stored_rumenaG = 127;
int Stored_rumenozelenaR = 63;
int Stored_rumenozelenaG = 127;
int Stored_zelena= 127;
int Stored_modrozelenaG = 127;
int Stored_modrozelenaB = 63;
int Stored_aquaG = 127;
int Stored_aquaB = 127;
int Stored_zelenomodraG = 63;
int Stored_zelenomodraB = 127;
int Stored_modra=127;
int Stored_magentaR = 63;
int Stored_magentaB = 127;
int Stored_pinkR = 127;
int Stored_pinkB = 127;
int Stored_maroonR= 127;
int Stored_maroonB = 63;








int barva = 1; // bela barva
int bela = 100;


int buttonPushCounter1 = 0;   // counter for the number of button presses
int lastButtonState1 = 0;     // previous state of the button
int buttonPushCounter2 = 0;   // counter for the number of button presses
int lastButtonState2 = 0;     // previous state of the button
int buttonPushCounter3 = 0;   // counter for the number of button presses
int lastButtonState3 = 0;     // previous state of the button
int buttonPushCounter4 = 0;   // counter for the number of button presses
int lastButtonState4 = 0;     // previous state of the button
int buttonPushCounter5 = 0;   // counter for the number of button presses
int lastButtonState5 = 0;     // previous state of the button

void setup() 
{
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
}

void loop() 
{
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);


ON_OFF_gumb();
SVETLOST_vec_gumb();
SVETLOST_manj_gumb();
BARVA_vec_gumb();
BARVA_manj_gumb();
 

  

}



































void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}



void ON_OFF_gumb()
{
 if (buttonState1 != lastButtonState1) 
 {
    if (buttonState1 == HIGH) 
    {
      // turn LED on:
      digitalWrite(ledPin, HIGH); 
      buttonPushCounter1++;
      Serial.print("buttonPushCounter1 je: ");
      Serial.println(buttonPushCounter1);
    }
    else
    {
      // turn LED off:
      digitalWrite(ledPin, LOW); 
    }
      // Delay a little bit to avoid bouncing
      delay(50);
    
 }
  // save the current state as the last state, for next time through the loop
  lastButtonState1 = buttonState1;

 if (buttonPushCounter1 % 2 == 0) 
  {
    setColor(bela,bela,bela);
    vklop = true;
    //barva = 1;
    //Serial.println("BARVA JE 1 ZARAD ZACETka
  } 
  else 
  {
    setColor(0,0,0);
    vklop = false;
  }  
  //Serial.print("barva je: ");  ce je to celi cajt 1 pise
  //Serial.println(barva)
}
////////////////////////////////////SVETLOST_vec_gumb//////////////////////////////////////////////////
void SVETLOST_vec_gumb()
{
  if(buttonState2 != lastButtonState2)
  {
     if (vklop == true)
     {
        if (buttonState2 == HIGH)
        {
         // turn LED on:
         digitalWrite(ledPin, HIGH); 
         buttonPushCounter2++;
         Serial.print("buttonPushCounter2 je: ");
         Serial.println(buttonPushCounter2);
          
          if (barva ==1)
          {
            Serial.print("barva je za 15 vecja ");
            bela = bela+15;
            setColor(bela+15,bela+15,bela+15); 
            Serial.print("bela je: ");
            Serial.println(bela);
            if(bela>=255)
            {
            Serial.print("barva je puno bela ");
            bela = 255;
            setColor(255,255,255);
            }
           
     
          } 
        }
        else
        {
         // turn LED off:
         digitalWrite(ledPin, LOW);  
        }
        
     delay(50);
     }
     lastButtonState2 = buttonState2;
     
      
  }
}

////////////////////////////////////SVETLOST_manj_gumb//////////////////////////////////////////////////
void SVETLOST_manj_gumb()
{
  if(buttonState3 != lastButtonState3)
  {
     if (vklop == true)
     {
        if (buttonState3 == HIGH)
        {
         // turn LED on:
         digitalWrite(ledPin, HIGH); 
         buttonPushCounter3++;
         Serial.print("buttonPushCounter3 je: ");
         Serial.println(buttonPushCounter3);
          
          if (barva ==1)
          {
            Serial.print("barva je za 15 manjsa ");
            bela = bela-15;
            setColor(bela-15,bela-15,bela-15); 
            Serial.print("bela je: ");
            Serial.println(bela);
            if(bela<=0)
            {
            Serial.print("barva je najmanj bela ");
            bela = 5;
            setColor(5,5,5);
            }
           
     
          } 
        }
        else
        {
         // turn LED off:
         digitalWrite(ledPin, LOW);  
        }
        
     delay(50);
     }
     lastButtonState3 = buttonState3;
     
      
  }
}

/////////////////////////////////////////BARVA_vec_gumb()/////////////////////////////////////
void BARVA_vec_gumb()
{
 if (buttonState4 != lastButtonState4) 
 {
  if(vklop == true)
  {
    if (buttonState4 == HIGH) 
    {
      // turn LED on:
      digitalWrite(ledPin, HIGH); 
      buttonPushCounter4++;
      Serial.print("buttonPushCounter4 je: ");
      Serial.println(buttonPushCounter4);
      barva = barva +1;
      Serial.print("barva naprej++");
      Serial.println(barva);

      IzbiraBarva();
      delay(1000);
      ///////////////naprej
      
    }
    else
    {
      // turn LED off:
      digitalWrite(ledPin, LOW); 
    }
      // Delay a little bit to avoid bouncing
      delay(50);
       
  }
    
 }
  // save the current state as the last state, for next time through the loop
  lastButtonState4 = buttonState4;

}

/////////////////////////////////////////BARVA_manj_gumb()/////////////////////////////////////
void BARVA_manj_gumb()
{
 
}






void IzbiraBarva()
  {
  switch (barva)
  {
    case 1:
    {
    setColor(bela,bela,bela); //bela
    break;
    }
    case 2:
    {
    setColor(rdeca,0,0); // rdeca
    break;
    }
 
    case 3:
    {
    setColor(Stored_oranznaR,Stored_oranznaG,0); // oranzna
    break;
    }
    
    case 4:
    {
    setColor(Stored_rumenaR,Stored_rumenaG,0);  //rumena
    break;
    }
    
    case 5:
    {
    setColor(Stored_rumenozelenaR,Stored_rumenozelenaG,0); // rumenozelena
    break;
    }
    
    case 6:
    {
    setColor(0,Stored_zelena,0);    //zelena
    break;
    }
    
    case 7:
    {
    setColor(0,Stored_modrozelenaG,Stored_modrozelenaB);      //modrozelena
    break;
    }
    
    case 8:
    {
    setColor(0,Stored_aquaG,Stored_aquaB);           //aqua
    break;
    }
    
    case 9:
    {
    setColor(0,Stored_zelenomodraG,Stored_zelenomodraB);        //zelenomodra
    break;
    }
    
    case 10:
    {
    setColor(0,0,Stored_modra);          //modra
    break;
    }
    
    case 11:
    {
    setColor(Stored_magentaR,0,Stored_magentaB);          //magenta
    break;
    }
    
    case 12:
    {
    setColor(Stored_pinkR,0,Stored_pinkB);         //pink
    break;
    }
    
    default:                        //kaj se zgodi ce je stevilo menjse od 13 in 1
    {
    //setColor(bela,bela,bela); // bela
    setColor(Stored_maroonR,0,Stored_maroonB);          //maroon
    barva = 0;
    break;
    }
    
    
  }
  }
