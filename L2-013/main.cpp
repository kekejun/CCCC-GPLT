#include <iostream>

using namespace std;

int data[501][501];
int visited[501];
int v,e;

void dfs(int now)
{
    visited[now] = 1;
    for(int i = 0 ;i< v ;i++ )
    {
        if(visited[i] == 0 && data[now][i] == 1)
        {
            dfs(i);
        }
    }
}

int getCount()
{
    int count = 0;
    fill(visited,visited+501 ,0);
    for(int i = 0 ;i< v ;i++ )
    {
        if(visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main()
{
    cin>>v>>e;

    fill(data[0],data[0]+v*v,0);

    for(int i = 0 ;i< e ;i++ )
    {
        int a,b;
        cin>>a>>b;
        data[a][b] = data[b][a] = 1;
    }

    int n;
    cin>>n;
    int beginCount = getCount();
    for(int i = 0 ;i< n ;i++ )
    {
        int temp;
        cin>>temp;

        for(int j = 0 ;j< v ;j++ )
        {
            data[temp][j] = 0;
            data[j][temp] = 0;
        }
        int nowCount = getCount();
        if(nowCount > beginCount+1)
        {
            cout<<"Red Alert: City "<<temp<<" is lost!"<<endl;
        } else
        {
            cout<<"City "<<temp<<" is lost."<<endl;
        }
        beginCount = nowCount;
        if(i == v-1)
        {
            cout<<"Game Over."<<endl;
        }
    }

    return 0;
}
