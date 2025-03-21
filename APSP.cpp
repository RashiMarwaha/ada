#include <iostream>
#include <climits>
using namespace std;
void APSP(int cost[5][5], int n)
{
    int A[5][5];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                A[i][j]=0;
            }
            else if (cost[i][j]==0)
            {A[i][j]=INT_MAX;}
            else A[i][j]=cost[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(A[i][k]!=INT_MAX && A[k][j]!=INT_MAX && A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j]=A[i][k]+A[k][j];
                }
                // else
                // {
                //     A[i][j]=0;
                // }
            }
        }
    }
    cout<<"REsult: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==INT_MAX)
            cout<<"INFINITY ";
            else
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int cost[5][5]=
    {{0,9,7,0,0},
        {0,0,0,8,0},
        {0,0,0,5,0},
        {0,0,0,0,5},
        {0,0,3,0,0}};
    APSP(cost, 5);
    return 0;
}
