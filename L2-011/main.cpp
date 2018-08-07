#include <iostream>

using namespace std;

int num;
int center[30];
int pre[30];
int level[100000];

void floor(int root,int start, int end,int index)
{
    if(start > end )
        return;

    int middle = start;
    for(middle = start ; middle < end; middle++ )
        if(center[middle] == pre[root])
            break;

    level[index] = pre[root];

    floor(root+1,start,middle-1,index*2+2);
    floor(root+middle-start+1,middle+1,end,index*2+1);

}

int main()
{
    cin>>num;

    for(int i = 0 ; i< num ; i++ )
        cin>>center[i];
    for(int i = 0 ; i< num ; i++ )
        cin>>pre[i];

    floor(0,0,num-1,0);

    cout<<level[0];
    for(int i = 1 ; i< 100000 ; i++ )
        if(level[i]!=0)
        {
            cout<<" "<<level[i];
        }

    cout<<endl;
    return 0;
}
