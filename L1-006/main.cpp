#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int num;
    cin>>num;

    int max = sqrt(num);
    int begin = 0,length = 0;

    for(int i = 2 ;i <= max ;i++ )
    {
        int temp = 1;
        int j;
        for(j = i ;j <= max ;j++ )
        {
            temp *= j;
            if(num % temp != 0)
                break;
        }
        if(j - i > length)
        {
            length = j-i;
            begin = i;
        }
    }

    if(begin == 0)
        cout<<1<<endl<<num<<endl;
    else
    {
        cout<<length<<endl;
        cout<<begin;
        for(int i = begin+1 ;i < begin+length ;i++ )
        {
            cout<<"*"<<i;
        }
    }

    return 0;
}
