# Deneyap Gerçek Zamanlı Saat Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Gerçek Zamanlı Saat MCP7940 için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M50**, **mpv1.0**
- `MCU` MCP79400
- `Ağırlık`
- `Modul Boyutları` 25,4 mm x 25,4 mm
- `I2C Adres` 0x6F, 0x57

| Adres |  | 
| :--- | :---     |
| 0x6F, 0x57 | varsayılan adres |

## :closed_book:Dokümanlar
[Deneyap Gerçek Zamanlı Saat](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-rtc-m50)

[Deneyap Gerçek Zamanlı Saat Şematik](https://docs.deneyapkart.org/en/content/contentDetail/deneyap-module-deneyap-rtc-m50)

[Deneyap Gerçek Zamanlı Saat Teknik Çizim](https://cdn.deneyapkart.org/media/upload/userFormUpload/exe2a7in62EN7ZwVND0DpCVeDrsT47Km.pdf)

[MCP7940-datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP79400-MCP79401-MCP79402-Data-Sheet-20005009G.pdf)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Gerçek Zamanlı Saat
Bu Arduino kütüphanesi Deneyap Gerçek Zamanlı Saatin I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.1 - örnek uygulamalarındaki yorum satırları güncellendi

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Gerçek Zamanlı Saat ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

| Gerçek Zamanlı Saat | Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     |3.3V Besleme Gerilimi| 3.3V    |
| GND      |Toprak|GND      |
| SDA      |Çift Yönlü Veri Hattı| SDA pini |
| SCL      |Veri Hatta Zaman Senkronivasyon İşareti| SCL pini|
| OUT      |Genel Amaçlı Çıkış Pini|PWM pin|

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-gercek-zamanli-saat-arduino-library/blob/master/LICENSE) dosyasını inceleyin.