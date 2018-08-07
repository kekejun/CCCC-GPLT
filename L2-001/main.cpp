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
        cin>>man[i];

    for(int i = 0 ;i< e ;i++ )
    {
        int a,b,c;
        cin>>a>>b>>c;
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

    int index = end;

    cout<<num[end]<<" "<<nowMan[end]<<endl;

    printPath(end,begin,path);

    //for(int i = vindex.size()-1 ;i>0  ;i-- )
    //    cout<<vindex[i]<<" ";
    //cout<<vindex[0]<<endl;

}


//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n, m, c1, c2;
//int dis[510], weight[510], e[510][510], num[510], w[510], pre[510];
//bool visit[510];
//const int inf = 99999999;
//void printPath(int v) {
//    if(v == c1) {
//        printf("%d", v);
//        return ;
//    }
//    printPath(pre[v]);
//    printf(" %d", v);
//}
//int main() {
//    scanf("%d%d%d%d", &n, &m, &c1, &c2);
//    for(int i = 0; i < n; i++)
//        scanf("%d", &weight[i]);
//    fill(e[0], e[0] + 510 * 510, inf);
//    fill(dis, dis + 510, inf);
//    int a, b, c;
//    for(int i = 0; i < m; i++) {
//        scanf("%d%d%d", &a, &b, &c);
//        e[a][b] = c;
//        e[b][a] = c;
//    }
//    dis[c1] = 0;
//    w[c1] = weight[c1];
//    num[c1] = 1;
//
//    for(int i = 0 ;i< n ;i++ )
//            cout<<w[i]<<" ";
//        cout<<endl;
//
//    for(int i = 0; i < n; i++) {
//        int u = -1, minn = inf;
//        for(int j = 0; j < n; j++) {
//            if(visit[j] == false && dis[j] < minn) {
//                u = j;
//                minn = dis[j];
//            }
//        }
//        cout<<u<<endl;
//        if(u == -1) break;
//        visit[u] = true;
//        for(int v = 0; v < n; v++) {
//            if(visit[v] == false && e[u][v] != inf) {
//                cout<<v<<" "<<e[u][v]<<" "<<dis[v]<<endl;
//                if(dis[u] + e[u][v] < dis[v]) {
//                    dis[v] = dis[u] + e[u][v];
//                    num[v] = num[u];
//                    w[v] = w[u] + weight[v];
//                    cout<<v<<" "<<w[v]<<" "<<u<<endl;
//                    pre[v] = u;
//                } else if(dis[u] + e[u][v] == dis[v]) {
//                    num[v] = num[v] + num[u];
//                    if(w[u] + weight[v] > w[v]) {
//                        w[v] = w[u] + weight[v];
//                        pre[v] = u;
//                    }
//                }
//            }
//        }
//        for(int i = 0 ;i< n ;i++ )
//            cout<<w[i]<<" ";
//        cout<<endl;
//    }
//    printf("%d %d\n", num[c2], w[c2]);
//    printPath(c2);
//    return 0;
//}
//
