#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2,3,5,9,14,16,18};
    
    int target=15;
    int low=0;
    int high=sizeof(arr)/sizeof(arr[0])-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
    }
    cout<<arr[low];     // for next smaller element -> return arr[end]
    //return low;
    return 0;
}