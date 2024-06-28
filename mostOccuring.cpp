#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"How many numbers? ";
    cin>>n;
    int maxCount=0;
    
    int mostOccuring;
    int a[n];
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }
            if(count>maxCount)
            {
                maxCount=count;
            }
        }
        mostOccuring=a[i];
    }
    return mostOccuring;
}
