#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> post;
int isMirror = 0;
void getPost(int root,int tail)
{
    if(root > tail)
        return;
    int begin = root+1;
    int i = begin,j = tail;
    if(isMirror == 0)
    {
        while( i<= tail && v[i] < v[root] )
            i++;
        while( j>= begin && v[j] >= v[root] )
            j--;
    } else
    {
        while( i<= tail && v[i] >= v[root] )
            i++;
        while( j>= begin && v[j] < v[root] )
            j--;
        cout<<i<<" "<<j<<endl;
    }
    if(i - j != 1)
        return;
    getPost(begin,j);
    getPost(i,tail);
    post.push_back(v[root]);

}

int main()
{
    int n;
    cin>>n;
    v.resize(n);

    for(int i = 0 ;i< n;i++ )
        cin>>v[i];

    getPost(0,n-1);

    if(post.size() != n)
    {
        isMirror = 1;
        post.clear();
        getPost(0,n-1);
    }

    if(post.size() == n)
    {
        cout<<"YES"<<endl;
        for(int i = 0 ;i< n-1 ;i++ )
            cout<<post[i]<<" ";
        cout<<post[n-1]<<endl;
    } else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}
