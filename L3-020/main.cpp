#include <iostream>

using namespace std;
const int MAXN = 1e6+10;
long long data[MAXN][4];
string str;

int main()
{
    cin>>str;
    int n = str.length();

    for(int i = 0 ; i<= n ; i++ )
        data[i][0] = 1;

    for(int i = 1 ; i<= 3 ; i++ )
    {
        data[i][i] = 1;
        for(int j = i+1; j<= n; j++ )
        {
            data[j][i] = data[j-1][i-1] + data[j-1][i];

            for(int k = 1 ;k<= i ; k++ )
            {
                if(str[j-k-1] == str[j-1])
                {
                    data[j][i] -= data[j-k-1][i-k];
                    break;
                }
            }
        }
    }

    cout<<data[n][0]+data[n][1]+data[n][2]+data[n][3]<<endl;
}
