#include <iostream>

using namespace std;

int main()
{

    string data;
    int a = 0,b = 0,c = 0,d = 0;
    cin>>data;

    for(int i = 0 ;i< data.length() ;i++ )
    {
        if(data[i] == 'G' || data[i] == 'g')
            a++;
        else if(data[i] == 'P' || data[i] == 'p')
            b++;
        else if(data[i] == 'L' || data[i] == 'l')
            c++;
        else if(data[i] == 'T' || data[i] == 't')
            d++;
    }

    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    while(a != 0 || b != 0 || c != 0 || d != 0)
    {
        if(a != 0)
        {
            cout<<"G";
            a--;
        }
        if(b != 0)
        {
            cout<<"P";
            b--;
        }
        if(c != 0)
        {
            cout<<"L";
            c--;
        }
        if(d != 0)
        {
            cout<<"T";
            d--;
        }
    }


    return 0;
}
