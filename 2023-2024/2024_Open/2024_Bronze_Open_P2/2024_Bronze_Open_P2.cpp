#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <stack>

#define RUN_SERVER 1

using namespace std;

bool ReadInFile(const string& sFile, vector<int>&)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }


    return true;
}

bool ReadInCout(vector<int>&)
{
    ios::sync_with_stdio(0); cin.tie(0);

    return true;
}

void Print(vector<int>&)
{

}

void WriteOut(vector<bool>& ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i])
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }
}

struct Point
{
    double x;
    double y;
    Point(double x_in, double y_in) :x(x_in), y(y_in)
    {};
};

int edgeDistant(const Point& p1, const Point& p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main()
{
    //ReadInFile("../P2.in");
    //Print();
    //ReadInCout();

    long N = 0, P = 0;
    vector<Point> vecPs;

#ifdef RUN_SERVER  
    cin >> N >> P;
#else
    string sFile = "../P2.in";
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }
    in >> N >> P;
#endif

    for (long i = 0; i < P; i++)
    {
        int x = 0, y = 0;
#ifdef RUN_SERVER  
        cin >> x >> y;
#else
        in >> x >> y;
#endif
        vecPs.push_back(Point(x, y));
    }

    //total dist
    int outline = 0;
    for (int j = 0; j < P - 1; j++)
    {
        outline += edgeDistant(vecPs[j], vecPs[j + 1]);
}
    outline += edgeDistant(vecPs[0], vecPs[P - 1]);


    for (long i = 0; i < N; i++)
    {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
#ifdef RUN_SERVER  
        cin >> x1 >> y1 >> x2 >> y2;
#else
        in >> x1 >> y1 >> x2 >> y2;
#endif
        Point p1(x1, y1);
        Point p2(x2, y2);

        int dist1 = INT_MAX;
        int idx1 = 0;
        for (int j = 0; j < P; j++)
        {
            int d1 = edgeDistant(vecPs[j], p1);
            if (dist1 > d1) {
                dist1 = d1;
                idx1 = j;
            }
            else if (dist1 == d1) {
                int d22 = edgeDistant(vecPs[j], p2);
                int d12 = edgeDistant(vecPs[idx1], p2);
                if (d12 > d22) {
                    dist1 = d1;
                    idx1 = j;
                }
            }
        }

        int dist2 = INT_MAX;
        int idx2 = 0;
        for (int j = 0; j < P; j++)
        {
            int d2 = edgeDistant(vecPs[j], p2);
            if (dist2 > d2) {
                dist2 = d2;
                idx2 = j;
            }
            else if (dist2 == d2) {
                int d22 = edgeDistant(vecPs[j], vecPs[idx1]);
                int d12 = edgeDistant(vecPs[idx2], vecPs[idx1]);
                if (d12 > d22) {
                    dist2 = d2;
                    idx2 = j;
                }
            }
        }


        //P1 to P2
        int distSec2 = 0, distSec2A = 0, distSec2B = 0;
        if (idx1 < idx2)
        {
            for (int j = idx1; j < idx2; j++)
            {
                distSec2A += edgeDistant(vecPs[j], vecPs[j + 1]);
            }
            distSec2B = outline - distSec2A;
        }
        else if (idx1 > idx2)
        {
            for (int j = idx2; j < idx1; j++)
            {
                distSec2A += edgeDistant(vecPs[j], vecPs[j + 1]);
            }
            distSec2B = outline - distSec2A;
        }
        distSec2 = min(distSec2A, distSec2B);

        int total = dist1 + distSec2 + dist2;
        cout << total << endl;
    }

    //WriteOut(ans);
}