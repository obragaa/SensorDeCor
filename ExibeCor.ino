//Programa: Sensor TCS3200
 
//Pins de ligação ao Arduino
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
  
//Variáveis das cores
int ver = 0;
int verde = 0;
int azul = 0;
 
void setup()
{
 // amarelo
  pinMode(12, OUTPUT);

  // verde
  pinMode(7, OUTPUT);

  //vermelho
  pinMode(8, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Detecta a cor
  cor();
  //Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(ver, DEC);

  Serial.print(" Verde : ");
  Serial.print(verde, DEC);

  Serial.print(" Azul : ");
  Serial.print(azul, DEC);

  Serial.println();
 

  //Verifica se a cor vermelha foi detetada
  if (ver < azul && ver < verde && ver < 100)
  {
    Serial.println("Vermelho");
  }
 

  //Verifica se a cor azul foi detetada
  else if (azul < ver && azul < verde && azul < 1000)
  {
    Serial.println("Azul");
  }
 

  //Verifica se a cor verde foi detetada
  else if (verde < ver && verde < azul)
  {
    Serial.println("Verde");
  }


  Serial.println();
 
  //Espera para a proxima leitura e reiniciar o processo
  delay(500);
} 
void cor()
{
  //Rotina para leitura das cores RGB
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  //Regista o valor da cor vermelha na variável ver
  ver = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);


  //Regista o valor da cor azul na variável azul
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);


  //Regista o valor da cor verde na variável verde
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}