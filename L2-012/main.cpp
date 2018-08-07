#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> v;
void upAdjust(int i)
{
    if(i == 1)
        return;

    while(i != 1)
    {
        if(v[i] < v[i/2])
        {
            swap(v[i],v[i/2]);
            i = i/2;
        } else
            break;
    }
}

int find(int data)
{
    for(int i = 1;i<= v.size() ;i++ )
        if(v[i] == data)
            return i;
    return 0;
}

int main()
{

    int m,n;
    cin>>m>>n;
    v.resize(m+1);

    for(int i= 1;i<= m ;i++ )
    {
        cin>>v[i];
        upAdjust(i);

    }

    for(int i = 0 ;i< n ;i++ )
    {
        int arg0,arg1;
        char str[100];
        cin>>arg0>>str;

        if(str[0] == 'a')//siblings
        {
            cin>>arg1>>str>>str;

            int a = find(arg0);
            int b = find(arg1);

            if(a/2 == b/2)
                cout<<"T"<<endl;
            else
                cout<<"F"<<endl;
        } else
        {
            scanf("%s",str);
            if(str[0] == 'a')//child
            {
                cin>>str>>str>>arg1;

                int a = find(arg0);
                int b = find(arg1);

                if(a/2 == b)
                    cout<<"T"<<endl;
                else
                    cout<<"F"<<endl;
            } else
            {
                scanf("%s",str);
                if(str[0] == 'r')//root
                {
                    int a = find(arg0);
                    if(a == 1)
                        cout<<"T"<<endl;
                    else
                        cout<<"F"<<endl;
                } else if(str[0] == 'p')//parent
                {
                    cin>>str>>arg1;


                    int a = find(arg0);
                    int b = find(arg1);

                    if(b/2 == a)
                        cout<<"T"<<endl;
                    else
                        cout<<"F"<<endl;
                }
            }
        }
    }

    return 0;
}
