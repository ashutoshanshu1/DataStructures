#include<bits/stdc++.h>
using namespace std;

int binarySearch(int array[])
{
    int low=0;
    int high=sizeof(array)/sizeof(array[0])-1;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(array[mid]<array[mid+1])
        {
            low=mid+1;
        }
        else if(array[mid]>array[mid+1])
        {
            high=mid;
        }
    }
    return array[low];
}

int main()
{
    int array[]={1,2,3,5,6,4,3,2,0};
    cout<<binarySearch(array);
    return 0;
}