#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int id;
    char sex;
    int fid;
    int mid;

    Node()
    {
        fid = -1;
        mid = -1;
    }
};

Node node[100001];
int flag[100001];

int main()
{
    int num,n;
    cin>>num;

    for(int i = 1 ;i<= num ;i++ )
    {
        int id;
        cin>>id;
        cin>>node[id].sex>>node[id].fid>>node[id].mid;
        node[node[id].fid].sex = 'M';
        node[node[id].mid].sex = 'F';
        node[id].id = id;
    }

    cin>>n;
    for(int i = 0 ;i< n ;i++ )
    {
        int a,b,tempFlag = 0;
        cin>>a>>b;

        if(node[a].sex == node[b].sex )
        {
            cout<<"Never Mind"<<endl;
            continue;
        }

        fill(flag,flag+100001,0);

        flag[a] = flag[b] = 1;
        queue<int> q;
        q.push(a);
        q.push(b);

        while(!q.empty())
        {
            int now = q.front();
            q.pop();

            int temp[2];
            temp[0] = node[now].fid;
            temp[1] = node[now].mid;

            for(int i = 0 ;i< 2 ;i++ )
            {
                int tint = temp[i];
                if(tint != -1)
                {
                    if( flag[tint] == 0 )
                    {
                        if(flag[now] + 1 < 6)
                        {
                            flag[tint] = flag[now]+1;
                            q.push(tint);
                        }
                    } else
                    {
                        tempFlag = 1;
                        break;
                    }
                }
            }
            if(tempFlag == 1)
                break;
        }
        if(tempFlag == 1)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }

    return 0;
}
