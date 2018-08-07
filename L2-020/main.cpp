#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

double total = 0.0;
double first = 0;
double reduce = 0;
int num;

vector<vector<int> > v;

void dfs(int now,double gongli,int* beishu)
{
    if(beishu[now] != 1)
    {
        total += gongli*beishu[now];
        return;
    }

    for(int i = 0 ;i< v[now].size() ;i++ )
    {
        dfs(v[now][i],gongli*(1-reduce/100),beishu);
    }

}

int main()
{
    cin>>num>>first>>reduce;
    v.resize(num);
    int beishu[num];

    fill(beishu,beishu+num,1);

    for(int i = 0 ;i< num ;i++ )
    {
        int n,temp;
        cin>>n;

        if(n == 0)
        {
            cin>>temp;
            beishu[i] = temp;
        } else
        {
            for(int j = 0 ; j< n ;j++ )
            {
                cin>>temp;
                v[i].push_back(temp);
            }
        }
    }

    dfs(0,first,beishu);

    printf("%d\n",(int)total);
    return 0;
}
