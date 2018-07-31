#include <iostream>

using namespace std;

int main()
{
    int num;
    cin>>num;

    int date =  num+2>7 ? num-5 : num+2;

    cout<<date<<endl;

    return 0;
}
