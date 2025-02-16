// Number of triangles using n points
#include <iostream>
using namespace std;
long long fact(int n)
{
    if(n==1 || n==0) return 1;
    else return n*fact(n-1);
}
int main()
{
    int n;
    cout<<"Enter n (no of points): ";
    cin>>n;
    if(n<3)
    {
        cout<<"Atleast 3 points needed to make 1 triangle";
        return 0;
    }
    long long result = fact(n)/(fact(n-3)*fact(3));
    cout<<"Number of possible triangles is nCr = n!/((n-r)!*(r!)) : "<<result;
    return 0;
}
