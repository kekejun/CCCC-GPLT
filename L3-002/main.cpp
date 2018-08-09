#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int num;

int main()
{
    cin>>num;

    for(int i = 0 ;i< num ;i++ )
    {
        string str;
        cin>>str;

        if(str[1] == 'o')
        {
            if(v.size() == 0)
            {
                cout<<"Invalid"<<endl;
            } else
            {
                cout<<*(v.rbegin())<<endl;
                v.pop_back();
            }
        } else if(str[1] == 'u')
        {
            int data;
            cin>>data;
            v.push_back(data);
        } else if(str[1] == 'e')
        {
            if(v.size() == 0)
            {
                cout<<"Invalid"<<endl;
            } else
            {
                vector<int> c = v;
                sort(c.begin(),c.end());
                int middle = (c.size()%2 == 1)? ((c.size()+1)/2) : (c.size()/2);
                cout<<c[middle-1]<<endl;
            }
        }
    }

    return 0;
}
