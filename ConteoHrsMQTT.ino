#include <WiFi.h>
#include <PubSubClient.h>

// ===========================
// Enter your WiFi credentials
// ===========================
const char* ssid = "Itzcuincles_2.4Gnormal";   // Red a conectarse 
const char* password = "1123581321";

// Configuraciones MQTT
const char* mqtt_server = "broker.hivemq.com";    // broker publico, conectarse en cualquier momento sin modificar ip
const char* mqtt_topic_inicio = "esp32/inicio"; // topicos de la esp 
const char* mqtt_topic_alerta = "esp32/alerta";
const char* mqtt_topic_descanso = "esp32/descanso";
// publicacion de mqtt 
WiFiClient espClient;
PubSubClient client(espClient); 

// Pines y variables de control
const int pinInicio = 13;
const int pinDescanso = 12;
const int pinAlarma = 14;
const int pinEstado = 27; 
unsigned long startTime;
bool counting = false;  // si esta contando prende led azul 

// Control de reconexión
unsigned long lastReconnectAttempt = 0;
const unsigned long reconnectInterval = 5000;  // Intervalo inicial de reconexión (5 segundos)

bool reconnectMQTT();
bool sendMQTTMessage(const char* topic, const char* message);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // Configurar MQTT
  client.setServer(mqtt_server, 1883);

  // Configurar pines
  pinMode(pinInicio, INPUT);
  pinMode(pinDescanso, INPUT);
  pinMode(pinAlarma, OUTPUT);
  pinMode(pinEstado, OUTPUT); // Configurar el nuevo pin como salida
  digitalWrite(pinAlarma, LOW);
  digitalWrite(pinEstado, LOW); // Inicialmente en bajo
}

void loop() {
  if (!client.connected()) {
    unsigned long now = millis();
    if (now - lastReconnectAttempt > reconnectInterval) {
      lastReconnectAttempt = now;
      if (reconnectMQTT()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    client.loop();
  }

  if (digitalRead(pinInicio) == HIGH && !counting) {
    sendInicioMessage();
  }

  if (digitalRead(pinDescanso) == HIGH && counting) {
    sendDescansoMessage();
  }

  if (counting) {
    checkAlerta();
  }
}

void sendInicioMessage() {
  String message = "{\"tabla\":\"estado_tiempos\",\"estado\":\"inicio\",\"duracion\":0}";
  if (sendMQTTMessage(mqtt_topic_inicio, message.c_str())) {
    startTime = millis();
    counting = true;
    digitalWrite(pinAlarma, HIGH);
    digitalWrite(pinEstado, HIGH); // Poner el pin en alto
  }
}

void sendDescansoMessage() {
  unsigned long elapsedMinutes = (millis() - startTime) / 60000;
  String message = "{\"tabla\":\"estado_tiempos\",\"estado\":\"descanso\",\"duracion\":" + String(elapsedMinutes) + "}";
  if (sendMQTTMessage(mqtt_topic_inicio, message.c_str())) {
    counting = false;
    digitalWrite(pinAlarma, LOW);
    digitalWrite(pinEstado, LOW); // Poner el pin en bajo
  }
}

void checkAlerta() {
  unsigned long elapsedMinutes = (millis() - startTime) / 60000;
  if (elapsedMinutes >= 50) {
    String message = "{\"tabla\":\"estado_tiempos\",\"estado\":\"alerta\",\"duracion\":" + String(elapsedMinutes) + "}";
    if (sendMQTTMessage(mqtt_topic_alerta, message.c_str())) {
      counting = false;
      digitalWrite(pinAlarma, LOW);
      digitalWrite(pinEstado, LOW); // Poner el pin en bajo
    }
  }
}

bool reconnectMQTT() {
  Serial.print("Attempting MQTT connection...");
  if (client.connect("ESP32Client")) {
    Serial.println("connected");
    return true;
  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println(" try again in 5 seconds");
    return false;
  }
}

bool sendMQTTMessage(const char* topic, const char* message) {
  if (client.connected()) {
    if (client.publish(topic, (const uint8_t*)message, strlen(message), true)) {  // Envía el mensaje con QoS 2
      Serial.println("MQTT message sent: " + String(message));
      return true;
    } else {
      Serial.println("MQTT message failed to send");
      return false;
    }
  } else {
    Serial.println("MQTT not connected, message not sent");
    return false;
  }
}
