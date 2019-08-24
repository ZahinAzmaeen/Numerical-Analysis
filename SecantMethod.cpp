#include <bits/stdc++.h>
using namespace std;

float f(float x)
{
    return x*x-4*x - 10;

}

int main()
{

    float x1 = 4, x2 = 2, E = 0.0001,xm, x0, c,fx1,fx2,fx0,x11,x22;
    cout.precision(4);
    cout.setf(ios::fixed);
    cout << "Secant Method :" <<  endl;
    cout <<" x1"<<"           "<<"x2"<<"              "<<"f(x1)"<<"              "<<"f(x2)"<<"              "<<"x3"<<"               "<<"ERROR"<<endl;


    do
    {
        x11 = x1;
        x22 = x2;
        fx1 = f(x1);
        fx2 = f(x2);
        x0 = (x1 * fx2 - x2 * fx1) / (fx2 - fx1);
        fx0 = f(x0);
        c = fx1 * fx0;
        x1 = x2;
        x2 = x0;
        if (c == 0)
            break;

        xm = (x1 * fx2 - x2 * fx1) / (fx2 - fx1);
        cout<<x11<<"       "<<x22<<"          "<<fx1<<"         "<<fx2<<"           "<<x0<<"           "<<abs(x0 - x22)/abs(x0)<<endl;

    }
    while (fabs(x0 - x22)/fabs(x0) >= E);
    cout << "\nRoot of the given equation=" << x0 << endl;
    return 0;
}
