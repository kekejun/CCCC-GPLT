#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
using namespace std;

int MAX_LENGTH = 999999;

int cmp(int a,int b){
    return a-b;
}

int main()
{

    int n,m,begin,end;
    cin>>n>>m>>begin>>end;

    int manCount[n];
    int flag[n];
    int path[n];

    int length[n][n];

    fill(length[0],length[0]+n*n,0);

    for(int i = 0 ;i< n ;i++ )
    {
        cin>>manCount[i];
        flag[i] = 0;
        path[i] = -1;
    }
    for(int i =0;i< n ;i++ ){
        for(int j = 0;j< n ;j++ ){
            length[i][j] = MAX_LENGTH;
        }
    }

    for(int i =0;i< m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        length[a][b] = c;
        length[b][a] = c;

        if(a == begin)
        {
            path[b] = a;
        }
    }


    for(int k = 0;k< n-1 ;k++ )
    {
        int min = MAX_LENGTH;
        int min_point = -1;
        for(int i = 0;i< n ;i++)
        {
            if(flag[i] == 0 && min>length[begin][i])
            {
                min = length[begin][i];
                min_point = i;
            }
        }

        flag[min_point] = 1;

        for(int i =0; i< n ;i++ )
        {
            if(i!=begin && length[begin][min_point]+length[min_point][i] < length[begin][i])
            {
                length[begin][i] = length[begin][min_point]+length[min_point][i];
                path[i] = min_point;

            }
        }
    }

    for(int i = 0;i< n ;i++ )
    {
        cout<<length[begin][i]<<" ";
    }

    cout<<endl;

    for(int i = 0;i< n ;i++ )
    {
        cout<<path[i]<<" ";
    }

    cout<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
