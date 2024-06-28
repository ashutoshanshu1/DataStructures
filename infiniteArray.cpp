#include<bits/stdc++.h>
using namespace std;

int binarySearch(int array[],int target, int low, int high)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(array[mid]==target)
        {
            return mid;
        }
        else if(array[mid]<target)
        {
            low=mid+1;
        }
        else if(array[mid]>target)
        {
            high=mid-1;
        }
    }
    return -1;
}
int findingRange(int array[],int target)
{
    // find the range
    // first start with a box of 2 elements

    int start=0;
    int end=1;

    // condition to check for the target lying in the range
    while(target>array[end])
    {
        int temp=end+1;
        // end index = previousEnd + (sizeOfCurrentBox)*2
        end=end+(end-start+1)*2;
        start=temp;
    }
    return binarySearch(array, target, start, end);
}

int main()
{
    int arr[]={3,5,7,9,10,90,100,130,140,160,170,899,1090, 1300};   //  had to give long list, because infinte array is the condition in the question
    int target=170;
    cout<<findingRange(arr,target);
    return 0;
}