#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int isLegal(string str)
{
    if(str.length() == 0)
        return 0;

    for(int i = 0 ;i< str.length() ;i++ )
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
    }

    int temp = atoi(str.c_str());
    if(temp < 1 || temp > 1000)
        return 0;

    return 1;
}

int main()
{
    string str,str1,str2;
    getline(cin,str);

    int index = str.find(" ");
    str1 = str.substr(0,index);
    str2 = str.substr(index+1);

    int flagA = isLegal(str1);
    int flagB = isLegal(str2);

    if(flagA == 0 && flagB == 0)
    {
        cout<<"? + ? = ?"<<endl;
    }else if(flagA == 0 && flagB != 0)
    {
        cout<<"? + "+str2+" = ?"<<endl;
    } else if(flagA != 0 && flagB == 0)
    {
        cout<<str1<<" + ? = ?"<<endl;
    } else
    {
        cout<<str1+" + "<<str2<<" = "<<atoi(str1.c_str())+atoi(str2.c_str())<<endl;
    }

    return 0;
}
