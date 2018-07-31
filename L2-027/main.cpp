#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    string name;
    int grade;
};

int com(Node a,Node b)
{
    if(a.grade == b.grade)
        return a.name < b.name;
    return a.grade > b.grade;
}

int main()
{
    int a,b,c;
    int totalMoney = 0;
    cin>>a>>b>>c;
    Node node[a];

    for(int i= 0 ;i< a ;i++ )
    {
        cin>>node[i].name>>node[i].grade;
        if( node[i].grade >= b )
            totalMoney += 50;
        else if(node[i].grade >= 60 )
            totalMoney += 20;
    }

    sort(node,node+a,com);

    cout<<totalMoney<<endl;

    int end = c;
    while(true)
    {
        if(node[end-1].grade == node[end].grade)
            end++;
        else
            break;
    }

    int m = 0;
    int n = 0;
    for(int i = 0 ;i< end ;i++ )
    {
        if(node[i].grade == m)
            cout<<n<<" "<<node[i].name<<" "<<node[i].grade<<endl;
        else
        {
            cout<<i+1<<" "<<node[i].name<<" "<<node[i].grade<<endl;
            m = node[i].grade;
            n = i+1;
        }
    }

}
