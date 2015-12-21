#include <iostream>
#include "sdt.h"

using  namespace std;

double convert(double temperature,char from,char to)
{
    if (from=='C')
    {
        if(temperature>-273.15)
        {
            if (to=='K')
                return temperature+273.15;
                       if (to=='F')
                           return (((9*temperature)/5)+32);
                }
        else
            cout << "Temperature <0!!!";
    }
    else
    {
        if (from=='K')
        {
            if(temperature>0)
            {
                if (to=='C')
                    return temperature-273.15;
                           if (to=='F')
                               return (((9*(temperature-273.15)/5)+32));
                    }
            else
                cout << "Temperature <0!!!";
        }
        else
        {
            if (from=='F')
            {
                if(temperature>-273.15)
                {
                    if (to=='C')
                        return (((temperature-32)*5)/9);
                               if (to=='K')
                                   return (((temperature-32)*5)/9+273.15);
                        }
                else
                    cout << "Temperature <0!!!";
            }
            else
                cout << "Error scale!!!!";
            }
    }
}
main()
{
    int i;
    double grad;
    char scale;
    vector <double> C,K,F;
    cout << "Enter Temperatyre : ";
    i=0;
    while (cin)
    {
        cin >> grad >> scale;
        if(!cin)
            break;
        else if (scale=='C')
        {
            C.push_back(grad);
            K.push_back(convert(grad,'C','K'));
            F.push_back(convert(grad,'C','F'));
            i=i+1;
            cout << "Enter temperature : ";
        }
        else if (scale=='K')
        {
            K.push_back(grad);
            C.push_back(convert(grad,'K','C'));
            F.push_back(convert(grad,'K','F'));
            i=i+1;
            cout << "Enter temperature : ";
        }
        else if (scale=='F')
        {
            F.push_back(grad);
            C.push_back(convert(grad,'F','C'));
            K.push_back(convert(grad,'F','K'));
            i=i+1;
            cout << "Enter temperature : ";
        }
        else
            {
                cout <<"Error scale"<<endl;
                cout << "Enter temperature : ";
            }
    }
    cout << fixed;
    cout.precision(1);
    cout<<"Celsius"<<"\tKelvin"<<"   Faringate"<<endl;
    for (int j=0; j<i; j++)
        cout<<C[j]<<"\t"<<K[j]<<"\t "<<F[j]<<endl;
}
