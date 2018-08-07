#include <iostream>

using namespace std;

int num;
int center[30];
int back[30];
int level[100000];

void floor(int root,int start,int end,int index)
{
    if(start > end)
        return;

    int begin = start;
    for(begin = start ;begin< end; begin++)
    {
        if(center[begin] == back[root])
            break;
    }
    level[index] = back[root];

    floor(root-end+begin-1,start,begin-1,index*2+1);
    floor(root-1,begin+1,end,index*2+2);

}

int main()
{
    cin>>num;

    for(int i = 0 ;i< num ;i++ )
        cin>>back[i];
    for(int i = 0 ;i< num ;i++ )
        cin>>center[i];

    floor(num-1,0,num-1,0);

    cout<<level[0];
    for(int i = 1 ;i< 100000 ;i++ )
        if(level[i]!=0)
        {
            cout<<" "<<level[i];
        }

    cout<<endl;

    return 0;
}
