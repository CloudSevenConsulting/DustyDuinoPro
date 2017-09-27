/*
 * dp_conf.cpp
 *
 * Created: 2017-09-27 19:13:29
 *  Author: kjph
 */ 

#include "dp_conf.h"
#include "globals.h"

char sys_config[DP_LUT__N_PARAM];

uint8_t dp_conf_set(char *package_payload)
{
    //TODO
}

uint8_t dp_conf_default(void)
{
    if (SystemState._config_set_flag == 0)
    {
        //TODO: Load the default
    }
    else
    {
        return 0;
    }

    return 1;
}

uint8_t dp_conf_param_set(uint8_t type, uint8_t value)
{
    //TODO
}

uint8_t dp_conf_param_get_cur(uint8_t param)
{
    //TODO
}

uint8_t dp_conf_param_lookup_max(uint8_t param)
{
    //TODO
}

uint8_t dp_conf_param_lookup_min(uint8_t param)
{
    //TODO
}