#include <LiquidCrystal.h>
#include <stdio.h>
/* 
 *  OĞUZHAN TAŞIMAZ 17020141 KAAN TECIK 170201069
 *  KOCAELI UNIVERSITESI PROGRAMLAMA LABORATUVARI 2 - 2. PROJE
 *  09.04.2019
 * =================================
 * LCD pin              Connect to
 * ---------------------------------
 * 01 - GND             GND
 * 02 - VCC             3.3V
 * 03 - Contrast        Potentiometer mid
 * 04 - RS              (PB_0)
 * 05 - R/W             GND
 * 06 - EN              (PB_1)
 * 07 - DB0             GND
 * 08 - DB1             GND
 * 09 - DB2             GND
 * 10 - DB3             GND
 * 11 - DB4             (PB_4)
 * 12 - DB5             (PB_5)
 * 13 - DB6             (PB_6)
 * 14 - DB7             (PB_7)
 * 15 - BL+             +
 * 16 - BL-             -
 * ================================
*/
   
LiquidCrystal lcd(PB_0, PB_1, PB_4, PB_5, PB_6, PB_7);
const int buttonPin1 = PUSH2;  //TIVA SAG
const int buttonPin2 = PD_2;   //1TL  1
const int buttonPin3 = PD_3;   //50KRS  2
const int buttonPin4 = PD_6;   //25KRS  3
const int buttonPin5 = PD_7;   //SECIM  4
const int buttonPin6 = PUSH1;  //TIVA SOL
const int buttonPin7 = PA_2;  //EN SOL
const int successLed = PC_4;
const int failLed = PC_5;
const int redPin =  RED_LED;
const int greenPin =  GREEN_LED;
const int bluePin = BLUE_LED;

int coinStocks[3]={20,20,10}; //25kurus, 50 kurus 1tl
int waterBottle[2]={30,50};//30tane, 50 kurus
int tea[2]={20,1};//20 tane, 1tl
int coffee[2]={15,150};//15 tane, 1.5tl
int chocolate[2]={50,175};//50 tane, 1.75tl
int biscuit[2]={100,2};//100 tane, 2tl

int randomNumber = 0;
int buttonState1 = 0;//tivaSAG PUSH2
int buttonState2 = 0;//1TL
int buttonState3 = 0;//50KRS
int buttonState4 = 0;//25KRS
int buttonState5 = 0;//SECIM  
int buttonState6 = 0;//TIVA SOLPUSH1
int buttonState7 = 0;//ENSOL
int currency = 0;
int currency2 = 0;
int tempCurrency= 0;
int tempCurrency2= 0;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
boolean isDone = false;

byte topSmile[8] = {
0b00000,
0b00000,
0b00000,
0b11011,
0b00000,
0b01010,
0b10101,
0b01010
};
byte bottomSmile[8] = {
0b10001,
0b10001,
0b10001,
0b01110,
0b00000,
0b00000,
0b00000,
0b00000
};
void setup()
  {
  Serial.begin(9600);
  initPinModes();
  randomSeed(analogRead(0));
  lcd.createChar(0,topSmile);
  lcd.createChar(1,bottomSmile);
  lcd.begin(16, 2);
  lcd.setCursor(2,0);
  lcd.print("H S E D N Z");
  lcd.setCursor(2,1);
  lcd.print(" O G L I I ");
  lcd.setCursor(14,0);
  lcd.write((uint8_t)0);
  lcd.setCursor(14,1);
  lcd.write((uint8_t)1);
  }

