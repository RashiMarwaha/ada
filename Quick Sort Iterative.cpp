// Iterative Quick Sort
#include <iostream>
#include <stack>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<=j)
    {
        while(i<=j && arr[i]<=pivot)
        {
            i++;
        }
        while(i<=j && arr[j] >pivot)
        {
            j--;
        }
        if (i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void QSI(int arr[], int low, int high)
{
    stack <int> st;
    do
    {
        while(low<high)
        {
            int j= partition(arr,low,high);
            if((j-low)>(high-j))
            {
                st.push(low);
                st.push(j-1);
                low=j+1;
            }
            else
            { 
                st.push(j+1);
                st.push(high);
                high=j-1;
            }
        }
        if (st.empty())
        {
            return;
        }
        else
        {
            high=st.top();
            st.pop();
            low=st.top();
            st.pop();
        }
    } while (true);
}
int main()
{
    int size;
    cout<<"Enter size of list: ";
    cin>>size;
    cout<<"Enter elements: ";
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    QSI(arr,0,size-1);
    cout<<"Sorted list: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
