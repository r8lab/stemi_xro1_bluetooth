#define motorkiriA 6
#define motorkiriB 5
#define motorkananA 9
#define motorkananB 10

char data= " ";

void setup() {
  Serial.begin(9600); 
  pinMode(motorkiriA, OUTPUT);
  pinMode(motorkiriB, OUTPUT);
  pinMode(motorkananA, OUTPUT);
  pinMode(motorkananB, OUTPUT);
}
void motor(int pwmkiriA, int pwmkiriB, int pwmkananA, int pwmkananB){
  analogWrite(motorkiriA, pwmkiriA);
  analogWrite(motorkiriB, pwmkiriB);
  analogWrite(motorkananA, pwmkananA);
  analogWrite(motorkananB, pwmkananB);
}

void loop() {

  if (Serial.available() > 0) {
    data = Serial.read();

    if (data == 'F') {  motor(255,0,255,0); }
    else if (data == 'B') {  motor(0,255,0,255); }
    else if (data == 'L') {  motor(0,255,255,0); }
    else if (data == 'R') {  motor(255,0,0,255); }
    
    else if (data == 'G') {  motor(150,0,255,0); }
    else if (data == 'I') {  motor(255,0,150,0); }
    else if (data == 'H') {  motor(0,150,0,255); }
    else if (data == 'J') {  motor(0,255,0,150); }
    
    else {  motor(0,0,0,0); }    
  }
}
