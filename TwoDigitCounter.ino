
#define Button  11  //Button is connected to pin 11

int Units = 9;  //Units display is enabled by pin 9
int Tens = 10;  //Tens display is enabled by pin 10
int Counter = 0;//Variable to count button presses
unsigned long Timer = 0;

int Zero[7] = {1,1,1,0,1,1,1};
int One[7] = {0,0,1,0,0,0,1};
int Two[7] = {1,1,0,1,0,1,1};
int Three[7] = {0,1,1,1,0,1,1};
int Four[7] = {0,0,1,1,1,0,1};
int Five[7] = {0,1,1,1,1,1,0};
int Six[7] = {1,1,1,1,1,1,0};
int Seven[7] = {0,0,1,0,0,1,1};
int Eight[7] = {1,1,1,1,1,1,1};
int Nine[7] = {0,1,1,1,1,1,1};

void Units_DisplayNumber(int Number[7]){
  digitalWrite(Units,LOW);  //Enabling Units display
  digitalWrite(Tens,HIGH);  //Disabling Tens display
  for (int i = 0; i < 7; i++){
    if(Number[i] == 1){
      digitalWrite(i+2,HIGH);
    }
    else{
      digitalWrite(i+2,LOW);
    }
  }
  delay(5);   //Units display stays ON for 5 milliseconds
}

void Tens_DisplayNumber(int Number[7]){
  digitalWrite(Units,HIGH); //Disabling Units display
  digitalWrite(Tens,LOW);   //Enabling Tens display
  for (int i = 0; i < 7; i++){
    if(Number[i] == 1){
      digitalWrite(i+2,HIGH);
    }
    else{
      digitalWrite(i+2,LOW);
    }
  }
  delay(5);   //Tens display stays ON for 5 milliseconds
}

void DisplayNumber(int Number){
  int Units_Value = Number % 10;  // Getting Units digit
  int Tens_Value = Number / 10;   //Getting Tens digit
    if(Units_Value == 0)   Units_DisplayNumber(Zero);
    else if(Units_Value == 1)  Units_DisplayNumber(One);
    else if(Units_Value == 2)  Units_DisplayNumber(Two);
    else if(Units_Value == 3)  Units_DisplayNumber(Three);
    else if(Units_Value == 4)  Units_DisplayNumber(Four);
    else if(Units_Value == 5)  Units_DisplayNumber(Five);
    else if(Units_Value == 6)  Units_DisplayNumber(Six);
    else if(Units_Value == 7)  Units_DisplayNumber(Seven);
    else if(Units_Value == 8)  Units_DisplayNumber(Eight);
    else if(Units_Value == 9)  Units_DisplayNumber(Nine);

    if(Tens_Value == 0) Tens_DisplayNumber(Zero);
    else if(Tens_Value == 1)  Tens_DisplayNumber(One);
    else if(Tens_Value == 2)  Tens_DisplayNumber(Two);
    else if(Tens_Value == 3)  Tens_DisplayNumber(Three);
    else if(Tens_Value == 4)  Tens_DisplayNumber(Four);
    else if(Tens_Value == 5)  Tens_DisplayNumber(Five);
    else if(Tens_Value == 6)  Tens_DisplayNumber(Six);
    else if(Tens_Value == 7)  Tens_DisplayNumber(Seven);
    else if(Tens_Value == 8)  Tens_DisplayNumber(Eight);
    else if(Tens_Value == 9)  Tens_DisplayNumber(Nine);
}

void setup(){
  for(int i = 2; i < 9; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(Units, OUTPUT);
  pinMode(Tens, OUTPUT);
  pinMode(Button,INPUT_PULLUP); //Setting button pin as input
}

void loop() {
  if(!digitalRead(Button)){ //Increasing Count when button 
    Counter++;              //is pressed
    delay(200);    //Waiting for the Button to be released
  }
  DisplayNumber(Counter);   //Displaying the count
  if(Counter > 99)  Counter = 0;  //Resetting the counter
}

