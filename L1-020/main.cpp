#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> a;
    set<string> b;

    int n;
    cin>>n;

    for(int i = 0 ;i< n ;i++ )
    {
        int num;
        string str;
        cin>>num;

        if(num == 1)
        {
            cin>>str;
            continue;
        }

        for(int j = 0;j< num ;j++)
        {
            cin>>str;
            a.insert(str);
        }
    }
    int m;
    cin>>m;
    string result = "";

    for(int i = 0;i< m ;i++ )
    {
        string str;
        cin>>str;

        if(a.find(str) == a.end() && b.find(str) == b.end())
        {
            b.insert(str);
            if(result == "")
                result+=str;
            else
                result+=" "+str;
        }
    }

    if(result == "")
    {
        cout<<"No one is handsome"<<endl;
    } else
    {
        cout<<result<<endl;
    }

    return 0;
}
