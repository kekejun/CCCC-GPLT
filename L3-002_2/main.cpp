#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
stack<int> s;

int lowbit(int x)
{
    return x & (-x);
}

int num;
int data[100010];
int nowMax = 100010;
int flag[100010];

void update(int x,int v)
{
    for(int i = x; i< 100010 ;i += lowbit(i))
        data[i] += v;
}
int getSum(int x)
{
    int sum = 0;
    for(int i = x ;i >0 ;i -= lowbit(i))
        sum += data[i];
    return sum;
}
void getMiddle()
{
    int left = 1,right = nowMax,mid,k = (s.size()+1)/2;

    while(left<right)
    {
        mid = (left+right)/2;
        if(getSum(mid) >= k)
            right = mid;
        else
            left = mid+1;
    }
    cout<<left<<endl;
}

int main()
{
    cin>>num;

    for(int i = 0 ;i< num ;i++ )
    {
        char str[15];
        scanf("%s",str);

        if(str[1] == 'o')
        {
            if(s.empty())
            {
                cout<<"Invalid"<<endl;
                continue;
            }
            flag[s.top()]--;
            update(s.top(),-1);
            cout<<s.top()<<endl;
            s.pop();
        } else if(str[1] == 'u')
        {
            int data;
            cin>>data;

            flag[data]++;
            s.push(data);
            update(data,1);
        } else if(str[1] == 'e')
        {
            if(s.empty())
            {
                cout<<"Invalid"<<endl;
                continue;
            }
            getMiddle();
        }
    }

    return 0;
}
