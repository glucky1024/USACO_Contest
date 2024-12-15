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
#include <set>
#include <map>

using namespace std;

bool ReadInFile(const string& sFile)
{
    fstream in;
    in.open("1.in", ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    return true;
}

void Print()
{


    cout << endl;
}

bool ReadInCout()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    //cin >> n >> nDays;

    //for (int i = 0; i < n; i++)
    //{
    //    int temp1, temp2;
    //    cin >> temp1 >> temp2;
    //    dayAmt.push_back(std::make_pair(temp1, temp2));
    //}

    return true;
}

int main()
{
    vector<pair<int, int>> theMap;
    int start = 0;

    //bool bOk = ReadInFile("2.in", start, theMap);
    ReadInCout();
    //Print();


    return 0;
}
