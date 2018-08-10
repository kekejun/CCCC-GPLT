#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int data[1000000];
set<int> st;

void insertNode(int root,int now)
{
    if(data[root] == -1)
        data[root] = now;
    else
    {
        if(now < data[root])
        {
            insertNode(root*2+1,now);
        } else
        {
            insertNode(root*2+2,now);
        }
    }
}
int findNode(int now)
{
    int begin = 0;
    while(data[begin] != now )
    {
        //cout<<now<<" "<<begin<<" "<<data[begin]<<endl;
        if(data[begin] > now)
            begin = begin*2 +1;
        else
            begin = begin*2 +2;
    }
    return begin;
}

int findNodeCeng(int now)
{
    int begin = 0;
    int ceng = 1;
    while(data[begin] != now && begin < 1000000)
    {
        if(data[begin] > now)
            begin = begin*2 +1;
        else
            begin = begin*2 +2;
        ceng++;
    }
    return ceng;
}

int main()
{
    fill(data,data+1000000,-1);
    int n;
    cin>>n;

    for(int i = 0 ;i< n ;i++ )
    {
        int temp;
        cin>>temp;
        insertNode(0,temp);
        st.insert(temp);
    }

    int m;
    cin>>m;
    for(int i = 0 ;i< m ;i++ )
    {

        int flag = 0;
        int a,b;
        char s[10];
        scanf("%d%s",&a,s);

        if(s[0] == 'i')
        {
            scanf("%s%s",s,s);
            if(s[0] == 'r' && s[1] == 'o')
            {
                if(data[0] == a)
                    flag = 1;
            } else if(s[0] == 'p')
            {
                scanf("%s%d",s,&b);

                if(st.find(a) != st.end() && st.find(b) != st.end())
                {
                    int indexA = findNode(a);
                    int indexB = findNode(b);

                    if((indexB+1)/2 == indexA+1)
                        flag = 1;
                }

            } else if(s[0] == 'l')
            {
                scanf("%s%s%d",s,s,&b);

                if(st.find(a) != st.end() && st.find(b) != st.end())
                {
                    int indexA = findNode(a);
                    int indexB = findNode(b);

                    if(indexB*2+1 == indexA)
                        flag = 1;
                }

            } else if(s[0] == 'r' && s[1] == 'i')
            {
                scanf("%s%s%d",s,s,&b);
                if(st.find(a) != st.end() && st.find(b) != st.end())
                {
                    int indexA = findNode(a);
                    int indexB = findNode(b);

                    if(indexB*2+2 == indexA)
                        flag = 1;
                }
            }

        } else
        {
            scanf("%d%s%s",&b,s,s);
            if(s[0] == 's')
            {
                if(st.find(a) != st.end() && st.find(b) != st.end())
                {
                    int indexA = findNode(a);
                    int indexB = findNode(b);

                    if((indexB+1)/2 == (indexA+1)/2)
                        flag = 1;
                }

            } else
            {
                scanf("%s%s%s",s,s,s);

                if(st.find(a) != st.end() && st.find(b) != st.end())
                {
                    int indexA = findNodeCeng(a);
                    int indexB = findNodeCeng(b);

                    if(indexB == indexA)
                        flag = 1;
                }
            }
        }

        if(flag == 0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }

    return 0;
}
