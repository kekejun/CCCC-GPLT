#include <iostream>

using namespace std;

int main()
{
    string a,b;
    string temp;
    int count = 0;

    while(cin>>temp)
    {
        if(temp == ".")
            break;
        count++;
        if(count == 2)
            a = temp;
        if(count == 14 )
            b = temp;
    }

    if( count > 14 )
        cout<<a<<" and "<<b<<" are inviting you to dinner..."<<endl;
    else if(count >= 2 )
        cout<<a<<" is the only one for you..."<<endl;
    else
        cout<<"Momo... No one is for you ..."<<endl;
    return 0;
}
