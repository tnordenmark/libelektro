#include <math.h>

float calc_power_r(float volt, float resistance)
{
	float power_r;
    power_r = powf(volt, 2) / resistance;
	    
    return power_r;
}


float calc_power_i(float volt, float current)
{
	float power_i;
	power_i = volt * current;

	return power_i;
}