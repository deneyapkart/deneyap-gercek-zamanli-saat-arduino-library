/*
*****************************************************************************
@file         Deneyap_GercekZamanliSaat.h
@mainpage     Deneyap Real Time Clock MCP7940 Arduino library header file
@version      v1.0.0
@date         June 28, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap Real Time Clock MCP7940 Arduino library
*****************************************************************************
*/
#ifndef Deneyap_GercekZamanliSaat_H
#define Deneyap_GercekZamanliSaat_H

#include "Arduino.h" // Arduino data type definitions
#include "Wire.h"    // Standard I2C "Wire" library

/***************************************************************************************************
** Declare classes used in within the class                                                       **
***************************************************************************************************/
class TimeSpan;
/***************************************************************************************************
** Declare constants used in the class                                                            **
***************************************************************************************************/

/** @brief Guard code definition */
#ifndef I2C_MODES // I2C related constants
#define I2C_MODES
const uint32_t I2C_STANDARD_MODE{100000}; ///< Default normal I2C 100KHz speed
const uint32_t I2C_FAST_MODE{400000};     ///< Fast mode
#endif

/** @brief If the "Wire.h" library doesn't define the buffer, do so here */
#if !defined(BUFFER_LENGTH) // The ESP32 Wire library doesn't currently define BUFFER_LENGTH
#define BUFFER_LENGTH 32
#endif

const uint8_t MCP7940_ADDRESS{0x6F};         ///< Device address, fixed value
const uint8_t MCP7940_RTCSEC{0x00};          ///< Timekeeping, RTCSEC Register address
const uint8_t MCP7940_RTCMIN{0x01};          ///< Timekeeping, RTCMIN Register address
const uint8_t MCP7940_RTCHOUR{0x02};         ///< Timekeeping, RTCHOUR Register address
const uint8_t MCP7940_RTCWKDAY{0x03};        ///< Timekeeping, RTCWKDAY Register address
const uint8_t MCP7940_RTCDATE{0x04};         ///< Timekeeping, RTCDATE Register address
const uint8_t MCP7940_RTCMTH{0x05};          ///< Timekeeping, RTCMTH Register address
const uint8_t MCP7940_RTCYEAR{0x06};         ///< Timekeeping, RTCYEAR Register address
const uint8_t MCP7940_CONTROL{0x07};         ///< Timekeeping, RTCCONTROL Register address
const uint8_t MCP7940_OSCTRIM{0x08};         ///< Timekeeping, RTCOSCTRIM Register address
const uint8_t MCP7940_ALM0SEC{0x0A};         ///< Alarm 0, ALM0SEC Register address
const uint8_t MCP7940_ALM0MIN{0x0B};         ///< Alarm 0, ALM0MIN Register address
const uint8_t MCP7940_ALM0HOUR{0x0C};        ///< Alarm 0, ALM0HOUR Register address
const uint8_t MCP7940_ALM0WKDAY{0x0D};       ///< Alarm 0, ALM0WKDAY Register address
const uint8_t MCP7940_ALM0DATE{0x0E};        ///< Alarm 0, ALM0DATE Register address
const uint8_t MCP7940_ALM0MTH{0x0F};         ///< Alarm 0, ALM0MTH Register address
const uint8_t MCP7940_ALM1SEC{0x11};         ///< Alarm 1, ALM1SEC Register address
const uint8_t MCP7940_ALM1MIN{0x12};         ///< Alarm 1, ALM1MIN Register address
const uint8_t MCP7940_ALM1HOUR{0x13};        ///< Alarm 1, ALM1HOUR Register address
const uint8_t MCP7940_ALM1WKDAY{0x14};       ///< Alarm 1, ALM1WKDAY Register address
const uint8_t MCP7940_ALM1DATE{0x15};        ///< Alarm 1, ALM1DATE Register address
const uint8_t MCP7940_ALM1MTH{0x16};         ///< Alarm 1, ALM1MONTH Register address
const uint8_t MCP7940_PWRDNMIN{0x18};        ///< Power-Fail, PWRDNMIN Register address
const uint8_t MCP7940_PWRDNHOUR{0x19};       ///< Power-Fail, PWRDNHOUR Register address
const uint8_t MCP7940_PWRDNDATE{0x1A};       ///< Power-Fail, PWDNDATE Register address
const uint8_t MCP7940_PWRDNMTH{0x1B};        ///< Power-Fail, PWRDNMTH Register address
const uint8_t MCP7940_PWRUPMIN{0x1C};        ///< Power-Fail, PWRUPMIN Register address
const uint8_t MCP7940_PWRUPHOUR{0x1D};       ///< Power-Fail, PWRUPHOUR Register address
const uint8_t MCP7940_PWRUPDATE{0x1E};       ///< Power-Fail, PWRUPDATE Register address
const uint8_t MCP7940_PWRUPMTH{0x1F};        ///< Power-Fail, PWRUPMTH Register address
const uint8_t MCP7940_RAM_ADDRESS{0x20};     ///< NVRAM - Start address for SRAM
const uint8_t MCP7940_ST{7};                 ///< MCP7940 register bits. RTCSEC reg
const uint8_t MCP7940_12_24{6};              ///< RTCHOUR, PWRDNHOUR & PWRUPHOUR
const uint8_t MCP7940_AM_PM{5};              ///< RTCHOUR, PWRDNHOUR & PWRUPHOUR
const uint8_t MCP7940_OSCRUN{5};             ///< RTCWKDAY register
const uint8_t MCP7940_PWRFAIL{4};            ///< RTCWKDAY register
const uint8_t MCP7940_VBATEN{3};             ///< RTCWKDAY register
const uint8_t MCP7940_LPYR{5};               ///< RTCMTH register
const uint8_t MCP7940_OUT{7};                ///< CONTROL register
const uint8_t MCP7940_SQWEN{6};              ///< CONTROL register
const uint8_t MCP7940_ALM1EN{5};             ///< CONTROL register
const uint8_t MCP7940_ALM0EN{4};             ///< CONTROL register
const uint8_t MCP7940_EXTOSC{3};             ///< CONTROL register
const uint8_t MCP7940_CRSTRIM{2};            ///< CONTROL register
const uint8_t MCP7940_SQWFS1{1};             ///< CONTROL register
const uint8_t MCP7940_SQWFS0{0};             ///< CONTROL register
const uint8_t MCP7940_SIGN{7};               ///< OSCTRIM register
const uint8_t MCP7940_ALMPOL{7};             ///< ALM0WKDAY register
const uint8_t MCP7940_ALM0IF{3};             ///< ALM0WKDAY register
const uint8_t MCP7940_ALM1IF{3};             ///< ALM1WKDAY register
const uint32_t SECS_1970_TO_2000{946684800}; ///< Seconds between year 1970 and 2000

