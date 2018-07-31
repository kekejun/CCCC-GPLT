#include <iostream>

using namespace std;

int main()
{

    int num,total = 0;
    cin>>num;

    int numA[num];
    int flag[num];
    int countNum[num];
    for(int i = 0 ;i< num ;i++ )
    {
        cin>>numA[i];
        countNum[i] = 0;
        flag[i] = 0;
        total += numA[i];
    }

    int data[num][100];
    fill(data[0],data[0]+num*100,0);

    int count = 0;
    int times = 0;

    if(num == 1)
        count--;

    while(true)
    {
        if(times == num)
            break;

        for(int i = 0 ;i< num ;i++ )
        {
            if(countNum[i] < numA[i]*10)
            {
                if(times == num-1)
                    count++;
                count++;

                data[i][countNum[i]] = count;
                countNum[i]++;
            }
            else if(flag[i] == 0)
            {
                times++;
                flag[i] = 1;
            }
        }
    }

    for(int i = 0 ;i< num ;i++ )
    {
        cout<<"#"<<i+1<<endl;
        for(int j = 0 ;j< numA[i]*10 ;j++ )
        {
            cout<<data[i][j];

            if( (j+1)%10 == 0 )
                cout<<endl;
            else
                cout<<" ";
        }
    }

    return 0;
}
