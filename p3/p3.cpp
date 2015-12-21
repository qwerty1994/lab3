#include "sdt.h"
#include <iostream>
#include <vector>

using namespace std;

enum error {er_temp,er_scale,no_er};
error convert(double temperature,char from,char to,double &result)
{
    switch(from)
    {
    case 'K':
        if (temperature>0)
        {
            result=temperature;
            return no_er;
            break;
        }
        else
        {
            return er_temp;
            break;
        }
    case 'C':
        if (temperature>=-273.15)
        {
            result=temperature+273.15;
            return no_er;
            break;
        }
        else
        {
            return er_temp;
            break;
        }
    case 'F':
        if (temperature>=-459.67)
        {
            result=(((temperature-32)*5)/9+273.15);
            return no_er;
            break;
        }
        else
        {
            return er_temp;
            break;
        }
    default:
        return er_scale;
    }
}

main()
{
    int i;
    double temp,temp2;
    char scale;
    vector <double> K;
    i=0;
    while (cout << "Enter temperature = ",cin >> temp >> scale)
    {
        switch(convert(temp,scale,'K',temp2))
        {
        case er_scale:
         {
            cerr << "Error scale!!!" << endl;
            break;
         }
        case er_temp:
         {
            cerr << "Temperature < 0!!!" << endl;
            break;
         }
        case no_er:
         {
            K.push_back(temp2);
            i++;
            break;
         }
        default:
         {
            cerr << "Unknown error!" << endl;
            break;
         }
        }
    }
    cout << fixed;
    cout.precision(1);
    cout<<"Kelvin"<<"\tCelsiu"<<"   Faringate"<<endl;
    for (int j=0; j<i; j++)
        cout<<K[j]<<"\t"<<K[j]-273.15<<"\t "<<((K[j]-273.15)*1.8+32)<<endl;
}
