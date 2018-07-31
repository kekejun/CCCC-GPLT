#include <iostream>

using namespace std;

int main()
{

    string str;
    getline(cin,str);

    int dataLength = str.length();
    int lastIndex = dataLength-1;

    for(int i = dataLength-1;i>=0 ;i-- )
    {
        if(str[i] == ' ')
        {
            for(int j = i+1 ;j<= lastIndex ;j++ )
            {
                cout<<str[j];
            }
            cout<<" ";
            lastIndex = i-1;
        }
    }

    for(int i = 0 ;i<=lastIndex ;i++ )
    {
        cout<<str[i];
    }
    cout<<endl;

    return 0;
}
