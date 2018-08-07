#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int> > map;
int v,e,k;
int color[501];

int isYes()
{
    for(int i = 1 ;i<= v; i++ )
    {
        for(unsigned int j = 0; j< map[i].size() ;j++ )
        {
            if(color[i] == color[map[i][j]])
            {
                return 0;
            }

        }
    }
    return 1;
}

int main()
{
    int n;

    cin>>v>>e>>k;
    map.resize(v+1);

    for(int i = 0 ;i< e ;i++ )
    {
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    cin>>n;

    for(int i = 0 ;i< n ;i++ )
    {
        set<int> s;
        fill(color,color+501,0);
        for(int j = 1 ;j<= v; j++ )
        {
            int temp;
            cin>>temp;
            s.insert(temp);
            color[j] = temp;
        }

        if(s.size() == k && isYes() == 1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
