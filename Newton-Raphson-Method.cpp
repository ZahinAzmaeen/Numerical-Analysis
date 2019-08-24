//Newton-Raphson Method
#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return exp(-x)-x;
}

double fprime(double x)
{
    return -exp(-x) - 1;
}
int main()
{
    double x,x1=0,e=0.001,fx,fx1;
    cout.precision(4);
    cout.setf(ios::fixed);
    cout<<"Newton-Raphson Method\n"<<endl;
    //cin>>x1;
    //cout<<"Enter desired accuracy\n";
    //cin>>e;
    cout <<" x1"<<"          "<<" f(x1)"<<"            "<<"f(x2)"<<"          "<<"x2"<<"            "<<"ERROR"<<endl;

    do
    {
        x=x1;                /*make x equal to the last calculated value of                             x1*/
        fx=f(x);            //simplifying f(x)to fx
        fx1=fprime(x);            //simplifying fprime(x) to fx1
        x1=x-(fx/fx1);            /*calculate x{1} from x, fx and fx1*/
        cout<<x<<"       "<<fx<<"          "<<fx1<<"         "<<x1<<"         "<<abs(x1-x)<<endl;
    }while (fabs(x1-x)>=e);            /*if |x{i+1}-x{i}| remains greater than the desired accuracy, continue the loop*/
    cout<<"\nThe root of the equation is "<<x1<<endl;
    return 0;
}
