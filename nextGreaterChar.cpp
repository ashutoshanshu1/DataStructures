#include<bits/stdc++.h>
using namespace std;

int main()
{
    char arr[]={'c','f','j'};
    
    char target='d';
    int low=0;
    int high=sizeof(arr)/sizeof(arr[0])-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>target)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    cout<<arr[low % (sizeof(arr)/sizeof(arr[0]))];     
    //return low;
    return 0;
}