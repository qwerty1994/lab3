#include "sdt.h"
#include <iostream>
#include <vector>
#include "convert.h"

main()
{
    using namespace std;
    double temp,temp2;
    Scale scale;
    int i;
    vector <double> k;
    i=0;
    while (cout << "Enter temperature = ",cin >> temp >> (char&) scale)
    {
        try //Блок, в котором возможна ошибка
        {
            double temp2 = convert(temp,scale,K);
            k.push_back(temp2);
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
        cout<<k[j]<<"\t"<<k[j]-273.15<<"\t "<<((k[j]-273.15)*1.8+32)<<endl;
}
