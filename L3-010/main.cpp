#include <iostream>

using namespace std;

int data[1000000];
int judge = 0;
int num;

void insertNode(int root,int node)
{
    if( judge == 0 && root*2+1 >= num )
    {
        judge = 1;
    }

    if(node > data[root])
    {
        if(data[root*2+1] == 0)
            data[root*2+1] = node;
        else
            insertNode(root*2+1,node);
    } else
    {
        if( judge == 0 && root*2+2 >= num )
        {
            judge = 1;
        }
        if(data[root*2+2] == 0)
            data[root*2+2] = node;
        else
            insertNode(root*2+2,node);
    }
}

void insert(int node)
{
    if(data[0] == 0)
        data[0] = node;
    else
    {
        insertNode(0,node);
    }
}


int main()
{
    fill(data,data+100,0);

    cin>>num;

    for(int i = 0 ;i< num ;i++ )
    {
        int temp;
        cin>>temp;
        insert(temp);
    }
    int count = 0;
    for(int i = 0 ; i< 1000000 ;i++ )
    {
        if(count == num)
            break;
        if(data[i] != 0)
        {
            count++;
            if(count == 1)
                cout<<data[i];
            else
                cout<<" "<<data[i];
        }
    }
    cout<<endl;
    if(judge == 1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

    return 0;
}
