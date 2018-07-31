#include <iostream>

using namespace std;

int data[10001];

struct Input
{
    int id;
    int count;
    int area;
};

int get(int a)
{
    while(a != data[a])
        a = data[a];
    return a;
}
void Union(int a,int b)
{
    int fa = get(a);
    int fb = get(b);

    if(fa > fb)
        data[fa] = fb;
    else
        data[fb] = fa;
}

int main()
{

    int num;
    cin>>num;

    Input inputNode[num];

    for(int i= 0 ;i< 10001 ;i++ )
        data[i] = i;

    for(int i= 0 ;i< num ;i++ )
    {
        int a,b,c;
        cin>>inputNode[i].id>>a>>b>>c;

        if(a != -1)
        {
            Union(inputNode[i].id,a);
        }
        if(b != -1)
        {
            Union(inputNode[i].id,b);
        }
        for(int j = 0 ;j< c ;j++ )
        {
            int d;
            cin>>d;
            Union(inputNode[i].id,d);
        }
        cin>>inputNode[i].count>>inputNode[i].area;
    }

    cout << "Hello world!" << endl;
    return 0;
}
