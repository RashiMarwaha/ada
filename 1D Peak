#include <iostream>
using namespace std;
int peak(int arr[], int n)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid=(high-low)/2;
        if((mid==0 || arr[mid-1]<arr[mid])  && (mid==n-1 || arr[mid+1]<arr[mid]))
        {
            return mid;
        }
        else if(mid>0 && arr[mid-1]>arr[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}
int main()
{
    int size;
    cout<<"Enter size of list: ";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of list: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int ans = peak(arr, size);
    cout<<"Peak is at index: "<<ans<<" and has value: "<<arr[ans];
    return 0;
}
