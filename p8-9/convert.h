#ifndef P6_H_INCLUDED
#define P6_H_INCLUDED
enum Scale:char
{
    C='C',
    K='K',
    F='F'
};
struct Temperature{
   Temperature (double value, Scale symbol);
   double value;
   Scale symbol;
};
double convert(double temperature, Scale from, Scale to);

#endif // P6_H_INCLUDED
