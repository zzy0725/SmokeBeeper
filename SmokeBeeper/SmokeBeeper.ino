#define SMOKE_ONE_DEFAULT 75
#define SMOKE_TWO_DEFAULT 125
#define BURNABLE_ONE_DEFAULT 200
void setup() {
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(9, HIGH);
  Serial.begin(1200);
  for (int t = 20; t > 0; t -= 1)
  {
    Serial.println(t);
    Serial.print("Smoke1:75/");
    Serial.println(analogRead(0), DEC);
    Serial.print("Smoke2:125/");
    Serial.println(analogRead(4), DEC);
    Serial.print("Burnable:200/");
    Serial.println(analogRead(2), DEC);
    Serial.println();
    digitalWrite(9, LOW);
    delay(20);
    digitalWrite(9, HIGH);
    for (int y = 15; y > 0; y -= 1)
    {
      digitalWrite(13, HIGH);
      delay(250);
      digitalWrite(13, LOW);
      delay(250);
      digitalWrite(13, HIGH);
      delay(250);
      digitalWrite(13, LOW);
      delay(250);
    }
  }
}

void loop()
{
  Serial.print(analogRead(0), DEC);
  Serial.print("|");
  Serial.print(analogRead(4), DEC);
  Serial.print("|");
  Serial.print(analogRead(2), DEC);
  Serial.print("|");
  Serial.println("80,95,155=NORMAL");
  delay(297);
  if (analogRead(0) > SMOKE_ONE_DEFAULT || analogRead(4) > SMOKE_TWO_DEFAULT)
  {
    Serial.println("Smoke Sensor Over Value!!");
    Serial.print("Smoke1:75/");
    Serial.println(analogRead(0), DEC);
    Serial.print("Smoke2:125/");
    Serial.println(analogRead(4), DEC);
    Serial.println();
    digitalWrite(9, LOW);
    delay(600);
    digitalWrite(9, HIGH);
  }
  if (analogRead(2) > BURNABLE_ONE_DEFAULT)
  {
    Serial.println("Burnable Gas Sensor Over Value!!");
    Serial.print("CO:200/");
    Serial.println(analogRead(2), DEC);
    Serial.println();
    digitalWrite(9, LOW);
    delay(600);
    digitalWrite(9, HIGH);
  }
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}
