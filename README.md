# Deneyap Real Time Clock MCP7940 Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Real Time Clock MCP7940

## :mag_right:Specifications 
- `Product ID` **M50**, **mpv1.0**
- `MCU` MCP79400
- `Weight` 
- `Module Dimension`
- `I2C address` 0x6F, 0x57

| Address |  | 
| :---      | :---     |
| 0x6F, 0x57 | default address |

## :closed_book:Documentation
Deneyap Real Time Clock MCP7940

[MCP7940](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP79400-MCP79401-MCP79402-Data-Sheet-20005009G.pdf)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Real Time Clock MCP7940
This Arduino library allows you to use Deneyap Real Time Clock MCP7940 with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Real Time Clock and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|Real Time Clock| Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|SDA  | I2C Data  | SDA pin |
|SCL  | I2C Clock | SCL pin |
|OUT  | OUTPUT pin|         |

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-gercek-zamanli-saat-arduino-library/blob/master/LICENSE) file for license information.

Based on Zanduino MCP7940 Arduino Library. Changed to work with Deneyap Real Time Clock MCP7940.
