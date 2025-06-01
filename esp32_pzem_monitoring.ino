#include <WiFi.h>
#include <HTTPClient.h>
#include <PZEM004Tv30.h>

#define RXD2 16
#define TXD2 17

HardwareSerial mySerial(2);
PZEM004Tv30 pzem(&mySerial, TXD2, RXD2);

const char* ssid = "POVA 6 Ultimate"; // Ganti nama Wifi/Hostpot ini!
const char* password = "hanan_ganteng06"; // Ganti Password Wifi ini!
const char* serverName = "http://192.168.73.199/pzem_monitoring/receive.php"; // Ganti IP ini!

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, RXD2, TXD2); // <-- HARUS 9600

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float energy = pzem.energy();

  Serial.print("Voltage: "); Serial.println(voltage);
  Serial.print("Current: "); Serial.println(current);
  Serial.print("Power: "); Serial.println(power);
  Serial.print("Energy: "); Serial.println(energy);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = serverName;
    url += "?voltage=" + String(voltage);
    url += "&current=" + String(current);
    url += "&power=" + String(power);
    url += "&energy=" + String(energy);

    http.begin(url);
    int code = http.GET();
    Serial.print("HTTP response: ");
    Serial.println(code);
    http.end();
  }

  delay(1000); // kirim setiap 1 detik
}
