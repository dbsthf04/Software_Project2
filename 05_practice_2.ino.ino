#define PIN_LED 7
unsigned int count, toggle;

int toggle_state(int toggle);

void setup() {
  pinMode(PIN_LED, OUTPUT);  
  Serial.begin(115200);
  digitalWrite(PIN_LED,0);
  delay(1000);
  while(!Serial){
    ;
  }
  Serial.println("Hello World!");
  count = toggle = 0;
}

void loop() {
   if (count < 10) {
    Serial.println(++count);
    toggle = toggle_state(toggle);
    digitalWrite(PIN_LED, toggle);
    delay(100);
  } else {
    digitalWrite(PIN_LED, 1);
  }
}

int toggle_state(int toggle) {
  toggle = (toggle + 1) % 2;
  return toggle;
}
