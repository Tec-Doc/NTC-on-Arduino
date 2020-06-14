# NTC-on-Arduino
This is to show how easy you can read a NTC and calculate the temperature.



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
