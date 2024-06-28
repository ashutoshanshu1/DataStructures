#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[],int target,bool findStartIndex)
{
    int ans=-1;
    int low=0;
    int high=sizeof(arr)/sizeof(arr[0])-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(arr[mid]<target)
        {
            low=mid+1;
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        else        // potential answer is found
        {
            ans=mid;        // potential answer
            if(findStartIndex)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
    return ans;
}
int main()
{
    int answer[2]={-1,-1};
    int arr[]={5,7,7,7,7,8,8,10};
    int target=8;
    bool findStartIndex;
    answer[0]=binarySearch(arr,target,findStartIndex=true);
    answer[1]=binarySearch(arr,target,findStartIndex=false);
    cout<<"["<<answer[0]<<","<<answer[1]<<"]";
    return 0;
}

