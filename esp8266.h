#include <ESP8266WiFi.h>

const char* ssid = "DILMA TCHAU QUERIDA";
const char* password = "midianet";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  //pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  digitalWrite(2, 0); 
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(12,0); 
  digitalWrite(13,0);
  digitalWrite(14,0);
  digitalWrite(16,0);
  digitalWrite(15,0);
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
  delay(1000);
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("New request");
  while(!client.available()){
    delay(1);
  }
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  String buf = "";
  buf += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
  buf += "<h3>Stark Auto-Home</h3>";
  buf += "<p>GPALL    <a href=\"?function=all_on\"><button>ON</button></a> <a href=\"?function=all_off\"><button>OFF</button></a></p>";
  //buf += "<p>GPIO2  <a href=\"?function=led2_on\"><button>ON</button></a> <a href=\"?function=led2_off\"><button>OFF</button></a></p>";
  buf += "<p>GPIO4  <a href=\"?function=led4_on\"><button>ON</button></a> <a href=\"?function=led4_off\"><button>OFF</button></a></p>";
  buf += "<p>GPIO5  <a href=\"?function=led5_on\"><button>ON</button></a> <a href=\"?function=led5_off\"><button>OFF</button></a></p>";
  buf += "<p>GPIO12 <a href=\"?function=led12_on\"><button>ON</button></a> <a href=\"?function=led12_off\"><button>OFF</button></a></p>";
  buf += "<p>GPIO13 <a href=\"?function=led13_on\"><button>ON</button></a> <a href=\"?function=led13_off\"><button>OFF</button></a></p>";
  buf += "<p>GPIO14 <a href=\"?function=led14_on\"><button>ON</button></a> <a href=\"?function=led14_off\"><button>OFF</button></a></p>";
  buf += "<p>GPIO15 <a href=\"?function=led15_on\"><button>ON</button></a> <a href=\"?function=led15_off\"><button>OFF</button></a></p>";  
  buf += "<p>GPIO16 <a href=\"?function=led16_on\"><button>ON</button></a> <a href=\"?function=led16_off\"><button>OFF</button></a></p>"; 
  buf += "<h4>By Midianet</h4>";
  buf += "</html>\n";
  client.print(buf);
  client.flush();
  if(req.indexOf("all_on") != -1)
    setAll(1);
  else if(req.indexOf("all_off") != -1)
    setAll(0); 
  //if (req.indexOf("led2_on") != -1)
  //  setPort(2,1);
  //else if (req.indexOf("led2_off") != -1)
  //  setPort(2,0);
  else if (req.indexOf("led4_on") != -1)
    setPort(4,1);
  else if (req.indexOf("led4_off") != -1)
    setPort(4,0);
  else if (req.indexOf("led5_on") != -1)
    setPort(5,1);
  else if (req.indexOf("led5_off") != -1)
    setPort(5,0);
  else if (req.indexOf("led12_on") != -1)
    setPort(12,1);
  else if (req.indexOf("led12_off") != -1)
    setPort(12,0);
  else if (req.indexOf("led13_on") != -1)
    setPort(13,1);
  else if (req.indexOf("led13_off") != -1)
    setPort(13,0);
  else if (req.indexOf("led14_on") != -1)
    setPort(14,1);
  else if (req.indexOf("led14_off") != -1)
    setPort(14,0);
  else if (req.indexOf("led15_on") != -1)
    setPort(15,1);
  else if (req.indexOf("led15_off") != -1)
    setPort(15,0);    
  else if (req.indexOf("led16_on") != -1)
    setPort(16,1);
  else if (req.indexOf("led16_off") != -1)
    setPort(16,0);    
  else {
    Serial.println("Invalid request");
    client.stop();
  }
  Serial.println("End request");
}

void setAll(int value){
    //digitalWrite(2, value); 
    digitalWrite(4, value); 
    digitalWrite(5, value); 
    digitalWrite(12,value); 
    digitalWrite(13,value); 
    digitalWrite(14,value); 
    digitalWrite(15,value); 
}

void setPort(int port, int value){
  digitalWrite(port,value);  
}
