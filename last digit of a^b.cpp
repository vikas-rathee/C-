#include <iostream>
#include<algorithm>
using namespace std;

int power(int num,int pow)
{
    if(pow==0)
        return 1;
    if(pow%2)
        return num*power(num*num,pow/2);
    else
        return power(num*num,pow/2);
}
int main()
{
    int test_cases;
    cin>>test_cases;
    while(test_cases--)
    {
        int a,b;
        cin>>a>>b;
        a=a%10;
        if(a==0)
            cout<<0<<endl;
        else if(b==0)
            cout<<1<<endl;
        else
        {b%=4;
        if(b==0)
            b=4;
        cout<<power(a,b)%10<<endl;}
    }
}