/**
 *    @class   DateTime
 *    @brief   Simple general-purpose date/time class
 *    @details Copied from RTClib. For further information on this implementation see
 *             https://github.com/SV-Zanshin/MCP7940/wiki/DateTimeClass
 **/
class DateTime {
public:
    DateTime(uint32_t t = 0);
    DateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour = 0, uint8_t min = 0,
             uint8_t sec = 0);
    DateTime(const DateTime &copy);
    DateTime(const char *date, const char *time);
    DateTime(const __FlashStringHelper *date, const __FlashStringHelper *time);
    uint16_t year() const { /*! return the current year */
        return 2000 + yOff;
    }
    uint8_t month() const { /*! return the current month */
        return m;
    }
    uint8_t day() const { /*! return the current day of the month */
        return d;
    }
    uint8_t hour() const { /*! return the current hour */
        return hh;
    }
    uint8_t minute() const { /*! return the current minute */
        return mm;
    }
    uint8_t second() const { /*! return the current second */
        return ss;
    }
    uint8_t dayOfTheWeek() const;             /*! return the current day of the week starting at 0 */
    long secondstime() const;                 /*! return the current seconds in the year */
    uint32_t unixtime(void) const;            /*! return the current Unixtime */
    DateTime operator+(const TimeSpan &span); /*! Overloaded "+" operator to add two timespans */
    DateTime operator-(const TimeSpan &span); /*! Overloaded "+" operator to add two timespans */
    TimeSpan operator-(
        const DateTime &right); /*! Overloaded "-" operator subtract add two timespans */
