#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    int a,b;
    cin>>a>>b;

    if(b == 0)
        cout<<a<<"/"<<b<<"=Error"<<endl;
    else if(b > 0 )
        printf("%d/%d=%.2f\n",a,b,(double)a/b);
    else
        printf("%d/(%d)=%.2f\n",a,b,(double)a/b);

    return 0;
}
