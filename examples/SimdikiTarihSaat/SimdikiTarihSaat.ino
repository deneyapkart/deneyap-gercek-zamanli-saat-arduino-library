/*
 *   Şimdiki tarih ve saat örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Şimdiki tarih ve saatten sonraki zaman akışını seri terminale yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap Gerçek Zamanlı Saat için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-gercek-zamanli-saat-arduino-library  <------
 *
*/

#include <Deneyap_GercekZamanliSaat.h>                                      // Deneyap_GercekZamanliSaat kutuphanesi eklenmesi

RTC GercekZamanliSaat;                                                      // RTC için class tanımlaması

void setup() {
    Serial.begin(115200);                                                   // Seri haberleşme başlatılması
    if (!GercekZamanliSaat.begin()) {                                       // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");                        // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1) ;
    }
    GercekZamanliSaat.deviceStart();
    GercekZamanliSaat.adjust();
}

void loop() {
    DateTime now = GercekZamanliSaat.now();
    Serial.print("\nTarih:");
    Serial.printf("%02d/%02d/%04d", now.day(), now.month(), now.year());     // yıl, ay, günün seri terminale yazdırılması
    Serial.print("\tSaat:");
    Serial.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second()); // saat, dakika, saniyeyi seri terminale yazdırılması
    delay(1000);
} 
