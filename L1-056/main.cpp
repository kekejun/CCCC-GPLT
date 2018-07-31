    #include <iostream>
    #include <cmath>
    #include <cstdio>
    using namespace std;

    int main()
    {

        int num;
        double total = 0;
        cin>>num;

        string str[num];
        int number[num];

        for(int i = 0 ;i< num ;i++ )
        {
            cin>>str[i]>>number[i];
            total += number[i];
        }

        double avg = total/num/2;

        double min = 100;
        int minNumber;
        for(int i = 0 ;i< num ;i++ )
        {
            if(abs(avg-number[i]) < min)
            {
                min = abs(avg-number[i]);
                minNumber = i;
            }
        }

        printf("%.0f ",avg);
        cout<<str[minNumber]<<endl;

        return 0;
    }
