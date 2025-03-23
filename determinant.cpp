#include <iostream>
using namespace std;
int determinant(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int det= x1*(y2-y3) - x2*(y1-y3) + x3*(y1-y2);
    return det;
}
int main()
{
    int x1, y1, x2, y2, x3, y3;
    cout<<"Enter coordinates 1: ";
    cin>>x1>>y1;
    cout<<"Enter coordinates 2: ";
    cin>>x2>>y2;
    cout<<"Enter coordinates 3: ";
    cin>>x3>>y3;
    int det=determinant(x1,y1,x2,y2,x3,y3);
    cout<<"DETERMINANT= "<<det<<endl;
    if(det>0) cout<<"LEFT SIDE";
    else if(det<0) cout<<"RIGHT SIDE";
    else cout<<"COLLINEAR";
    return 0;
}