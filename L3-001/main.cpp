#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int data[10001];
int flag[10001];
int now = 0;
int total = 0;
int judge = 0;
int shengyu = 0;


void dfs(int index)
{
    if(now == m)
    {
        judge = 1;
        return;
    }
    if(now > m)
        return;
    if(index >= n)
        return;

    if(shengyu + now < m)
        return;

    shengyu -= data[index];
    flag[index] = 1;
    now += data[index];
    dfs(index+1);
    if(judge == 1)
        return;
    now -= data[index];

    flag[index] = 0;
    dfs(index+1);
    if(judge == 1)
        return;
     shengyu += data[index];
}

int main()
{
    cin>>n>>m;

    fill(data,data+10001,0);
    fill(flag,flag+10001,0);

    for(int i = 0 ;i< n ;i++ )
    {
        cin>>data[i];
        total += data[i];
    }
    shengyu = total;

    sort(data,data+n);

    dfs(0);

    int temp = 0;
    if(judge == 1)
    {
        for(int i = 0 ;i< n ;i++ )
            if(flag[i] == 1)
            {
                if(temp == 0)
                {
                    temp = 1;
                    cout<<data[i];
                }
                else
                    cout<<" "<<data[i];
            }
        cout<<endl;
    } else
    {
        cout<<"No Solution"<<endl;
    }

    return 0;
}
