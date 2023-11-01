	// C++ code
//
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
//int seconds = 0;
const int buttonPin = 5;
const int servo_pin = 7;
const int potPin = A0;	// Pin connected to the potentiometer
const int heaterpin = 8; // Pin connected to heater
int potValue = 0;	// Variable to store the potentiometer value
int button = 0;	//  Variable to store the Button value
int mode_1 = 0;
int button_1 =0;
unsigned long duration = 120000; // 2 minutes
const int heaterpin = 7;
int buzzerpin=8;
int buzzer ;
//------------------cuplock-------------------------
int cup_1 = 0;
int cup_2 = 0;
int cup_3 = 0;
int cup_4 = 0;
int cup_21= 0;
int cupvalue = 0;
int potlock = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
	lcd_1.begin(16, 2);

	lcd_1.print("Smart Cooker");
	pinMode(buttonPin, INPUT_PULLUP);
	pinMode(potPin, INPUT_PULLUP);
	pinMode(heaterpin, OUTPUT);
	pinMode(buttonPin, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	// Read the potentiometer value
	potValue = analogRead(potPin);
	button = digitalRead(buttonPin);
    heater= heaterpin;
	buzzer = buttonPin;
	delay(100);

	// Divide the potentiometer value into 14 modes
    //------------------------- Mode 1-----------------------
	if (potValue < 73 || potlock == 1)
	{
		lcd_1.setCursor(0, 0);
		lcd_1.clear();
		lcd_1.print("rice  1");

		// mode_1 for hold in current state
		// Do something for mode 1

		if (button == 1 || mode_1 == 1)
		{
			mode_1 = 1;
			potlock = 1;

			lcd_1.setCursor(0, 0);
			lcd_1.print("Rice 1");
			delay(1000);
            button = 0;
            button_1 = digitalRead(buttonPin);

			//potValue=cupvalue;
            // ---------------Cup 1----------------
			if ((potValue >= 0 && potValue <= 255) || cup_1 == 1)
			{
			 	// cup 1

				lcd_1.setCursor(0, 1);
				lcd_1.print("cup 1");
				if (button_1 == 1 || cup_1 == 1)
				{
					cup_1 = 1;

					lcd_1.setCursor(0, 1);
					lcd_1.print("Cup 1");
					delay(1000);
                    button_1 =0;
                  
				}
			}
             // ---------------Cup 2----------------
			else if ((potValue  >= 256 && potValue  <= 511) || cup_2 == 1)
			{
			 	// cup 2

				lcd_1.setCursor(0, 1);
				lcd_1.print("cup 2");
				// Do something for cup 2
				if (button_1 == 1 || cup_2 == 1)
				{
					cup_2 = 1;
                    cup_21 =1;

					lcd_1.setCursor(0, 1);
					lcd_1.print("Cup 2");
                    button_1 =0;
					delay(1000);
				}
			}
             // ---------------Cup 3----------------
			else if ((potValue  >= 512 && potValue  <= 767 )|| cup_3 == 1)
			{
			 	// cup 3
				lcd_1.setCursor(0, 1);
				lcd_1.print("cup 3");
				// Do something for mode 3
				if (button_1 == 1 || cup_3 == 1)
				{
					cup_3 = 1;

					lcd_1.setCursor(0, 1);
					lcd_1.print("Cup 3");
					delay(1000);
                    button_1 =0;
				}
			}
             // ---------------Cup 4----------------
			else if ((potValue  >= 768 && potValue <= 1023)|| cup_4 == 1)
			{
			 	// cup 4
				lcd_1.setCursor(0, 1);
				lcd_1.print("cup 4");
				// Do something for mode 4
				if (button_1 == 1 || cup_4 == 1)
				{
					cup_4 = 1;

					lcd_1.setCursor(0, 1);
					lcd_1.print("Cup 4 ");
					delay(1000);
                    button_1 =0;
				}
			}
		}
	}

}
//----------------cooking-timing-in minute--------------------
cooking_time (int cup_time)
{     
	  heater = HIGH ;
	  unsigned long duration_cup = 60000*cup_time; // 2 minutes
      delay(duration_cup);
	  heater = LOW ;
	  buzzer=HIGH;
	  delay(6000);
}
valve()
{
    servoMotor.write(angle90);
  
  // Wait for the specified duration
  delay(duration);
  
  // Move the servo back to 0 degrees
  servoMotor.write(angle0);
  
  // Wait for the specified duration
  delay(duration);
  	  buzzer=HIGH;
	  delay(6000);
}
