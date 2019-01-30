
int x = 0;
String reponsePycharm = "start";

void setup() {
  Serial.begin(9600);
  Serial.println("Test de comm entre arduino (OpenCR) et Pycharm");

}

void loop() {
  while(reponsePycharm != "stop"){
    x++;
    Serial.print("Hello for the ");
    Serial.print(x);
    Serial.println(" time"); 
    
    while(Serial.available() > 0){
      reponsePycharm = Serial.read();
    }
  }
}
