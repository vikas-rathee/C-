#include<bits/stdc++.h>
#define MAX 500
using namespace std;
int multiply(int[],int,int);
void factorial(int n)
{
    int a[MAX],a_size=1;
    a[0]=1;
    for(int num=2;num<=n;num++)
    {
        a_size=multiply(a,num,a_size);
    }
    for(int i=a_size-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;
}

int multiply(int a[],int num,int a_size)
{
    int carry=0,temp;
    for(int i=0;i<a_size;i++)
    {
        temp=a[i]*num+carry;
        a[i]=temp%10;
        carry=temp/10;
    }
    while(carry)
    {
        a[a_size]=carry%10;
        carry/=10;
        a_size++;
    }
    return a_size;
}
int main()
{
    int test_cases;
    cin>>test_cases;
    while(test_cases--)
    {
        int n;
        cin>>n;
        factorial(n);
    }
}
