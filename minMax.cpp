// MinMax via Divide and Conquer approach
#include <iostream>
using namespace std;
void maxmin(int arr[], int low, int high, int &max, int &min)
{
    if (low==high) {max=min=arr[low];}
    else if (low==high-1) 
    {
        if(arr[low]<arr[high])
        {
            max=arr[high];
            min=arr[low];
        }
        else
        {
            max=arr[low];
            min=arr[high];
        }
    }
    else
    {
        int mid= (low+high)/2;
        int max1, min1;
        maxmin(arr,low,mid,max,min);
        maxmin(arr,mid+1,high,max1,min1);
        if(max<max1) max=max1;
        if(min>min1) min=min1;

    }

}
int main()
{
    int n;
    cout<<"Enter size of list: ";
    cin>>n;
    cout<<"Enter elements of list: ";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max, min;
    maxmin(arr,0,n-1,max,min);
    cout<<"Max is: "<<max<<", Min is: "<<min;
    return 0;
}
