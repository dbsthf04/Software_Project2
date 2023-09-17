#define PIN_LED 13
unsigned int count, toggle;

// 함수 원형 선언
int toggle_state(int toggle);

void setup() {
  pinMode(PIN_LED, OUTPUT);  // LED 핀을 출력으로 설정
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  Serial.println("Hello World!");
  count = toggle = 0;
  digitalWrite(PIN_LED, toggle);
}

void loop() {
  Serial.println(++count);
  toggle = toggle_state(toggle);
  digitalWrite(PIN_LED, toggle);
  delay(1000);
}

int toggle_state(int toggle) {
  toggle = (toggle + 1) % 2;
  return toggle;
}
