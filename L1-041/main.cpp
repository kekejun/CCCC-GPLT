#include <iostream>

using namespace std;

int main()
{

    int data;
    int count = 0;

    while(cin>>data)
    {
        count++;
        if(data == 250)
        {
            cout<<count<<endl;
            break;
        }
    }

    return 0;
}
