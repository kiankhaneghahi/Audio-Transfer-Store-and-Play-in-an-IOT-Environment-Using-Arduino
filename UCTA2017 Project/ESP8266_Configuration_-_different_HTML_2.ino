#include <ESP8266WiFi.h>


const char* ssid = "Kian Khaneghahi";
const char* password = "Kian123456@";

WiFiServer server(80);

int output_pin = 2;

void setup() {

 

  
  Serial.begin(9600);
  delay(10);

  pinMode(output_pin, OUTPUT);
  digitalWrite(output_pin, 0);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");

  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }


  while (!client.available()) {
  delay(1);
  }

  String req = client.readStringUntil('\r');
  //Serial.println(req);

  if (req.indexOf("/Download") != -1) {
  //digitalWrite(output_pin, 0);
  Serial.println('d');
     
  }
  else if (req.indexOf("/Play") != -1) {
  digitalWrite(output_pin, 0);
  Serial.println('p');
     
  }
  else if (req.indexOf("/Stop") != -1) {
  //digitalWrite(output_pin, 0);
  Serial.println('s');

  }
  else if (req.indexOf("/Volume100") != -1) {
  //digitalWrite(output_pin, 0);
  Serial.println('a');
     
  }
  else if (req.indexOf("/Volume50") != -1) {
  //digitalWrite(output_pin, 0);
  Serial.println('b');

  }
  else if (req.indexOf("Volume0") != -1) {
  //digitalWrite(output_pin, 0);
  Serial.println('c');
  }
  

    client.flush();
 
  
  /*SERVER HTML CODE */
  
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";

  
  s += "<head>";
  s += "<meta charset=\"utf-8\">";
  s += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  s += "<script src=\"https://code.jquery.com/jquery-2.1.3.min.js\"></script>";
  s += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css\">";
  s += "</head>";
  
  s += "<div class=\"container\">";
  s += "<h1>  In The Name Of God </h1>";
  s += "<h1>  Media Control : </h1>";
  s += "<div class=\"row\">";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\"type=\"button\" value=\"Download\" onclick=\"Download()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"Play\" onclick=\"Play()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"Stop\" onclick=\"Stop()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"Volume100\" onclick=\"Volume100()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"Volume50\" onclick=\"Volume50()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\"style=\"font-size:24px;border-radius:100%;height:100px;width:200px;\" type=\"button\" value=\"Volume0\" onclick=\"Volume0()\"></div>";
  s += "</div></div>";
  

  s += "<script>function Download() {$.get(\"/Download\");}</script>";
  s += "<script>function Play() {$.get(\"/Play\");}</script>";
  s += "<script>function Stop() {$.get(\"/Stop\");}</script>";
  s += "<script>function Volume100() {$.get(\"/Volume100\");}</script>";
  s += "<script>function Volume50() {$.get(\"/Volume50\");}</script>";
  s += "<script>function Volume0() {$.get(\"/Volume0\");}</script>";
  


  client.print(s);
  delay(1);
    
  //Serial.println("Client disconnected");
}
