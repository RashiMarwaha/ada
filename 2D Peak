#include <iostream>
using namespace std;
int max(int arr[][6], int col, int row)
{
    int maxIdx = 0;
    for(int i=1;i<row;i++)
    {
        if(arr[i][col]>arr[maxIdx][col]) maxIdx=i;
    }
    return maxIdx;
}
void peak(int arr[][6], int rows, int st_col, int cols)
{
    int mid_col = (st_col+cols)/2;
    int maxIdx = max(arr,mid_col, rows);
    int maxEl = arr[maxIdx][mid_col];
    if(mid_col > st_col && arr[maxIdx][mid_col-1]>maxEl) return peak(arr, rows, st_col, mid_col-1);
    else if(mid_col < cols-1 && arr[maxIdx][mid_col+1]>maxEl) return peak(arr, rows, mid_col+1, cols);
    else 
    {
        cout<<"Peak at index: ["<<maxIdx<<"]["<<mid_col<<"] and value is: "<<arr[maxIdx][mid_col];
        return; 
    }
}
int main()
{
    int arr[5][6];
    cout<<"enter elements in 2D array of dimensions 5 X 6: "<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            cin>>arr[i][j];
        }
    }
    peak(arr, 5, 0, 6);
    return 0;
    
}
