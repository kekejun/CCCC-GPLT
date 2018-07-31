#include <iostream>
#include <cstdio>

#include <math.h>

using namespace std;

int main()
{

    int beginTime[1001],flag[1001];

    fill(beginTime,beginTime+1001,0);
    fill(flag,flag+1001,0);

    int num;
    cin>>num;
    for(int i = 0 ;i< num ;i++ )
    {
        int no,hour,minus;
        char c;

        int count = 0;
        double total = 0;

        while(scanf("%d %c %d:%d",&no,&c,&hour,&minus))
        {
            if(no == 0)
            {
                if(count == 0)
                    cout<<"0 0"<<endl;
                else
                    printf("%d %d\n",count,(int)round(total/count));

                fill(beginTime,beginTime+1001,0);
                fill(flag,flag+1001,0);

                break;
            }
            else
            {
                if(c == 'S')
                {
                    beginTime[no] = hour*60+minus;
                    flag[no] = 1;
                } else
                {
                    if(flag[no] == 1)
                    {
                        count++;
                        total += hour*60+minus - beginTime[no];
                        beginTime[no] = 0;
                        flag[no] = 0;
                    }

                }
            }

        }
    }

    return 0;
}
