#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

double f(double x)
{
    return x*x - 4*x - 10;
}
void false_position(double a, double b){
    int i = 1;
    double c,fa,fb,fc;
    cout<<"\nFalse Position Method Iterations are as follows: \n"<<endl;

    if (f(a)*f(b)>0)
    {
        cout<<"\nPlease enter a different initial guess\n"<<endl;
    }
    else
    {
        do
        {
            fa=f(a);
            fb=f(b);
            c=(a*f(b)-b*f(a))/(f(b)-f(a));
            fc=f(c);
            cout<<i<<".    "<<"a="<<a<<"     "<<"b="<<b<<"     "<<"c="<<c<<"      fc="<<fc<<endl;
            if (fc==0.0)
            {
                //cout<<"\n\nThe root of the equation is "<<c;
                break;
            }
            if (fa*fc>0)
            {
                a=c;
            }
            else if (fa*fc<0)
            {
                b=c;
            }
            i++;
        }while(fabs(f(c)) >= EPSILON);
    }
    cout<<"\nThe root of the equation using False Position Method is :-  "<<c<<endl;

}
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    false_position(-3,-1);

    return 0;
}
