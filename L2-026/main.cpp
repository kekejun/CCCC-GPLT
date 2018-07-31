#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin>>n;

    int data[n+1];
    int flag[n+1];

    fill(flag,flag+n+1,0);

    for(int i = 1 ;i<= n ; i++ )
        cin>>data[i];

    int max = -1;
    for(int i = 1; i<= n ; i++ )
    {
        int now = i,count = 1;
        if(flag[now] == 1)
            continue;

        while(data[now] != -1)
        {
            count++;
            now = data[now];
            flag[now] = 1;
        }

        if(max < count)
        {
            for(int j = 0 ;j< v.size() ;j++ )
                flag[v[j]] = 1;
            v.clear();
            v.push_back(i);
            max = count;
        }
        else if(max == count )
        {
            v.push_back(i);
        }
    }

    cout<<max<< endl;
    for(int j = 0 ;j< v.size()-1 ;j++ )
    {
        cout<<v[j]<<" ";;
    }
    cout<<v[v.size()-1]<<endl;
    return 0;
}
