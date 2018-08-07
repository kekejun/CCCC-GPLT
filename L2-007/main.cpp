#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int data[10001];
int visited[10001];

struct Input
{
    int id;
    int count;
    int area;
};
struct Node
{
    int id;
    int people;
    double area;
    double count;
    int flag ;
    Node()
    {
        id = -1;
        people = 0;
        area = 0.0;
        count = 0.0;
        flag = 0;
    }
};

int cmp(Node a,Node b)
{
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}

int get(int a)
{
    while(a != data[a])
        a = data[a];
    return a;
}
void Union(int a,int b)
{
    int fa = get(a);
    int fb = get(b);

    if(fa > fb)
        data[fa] = fb;
    else
        data[fb] = fa;
}

int main()
{

    int num;
    cin>>num;

    Input inputNode[num];
    Node node[10001];

    for(int i= 0 ;i< 10001 ;i++ )
        data[i] = i;
    fill(visited,visited+10001,0);

    for(int i= 0 ;i< num ;i++ )
    {
        int a,b,c;
        cin>>inputNode[i].id>>a>>b>>c;

        visited[inputNode[i].id] = 1;
        if(a != -1)
        {
            Union(inputNode[i].id,a);
            visited[a] = 1;
        }
        if(b != -1)
        {
            Union(inputNode[i].id,b);
            visited[b] = 1;
        }
        for(int j = 0 ;j< c ;j++ )
        {
            int d;
            cin>>d;
            Union(inputNode[i].id,d);
            visited[d] = 1;
        }
        cin>>inputNode[i].count>>inputNode[i].area;
    }

    for(int i = 0 ; i< num ;i++ )
    {
        int id = get(inputNode[i].id);
        node[id].id = id;
        node[id].area += inputNode[i].area;
        node[id].count += inputNode[i].count;
        node[id].flag = 1;
    }

    int cnt = 0;
    for(int i= 0 ;i< 10001 ;i++ )
    {
        if(visited[i] == 1)
            node[get(i)].people++;
        if(node[i].flag == 1)
            cnt++;
    }

    for(int i= 0 ;i< 10001 ;i++ )
    {
        if(node[i].flag == 1)
        {
            node[i].count = (double)(node[i].count*1.0/node[i].people);
            node[i].area = (double)(node[i].area*1.0/node[i].people);
        }
    }

    sort(node,node+10000,cmp);
    cout<<cnt<<endl;

    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", node[i].id, node[i].people, node[i].count, node[i].area);
    return 0;
}
