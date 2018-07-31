#include <iostream>

using namespace std;

int main()
{

    int numA,numB,num;
    cin>>numA>>numB>>num;

    int timeA = 0,timeB = 0;
    for(int i = 0 ;i < num ;i++ )
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        if( b == a + c && d != a + c )
        {
            timeA++;
        }
        if( b != a + c && d == a + c )
        {
            timeB++;
        }

        if( timeA > numA )
        {
            cout<<"A"<<endl<<timeB<<endl;
            break;
        }
        if( timeB > numB )
        {
            cout<<"B"<<endl<<timeA<<endl;
            break;
        }
    }

    return 0;
}
