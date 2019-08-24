#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

double f(double x)
{
    return x*x - 4*x - 10;
}
double fprime(double x)
{
    return 2*x - 4;
}
void bisection(double a, double b)
{
    int i = 1;
    double c,fa,fb,fc;
    cout<<"\nBisection Method Iterations are as follows: \n"<<endl;

    if (f(a)*f(b)>0)
    {
        cout<<"\nPlease enter a different initial guess\n"<<endl;
    }
    else
    {
        while (fabs(a-b) >= EPSILON)
        {
            c=(a+b)/2.0;
            fa=f(a);
            fb=f(b);
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
        }
    }
    cout<<"\nThe root of the equation using Bisection Method is :-  "<<c<<endl;
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
    cout<<"\nThe root of the equation using Bisection Method is :-  "<<c<<endl;

}
void newton_raphson(double x1){
    int i = 1;
    double x,fx,fx1;
    cout<<"\n\nNewton-Raphson Method Iterations are as follows\n"<<endl;
    //cin>>x1;
    //cout<<"Enter desired accuracy\n";
    //cin>>e;
    cout <<"Iterations "<<"   x1"<<"          "<<" f(x1)"<<"            "<<"f(x2)"<<"          "<<"x2"<<"            "<<"ERROR"<<endl;

    do
    {
        x=x1;                /*make x equal to the last calculated value of                             x1*/
        fx=f(x);            //simplifying f(x)to fx
        fx1=fprime(x);            //simplifying fprime(x) to fx1
        x1=x-(fx/fx1);            /*calculate x{1} from x, fx and fx1*/
        cout<<i<<".         "<<x<<"       "<<fx<<"          "<<fx1<<"         "<<x1<<"         "<<abs(x1-x)<<endl;
        i++;
    }while (fabs(x1-x)>= EPSILON);            /*if |x{i+1}-x{i}| remains greater than the desired accuracy, continue the loop*/
    cout<<"\nThe root of the equation is :-     "<<x1<<endl;
}
void Secant(double x1,double x2){
    int i =1;
    double xm, x0, c,fx1,fx2,fx0,x11,x22;
    cout << "\n\nSecant Method Iterations are as follows :\n\n" <<  endl;
    cout <<"Iterations  "<<" x1"<<"           "<<"x2"<<"              "<<"f(x1)"<<"              "<<"f(x2)"<<"              "<<"x3"<<"               "<<"ERROR"<<endl;


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
        cout<<i<<"       "<<x11<<"       "<<x22<<"          "<<fx1<<"         "<<fx2<<"           "<<x0<<"           "<<abs(x0 - x22)/abs(x0)<<endl;
        i++;

    }
    while (fabs(x0 - x22)/fabs(x0) >= EPSILON);
    cout << "\nRoot of the given equation=" << x0 << endl;
}
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    bisection(-3,-1);
    false_position(-3,-1);
    newton_raphson(0);
    Secant(-3,-1);
    return 0;
}
