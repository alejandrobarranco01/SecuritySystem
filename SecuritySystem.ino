#include <HTTPClient.h>
#include <WiFi.h>

#include "secrets.h"

const int connectionTimeout = 10000;

void setup() {
  Serial.begin(115200);

  // Check to see if we are already connected to Wifi, if so disconnect
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Disconnecting from previous Wi-Fi...\n");
    WiFi.disconnect(true);
    delay(1000);
  }

  unsigned long startConnectionAttemptTime = millis();

  // Connect to Wifi
  WiFi.begin(ssid);  
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED && millis() - startConnectionAttemptTime < connectionTimeout) {
    delay(1000);
    Serial.print(".");
  }

  // Check if Wi-Fi connected or timeout occurred
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

  } else {
    Serial.println("\nFailed to connect to Wi-Fi within the timeout period.");
  }
}

void loop() {
}
