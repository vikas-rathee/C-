#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map <int,list<int>> hash_table;
    map <int,list<int>>::iterator m_it;
    list <int>::iterator l_it;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        hash_table[a+b].push_back(i+1);
    }
    for(m_it=hash_table.begin();m_it!=hash_table.end();m_it++)
    {
        l_it=m_it->second.begin();
        while(l_it!=m_it->second.end())
        {
            cout<<*l_it<<" ";
                l_it++;
        }
    }
}
