#include <Keypad.h>
#include <DmxMaster.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4 }; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0; 
int v5 = 0;
int v6 = 0;
int MaxDMXVal = 0;
int UseChannel = 0;
int channelVal = 0;
int FixtureStart =0;
int FixtureMax = 0;


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display



void setup(){
	
	Serial.begin(9600);
	Wire.begin();
	DmxMaster.usePin(3);
	lcd.init();                      // initialize the lcd
	lcd.init();                       // initialize the lcd
	lcd.backlight();                  // initialize the backlight
	lcd.setCursor(4,0);               // centers the cursor to the center of the screen
	lcd.print("Welcome!");
	delay(1000);
	lcd.clear();
	
	}


void loop(){	

DmxMaster.maxChannel(MaxDMXVal);
DmxMaster.write(UseChannel, channelVal);

	char key = keypad.getKey();
	if (key == 'D'){
		MaxDMX();}
		
	if (key == 'A'){
		UseCh();}
				
	if (key == 'B'){
		chval();}
		
	if (key == '*'){
		reset1();  }
	
	if (key == 'C'){
		FixtureSt();}
	
	if (key == '3'){
		Obey3();} 
	
	if (key == '4'){
		Obey4();}
	
	if (key == '6'){
		Obey6();}
	
	if (key == '1'){
		Obey10();}
	
	if (key == '7'){
		Obey70();}
	
	if (key == '5'){
		SD50();}
	
	if (key == '0'){
		Obey40();}
	
	}
	
int MaxDMX (){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("select Max Ch:");
	v1 = GetNumber2();
	MaxDMXVal= v1;
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("MaxDMX CH is:");
	lcd.setCursor(5,1);
	lcd.print(MaxDMXVal);
	delay(2000);
	lcd.clear();
	}
int UseCh (){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Ch to Test?");
	v2 = GetNumber2();
	UseChannel = v2;
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Channel set to:");
	lcd.setCursor(5,1);
	lcd.print(UseChannel);
	delay(1000);
	lcd.clear();
		
}

int chval(){
	lcd.clear();
	lcd.setCursor(1,0);
	lcd.print("Channel Test");
	lcd.setCursor(4,1);
	lcd.print("Value?");
	v3 = GetNumberval();
	channelVal = v3;
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Ch Value is:");
	lcd.setCursor(13,0);
	lcd.print(channelVal);
	delay(2000);
	lcd.clear();
}

int FixtureSt(){
	
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Test a Range");
	lcd.setCursor(0,1);
	lcd.print("of channels");
	delay(2000);
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Start Channel?");
	v4 = GetNumber2();
	FixtureStart = v4;
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("start Channel is: ");
	lcd.setCursor(5,1);
	lcd.print(FixtureStart);
	
	delay(1000);
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Last Channel?");
	v5 = GetNumber2();
	FixtureMax = v5;
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Last Channel is:");
	lcd.setCursor(5,1);
	lcd.print(FixtureMax);
	delay(1000);
	lcd.clear();
	test1();
	
	
}
int GetNumber()
{
	int num = 0;
	char key = keypad.getKey();
	while(key != '#' && 'A' && 'B' && 'C' && 'D')
	{
		switch (key)
		{
			case NO_KEY:
			break;

			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			lcd.println(key);
			num = num * 10 + (key - '0');
			break;

			case '*':
			num = 0;
			//lcd.clear();
			break;
		}

		key = keypad.getKey();
	}

	return num;
}
int GetNumberval()
{
	int num = 0;
	char key = keypad.getKey();
	while(key != '#' && 'A' && 'B' && 'C' && 'D')
	{
		switch (key)
		{
			case NO_KEY:
			break;

			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			lcd.setCursor(0,1);
			lcd.clear();
			lcd.print(key);
			num = num * 10 + (key - '0');
			break;

			case '*':
			num = 0;
			//lcd.clear();
			break;
		}

		key = keypad.getKey();
	}
if (num >= 256)
{
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Error not > 256");
	delay(2000);
	lcd.clear();
} 
else
{
	return num;
}
	
}
int GetNumber2()
{
	int num = 0;
	char key = keypad.getKey();
	while(key != '#' && 'A' && 'B' && 'C' && 'D')
	{
		switch (key)
		{
			case NO_KEY:
			break;

			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			lcd.setCursor(0,1);
			lcd.clear();
			lcd.print(key);
			num = num * 10 + (key - '0');
			break;

			case '*':
			num = 0;
			//lcd.clear();
			break;
		}

		key = keypad.getKey();
	}
	if (num >= 513)
	{
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.print("Error not > 513");
		delay(2000);
		lcd.clear();
	}
	else
	{
		return num;
	}
	
}
void test1 () {

	  for (int x = FixtureStart; FixtureStart <= FixtureMax; FixtureStart++)
	  {
		  DmxMaster.write(FixtureStart, 255);
		  delay(500);
		  DmxMaster.write(FixtureStart, 0);
		  
	  }
  }
void reset1() {

	  UseChannel = 0;
	  channelVal = 0;
	  for (int i = 0; i <= 512; i++) {
		  DmxMaster.write(i, 0);


	  }
  }
int Obey3(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("selected Obey 3:");
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is: 3");
	MaxDMXVal= 3;
	delay(2000);
	lcd.clear();
	
}
int Obey4(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("selected Obey 4:");
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is: 16");
	MaxDMXVal= 16;
	delay(2000);
	lcd.clear();
	
}
int Obey6(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("selected Obey 6:");
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is: 36");
	MaxDMXVal= 36;
	delay(2000);
	lcd.clear();
	
}
int Obey10(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("selected Obey 10:");
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is:128");
	MaxDMXVal= 128;
	delay(2000);
	lcd.clear();
	
}
int Obey40(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("selected Obey 40:");
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is:192");
	MaxDMXVal= 192;
	delay(2000);
	lcd.clear();
}
int Obey70(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("selected Obey 70:");
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is:384");
	MaxDMXVal= 384;
	delay(2000);
	lcd.clear();}
int SD50(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("selected SD 50:");
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is:48");
	MaxDMXVal= 48;
	delay(2000);
	lcd.clear();
	
}
void display1(){
	
	lcd.clear();
	lcd.setCursor(0,1);
	lcd.print("MaxDMX CH is:");
	lcd.setCursor(13,1);
	lcd.print(MaxDMXVal);
	delay(3000);
	}
	
