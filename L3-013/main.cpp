#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double e = 1000,g = 9.8,m,length = 0;
    int p;

    cin>>m>>p;
    m /= 100;

    while(e > 0.0000001)
    {
        length += 2*e/(m*g);
        e = e * (100-p) / 100;
    }

    printf("%.3f\n",length);

    return 0;
}
