#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{

    int a,b,c;
    cin>>a>>b>>c;

    double data[a];

    for(int i = 0 ;i< a ;i++ )
    {
        double total = 0;
        int max = -1;
        int min = 101;
        for(int j = 0; j< b ;j++ )
        {
            int temp;
            cin>>temp;
            if(temp > max)
                max = temp;
            if(temp < min)
                min = temp;
            total += temp;
        }
        data[i] = (total-min-max)/(b-2);
    }

    sort(data,data+a);

    for(int i =a-c  ;i< a-1 ;i++ )
    {
        printf("%.3f ",data[i]);
    }
    printf("%.3f\n",data[a-1]);

    return 0;
}
