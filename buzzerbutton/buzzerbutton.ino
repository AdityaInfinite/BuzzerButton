void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);

  //playWinner(12);
}


int led_button_pin_number[4] = {5, 6, 7, 8};
int led_pin_number[4] = {10, 11, 12, 13};
int reset_button_pin_number = 4;

int led_button_status[4] = {0, 0, 0, 0};

void reset(){
  for(int i=0; i<4; i++){
      led_button_status[i] = 0;
  }
  show_status();
}

void show_status(){
  for(int i=0; i<4; i++){
      digitalWrite(led_pin_number[i], led_button_status[i] ? HIGH : LOW);
  }  
}

void loop() {
   int sv5 = digitalRead(reset_button_pin_number);

   int reset_button_status = (sv5 == HIGH) ? 0 : 1;
   if (reset_button_status) {
     reset();
     return;
   }
   boolean is_led_on = false;
   for(int i=0; i<4; i++){
      is_led_on = is_led_on or led_button_status[i];
   }
   if(not is_led_on){
      for(int i=0; i<4; i++){
        int button_status = digitalRead(led_button_pin_number[i]) == HIGH ? 0 : 1;
        if(button_status){
          led_button_status[i] = button_status;
          show_status();
          break;
        }
      }
   }

   show_status();
   
}
