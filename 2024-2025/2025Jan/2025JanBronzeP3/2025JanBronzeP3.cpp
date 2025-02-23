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

    return true;
}

int main()
{
    vector<pair<int, int>> theMap;
    int start = 0;

    bool bOk = ReadInFile("1.in");
    //ReadInCout();
    Print();


    return 0;
}
