#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Node
{
    int id;
    double money;
    int count;
};

int com(Node a,Node b)
{
    if(a.money == b.money)
    {
        if(a.count == b.count)
            return a.id < b.id;
        return a.count > b.count;
    }
    return a.money > b.money;
}

int main()
{

    int n;
    cin>>n;

    Node node[n+1];

    for(int i = 0 ;i<= n ;i++ )
    {
        node[i].id = i;
        node[i].money = 0;
        node[i].count = 0;
    }

    for(int i = 1 ;i<= n ;i++ )
    {
        int m;
        cin>>m;

        for(int j= 0 ;j< m ;j++ )
        {
            int a,b;
            cin>>a>>b;
            node[a].count++;
            node[a].money += b;
            node[i].money -= b;

        }
    }

    sort(node+1,node+n+1 , com);

    for(int i = 1 ;i<= n ;i++ )
    {

        cout<<node[i].id<<" ";
        printf("%.2f\n",node[i].money/100);

    }
    return 0;
}