protected:
    uint8_t yOff; ///< Internal year offset value
    uint8_t m;    ///< Internal month value
    uint8_t d;    ///< Internal day value
    uint8_t hh;   ///< Internal hour value
    uint8_t mm;   ///< Internal minute value
    uint8_t ss;   ///< Internal seconds
};                // of class DateTime definition

/**
 *   @class   TimeSpan
 *   @brief   Timespan class which can represent changes in time with seconds accuracy
 *   @details Copied from RTClib. For further information see
 *            https://github.com/SV-Zanshin/MCP7940/wiki/TimeSpanClass for additional details
 **/
class TimeSpan {
public:
    TimeSpan(int32_t seconds = 0);                                        ///< Default constructor
    TimeSpan(int16_t days, int8_t hours, int8_t minutes, int8_t seconds); ///< Overloaded constructor
    TimeSpan(const TimeSpan &copy);                                       ///< Overloaded constructor
    int16_t days() const { return _seconds / 86400L; }                    ///< return the number of days
    int8_t hours() const { return _seconds / 3600 % 24; }                 ///< return number of hours
    int8_t minutes() const { return _seconds / 60 % 60; }                 ///< return number of minutes
    int8_t seconds() const { return _seconds % 60; }                      ///< return number of seconds
    int32_t totalseconds() const { return _seconds; }                     ///< return total number of seconds
    TimeSpan operator+(const TimeSpan &right);                            ///< redefine "+" operator
    TimeSpan operator-(const TimeSpan &right);                            ///< redefine "-" operator
protected:
    int32_t _seconds; ///< Internal value for total seconds
};                    // of class TimeSpan definition

/**
 *   @class RTC
 *   @brief Main class definition with forward declarations
 **/
class RTC {
public:
    RTC(){};  ///< Unused Class constructor
    ~RTC(){}; ///< Unused Class destructor
    bool begin(const uint32_t i2cSpeed = I2C_STANDARD_MODE) const;
    bool deviceStatus() const;
    bool deviceStart() const;
    bool deviceStop() const;
    DateTime now() const;
    void adjust();
    void adjust(const DateTime &dt);
    int8_t calibrate() const;
    int8_t calibrate(const int8_t newTrim);
    int8_t calibrate(const DateTime &dt);
    int8_t calibrate(const float fMeas) const;
    int8_t getCalibrationTrim() const;
    uint8_t weekdayRead() const;
    uint8_t weekdayWrite(const uint8_t dow) const;
    bool setMFP(const bool value) const;
    uint8_t getMFP() const;
    bool setAlarm(const uint8_t alarmNumber, const uint8_t alarmType, const DateTime &dt,
                  const bool state = true) const;
    void setAlarmPolarity(const bool polarity) const;
    DateTime getAlarm(const uint8_t alarmNumber, uint8_t &alarmType) const;
    bool clearAlarm(const uint8_t alarmNumber) const;
    bool setAlarmState(const uint8_t alarmNumber, const bool state) const;
    bool getAlarmState(const uint8_t alarmNumber) const;
    bool isAlarm(const uint8_t alarmNumber) const;
    uint8_t getSQWSpeed() const;
    bool setSQWSpeed(uint8_t frequency, bool state = true) const;
    bool setSQWState(const bool state) const;
    bool getSQWState() const;
    bool setBattery(const bool state) const;
    bool getBattery() const;
    bool getPowerFail() const;
    bool clearPowerFail() const;
    DateTime getPowerDown() const;
    DateTime getPowerUp() const;
    int8_t calibrateOrAdjust(const DateTime &dt);
    int32_t getPPMDeviation(const DateTime &dt) const;
    void setSetUnixTime(uint32_t aTime);
    uint32_t getSetUnixTime() const;

    /*************************************************************************************************
    ** Template functions definitions are done in the header file                                   **
    ** ============================================================================================ **
    ** readRAM   read any number of bytes from the MCP7940 SRAM area                                **
    ** writRAM   write any number of bytes to the MCP7940 SRAM area                                 **
    *************************************************************************************************/

