#include "sdt.h"
#include <iostream>
#include <vector>

using namespace std;

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

main()
{
    double temp,temp2;
    char scale;
    int i;
    vector <double> K;
    i=0;
    while (cout << "Enter temperature = ",cin >> temp >> scale)
    {
        try //Блок, в котором возможна ошибка
        {
            double temp2 = convert(temp,scale,'K');
            K.push_back(temp2);
            i++;
        }
        catch (const invalid_argument& ia)  //Информация об ошибке
        {
            cerr << ia.what() << endl;
        }
        catch (const logic_error& le)  //Информация об ошибке
        {
            cerr << le.what() << endl;
        }
    }
    cout << fixed;
    cout.precision(1);
    cout<<"Kelvin"<<"\tCelsiu"<<"   Faringate"<<endl;
    for (int j=0; j<i; j++)
        cout<<K[j]<<"\t"<<K[j]-273.15<<"\t "<<((K[j]-273.15)*1.8+32)<<endl;
}
