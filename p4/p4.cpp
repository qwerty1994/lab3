#include "sdt.h"
#include <iostream>
#include <vector>

using namespace std;

int last_error = 0;

double convert(double temperature, char from, char to)
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
            last_error=1;
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
            last_error=1;
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
            last_error=1;
            break;
        }
    default:
        last_error=2;
    }
    return temperature;
}

int get_last_error()
{
    return last_error;
}


main()
{
    double temp,temp2;
    char scale;
    int i;
    vector <double> K;
    i=0;
    while (cout << "Enter temperature = ",cin >> temp >> scale)
    {
        temp2 = convert(temp,scale,'K');
        switch(get_last_error())
        {
         case 0:
         {
            K.push_back(temp2);
            i++;
            break;
         }
         case 1:
         {
            cerr << "Temperature < 0!!!" << endl;
            break;
         }
         case 2:
         {
            cerr << "Error scale!!!" << endl;
            break;
         }
         default:
            cerr << "Unknown error!!!";
        }
    last_error=0;
    }
    cout << fixed;
    cout.precision(1);
    cout<<"Kelvin"<<"\tCelsiu"<<"   Faringate"<<endl;
    for (int j=0; j<i; j++)
        cout<<K[j]<<"\t"<<K[j]-273.15<<"\t "<<((K[j]-273.15)*1.8+32)<<endl;
}
