#include <iostream>

using namespace std;

int data[10001];
int flag[10001];

int get(int a)
{
    if(data[a] != a)
        return get(data[a]);
    return a;
};

int main()
{
    int m,n,count = 0;
    cin>>m;

    fill(flag,flag+10001,0);
    for(int i = 0 ;i< 10001 ;i++ )
        data[i] = i;

    for(int i = 0 ;i< m ;i++ )
    {
        int a;
        cin>>a;
        int begin = -1;
        for(int j = 0 ;j< a ;j++ )
        {
            int temp;
            cin>>temp;

            if(flag[temp] == 0)
            {
                flag[temp] = 1;
                count++;
            }
            if(begin == -1)
                begin = temp;

            if(get(temp) == temp)
                data[get(temp)] = begin;
            else
                data[get(begin)] = get(temp);
        }
    }

    int total = 0;
    for(int i = 0 ;i< 10001 ;i++ )
    {
        if(flag[i] == 1 && data[i] == i)
            total++;
    }

    cout<<count<<" "<<total<<endl;

    cin>>n;
    for(int i = 0 ;i< n ;i++ )
    {
        int a,b;
        cin>>a>>b;

        if(get(a) == get(b))
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }

    return 0;
}
