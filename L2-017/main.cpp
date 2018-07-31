#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int data[n];

    for(int i = 0 ;i< n ;i++ )
    {
        cin>>data[i];
    }

    sort(data,data+n);

    long long int total = 0;
    for(int i = 0 ;i< n/2 ;i++ )
    {
        total += data[n-1-i]-data[i];
    }
    if( n%2 == 1 )
        total += data[n/2];

    cout<<"Outgoing #: "<<n/2+n%2<<endl;
    cout<<"Introverted #: "<<n/2<<endl;
    cout<<"Diff = "<<total<<endl;

    return 0;
}
