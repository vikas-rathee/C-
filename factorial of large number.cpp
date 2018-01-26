#include<bits/stdc++.h>
using namespace std;
int multiply(int[],int,int);
void factorial(int n)
{
    int a[10000]={1},a_size=1;
    for(int i=2;i<=n;i++)
    {
        a_size=multiply(a,i,a_size);
    }
    for(int i=a_size-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;
}
int multiply(int a[],int n,int a_size)
{
    int temp,carry=0,i;
    for(i=0;i<a_size;i++)
    {
        temp=a[i]*n+carry;
        carry=temp/10;
        temp=temp%10;
        a[i]=temp;
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
