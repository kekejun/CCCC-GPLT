#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100005;
int data[maxn];
vector<vector<int> > v;

int max_deep = -1;

void dfs(int root,int deep)
{
    data[root] = deep;
    if(deep > max_deep)
        max_deep = deep;
    for(int i = 0 ;i< v[root].size() ;i++ )
    {
        dfs(v[root][i],deep+1);
    }

}

int main()
{

    v.resize(maxn);

    int n,root;
    cin>>n;

    for(int i = 1 ;i<= n ; i++ )
    {
        int temp;
        cin>>temp;

        if(temp == -1)
            root = i;
        else
            v[temp].push_back(i);
    }

    dfs(root,1);

    int flag = 0;
    cout<<max_deep<<endl;
    for(int i = 1;i<= n; i++ )
    {
        if(max_deep == data[i])
        {
            if(flag == 0 )
            {
                flag = 1;
                cout<<i;
            }
            else
            {
                cout<<" "<<i;
            }
        }
    }
    cout<<endl;

    return 0;
}
