/*
 * Barteneding Bot using motors
 * Version 1.60
 * Made By William Glass
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ezButton.h>
#include <EEPROM.h>
#include "HX711.h"


/////// Set the LCD address to 0x27 for a 16 chars and 2 line display ////////
LiquidCrystal_I2C lcd(0x27, 16, 2);
/////// Button inputs Setup //////////
ezButton BUTTON_PIN_Left(2); // Button on d2
ezButton BUTTON_PIN_Middle(3); // Button on d3
ezButton BUTTON_PIN_Right(4); // Button on d4
bool buttonReset = false; // Bool to prevent double pressing buttons durring a loop
/////// Scale Setup  /////////
HX711 scale;
long weight;


///////// Top Menu and Configurations for Menu ///////////
bool hasChanged = false;
int menuSelect = 0; // memValue to Navigate different menus Menu
int8_t whichScreen = 0; // memValue to Navigate with in Menu
String menu_Start[4] = {"Drink Select","Port Configure","Port Clean", "Reset Ports"};

//////// Drink Select Menu & Liquor Menu ///////////////
String menu_Drinks[4] = {"None", "Manhattan", "Long Island", "White Russian"};
// --> Manhattan = 1, Long Island = 2, White Russian = 3
String menu_Drink_Select[20]; // Used to make new drink Menu for Selection
String Liquor[10] = {"None", "Whiskey", "Vermouth", "Vodka", "White Rum", "Tequila", "Gin", "Triple Sec", "Kahlua","Milk/Cream"};
// --> Whiskey = 1, Vermouth = 2, Vodka = 3, White Rum = 4, Tequila = 5, Gin = 6, Triple Sec = 7, ,Kahlua = 8, Milk/Cream, = 9

///////// Port Menu & Config for Drink Menu /////////////
String menu_Port_Select[6] = {"Port: 1", "Port: 2", "Port: 3", "Port: 4", "Port: 5", "All Ports"};
int selected_Port, port1, port2, port3, port4, port5; // port integer variables to assign each port a liquor
bool selecting_Port = false; //enables port to be writen to or not.
bool check_ports = false; // For drink list creation.
String menu_AYS[2] = {"Are You Sure: N", "Are You Sure: Y"};

//////// Motors ////////
int M1 = 5, M2 = 6, M3 = 7, M4 = 8, M5 = 9;
int cleanTime = 3000;
int shotSize = 10; // mL 1/2 shot size

//////// EERPOM Saving Info ////////////
int address = 0;
int8_t memValue;

void setup()
{
  Serial.begin(9600); // Set Baudrate
  lcd.backlight();  // Turn on the blacklight and print a message.
  lcd.init();// initialize the lcd
  menuPrint("BarBot v1.60", "Made By: William"); // Starting Display
  delay(2000); // To keep start display message for a bit
  menuPrint(menu_Start[whichScreen],""); // Will Display Starting Menu

  ///////// Motor Setup ////////
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(M5, OUTPUT);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  digitalWrite(M5, LOW);

  //////// Scale SetUp ///////
  scale.begin(10, 11); // scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN)
  
  ///////// EEPROM READ to assign vaules to port (liquior port assignment) //////////
  port1 = EEPROM.read(0);
  port2 = EEPROM.read(1);
  port3 = EEPROM.read(2);
  port4 = EEPROM.read(3);
  port5 = EEPROM.read(4);
}

void loop(){
  Serial.print(" | P1: ");Serial.print(port1);
  Serial.print(" | P2: ");Serial.print(port2);
  Serial.print(" | P3: ");Serial.print(port3);
  Serial.print(" | P4: ");Serial.print(port4);
  Serial.print(" | P5: ");Serial.print(port5); Serial.print(" |\n");
  BUTTON_PIN_Left.loop(); // Needed to loop Button Controlls
  BUTTON_PIN_Middle.loop(); // Needed to loop Button Controlls
  BUTTON_PIN_Right.loop();  // Needed to loop Button Controlls
  buttonNavigate(); // Handles button input and crude menu system
  
  if (BUTTON_PIN_Middle.isReleased()){buttonReset = true;} //Allows loop to run after button.isPressed()
}

void buttonNavigate(){
  //Exit
  if(BUTTON_PIN_Left.isPressed() && BUTTON_PIN_Right.isPressed()){
    whichScreen = 0;
    menuSelect = 0;
    hasChanged = true;
  }
  //Left
    if(BUTTON_PIN_Left.isPressed()){
    whichScreen--;
    hasChanged = true;
    //Serial.print("I Have been pressed");
  }
  //Right
  if(BUTTON_PIN_Right.isPressed()){
    whichScreen++;
    hasChanged = true;
  }
  topMenu();//Runs Top Level Menu
  drinkSelectMenu();
  portConfigureMenu();
  portCleanMenu();
  portResetMenu();
  liquorSelectMenu();
}

void topMenu(){
  // Initialised Menu Num 
  int assign_Menu_Num = 0;
  //Draw Menu
  menuNav(menu_Start, sizeof(menu_Start)/sizeof(menu_Start[0]),0);
   //DrinkSelect to Drinks
   button2NewMenu(assign_Menu_Num,0,1);
  //Port Select
   button2NewMenu(assign_Menu_Num,1,2);
  //Port Clean
   button2NewMenu(assign_Menu_Num,2,3);
  //Reset Ports
   button2NewMenu_Port_Assignment(assign_Menu_Num,3,4);
}

void drinkSelectMenu(){
  int assign_Menu_Num = 1;
  int newDrinklistSize = 0;
  //Drink Select Menu
    
  drinkSelectMaker(newDrinklistSize);

  Serial.print("Drink List Size: ");Serial.print(newDrinklistSize);

  if(newDrinklistSize == 0){
    menu_Drink_Select[0] = menu_Drinks[0];
    newDrinklistSize++;
    }
  menuNav(menu_Drink_Select, newDrinklistSize,assign_Menu_Num); // menuNav at end due to changing menu_Drink_Select array size
  drinkMaker(menu_Drink_Select, assign_Menu_Num); //////////////////////////////// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-------------------------
}

void portConfigureMenu(){
  int assign_Menu_Num = 2;
  menuNav(menu_Port_Select,5,assign_Menu_Num);
  //Port 1
  button2NewMenu_Port_Assignment(assign_Menu_Num,0,5);
  //Port 2
  button2NewMenu_Port_Assignment(assign_Menu_Num,1,5);
  //Port 3
  button2NewMenu_Port_Assignment(assign_Menu_Num,2,5);
  //Port 4
  button2NewMenu_Port_Assignment(assign_Menu_Num,3,5);
  //Port 5
  button2NewMenu_Port_Assignment(assign_Menu_Num,4,5);
}

void portCleanMenu(){
  int assign_Menu_Num = 3;
  menuNav(menu_Port_Select, sizeof(menu_Port_Select)/sizeof(menu_Port_Select[0]),assign_Menu_Num);
  pumpClean(assign_Menu_Num);
}
void portResetMenu(){
  int assign_Menu_Num = 4;
  menuNav(menu_AYS,sizeof(menu_AYS)/sizeof(menu_AYS[0]),assign_Menu_Num); // Navigate Are you sure String array
  // If Selectinport is 1 (from button2NewMenu_Port_Assignment funvtion) & middle button is pressed & resetbutton is 1 &
  // the current menue is portReset (MenNUM 4) and finally if whichScreen = 1 (which is yes in AYS array) then ports will reset.
  if (selecting_Port && BUTTON_PIN_Middle.isPressed() && buttonReset && menuSelect ==  assign_Menu_Num && whichScreen == 1){
    memValue = 0; // Assigned memmory memValue
    for(int i = 0; i < 5 ; i++){
      portSel(i) = memValue;
      EEPROM.update(i,memValue);
      Serial.print(" Port: "); Serial.print(i+1);
      Serial.print(" EEPROM UPDATED\n");
    }
    selecting_Port = false;
    // Goes Back to Start
   back2start(); 
  }
  // Else goes back to start 
  else if (selecting_Port && BUTTON_PIN_Middle.isPressed() && buttonReset && menuSelect ==  assign_Menu_Num && whichScreen == 0){
    selecting_Port = false;
    // Goes Back to Start
    back2start(); 
  }
}

void liquorSelectMenu(){ // Relies on button2NewMenu_Port_Assignment function to assign liquor to a port
  int assign_Menu_Num = 5;
  menuNav(Liquor, sizeof(Liquor)/sizeof(Liquor[0]),assign_Menu_Num); // Allows liquor navigation
  if (selecting_Port && BUTTON_PIN_Middle.isPressed() && buttonReset){
    portSel(selected_Port) = whichScreen; // Assigns liquor memValue to port
    memValue = whichScreen;
    EEPROM.update(selected_Port,memValue);
    Serial.print(" Port: "); Serial.print(selected_Port);
    Serial.print(" EEPROM UPDATED\n");
    selecting_Port = false; // Resets port assignment check
    // Goes Back to Start
    back2start(); 
  }
}

// Returns ports by reference to assign a memValue
int& portSel(int8_t port){
  if (port == 0) {return port1;}
  if (port == 1) {return port2;}
  if (port == 2) {return port3;}
  if (port == 3) {return port4;}
  if (port == 4) {return port5;}
}

//Prints Text on LCD via i2c and LiquidCrystal_I2C.h
void menuPrint(String lineOne, String lineTwo){
    lcd.clear(); // clears LCD
    lcd.setCursor(0,0); // Column, line
    lcd.print(lineOne); //Prints Top line string 
    lcd.setCursor(0,1); // Column, line
    lcd.print(lineTwo); // Prints Bottom line string
    hasChanged = false; // Changes hasChange back to false to prevent menu redrawing, NEEDED FOR menNav Function 
}

//Prints menu inputs(menu_array_name, length_of_array, assigned_menu_num) 
void menuNav(String menu_Name[], int array_Length, int menu_Num){
  Serial.print(menuSelect);
  if (hasChanged == true && menuSelect == menu_Num){ // Verrifies if menu should be reDrawn and which menu
    if (whichScreen > array_Length - 1) {whichScreen = 0;} // Prevent going past menu elements
    if (whichScreen < 0) {whichScreen = array_Length-1;} // Prevent going past menu elements
    menuPrint(menu_Name[whichScreen],""); // Draws new menu via menuPrint function
    }
}

// Navigates from one menu to another based on (current_Menu_Num, current_Menu_Position, new_Menu_Num)
void button2NewMenu(int current_Menu_Num, int current_Menu_Position, int new_Menu_Num){

  // verifies that middle button is press after a loop reset that users is on said current menu and screen in order to change to new menu
  if(BUTTON_PIN_Middle.isPressed() && menuSelect == current_Menu_Num && whichScreen == current_Menu_Position && buttonReset){
    menuSelect = new_Menu_Num; // Changes Menu based on function inputed menu number
    whichScreen = 0; // Goes to start of menu
    hasChanged = true; // Needed to allow menuNav to draw new menu
    buttonReset = false; //Needed to reset middle button press
    }  
}

// Navigates from one menu to another based on (current_Menu_Num, current_Menu_Position, new_Menu_Num)
void button2NewMenu_Port_Assignment(int current_Menu_Num, int current_Menu_Position_Port, int new_Menu_Num){
  if(BUTTON_PIN_Middle.isPressed() && menuSelect == current_Menu_Num && whichScreen == current_Menu_Position_Port && buttonReset){
    menuSelect = new_Menu_Num;
    whichScreen = 0;
    hasChanged = true; // Needed to allow menuNav to draw new menu
    buttonReset = false; //Needed to reset middle button press
    selected_Port = current_Menu_Position_Port;
    selecting_Port = true;
    }  
}

void drinkSelectMaker(int& newDrinklistSize){
  // --> Whiskey = 1, Vermouth = 2, Vodka = 3, White Rum = 4, Tequila = 5, Gin = 6, Triple Sec = 7, ,Kahlua = 8, Milk/Cream, = 9

  //Manhattan Recipes Whisky (1)
   if(port1 == (1) || port2 == (1) || port3 == (1) || port4 == (1) || port5 == (1)){
    if(port1 == (2) || port2 == (2) || port3 == (2) || port4 == (2) || port5 == (2)){
      menu_Drink_Select[newDrinklistSize] = menu_Drinks[1]; // Drink ID is 1
      newDrinklistSize++;
    }
  }
  //Long Island
  if(port1 == (6) || port2 == (6) || port3 == (6) || port4 == (6) || port5 == (6)){
    if(port1 == (4) || port2 == (4) || port3 == (4) || port4 == (4) || port5 == (4)){
      if(port1 == (5) || port2 == (5) || port3 == (5) || port4 == (5) || port5 == (5)){
        if(port1 == (3) || port2 == (3) || port3 == (3) || port4 == (3) || port5 == (3)){
          if(port1 == (7) || port2 == (7) || port3 == (7) || port4 == (7) || port5 == (7)){
            menu_Drink_Select[newDrinklistSize] = menu_Drinks[2]; // Drink ID is 1
            newDrinklistSize++;
          }
        }
      }
    }
  }
  // White Russian (3)
  if(port1 == (3) || port2 == (3) || port3 == (3) || port4 == (3) || port5 == (3)){
    if(port1 == (8) || port2 == (8) || port3 == (8) || port4 == (8) || port5 == (8)){
      if(port1 == (9) || port2 == (9) || port3 == (9) || port4 == (9) || port5 == (9)){
        menu_Drink_Select[newDrinklistSize] = menu_Drinks[3]; // Drink ID is 3
        newDrinklistSize++;
      }
    }
  }
  //Serial.print(menu_Drink_Select[0]);
}
//
void drinkMaker(String menu_Drink_Select[], int current_Menu_Num){
  if (menuSelect == 1 && BUTTON_PIN_Middle.isPressed() && buttonReset){
    if (menu_Drink_Select[whichScreen] == "Manhattan"){
    menuPrint("Making Drink ...","");
	  pumpCheck(1,5);
	  pumpCheck(2,2);
    menuPrint("Done","Enjoy!");
    delay(2000);
    back2start();  
    }
    if (menu_Drink_Select[whichScreen] == "White Russian"){
    menuPrint("Making Drink ...","");
    pumpCheck(3,3);
    pumpCheck(8,3);
    pumpCheck(9,3);
    menuPrint("Done","Enjoy!");
    delay(2000);
    back2start();  
    }
  }
}
// checks each port for wanted liquor then activates pump
void pumpCheck(int liquorWanted, int numShots){
	if (port1 == liquorWanted){pumpActivate(M1, numShots);}
	else if (port2 == liquorWanted){pumpActivate(M2, numShots);}
	else if (port3 == liquorWanted){pumpActivate(M3, numShots);}
	else if (port4 == liquorWanted){pumpActivate(M4, numShots);}
	else if (port5 == liquorWanted){pumpActivate(M5, numShots);}
}
// turns on pump
void pumpActivate(int motor, int numShots){
		delay(2000);
		weight = scale.read();
		delay(100);
		digitalWrite(motor, HIGH);
		while (scale.read() - weight < 3000) {}
		delay(((shotSize*numShots)/11)*1000);
		digitalWrite(motor, LOW);
  }
  
void pumpClean(int current_Menu_Num){
  if (whichScreen == 0 && menuSelect == 3 && BUTTON_PIN_Middle.isPressed() && buttonReset){
    digitalWrite(M1, HIGH);
    delay(cleanTime);
    digitalWrite(M1, LOW);
    back2start();  
  }
  else if (whichScreen == 1 && menuSelect == 3 && BUTTON_PIN_Middle.isPressed() && buttonReset){
    digitalWrite(M2, HIGH);
    delay(cleanTime);
    digitalWrite(M2, LOW);
    back2start();  
  }
  else if (whichScreen == 2 && menuSelect == 3 && BUTTON_PIN_Middle.isPressed() && buttonReset){
    digitalWrite(M3, HIGH);
    delay(cleanTime);
    digitalWrite(M3, LOW);
    back2start();  
  }
  else if (whichScreen == 3 && menuSelect == 3 && BUTTON_PIN_Middle.isPressed() && buttonReset){
    digitalWrite(M4, HIGH);
    delay(cleanTime);
    digitalWrite(M4, LOW);
    back2start();  
  }
  else if (whichScreen == 4 && menuSelect == 3 && BUTTON_PIN_Middle.isPressed() && buttonReset){
    digitalWrite(M5, HIGH);
    delay(cleanTime);
    digitalWrite(M5, LOW);
    back2start();  
  }
  else if (whichScreen == 5 && menuSelect == 3 && BUTTON_PIN_Middle.isPressed() && buttonReset){
    digitalWrite(M1, HIGH);
    delay(cleanTime);
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    delay(cleanTime);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    delay(cleanTime);
    digitalWrite(M3, LOW);
    digitalWrite(M4, HIGH);
    delay(cleanTime);
    digitalWrite(M4, LOW);
    digitalWrite(M5, HIGH);
    delay(cleanTime);
    digitalWrite(M5, LOW);
    back2start();  

  }
}
// goes back to start
void back2start(){
    buttonReset = false; //Needed to reset middle button press
    hasChanged = true; //Needed to enable menuNav
    menuSelect = 0; // goes back to start
    whichScreen = 0; // goes back to star
    
  }
