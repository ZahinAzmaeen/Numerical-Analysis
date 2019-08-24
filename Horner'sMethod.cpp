#include <iostream>
using namespace std;

// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
float horner(float poly[], int n, float x)
{
    float result = poly[0];  // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}

// Driver program to test above function.
int main()
{
    // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
    float poly[] = {1,-4,-10};
    //float x = 2.71;
    int n = sizeof(poly)/sizeof(poly[0]);
    //cout << "Value of polynomial is " << horner(poly, n, x);
    double i = -2;
    int j = 0;
    while(j<20){
        cout << "\n\nValue of polynomial is " << horner(poly, n, i)<<endl;
        i += 0.02;
        j++;
    }
    return 0;
}
