# 1 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino"
# 1 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino"
/*

  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update

*/
# 5 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino"
# 6 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino" 2
# 7 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino" 2
# 8 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino" 2
# 9 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino" 2
# 10 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino" 2

# 12 "d:\\Project\\Arduino\\sonoff_ota\\sonoff_ota.ino" 2

const char* host = "esp8266-webupdate";
const char* ssid = "WAKANDA";
const char* password = "jombloelit";




ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;




char auth[] = "jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC";
void setup(void) {

  pinMode(0, 0x02);
  pinMode(13, 0x01);
  pinMode(12, 0x01);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
  WiFi.mode(WIFI_AP_STA);
  // WiFi.begin(ssid, password);

  // while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    // WiFi.begin(ssid, password);
    Blynk.begin(auth, ssid, password, "blynk-cloud.com", 8080);
    // Serial.println("WiFi failed, retrying.");
    digitalWrite(13, 0x1);
  // }

  digitalWrite(13, 0x0);


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
# 1 "d:\\Project\\Arduino\\sonoff_ota\\secondaryCode.ino"
