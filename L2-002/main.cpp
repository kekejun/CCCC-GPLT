#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node
{
       int address;
       int key;
       int next;
       int flag;
};

int cmp(Node node1,Node node2)
{
    return node1.flag < node2.flag;
}

int main(int argc, char *argv[])
{

    int begin,num;
    int data[10000+1];
    Node node[100000+1];
    fill(data,data+10000+1,0);

    cin>>begin>>num;

    for(int i = 0; i < 100000+1; i++) {
        node[i].flag = 2 * 100000;
    }

    for(int i = 0;i< num ;i++ )
    {
            int b,a,c;
            cin>>a>>b>>c;
            node[a].address = a;
            node[a].key = b;
            node[a].next = c;
            node[a].flag = 100000*2;
    }


    int successShunxu = 0;
    int errorShunxu = 0;
    for(int i = begin ;i!= -1 ;i = node[i].next)
    {
            int key = abs(node[i].key);

            if(data[key] == 0)
            {
                    data[key] = 1;
                     successShunxu++;
                     node[i].flag = successShunxu;
            }else
            {
                 errorShunxu++;
                 node[i].flag = errorShunxu+100000;
            }
    }

    sort(node,node+100000,cmp);

    for(int i = 0;i< successShunxu-1 ;i++ )
    {
        printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);
    }
    printf("%05d %d -1\n",node[successShunxu-1].address,node[successShunxu-1].key);

    for(int i = successShunxu;i< successShunxu+errorShunxu ;i++ )
    {
        if(i == successShunxu+errorShunxu-1)
        {
            printf("%05d %d -1\n",node[successShunxu+errorShunxu-1].address,node[successShunxu+errorShunxu-1].key);
            break;
        }
        printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
