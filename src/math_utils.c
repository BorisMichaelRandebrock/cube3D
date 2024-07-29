#include <math.h>

#define M_PI 3.14159265358979323846

double deg_to_rad(double degrees) 
{
    return (degrees * (M_PI / 180.0));
}

double  rad_to_deg(double radians)
{
    return (radians * (180.0 / M_PI));
}