/*****************************************************************************************
 * NTC mit Arduino auswerten und Temperatur berechnen.                                   *
 * --------------------------------------------------------------------------------------*
 * Ausgabe Seriell mit 9600 Baud                                                         *
 * --------------------------------------------------------------------------------------*
 * NTC mit einer Seite an Vcc (bzw. wenn Aref anders gewählt wird an Quelle von Aref)    *
 * andere Seite an analog Port und von analog Port Widerstand R2 an GND.                 *
 *                                                                                       *
 * VCC---(NTC)---*---(R2)---GND                                                          *
 *               |                                                                       *
 *               |                                                                       *
 *           analog Port                                                                 *
 *                                                                                       *
 * Die Genauigkeit ist abhängig von der Stabilität von VCC und der Angabe ADCref.        *
 * Man kann VCC im obigen Beispiel durch eine Referenzspannungsquelle ersetzen und       *
 * diese dann auch als Aref verwenden. ADCref ist entsprechend anzupassen.               *
 *---------------------------------------------------------------------------------------*
 *  (C) 2020 14th of June   Dr.sc. Klaus Helmgens, M.I.T., USA                           *
 *  This example code is in the public domain an can be used free as long as the         *
 *  usage is non comercial.                                                              * 
 *****************************************************************************************/


const float Tr = 298.15; // Referenz Temperature in Kelvin (25°C)
const float B = 3528; // B-Wert des NTC
const float Rr = 1500; // Referenz Widerstand bei Referenz Temperature
const float R2 = 10000; // Widerstand im Spannungsteiler mit NTC gegen GND
const float ADCref = 5.00; // Referenzspannung des ADC am Aref Eingang !Dezimalpunkt ist wichtig!

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  // analogReference(EXTERNAL); // Wenn Aref mit anderer Spannung statt AVcc genutzt wird.
}

void loop() {
  float Rn = widerstand(0);
  float Tn = temperature(Rn);
  Serial.print("Widerstand des NTC = ");
  Serial.print(Rn);
  Serial.println(" Ohm");
  Serial.print("Temperature = ");
  Serial.print(Tn);
  Serial.println(" °C");
  delay(2000);

}


float temperature(float R1) {
  float Tn = ((Tr / (1 - (Tr / B) * log(Rr / R1)))) - 273.15;
  return Tn;
}

float widerstand(int port) {
  int adc = analogRead(port);
  delay(100);
  float U2 = (ADCref / 1023) * adc;
  float R1 = (R2 / (U2 / ADCref)) - R2;
  return R1;
}
