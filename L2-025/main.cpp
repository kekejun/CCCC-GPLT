#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector<int> > data;
    data.resize(v+1);

    for(int i = 0 ;i< e; i++ )
    {
        int a,b;
        cin>>a>>b;

        data[a].push_back(b);
        data[b].push_back(a);
    }

    int n;
    cin>>n;

    for(int i = 0 ;i< n ;i++ )
    {
        int m;
        cin>>m;
        int flag[v+1];
        fill(flag,flag+v+1,0);
        for(int j = 0;j< m ;j++ )
        {
            int temp;
            cin>>temp;

            flag[temp] = 1;
        }

        int judge = 0;
        for(int j = 1;j<= v ;j++ )
        {
            if(flag[j] == 0)
            {
                for(int k = 0;k< data[j].size() ;k++ )
                {
                    if(flag[data[j][k]] == 0)
                    {
                        judge = 1;
                        break;
                    }
                }
            }
            if(judge == 1)
                break;
        }
        if(judge == 1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

    }

    return 0;
}
