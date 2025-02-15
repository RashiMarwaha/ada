// Iterative Quick Sort
#include <iostream>
#include <stack>
#include <ctime>
using namespace std;
void randomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}
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
int QSI(int arr[], int low, int high)
{
    stack <int> st;
    int count=0;
    do
    {
        while(low<high)
        {
            int j= partition(arr,low,high);
            if((j-low)>(high-j))
            {
                st.push(low);
                count++;
                st.push(j-1);
                count ++;
                low=j+1;
            }
            else
            { 
                st.push(j+1);
                count++;
                st.push(high);
                count ++;
                high=j-1;
            }
        }
        if (st.empty())
        {
            return count;
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
    // int size;
    // cout<<"Enter size of list: ";
    // cin>>size;
    // cout<<"Enter elements: ";
    // int arr[size];
    // for(int i=0;i<size;i++)
    // {
    //     cin>>arr[i];
    // }

    // QSI(arr,0,size-1);
    // cout<<"Sorted list: ";
    // for(int i=0;i<size;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    srand(time(0));
    int n=100;
    int matrix[10][2];
    int rowCount=0;
    while(n<=1000)
    {
        int arr[n];
        randomNumbers(arr,n);
        int count = QSI(arr,0,n-1);
        matrix[rowCount][0]=n;
        matrix[rowCount][1]=count;
        rowCount++;
        n+=100;
    }
    cout<<"Size of Input and Stack Calls Matrix: "<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
