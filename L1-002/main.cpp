#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    int n;
    char c;

    cin>>n>>c;

    int cengshu = 0;
    for(int i = 1;i< n ;i++)
    {
        if(2*i*i-1 > n)
                   break;
        cengshu = i-1;
    }


    for(int i=cengshu ;i>0 ;i--)
    {
            for(int k=i;k< cengshu ;k++)
                    cout<<" ";
            for(int j=0;j< i*2+1 ;j++)
                    cout<<c;
            cout<<endl;
    }

    for(int i=0;i< cengshu ;i++)
    {
            cout<<" ";
    }
    cout<<c<<endl;

    for(int i=1 ;i<=cengshu ;i++)
    {
            for(int k=i+1;k<= cengshu ;k++)
                    cout<<" ";
            for(int j=0;j< i*2+1 ;j++)
                    cout<<c;
            cout<<endl;
    }
    if(n != 2*cengshu*cengshu+1)
         cout<<n-2*(cengshu+1)*(cengshu+1)+1;

    return 0;
}