    /**
     *      @brief     Template for readRAM()
     *      @details   As a template it can support compile-time data type definitions
     *      @param[in] addr Memory address
     *      @param[in] value    Data Type "T" to read
     *      @retval    Pointer to return data structure
     **/
    template <typename T>
    uint8_t &readRAM(const uint8_t &addr, T &value) const {
        uint8_t i = I2C_read((addr % 64) + MCP7940_RAM_ADDRESS, value);
        return (i);
    } // of method readRAM()

    /**
     *  @brief     Template for writeRAM()
     *  @details   As a template it can support compile-time data type definitions
     *  @param[in] addr Memory address
     *  @param[in] value Data Type "T" to write
     *  @retval    True if successful, otherwise false
     **/
    template <typename T>
    bool writeRAM(const uint8_t &addr, const T &value) const {
        uint8_t i = I2C_write((addr % 64) + MCP7940_RAM_ADDRESS, value);
        return i;
    } // of method writeRAM()
private:
    uint32_t _SetUnixTime{0}; ///< UNIX time when clock last set
    /*************************************************************************************************
    ** Template functions definitions are done in the header file                                   **
    ** ============================================================================================ **
    **                                                                                              **
    ** I2C_read  read any number of bytes from the MCP7940                                          **
    ** I2C_write write any number of bytes to the MCP7940                                           **
    *************************************************************************************************/

    /**
     *   @brief     Template for I2C_read() generic read function
     *   @details   The template supports reading any number of bytes from a structure. The size of the
     *              structure is determined by the template and determines how often the main loop is
     *              entered.
     *   @param[in] device  I2C Device number
     *   @param[in] address Memory address to read from on device
     *   @param[in] value   Data Type "T" to read
     *   @retval    number of bytes read
     **/
    template <typename T>
    uint8_t I2C_read(const uint8_t address, T &value) const {
        uint8_t i{0};                            // return number of bytes read
        Wire.beginTransmission(MCP7940_ADDRESS); // Address the I2C device
        Wire.write(address);                     // Send register address to read from
        if (Wire.endTransmission() == 0) {       // Close transmission and check error code
            Wire.requestFrom(MCP7940_ADDRESS, sizeof(T)); // Request a block of data
            uint8_t *bytePtr = (uint8_t *)&value;         // Declare pointer to start of structure
            for (i = 0; i < sizeof(T); i++) {             // Loop for each byte to be read
                *bytePtr++ = Wire.read(); // Read a byte
            }                             // of for-next each byte
        }                                 // if-then success
        return i;                         // return number of bytes read
    }                                     // end of template method "I2C_read"

    /**
     *    @brief     Template for I2C_write() generic read function
     *    @details   The template supports writing any number of bytes into a structure. The size of the
     *               structure is determined by the template and determines how many bytes are written
     *    @param[in] device  I2C Device number
     *    @param[in] address Memory address to write to on device
     *    @param[in] value   Data Type "T" to write
     *    @retval    number of bytes written
     **/
    template <typename T>
    uint8_t I2C_write(const uint8_t address, const T &value) const {
        Wire.beginTransmission(MCP7940_ADDRESS);  // Address the I2C device
        Wire.write(address);                      // Send register address to read from
        Wire.write((uint8_t *)&value, sizeof(T)); // write the data
        uint8_t i = Wire.endTransmission();       // close transmission and save status
        if (i == 0)
            i = sizeof(T);                                           // return number of bytes on success
        return i;                                                    // return the number of bytes written
    }                                                                // end of template method "I2C_write()"
    uint8_t readByte(const uint8_t addr) const;                      // Read 1 byte from address on I2C
    uint8_t bcd2int(const uint8_t bcd) const;                        // convert BCD digits to integer
    uint8_t int2bcd(const uint8_t dec) const;                        // convert integer to BCD
    void clearRegisterBit(const uint8_t reg, const uint8_t b) const; // Clear a bit, values 0-7
    void setRegisterBit(const uint8_t reg, const uint8_t b) const;   // Set   a bit, values 0-7
    void writeRegisterBit(const uint8_t reg, const uint8_t b,
                          bool bitvalue) const;                        // Clear a bit, values 0-7
    uint8_t readRegisterBit(const uint8_t reg, const uint8_t b) const; // Read  a bit, values 0-7
};                                                                     // of MCP7940 class definition
#endif /* Deneyap_GercekZamanliSaat_H */
