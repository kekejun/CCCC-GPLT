#include <iostream>

using namespace std;

int main()
{

    int num;
    cin>>num;

    int countA = 0, countB = 0;
    for(int i = 0 ;i < num ;i++ )
    {
        int a;
        cin>>a;
        a % 2 == 0 ? countA++ : countB++;
    }

    cout <<countB<<" "<<countA<< endl;
    return 0;
}
