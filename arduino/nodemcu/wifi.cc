#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// D4 pin is default built in LED

char auth[] = "";
char ssid[] = "";
char pass[] = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
  
  Blynk.begin(auth, ssid, pass);
//  Blynk.connect();  // timeout set to 10 seconds and then continue without Blynk

  Serial.println("Connected to Blynk server");
}

void loop() {
  Blynk.run();
}