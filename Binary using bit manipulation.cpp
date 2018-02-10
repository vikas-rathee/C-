#include<bits/stdc++.h>
using namespace std;

void binary_iterative(int n)
{
    bool flag = false;
    for(int i = (1 << 30); i > 0; i/=2)
    {
        if(i & n)
            {
                cout << "1";
                flag = true;
            }
        else if(flag)
            cout << "0";
    }
    cout << endl;
}

void bin_rec(int n)
{
    if(n > 1)
        bin_rec(n/2);
    cout << (n & 1);
    return;
}
int main()
{
    int n;
    cin >> n;
    binary_iterative(n);
    bin_rec(n);
    cout << endl;

}
