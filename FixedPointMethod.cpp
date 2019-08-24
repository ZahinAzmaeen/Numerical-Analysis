#include <bits/stdc++.h>
using namespace std;


double a,b,c,Error,x0,x1;

void display()
{
    static int i;
    cout << ++i << "             " << x0 << "                 " << x1 << "          " << Error << endl;
}

void askX0()
{
    cout << "Enter initial value of X0: ";
    cin >> x0;
}

void askEqn()
{
    cout << "For the eqn ax*x + bx + c = 0 , Enter a,b,c,d:\n";
    cin >>a>>b>>c;
}

double g(double x)
{
    return cos(x); //(x + 5 / x) / 2 ;
}

void findError()
{
    Error = fabs( (x1-x0)/x1 );
}

int main()
{

    //askEqn();
    cout.precision(4);
    cout.setf(ios::fixed);
    askX0();
    cout << endl << endl << "S.N.          Xi                     Xi+1             Error\n";
    do{
        x1 = g(x0);
        findError();
        display();
        x0 = x1;
    }while(Error>=0.001);

    cout << endl<< "\nThe root is : " << x1 <<  endl;
    return 0;
}
