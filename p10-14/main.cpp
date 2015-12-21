#include "sdt.h"
#include <iostream>
#include <vector>
#include "convert.h"

main()
{
    using namespace std;
    Temperature data{0,K};
    vector <Temperature>  k;
    i=0;
    while (cout << "Enter temperature = ",cin >> data.value,cin >> (char&) data.symbol))
    {
        try //Блок, в котором возможна ошибка
        {
            k.push_back(Temperature(convert(data.value,data.symbol,K),K));
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
