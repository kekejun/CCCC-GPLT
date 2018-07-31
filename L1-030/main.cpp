#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin>>num;

    int a[num];
    string student[num];

    for(int i= 0 ;i< num ;i++ )
    {
        cin>>a[i]>>student[i];
    }

    int k = num-1 , z = num-1;

    for(int i = 0 ;i< num/2 ;i++ )
    {
        if(a[i] == 0)
        {
            while(a[k] != 1)
                k--;
            cout<<student[i]<<" "<<student[k]<<endl;
            k--;
        } else
        {
             while(a[z] != 0)
                z--;
            cout<<student[i]<<" "<<student[z]<<endl;
            z--;
        }
    }

    return 0;
}
