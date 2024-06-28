#include<bits/stdc++.h>
using namespace std;
void demo()
{
    static int x=0;
    cout<<x<<" ";
    x++;
}

int main()
{
    for(int i=0;i<5;i++)
    {
        demo();
    }
    return 0;
}