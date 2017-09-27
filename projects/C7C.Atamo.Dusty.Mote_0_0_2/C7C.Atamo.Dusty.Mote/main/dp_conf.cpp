/*
 * dp_conf.cpp
 *
 * Created: 2017-09-27 19:13:29
 *  Author: kjph
 */ 

#include "dp_conf.h"
#include "globals.h"

const char SYS_LUT[DP_LUT__N_PARAM][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
};

char sys_conf[DP_LUT__N_PARAM];

uint8_t dp_conf_set(char *package_payload)
{
    //TODO
}

uint8_t dp_conf_default(void)
{
    if (SystemState._conf_set_flag == 0)
    {
        //TODO: Load the default
    }
    else
    {
        return FAILURE;
    }

    return SUCCESS;
}

uint8_t dp_conf_param_set(uint8_t param, uint8_t value)
{

    uint8_t max;
    uint8_t min;

    //Input validation
    if (param >= DP_LUT__N_PARAM) 
    {
        return FAILURE;
    }

    //Input validation
    max = dp_conf_param_lookup_max(param);
    if (value > max) 
    {
        return FAILURE;
    }

    //Input validation
    min = dp_conf_param_lookup_min(param);
    if (value < min)
    {
        return FAILURE;
    }

    //Check the configuration has been set
    if (SystemState._conf_set_flag == 0)
    {
        dp_conf_default();
    }

    SystemState._conf[param] = value;
}

uint8_t dp_conf_param_get_cur(uint8_t param)
{
    if (param >= DP_LUT__N_PARAM) 
    {
        return FAILURE;
    }

    return SystemState._conf[param];
}

uint8_t dp_conf_param_lookup_max(uint8_t param)
{

    if (param >= DP_LUT__N_PARAM) 
    {
        return FAILURE;
    }

    return SYS_LUT[param][DP_LUT__COL_MAX_VAL];
}

uint8_t dp_conf_param_lookup_min(uint8_t param)
{
    if (param >= DP_LUT__N_PARAM) 
    {
        return FAILURE;
    }
    
    return SYS_LUT[param][DP_LUT__COL_MIN_VAL];
}