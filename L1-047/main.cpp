#include <iostream>

using namespace std;

int main()
{

    int num;
    cin>>num;

    for(int i = 0 ;i< num ;i++ )
    {
        string a;
        int b,c;

        while(cin>>a>>b>>c)
        {
            if(b<15 || b>20)
            {
                cout<<a<<endl;
                break;
            }
            else if(c<50 || c>70)
            {
                cout<<a<<endl;
                break;
            }
            break;

        }
    }

    return 0;
}
