/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

#include <BlynkSimpleEsp8266.h>

const char* host = "esp8266-webupdate";
const char* ssid = "WAKANDA";
const char* password = "jombloelit";


#define BLYNK_PRINT Serial

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
#define tombol 0
#define led 13
#define relay 12
#define aman 2
char auth[] = "jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC";
void setup(void) {

  pinMode(tombol, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
  WiFi.mode(WIFI_AP_STA);
  // WiFi.begin(ssid, password);

  // while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    // WiFi.begin(ssid, password);
    Blynk.begin(auth, ssid, password, "blynk-cloud.com", 8080);
    // Serial.println("WiFi failed, retrying.");
    digitalWrite(led, HIGH);
  // }

  digitalWrite(led, LOW);


  MDNS.begin(host);

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop(void) {
  // int dataTombol  = digitalRead(tombol);


  // digitalWrite(led, dataTombol);
  // digitalWrite(relay, dataTombol);
  
  Blynk.run();
  httpServer.handleClient();
}
