// time complexity=O(n^2) because of 2 nested loops
#include <iostream>
#include <climits> 
// We included climits for use of INT_MAX 
using namespace std;
// cost is adjacency matrix
// v is source vertex
// dist is final minimum distance for each vertex
// n is total number of vertices
// flag checks for each vertex if visited or not 
int cost[3][3]={{0,6,3},{0,0,0},{0,2,0}};
int dist[3]={INT_MAX, INT_MAX, INT_MAX};
int v=0;
int n=3;
bool flag[3]={false, false, false};
int answer[5]={0};
int res=0;

int minDist(int dist[3], bool flag[3])
{
    int min=INT_MAX;
    int minIndex = -1;
    for(int i=0;i<n;i++)
    {
        if (!flag[i] && dist[i]<=min)
        {
            min=dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void djiktras(int v, int cost[3][3], int n, int dist[3])
{
    for(int i=0;i<n;i++)
    {
        dist[i]=cost[v][i];
        flag[i]=0;
    }
    flag[v]=1;
    dist[v]=0;
    answer[res]=v;
    res++;
    for(int i=1;i<n;i++)
    {
        int u=minDist(dist,flag);
        if(!flag[u])
        {
            flag[u]=1;
            answer[res]=u;
            res++;
            for(int w=0;w<n;w++)
            {
                if(cost[u][w] && !flag[w] && dist[u]!=INT_MAX)
                {
                    if(dist[w]>dist[u]+cost[u][w])
                    {
                        dist[w]=dist[u]+cost[u][w];
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v<<" to "<<i<<" = "<<dist[i]<<endl;
    }
}
int main()
{
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         cout<<cost[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    djiktras(v,cost,n,dist);
    return 0;
}
