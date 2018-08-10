#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include <vector>
using namespace std;

int MAX_LENGTH = 999999;

void printPath(int now,int end,int* path)
{
    if(now == end)
    {
        printf("%d",now);
        return;
    }
    printPath(path[now],end,path);
    printf(" %d", now);
}

int main()
{
    int v,e,begin,end;
    cin>>v>>e>>begin>>end;

    int man[v];
    int length[v][v];
    int flag[v];
    int path[v];
    int nowMan[v];
    int dist[v];
    int num[v];

    fill(length[0],length[0]+v*v,MAX_LENGTH);
    fill(flag,flag+v,-1);
    fill(path,path+v,-1);
    fill(dist,dist+v,MAX_LENGTH);

    for(int i = 0 ;i< v ;i++ )
        scanf("%d",&man[i]);

    for(int i = 0 ;i< e ;i++ )
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        length[a][b] = length[b][a] = c;
        if(a == begin)
            path[b] = a;
    }
    dist[begin] = 0;
    num[begin] = 1;
    nowMan[begin] = man[begin];

    for(int k = 0 ;k< v ;k++ )
    {
        int min_length = MAX_LENGTH;
        int min_point = -1;

        for(int i = 0 ;i< v ;i++ )
        {
            if(flag[i] == -1 && dist[i] < min_length)
            {
                min_length = length[begin][i];
                min_point = i;
            }
        }
        if(min_point == -1)
            break;
        flag[min_point] = 1;

        for(int i = 0 ; i< v ;i++ )
        {
            if( flag[i] == -1 && length[min_point][i] != MAX_LENGTH)
            {
                if(dist[min_point] + length[min_point][i] < dist[i])
                {
                    num[i] = num[min_point];
                    dist[i] = dist[min_point] + length[min_point][i];
                    path[i] = min_point;
                    nowMan[i] = nowMan[min_point] + man[i];
                } else if(dist[min_point] + length[min_point][i] == dist[i])
                {
                    num[i] = num[i] + num[min_point];
                    int temp = nowMan[min_point] + man[i];
                    if(temp > nowMan[i])
                    {
                        path[i] = min_point;
                        nowMan[i] = temp;
                    }
                }
            }
        }
    }
    cout<<num[end]<<" "<<nowMan[end]<<endl;

    printPath(end,begin,path);

}
