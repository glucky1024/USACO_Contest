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

using namespace std;

bool ReadInFile(const string& sFile, vector<int>& bills, vector<int>& trucks)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    for (int i = 0; i < 8; i++)
    {
        int temp = 0;
        in >> temp;
        bills.push_back(temp);
    }

    for (int i = 0; i < 4; i++)
    {
        int temp = 0;
        in >> temp;
        trucks.push_back(temp);
    }

    return true;
}

void Print(const vector<int> bills, const vector<int> trucks)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << bills[i] << " ";
        count++;


        if (count % 4 == 0)
        {
            cout << endl;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << trucks[i] << " ";
    }

    cout << endl;
}

bool WriteOut(const string& sFile, const int ans)
{
    cout << ans;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << ans << endl;

    out_file.close();

    return true;
}

bool check(int x, int y, vector<int> trucks)
{
    for (int t_x = trucks[0]; t_x < trucks[2]; t_x++)
    {
        for (int t_y = trucks[1]; t_y < trucks[3]; t_y++)
        {
            if (x == t_x && y == t_y)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> bills;
    vector<int> trucks;

    int ans = 0;

    bool bOk = ReadInFile("billboard.in", bills, trucks);
    //Print(bills, trucks);

    //areas
    int area1 = abs(bills[1] - bills[3]) * abs(bills[0] - bills[2]);
    int area2 = abs(bills[5] - bills[7]) * abs(bills[4] - bills[6]);
    
    int int_x1 = max(0, min(bills[2], trucks[2])) - max(bills[0], trucks[0]);
    int int_y1 = max(0, min(bills[3], trucks[3])) - max(bills[1], trucks[1]);
    ans += int_x1 * int_y1;

    int int_x2 = max(0, min(bills[6], trucks[2])) - max(bills[4], trucks[0]);
    int int_y2 = max(0, min(bills[7], trucks[3])) - max(bills[5], trucks[1]);
    ans += int_x2 * int_y2;

    ans = (area1 + area2) - ans;

    WriteOut("billboard.out", ans);
}