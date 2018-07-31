#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    int num;
    cin>>num;

    for(int i = 0 ;i< num ;i++ )
    {
        char c;
        double d;
        cin>>c>>d;

        if(c == 'M')
            printf("%.2f\n",d/1.09);
        else
            printf("%.2f\n",d*1.09);
    }

    return 0;
}
