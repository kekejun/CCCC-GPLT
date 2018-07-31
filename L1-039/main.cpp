#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{

    int num;
    string data;
    cin>>num;
    getchar();
    getline(cin,data);

    int rol = (data.length()-1)/num+1;

    char array[num][rol];
    fill(array[0],array[0]+num*rol,' ');

    int begin = 0;
    for(int j = rol-1 ;j >= 0 ;j-- )
    {
        for(int z = 0 ;z< num ;z++ )
        {
            if(begin >= data.length())
                break;
            array[z][j] = data[begin++];
        }
        if(begin >= data.length())
                break;
    }

    for(int i = 0 ;i< num ;i++ )
    {
        for(int j = 0;j< rol ;j++ )
            cout<<array[i][j];
        cout<<endl;
    }

    return 0;
}
