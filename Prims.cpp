#include <iostream>
#include <climits>
using namespace std;
#define N 5
#define NO INT_MAX
void minEdgefind(int cost[N][N], int n, int &k, int &l, int &minEdge)
{
    minEdge=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                if(cost[i][j]<minEdge && cost[i][j]!=NO)
                {
                    minEdge=cost[i][j];
                    k=i;
                    l=j;
                }
            }
        
    }
}

void prims(int cost[N][N], int n)
{
    int minCost=0;
    int near[N];
    int t[N-1][2];
    int k=-1, l=-1, minEdge;
    minEdgefind(cost,n,k,l,minEdge);
    minCost=minEdge;
    t[0][0]=k;
    t[0][1]=l;
    
    for(int i=0;i<n;i++)
    {
        if(cost[i][l]<cost[i][k])
        near[i]=l;
        else near[i]=k;
    }
    near[k]=near[l]=-1;
    
    for(int i=1;i<n-1;i++)
    {
        int minIndex=-1;
        int minVal=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if (near[j]!=-1 && cost[j][near[j]]<minVal)
            {
                minVal=cost[j][near[j]];
                minIndex=j;
            }
        }
    
    t[i][0]=minIndex;
    t[i][1]=near[minIndex];
    minCost+=cost[minIndex][near[minIndex]];
    near[minIndex]=-1;
    
    for(int j=0;j<n;j++)
    {
        if(near[j]!=-1 && cost[j][near[j]]>cost[j][minIndex])
        near[j]=minIndex;
    }
    
    }
    cout<<"MST EDGES: "<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<t[i][0]<<" "<<t[i][1]<<endl;
    }
    cout<<"Total minCost: "<<minCost;
}
int main()
{
    int cost[N][N] = {
        {NO, 2, NO, 6, NO},
        {2, NO, 3, 8, 5},
        {NO, 3, NO, NO, 7},
        {6, 8, NO, NO, 9},
        {NO, 5, 7, 9, NO}
    };
    prims(cost,N);
    return 0;
}
