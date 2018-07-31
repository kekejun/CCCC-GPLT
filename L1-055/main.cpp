#include <iostream>

using namespace std;

int main()
{

    int ga = 0,gb = 0,pa = 0,pb = 0;

    cin>>ga>>gb;

    for(int i =0 ;i< 3 ;i++ )
    {
        int temp;
        cin>>temp;
        temp==0 ? pa++ : pb++;
    }

    if(ga > gb && pa != 0)
        cout<<"The winner is a: "<<ga<<" + "<<pa<<endl;
    else
        cout<<"The winner is b: "<<gb<<" + "<<pb<<endl;

    return 0;
}