void loop()
  {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);

  if(isDone==false)
  {
    button1TL();
    button50KRS();
    button25KRS();
    doneButton();
  }
  else
  {
    waterButton();
    teaButton();
    coffeeButton();
    biscuitButton();
    chocolateButton();
    resetButton();
    finishButton();
  }
  //endofcode
  }
  void initPinModes()
  {
    pinMode(redPin, OUTPUT); 
    pinMode(greenPin, OUTPUT); 
    pinMode(bluePin, OUTPUT); 
    pinMode(successLed, OUTPUT); 
    pinMode(failLed, OUTPUT); 
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buttonPin3, INPUT_PULLUP);
    pinMode(buttonPin4, INPUT_PULLUP);
    pinMode(buttonPin5, INPUT_PULLUP);
    pinMode(buttonPin6, INPUT_PULLUP);
    pinMode(buttonPin7, INPUT_PULLUP);
  }
  void button1TL()
  {
    if(buttonState2 == 0)//1TL
    {
     digitalWrite(bluePin, HIGH); 
    } 
    else {
    currency++;
    digitalWrite(bluePin, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
  }
  void button50KRS()
  {
    if(buttonState3 == 0)//50KRS
    {
     digitalWrite(bluePin, HIGH); 
    } 
    else {
    currency2 += 50;
    if(currency2 == 100)
    {
      currency++;
      currency2=0;
    }
    digitalWrite(bluePin, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
  }
  void button25KRS()
  {
    if(buttonState4 == 0)//25KRS
    {
     digitalWrite(bluePin, HIGH); 
    } 
    else {
    currency2 += 25;
    if(currency2 == 100)
    {
      currency++;
      currency2=0;
    }
    digitalWrite(bluePin, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
  }
  void doneButton()
  {
    if(buttonState1 == 1)//PUSH2 
    {
     digitalWrite(bluePin, HIGH); 
    } 
    else {
    isDone = true;
    tempCurrency=currency;
    tempCurrency2=currency2;
    digitalWrite(bluePin, LOW);
    delay(500);
    lcd.clear();
    lcd.print("BAKIYENIZ = "+String(currency)+"."+String(currency2));
    lcd.setCursor(0,1);
    lcd.print("SECIM YAPINIZ");
    }
  }
  //PART TWO
  void waterButton()
  { 
    if(buttonState3 == 0)//50KRSBUTTON SU
    {
    } 
    else {
    counter2++;
    currency2-=50;
    if(currency2 < 0)
    {
      currency--;
      currency2=50;
    }
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    lcd.setCursor(0,1);
    lcd.print(String(counter2)+"-SU");
    if(currency < 0)
    {
      currency2+=50;
      counter2--;
      if(currency2==100)
      {
        currency++;
        currency2=0;
      }
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0,1);
      lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
    delay(500);
    }
  }
  void teaButton()
  {
    if(buttonState2 == 0)//1TLBUTTON CAY
    { 
    } 
    else {
    counter1++;
    currency--;
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    lcd.setCursor(0,1);
    lcd.print(String(counter1)+"-CAY");
    if(currency < 0)
    {
      counter1--;
      currency++;
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0,1);
      lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
    delay(500);
    }
  }
  void chocolateButton()
  {
    if(buttonState6 == 1)//SECIMBUTTON CIKOLATA
    {
    } 
    else {
    counter5++;
    currency--;
    if(currency2==0)
    {
      currency2=100;
      currency--;
    }
    currency2-=75;
    if(currency2 < 0)
    {
      currency--;
      currency2 = 100-abs(currency2);
    }
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    lcd.setCursor(0,1);
    lcd.print(String(counter5)+"-CIKOLATA");
    if(currency < 0)
    {
      counter5--;
      currency++;
      currency2+=75;
      if(currency2>100)
      {
        currency++;
        currency2 = currency2 % 100;
      }
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0,1);
      lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
    delay(500);
    }
  }
  void biscuitButton()
  {
    if(buttonState4 == 0)//25KRSBUTTON BISKUVI
    {
    } 
    else {
    counter3++;
    currency-=2;
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    lcd.setCursor(0,1);
    lcd.print(String(counter3)+"-BISKUVI");
    if(currency < 0)
    {
      counter3--;
      currency2+=2;
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0,1);
      lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
    delay(500);
    }
  }
  void coffeeButton()
  {
    if(buttonState5 == 0)//SECIMBUTTON KAHVE
    {
    } 
    else {
    counter4++;
    currency--;
    currency2-=50;
    if(currency2 < 0)
    {
      currency--;
      currency2=50;
    }
    lcd.clear();
    lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    lcd.setCursor(0,1);
    lcd.print(String(counter4)+"-KAHVE");
    if(currency < 0)
    {
      counter4--;
      currency++;
      currency2+=50;
      if(currency2=100)
      {
        currency++;
        currency2=0;
      }
      lcd.clear();
      lcd.print("YETERSIZ BAKIYE");
      lcd.setCursor(0,1);
      lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
    }
    delay(500);
    }
  }
  void resetButton()
  {
    if(buttonState7 == 0)//RESET BUTON
    {
    } 
    else {
     resetCounters();
     lcd.clear();
     lcd.print("BAKIYE = "+String(currency)+"."+String(currency2));
     lcd.setCursor(0,1);
     lcd.print("TEKRAR SECIN");
    }
  }
  void finishButton()
  {
     if(buttonState1 == 1)//FINISH BUTON PUSH2
    {
      digitalWrite(redPin, LOW); 
      digitalWrite(greenPin, LOW); 
      digitalWrite(successLed, LOW);
      digitalWrite(failLed, LOW);  
    } 
    else {
      minusCounters();
      randomNum();
      delay(500);
    }
  }
  void randomNum()
  {
      randomNumber = random(0,4);
      Serial.println("Random Sayi= "+String(randomNumber)); 
      if(randomNumber == 2)
      {
        digitalWrite(redPin, HIGH);
        digitalWrite(failLed, HIGH); 
        lcd.clear();
        lcd.print("PARA SIKISTI");
        lcd.setCursor(0,1);
        lcd.print("RESET'E BASINIZ");
      }
      else
      {
        digitalWrite(successLed, HIGH); 
        digitalWrite(greenPin, HIGH);
        lcd.clear();
        lcd.print("PARA USTUNUZ");
        lcd.setCursor(0,1);
        lcd.print(String(currency)+"."+String(currency2));
        Serial.println(String(currency)+" "+String(currency2));
        backInChange();
        Serial.println("Kasada kalan para miktarlari");
        Serial.println("1TL "+String(coinStocks[2])+"  50KRS "+String(coinStocks[1])+"  25KRS "+String(coinStocks[0]));
        Serial.println("Kasada kalan urun miktarlari");
        Serial.println("Tea"+String(tea[0])+" Water"+String(waterBottle[0])+" Biscuit"+String(biscuit[0]));
        Serial.println("Coffee"+String(coffee[0])+" Chocolate"+String(chocolate[0]));
      }
  }
  void resetCounters()
  {
     tea[0]=20;
     waterBottle[0]=30;
     biscuit[0]=counter3;
     coffee[0]=15;
     chocolate[0]=50;
     counter1 = 0;
     counter2 = 0;
     counter3 = 0;
     counter4 = 0;
     counter5 = 0;
     currency= tempCurrency;
     currency2= tempCurrency2;
  }
  void minusCounters()
  {
     tea[0] -= counter1;
     waterBottle[0] -= counter2;
     biscuit[0] -= counter3;
     coffee[0] -= counter4;
     chocolate[0] -= counter5;
  }
  void backInChange()
  {
        if(currency>10)
        {
          coinStocks[2]=0;
        }
        else{
        coinStocks[2]-=currency;
        }
        currency = currency % 10;
        if(currency2==75)
        {
          coinStocks[1]-=1;
          coinStocks[0]-=1;
          currency2=0;
        }
        if(currency2==50)
        {
          coinStocks[1]-=1;
          currency2=0;
        }
        if(currency2==25)
        {
          coinStocks[0]-=1;
          currency2=0;
        }
        if(coinStocks[1]>0)
        {
          coinStocks[1]-= currency * 2;
        }
        else{
          coinStocks[0]-= currency *4;
        }
        
        if(coinStocks[0]<=0 && coinStocks[1]<=0 && coinStocks[2]<=0)
        {
          lcd.clear();
          lcd.print("Kasada yeterli");
          lcd.setCursor(0,1);
          lcd.print("para yoktur");
        }
  }
