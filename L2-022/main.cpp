#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int preview;
    int address;
    int data;
    int next;
    int rank;
};

Node node[100001];

int main()
{
    int begin,num,end;
    cin>>begin>>num;

    for(int i= 0 ;i< num ;i++ )
    {
        int a;
        cin>>a;
        node[a].address = a;
        cin>>node[a].data>>node[a].next;

        if(node[a].next == -1)
            end = a;
    }

    int length = 0;
    int now = begin;

    while(now != -1)
    {
        length++;
        now = node[now].next;
    }

    int preview = -1;
    now = begin;
    for(int i = 0 ;i< length ;i++ )
    {
        if(i != 0 )
            node[now].preview = preview;
        preview = now;
        now = node[now].next;
    }

    int count = 0;
    while(count < length)
    {
        int now,next;
        if(count %2 == 0)
        {
            now = end;
            end = node[end].preview;
            next = begin;
        } else
        {
            now = begin;
            begin = node[begin].next;
            next = end;
        }
        count++;
        if(count == length)
            printf("%05d %d %d\n",node[now].address,node[now].data,-1);
        else
            printf("%05d %d %05d\n",node[now].address,node[now].data,next);
    }

    return 0;
}
