#include <iostream>
#include <cmath>

using namespace std;

#define MAX_POINTS 100

int hull[MAX_POINTS][2], hullCount = 0;

int findSide(int p1[], int p2[], int p[])
{
    int val = (p[1] - p1[1]) * (p2[0] - p1[0]) - 
              (p2[1] - p1[1]) * (p[0] - p1[0]);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

int lineDist(int p1[], int p2[], int p[])
{
    return abs((p[1] - p1[1]) * (p2[0] - p1[0]) - 
               (p2[1] - p1[1]) * (p[0] - p1[0]));
}

bool isInHull(int p[])
{
    for (int i = 0; i < hullCount; i++)
    {
        if (hull[i][0] == p[0] && hull[i][1] == p[1])
            return true;
    }
    return false;
}

void addToHull(int p[])
{
    if (!isInHull(p))
    {
        hull[hullCount][0] = p[0];
        hull[hullCount][1] = p[1];
        hullCount++;
    }
}

void quickHull(int points[][2], int n, int p1[], int p2[], int side)
{
    int ind = -1;
    int max_dist = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = lineDist(p1, p2, points[i]);
        if (findSide(p1, p2, points[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }
    if (ind == -1)
    {
        addToHull(p1);
        addToHull(p2);
        return;
    }
    quickHull(points, n, points[ind], p1, -findSide(points[ind], p1, p2));
    quickHull(points, n, points[ind], p2, -findSide(points[ind], p2, p1));
}

void printHull(int points[][2], int n)
{
    if (n < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }
    int min_x = 0;
    int max_x = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i][0] < points[min_x][0])
            min_x = i;
        if (points[i][0] > points[max_x][0])
            max_x = i;
    }
    quickHull(points, n, points[min_x], points[max_x], 1);
    quickHull(points, n, points[min_x], points[max_x], -1);

    cout << "The points in Convex Hull are:  ";
    for (int i = 0; i < hullCount; i++)
        cout << "(" << hull[i][0] << ", " << hull[i][1] << ") ";
    cout << endl;
}

int main()
{
    int points[][2] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    printHull(points, n);
    return 0;
}
