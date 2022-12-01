/*
 *   SimdikiTarihSaat örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Şimdiki tarih ve saati seri port ekranına yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap Gerçek Zamanlı Saat için oluşturulmuştur
 *      ------> https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-rtc-m50 <------
 *      ------> https://github.com/deneyapkart/deneyap-gercek-zamanli-saat-arduino-library <------
*/
#include <Deneyap_GercekZamanliSaat.h>                                      // Deneyap Gerçek Zamanlı Saat kutuphanesi eklenmesi

RTC GercekZamanliSaat;                                                      // RTC için class tanımlaması

void setup() {
    Serial.begin(115200);                                                   // Seri haberleşme başlatılması
    if (!GercekZamanliSaat.begin()) {                                       // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");                        // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
        while (1) ;
    }
    GercekZamanliSaat.deviceStart();
    GercekZamanliSaat.adjust();
}

void loop() {
    DateTime now = GercekZamanliSaat.now();
    Serial.print("\nTarih:");
    Serial.printf("%02d/%02d/%04d", now.day(), now.month(), now.year());     // yıl, ay, günün seri port ekranına yazdırılması
    Serial.print("\tSaat:");
    Serial.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second()); // saat, dakika, saniyeyi seri port ekranına yazdırılması
    delay(1000);
} 
