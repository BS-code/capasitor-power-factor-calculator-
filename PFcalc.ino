#include <math.h>
#include <SoftwareSerial.h>
#include <PZEM004T.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Deklarasi konstanta
const int SENSOR_RX = 2; // Pin Rx sensor PZEM-004T
const int SENSOR_TX = 3; // Pin Tx sensor PZEM-004T
const int SENSOR_ADDRESS = 1; // Alamat sensor PZEM-004T

PZEM004T sensor(SENSOR_ADDRESS);
SoftwareSerial serial(SENSOR_RX, SENSOR_TX);

// Inisialisasi objek LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // Inisialisasi Serial Monitor
  Serial.begin(9600);
  
  // Inisialisasi sensor PZEM-004T
  serial.begin(9600);
  
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  // Mengambil nilai tegangan, arus, daya, frekuensi, dan cos phi dari sensor PZEM-004T
  float voltage = sensor.voltage(serial);
  float current = sensor.current(serial);
  float power = sensor.power(serial);
  float cos_phi = sensor.readPF(serial);
  float frequency = sensor.frequency(serial) ; 

  // Menghitung impedansi
  float Z = voltage / (current * cos_phi);

  // Menghitung kapasitansi
  float C = 1 / (2 * PI * frequency * Z);

  // Menampilkan hasil di Serial Monitor
  Serial.print("Kapasitansi yang diperlukan: ");
  Serial.print(C, 6);
  Serial.println(" Farad");
  Serial.print("Cos phi: ");
  Serial.println(cos_phi, 4);

  // Menampilkan hasil di LCD
  lcd.setCursor(0, 0);
  lcd.print("Kapasitansi: ");
  lcd.print(C, 6);
  lcd.print("F");

  lcd.setCursor(0, 1);
  lcd.print("Cos phi: ");
  lcd.print(cos_phi, 4);
  
  delay(1000);
}
