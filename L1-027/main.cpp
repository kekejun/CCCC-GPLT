#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    string str;
    cin>>str;

    int a[10] = {0};
    for(int i = 0 ;i< str.length() ;i++ )
    {
        a[str[i]-'0']++;
    }

    for(int i = 9 ;i>= 0 ;i-- )
    {
        if(a[i] != 0)
            v.push_back(i);
    }

    vector<int> index;
    for(int i = 0 ;i< str.length() ;i++ )
    {
        for(int j = 0 ;j< v.size() ;j++ )
        {
            if(v[j] == str[i]-'0')
                index.push_back(j);
        }
    }

    cout<<"int[] arr = new int[]{"<<v[0];
    for(int i = 1 ;i< v.size() ;i++ )
    {
        cout<<","<<v[i];
    }
    cout<<"};"<<endl;
    cout<<"int[] index = new int[]{"<<index[0];
    for(int i = 1; i< index.size(); i++ )
    {
        cout<<","<<index[i];
    }
    cout<<"};"<<endl;

    return 0;
}
