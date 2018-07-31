#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

long long int gcd(long long a,long long b)
{
    return b == 0? a : gcd(b,a%b);
}

int main()
{

    int num;
    cin>>num;

    long long int nowChild = 0,nowParent = 1;

    for(int i = 0 ;i < num ;i++ )
    {
        long long int child,parent;
        scanf("%lld/%lld",&child,&parent);

        long long int yuefen = (child == 0 || parent == 0)? 1: gcd(abs(child),abs(parent));
        child /= yuefen;
        parent /= yuefen;


        nowChild = nowChild * parent + nowParent * child;
        nowParent = nowParent * parent;

        yuefen = (nowChild == 0 || nowParent == 0)? 1: gcd(abs(nowChild),abs(nowParent));
        nowChild /= yuefen;
        nowParent /= yuefen;

    }

    if( abs(nowChild) < nowParent)
    {
        if(nowChild == 0)
            cout<<0<<endl;
        else
            cout<<nowChild<<"/"<<nowParent<<endl;
    } else
    {
        if(nowChild % nowParent == 0)
        {
            cout<<nowChild/nowParent<<endl;
        } else
        {
            int yuefen = gcd(abs(nowChild%nowParent),abs(nowParent));
            cout<<nowChild/nowParent<<" "<<nowChild%nowParent/yuefen<<"/"<<nowParent/yuefen<<endl;
        }
    }

    return 0;
}
