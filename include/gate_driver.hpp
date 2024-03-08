#pragma once

#include "lks32mc07x_lib.h"

class GateDriver
{
private:
    /* data */
public:
    GateDriver(GPIO_TypeDef *ah_port, uint32_t ah_pin, GPIO_TypeDef *bh_port, uint32_t bh_pin,
               GPIO_TypeDef *ch_port, uint32_t ch_pin, GPIO_TypeDef *al_port, uint32_t al_pin,
               GPIO_TypeDef *bl_port, uint32_t bl_pin, GPIO_TypeDef *cl_port, uint32_t cl_pin);
    ~GateDriver();
};

GateDriver::GateDriver(GPIO_TypeDef *ah_port, uint32_t ah_pin, GPIO_TypeDef *bh_port, uint32_t bh_pin,
                       GPIO_TypeDef *ch_port, uint32_t ch_pin, GPIO_TypeDef *al_port, uint32_t al_pin,
                       GPIO_TypeDef *bl_port, uint32_t bl_pin, GPIO_TypeDef *cl_port, uint32_t cl_pin)
{
    GPIO_InitTypeDef gis;
    GPIO_StructInit(&gis);
    gis.GPIO_Mode = GPIO_Mode_OUT;
    gis.GPIO_Pin = ah_pin;
    GPIO_Init(ah_port, &gis);

    gis.GPIO_Pin = bh_pin;
    GPIO_Init(bh_port, &gis);

    gis.GPIO_Pin = ch_pin;
    GPIO_Init(ch_port, &gis);

    gis.GPIO_Pin = al_pin;
    GPIO_Init(al_port, &gis);

    gis.GPIO_Pin = bl_pin;
    GPIO_Init(bl_port, &gis);

    gis.GPIO_Pin = cl_pin;
    GPIO_Init(cl_port, &gis);
}

GateDriver::~GateDriver()
{
}
