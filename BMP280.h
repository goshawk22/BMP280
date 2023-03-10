/**
 *  BME280 Combined humidity and pressure sensor library
 *
 *  @author  Toyomasa Watarai
 *  @version 1.0
 *  @date    06-April-2015
 *
 *  Library for "BME280 temperature, humidity and pressure sensor module" from Switch Science
 *    https://www.switch-science.com/catalog/2236/
 *
 *  For more information about the BME280:
 *    http://ae-bst.resource.bosch.com/media/products/dokumente/bme280/BST-BME280_DS001-10.pdf
 */
 
#ifndef MBED_BMP280_H
#define MBED_BMP280_H

#include "mbed.h"

// default address with SDO High 0x77
// address with SDO LOW 0x76
#define DEFAULT_SLAVE_ADDRESS (0x77)

/** BME280 class
 *
 *  BME280: A library to read environmental data using Bosch BME280 device
 * Readds temperature and pressure
 *
 *  BME280 is an environmental sensor
 *  @endcode
 */
 
class BMP280
{
public:

    /** Create a BME280 instance
     *  which is connected to specified I2C pins with specified address
     *
     * @param sda I2C-bus SDA pin
     * @param scl I2C-bus SCL pin
     * @param slave_adr (option) I2C-bus address (default: 0x77)
     */
    BMP280(PinName sda, PinName sck, char slave_adr = DEFAULT_SLAVE_ADDRESS);

    /** Create a BME280 instance
     *  which is connected to specified I2C pins with specified address
     *
     * @param i2c_obj I2C object (instance)
     * @param slave_adr (option) I2C-bus address (default: 0x77)
     */
    BMP280(I2C &i2c_obj, char slave_adr = DEFAULT_SLAVE_ADDRESS);

    /** Destructor of BME280
     */
    virtual ~BMP280();

    /** Initialize BME280 sensor
     *
     *  Configure sensor setting and read parameters for calibration
     *
     */
    void initialize(void);

    /** Deinitialize BME280 sensor
     *
     *  Free the I2C object
     *
     */
    void deInit(void);

    /** Read the current temperature value (degree Celsius) from BME280 sensor
     *
     */
    float getTemperature(void);

    /** Read the current pressure value (hectopascal)from BME280 sensor
     *
     */
    float getPressure(void);

private:

    I2C         *i2c_p;
    I2C         &i2c;
    char        address;
    uint16_t    dig_T1;
    int16_t     dig_T2, dig_T3;
    uint16_t    dig_P1;
    int16_t     dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;
    int32_t     t_fine;

};

#endif // MBED_BME280_H
