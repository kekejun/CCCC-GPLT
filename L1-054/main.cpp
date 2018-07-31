#include <iostream>
#include <cstdio>
using namespace std;

int a;

int isReserve(char data[][100])
{
    int flag = 0;
    for(int i = 0 ;i< a/2+1 ;i++ )
    {
        for(int j = 0 ;j< a ;j++ )
        {
            if(data[i][j] != data[a-i-1][a-j-1] )
            {
                flag = 1;
                return flag;
            }
        }
    }
    return flag;
}

int main()
{

    char b;
    scanf("%c %d",&b,&a);
    getchar();

    char data[100][100];

    for(int i = 0 ;i< a ;i++ )
    {
        for(int j = 0 ; j< a ;j++ )
        {
            data[i][j] = getchar();
        }
        getchar();
    }

    int flag = isReserve(data);
    if(flag == 0)
    {
        cout<<"bu yong dao le"<<endl;
    }

    for(int i = a-1 ;i>= 0 ;i-- )
    {
        for(int j = a-1 ; j>= 0 ;j-- )
        {
            if(data[i][j] == ' ')
                cout<<" ";
            else
                cout<<b;
        }
        cout<<endl;
    }


    return 0;
}
