#include "sdt.h"
#include <iostream>
#include <vector>
#include "convert.h"

double convert(double temperature, Scale from, Scale to)
{
    switch(from)
    {
    case 'K':
        if (temperature>0)
        {
            temperature=temperature;
            break;
        }
        else
        {
            throw logic_error("Temperature < 0 !!!"); //Исключение
            break;
        }
    case 'C':
        if (temperature>=-273.15)
        {
            temperature=temperature+273.15;
            break;
        }
        else
        {
            throw logic_error("Temperature < 0 !!!"); //Исключение
            break;
        }
    case 'F':
        if (temperature>=-459.67)
        {
            temperature=(((temperature-32)*5)/9+273.15);
            break;
        }
        else
        {
            throw logic_error("Temperature < 0 !!!"); //Исключение
            break;
        }
    default:
        throw invalid_argument("Error scale!!!"); //Исключение
    }
    return temperature;
}
