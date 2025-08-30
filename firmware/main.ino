#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID   "TMPL3z58DlEiu"
#define BLYNK_TEMPLATE_NAME "FISH TANK MONITORING"
#define BLYNK_AUTH_TOKEN    "4Vm23sH3mGhf15ctlM6LbZ2FOawIKoY"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

#define RX_PIN 22
#define TX_PIN 23

const int ldrPin = 34;
const int lightPin = 14;
const int oneWireBus = 4;
int led, l, pH;

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
SoftwareSerial sensorSerial(RX_PIN, TX_PIN);

char ssid[] = "selva";        // type your wifi name
char pass[] = "selvadinesh";  // type your wifi password

BlynkTimer timer;

void sendSensor() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  Serial.print(temperatureC);
  Serial.println("°C");

  if (sensorSerial.available() > 0) {
    String serialData = sensorSerial.readStringUntil('\n');
    int indexOfPH = serialData.indexOf("PH:");
    if (indexOfPH != -1) {
      String phValue = serialData.substring(indexOfPH + 3, serialData.indexOf(',', indexOfPH));
      pH = phValue.toFloat();

      Serial.print("pH Value: ");
      Serial.println(pH);
    }
  }

  l = analogRead(ldrPin);
  Serial.print("ldr value:");
  Serial.println(l);

  if (l > 1000) {
    digitalWrite(lightPin, LOW);
    led = 0;
  } else {
    digitalWrite(lightPin, HIGH);
    led = 1;
  }

  Blynk.virtualWrite(V1, temperatureC);
  Blynk.virtualWrite(V0, pH);
  Blynk.virtualWrite(V2, led);

  if (pH > 8) {
    Blynk.logEvent("ph_alert", "The pH is NOT optimum so change the water in fish tank");
  }

  if (pH < 6) {
    Blynk.logEvent("ph_alert", "The pH is NOT optimum so change the water in fish tank");
  }

  if (temperatureC > 27) {
    Blynk.logEvent("temperature_alert", "The temperature is NOT optimum so check the heater in fish tank");
  }

  if (temperatureC < 21) {
    Blynk.logEvent("temperature_alert", "The temperature is NOT optimum so check the heater in fish tank");
  }
}

void setup() {
  Serial.begin(9600);
  sensorSerial.begin(9600);
  sensors.begin();

  pinMode(lightPin, OUTPUT);
  pinMode(ldrPin, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2500L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
