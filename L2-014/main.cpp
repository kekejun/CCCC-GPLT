#include <iostream>
#include <set>
using namespace std;

int main()
{

    int num;
    cin>>num;

    set<int> s;
    s.insert(0);

    for(int i = 0 ;i< num ;i++ )
    {
        int temp;
        cin>>temp;

        if(temp < *s.rbegin())
        {
            s.erase(*s.upper_bound(temp));
        }
        s.insert(temp);
    }


    cout <<s.size()-1<< endl;
    return 0;
}
