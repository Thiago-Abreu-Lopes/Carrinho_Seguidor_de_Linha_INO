#define ldr1 A0
#define ldr2 A4
#define motor1 5 //Porta PWM
#define motor2 9 //Porta PWM
#define linha1 400
#define linha2 400

int vldr1 = 0;
int vldr2 = 0;
int motor_1 = 0;
int motor_2 = 0;


void setup() {
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  //digitalWrite(motor1,HIGH); //MANTEM O MOTOR 1 DESLIGADO
  //digitalWrite(motor2,HIGH); //MANTEM O MOTOR 2 DESLIGADO
  Serial.begin(9600);

}

void loop() {
  vldr1 = analogRead(ldr1); //CAPTURA O VALOR DO LDR1
  vldr2 = analogRead(ldr2); //CAPTURA O VALOR DO LDR2
  
  //ATUAÇÃO PELA LÓGICA  ORIGINAL
  if(vldr1>linha1 && vldr2>linha2){
    digitalWrite(motor1,HIGH); //DESLIGA MOTOR 1
    digitalWrite(motor2,HIGH); //DESLIGA MOTOR 2
  }else if(vldr1>linha1){ 
    digitalWrite(motor1,HIGH); //DESLIGA MOTOR 1
    digitalWrite(motor2,LOW); //LIGA MOTOR 2  
  }else if(vldr2>linha2){
    digitalWrite(motor2,HIGH); //DESLIGA MOTOR 2
    digitalWrite(motor1,LOW); //LIGA MOTOR 1 
  }else{
    digitalWrite(motor1,LOW); //LIGA MOTOR 1 
    digitalWrite(motor2,LOW); //LIGA MOTOR 2
  }

  //TENTIVA DE ATUAÇÃO POR PWM 
  /*motor_1=map(vldr2,328,553,255,0);
  motor_2=map(vldr1,333,508,255,0);
  analogWrite(motor1,motor_1);
  analogWrite(motor2,motor_2);*/

  //IMPRESSÃO DOS VALORES DO LDR
  Serial.print("LDR 1: ");
  Serial.print(vldr1);
  Serial.print("  LDR 2: ");
  Serial.println(vldr2);
  /*Serial.print("Motor 1: ");
  Serial.print(motor_1);
  Serial.print("  Motor 2: ");
  Serial.println(motor_2);*/
  //TEMPO DE LEITURA A CADA 0.5 SEGUNDOS
  //delay(500);
}
