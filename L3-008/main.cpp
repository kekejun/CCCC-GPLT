#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int flag[10001];
int v,e,n;
vector<vector<int> > data;

int main()
{

    cin>>v>>e>>n;
    data.resize(v+1);

    for(int i = 0 ;i< e ;i++ )
    {
        int a,b;
        cin>>a>>b;

        data[a].push_back(b);
        data[b].push_back(a);
    }

    for(int i = 0 ;i< n ;i++ )
    {
        int m;
        cin>>m;

        fill(flag,flag+10001,-1);

        queue<int> q;
        q.push(m);
        flag[m] = 0;

        int min_value = 0;
        int min_point = 0;
        while(!q.empty())
        {
            int now = q.front();
            q.pop();

            //cout<<now<<endl;

            for(int i = 0 ;i< data[now].size() ;i++ )
            {
                if(flag[data[now][i]] == -1 )
                {
                    q.push(data[now][i]);
                    flag[data[now][i]] = flag[now] + 1;
                    if(min_value < flag[data[now][i]])
                    {
                        min_value = flag[data[now][i]];
                        min_point = data[now][i];
                    } else if(min_value == flag[data[now][i]] && min_point > data[now][i])
                    {
                        min_point = data[now][i];
                    }
                }
            }
        }

        if(min_value == 0)
            cout<<0<<endl;
        else
            cout<<min_point<<endl;

    }

    return 0;
}
