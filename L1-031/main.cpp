#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int num;
    cin>>num;

    for(int i = 0 ;i< num ; i++ )
    {
        double a,b;
        cin>>a>>b;

        double temp  = (a - 100)*1.8;

        if( abs(b-temp) < temp*0.1)
            cout<<"You are wan mei!"<<endl;
        else if( b >= temp )
            cout<<"You are tai pang le!"<<endl;
        else
            cout<<"You are tai shou le!"<<endl;

    }

    return 0;
}
