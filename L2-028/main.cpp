#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

double data[1001][1001];

vector<int> v;
int myflag = 0;

void getResult(string str,string str1)
{
    v.clear();
    int a = abs(atoi(str.c_str()));
    int b = abs(atoi(str1.c_str()));
    if(str[0] != '-')
    {
        double max = data[a][b];
        for(int i = 0 ;i< 1001 ;i++ )
        {
            if(data[a][i] > max )
            {
                v.clear();
                v.push_back(i);
                max = data[a][i];
            } else if(data[a][i] == max)
            {
                v.push_back(i);
            }
        }

        if(data[a][b] == max)
        {
            if(myflag == 0) {
                cout<<str<<" "<<str1<<endl;
                myflag = 1;
            }
        }
        else
        {
            for(int i = 0 ;i< v.size() ;i++ )
                cout<<str<<" -"<<v[i]<<endl;
        }
    } else
    {
        double max = data[b][a];
        for(int i = 0 ;i< 1001 ;i++ )
        {
            if(data[i][a] > max )
            {
                v.clear();
                v.push_back(i);
                max = data[i][a];
            } else if(data[i][a] == max)
            {
                v.push_back(i);
            }
        }

        if(data[b][a] == max)
        {
            if(myflag == 0) {
                cout<<str<<" "<<str1<<endl;
                myflag = 1;
            }
        }
        else
        {
            for(int i = 0 ;i< v.size() ;i++ )
                cout<<str<<" "<<v[i]<<endl;
        }
    }
}

int main()
{

    int m,n;
    cin>>m>>n;

    fill(data[0],data[0]+1001*1001,0);

    for(int i = 0 ;i<n ;i++ )
    {
        int num;
        cin>>num;

        int temp[num];
        int flag[num];

        fill(flag,flag+num ,0);

        for(int j = 0 ;j< num ;j++ )
        {
            string str;
            cin>>str;
            if(str[0] == '-')
                flag[j] = 1;
            temp[j] = abs(atoi(str.c_str()));
        }

        double d = 1.0/num;

        for(int j = 0 ;j< num ;j++ )
        {
            for(int z = j+1 ; z< num ;z++ )
            {
                if(flag[j] != flag[z])
                {
                    if(flag[j] == 0)
                    {
                        data[temp[j]][temp[z]] += d;
                    }
                    else
                        data[temp[z]][temp[j]] += d;
                }
            }
        }

    }

    string a,b;
    cin>>a>>b;

    getResult(a,b);
    getResult(b,a);

    return 0;
}
