#include <iostream>

using namespace std;

int find(int* frien,int x)
{
    while(x!=frien[x]) {
        x = frien[x];
    }
    return x;
}

void unio(int* frien,int x,int y)
{
    int temp_x = find(frien,x);
    int temp_y = find(frien,y);

    if(temp_x != temp_y)
        frien[temp_x] = temp_y;
}

int main()
{

    int x,y,z;
    cin>>x>>y>>z;

    int frien[x+1];
    int data[x+1][x+1];

    for(int i = 0 ;i< x+1 ; i++ )
        frien[i] = i;
    fill(data[0],data[0]+(x+1)*(x+1),0);

    for(int i = 0 ;i< y ;i++ )
    {
        int a,b,c;
        cin>>a>>b>>c;

        if(c == -1)
        {
            data[a][b] = 1;
            data[b][a] = 1;
        } else
        {
            unio(frien,a,b);
        }
    }

    for(int i = 0 ;i< z ;i++ )
    {
        int a,b;
        cin>>a>>b;

        int temp_a = find(frien,a);
        int temp_b = find(frien,b);

        if(temp_a == temp_b && data[a][b] == 0) {
            cout<<"No problem"<<endl;
        } else if(temp_a == temp_b && data[a][b] != 0) {
            cout<<"OK but..."<<endl;
        } else if(data[a][b] != 0) {
            cout<<"No way"<<endl;
        } else if(temp_a != temp_b && data[a][b] == 0) {
            cout<<"OK"<<endl;
        }
    }

    return 0;
}
