#include <WiFi.h>
#include "FirebaseESP32.h"

#define FIREBASE_HOST "hw-bootcamp.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "Wleb7G85te03i9RRbZsU9X5Za56g4xwD5D3jMNLG"
#define WIFI_SSID "PEET"
#define WIFI_PASSWORD "10042541"

FirebaseData firebaseData;


void setup() {
 Serial.begin(115200);
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  
}

void loop() {
 //SET  
 Firebase.setInt(firebaseData,"/set/int",100);
 Firebase.setString(firebaseData,"/set/String","Hello");
 Firebase.setDouble(firebaseData,"/set/Double",2.5);
 //PUSH
 Firebase.pushInt(firebaseData,"/Psh/Int",100);
 delay(100);
 //GAT
 if(Firebase.getString(firebaseData,"/LED/Satatus")){
  Serial.println(firebaseData.stringData());
 }
}
