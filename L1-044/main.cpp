#include <iostream>

using namespace std;

int main()
{

    int k;
    cin>>k;

    string str;

    int count = 0;
    while(cin>>str)
    {
        if(str == "End")
            break;
        count++;
        if(count == k+1)
        {
            cout<<str<<endl;
            count = 0;
        } else
        {
            if(str == "ChuiZi")
                cout<<"Bu"<<endl;
            else if(str == "Bu")
                cout<<"JianDao"<<endl;
            else if(str == "JianDao")
                cout<<"ChuiZi"<<endl;
        }
    }

    return 0;
}
