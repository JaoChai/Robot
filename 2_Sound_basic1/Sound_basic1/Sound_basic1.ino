
int timeSound = 100;
int time = 500;
void setup() {
 
}

void loop() {
  // no need to repeat the melody.
  tone(9,131,timeSound);
  delay(time);
  tone(9,147,timeSound);
  delay(time);
  tone(9,165,timeSound);
  delay(time);
  tone(9,175,timeSound);
  delay(time);
  tone(9,196,timeSound);
  delay(time);
  tone(9,220,timeSound);
  delay(time);
  tone(9,247,timeSound);
  delay(time);
  tone(9,262,timeSound);
  delay(time);
  noTone(9);
  delay(time);
}
