#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
DHT dht(D1,DHT22);
float hum,temp_c,temp_f;
char* ssid = "BITS-IOT";
char* pass = "b!t$%2o25&pw";
WiFiClient client;
long id = 3070306;
char* api = ""; //Enter your API Key
char ip[] = "184.106.153.149";

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Connecting to WiFi..");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println("WiFi Connected");
  ThingSpeak.begin(client);
}

void loop() {
  if(client.connect(ip,80)){
      hum = dht.readHumidity();
      temp_c = dht.readTemperature();
      temp_f = dht.readTemperature(true);
      Serial.print("Humidity:");Serial.print(hum);Serial.print(",");
      Serial.print("Temperature:");Serial.print(temp_c);Serial.print("*C,");
      Serial.print(temp_f);Serial.println("*F");
      ThingSpeak.setField(1,hum);
      ThingSpeak.setField(2,temp_c);
      ThingSpeak.setField(3,temp_f);
      ThingSpeak.writeFields(id,api);
    }
  delay(100);
}
