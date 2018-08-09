#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int x,y,z;
    Node(int x,int y,int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int data[1300][130][61];
int flag[1300][130][61];
int length,width,height,t;


int main()
{
    cin>>length>>width>>height>>t;

    for(int i = 0 ;i< height ;i++ )
    {
        for(int j = 0 ;j< length ;j++ )
        {
            for(int k = 0 ;k< width ;k++ )
            {
                cin>>data[j][k][i];
            }
        }
    }


    int total = 0;
    for(int k = 0 ;k< height ;k++ )
    {
        for(int i = 0 ;i< length ;i++ )
        {
            for(int j = 0 ;j< width ;j++ )
            {
                if(data[i][j][k] == 1 && flag[i][j][k] == 0)
                {
                    flag[i][j][k] = 1;
                    queue<Node> q;
                    Node node(i,j,k);
                    q.push(node);
                    int count = 1;
                    while(!q.empty())
                    {
                        Node now = q.front();
                        q.pop();

                        int x = now.x;
                        int y = now.y;
                        int z = now.z;

                        if( x+1 < length && flag[x+1][y][z] == 0 && data[x+1][y][z] == 1)
                        {
                            flag[x+1][y][z] = 1;
                            Node node(x+1,y,z);
                            q.push(node);
                            count++;
                        }
                        if( x-1 >= 0 && flag[x-1][y][z] == 0 && data[x-1][y][z] == 1)
                        {

                            flag[x-1][y][z] = 1;
                            Node node(x-1,y,z);
                            q.push(node);
                            count++;
                        }
                        if( y+1 < width && flag[x][y+1][z] == 0 && data[x][y+1][z] == 1)
                        {
                            flag[x][y+1][z] = 1;
                            Node node(x,y+1,z);
                            q.push(node);
                            count++;
                        }
                        if( y-1 >= 0 && flag[x][y-1][z] == 0 && data[x][y-1][z] == 1)
                        {
                            flag[x][y-1][z] = 1;
                            Node node(x,y-1,z);
                            q.push(node);
                            count++;
                        }
                        if( z+1 < height && flag[x][y][z+1] == 0 && data[x][y][z+1] == 1)
                        {
                            flag[x][y][z+1] = 1;
                            Node node(x,y,z+1);
                            q.push(node);
                            count++;
                        }
                        if( z-1 >= 0 && flag[x][y][z-1] == 0 && data[x][y][z-1] == 1)
                        {
                            flag[x][y][z-1] = 1;
                            Node node(x,y,z-1);
                            q.push(node);
                            count++;
                        }
                    }
                    if(count >= t)
                    {
                        total+=count;
                    }

                }
            }
        }
    }

    cout << total << endl;
    return 0;
}

/*

1 1 1 1
1 1 1 1
1 1 1 1

0 0 1 1
0 0 1 1
0 0 1 1

1 0 1 1
0 1 0 0
0 0 0 0

0 0 0 1
0 0 0 0
0 0 0 0

0 0 0 0
0 0 0 0
0 0 0 0

0 0 0 0
0 0 0 0
0 0 0 0

*/
