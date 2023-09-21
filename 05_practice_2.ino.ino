#define PIN_LED 7
unsigned int count, toggle;

// 함수 원형 선언
int toggle_state(int toggle);

void setup() {
  pinMode(PIN_LED, OUTPUT);  // LED 핀을 출력으로 설정
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
   if (count < 10) { // count가 10보다 작을 때만 아래 코드를 실행
    Serial.println(++count);
    toggle = toggle_state(toggle);
    digitalWrite(PIN_LED, toggle);
    delay(100);
  } else {
    // count가 10 이상이면 루프를 멈춤
    digitalWrite(PIN_LED, 1);
      // 루프를 멈추기 위해 아무것도 하지 않음
  
  }
}

int toggle_state(int toggle) {
  toggle = (toggle + 1) % 2;
  return toggle;
}
