/*
 * I2C.h
 *
 * Created: 1/13/2018 12:37:27 PM
 *  Author: Rajesh Jat
 */ 


#ifndef I2C_H_
#define I2C_H_

void I2C_init(void);

void I2C_start(void);

void I2C_stop(void);

void I2C_write(uint8_t *data);

uint8_t I2C_read(void);

#endif /* I2C_H_ */