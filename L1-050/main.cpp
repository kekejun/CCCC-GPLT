#include <iostream>

using namespace std;

int pow(int a,int b)
{
    int sum = 1;
    for(int i = 0;i< b ;i++)
        sum *= a;
    return sum;
}

int main()
{
    int length,index;
    cin>>length>>index;

    char ch[length];
    fill(ch,ch+length,'z');

    int len = 0;
    while(pow(26,len)<index)
        len++;

    cout<<len<<endl;

    for(int i = len ;i> 0 ;i-- )
    {
        if(i == 1 && index != 0)
            index -= 1;

        cout<<'z'-index/pow(26,i-1)<<endl;
        ch[i-1] = 'z'-index/pow(26,i-1);
        index = index%pow(26,i-1);
    }

    for(int i = length - 1;i>= 0 ;i--)
        cout<<ch[i];
    cout<<endl;

    return 0;
}
