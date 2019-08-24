#include<bits/stdc++.h>

using namespace std;
int n;
int ar[100],apr[100],br[100];
double error=.001;

double function(double x)
{
    double res=ar[n];

    for(int i=n-1;i>=0;i--)
    {
        res=res*x+ar[i];
    }
    return res;
}
double fprime(double x)
{
    for(int i=n;i>0;i--)
    {
       apr[i-1]=ar[i]*i;
    }
    double res=apr[n-1];
    for(int i=n-2;i>=0;i--)
    {
       res=res*x+apr[i];
    }
    return res;
}

int main()
{
    cout<<"Enter the degree of the eqn:";
    cin>>n;
    for(int i=n;i>=0;i--)
    {
        cin>>ar[i];
    }

    double x0,xr;
    cout<<"Enter the value of x0:";
    cin>>x0;
    while(n>0)
    {
        while(true)
        {
            xr=x0-(function(x0)/fprime(x0));
            double err=fabs((xr-x0)/xr);
            if(err<=error)
            {
                cout<<"Root is: "<<xr<<endl;
                break;
            }
            x0=xr;
        }
        br[n]=0;
        for(int i=n;i>0;i--)
        {
            br[i-1]=ar[i]+xr*br[i];
        }
        n--;
        for(int i=0;i<=n;i++)
        {
            ar[i]=br[i];
        }
        //x0=xr;

    }
    return 0;
}

/*

2
1 -3 2
0

*/



