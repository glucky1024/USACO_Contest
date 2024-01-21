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

bool ReadInFile(const string& sFile, int& nDays, vector<pair<int, int>>& dayAmt)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int n;
    in >> n >> nDays;

    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        in >> temp1 >> temp2;

        dayAmt.push_back(std::make_pair(temp1, temp2));
    }

    return true;
}

void Print(const int nDays, const vector<pair<int, int>> dayAmt)
{
    cout << dayAmt.size() << " " << nDays << endl;

    for (int i = 0; i < dayAmt.size(); i++)
    {
        cout << dayAmt[i].first << " " << dayAmt[i].second << endl;
    }
}

bool ReadInCout(int& nDays, vector<pair<int, int>>& dayAmt)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n >> nDays;

    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        dayAmt.push_back(std::make_pair(temp1, temp2));
    }

    return true;
}


bool WriteOut(const string& sFile, const int ans)
{
    cout << ans << endl;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << ans << endl;

    out_file.close();

    return true;
}

int main()
{
    int nDays = 0;
    vector<pair<int, int>> dayAmt;

    bool bOk = ReadInFile("../prob1_bronze_feb23/2.in", nDays, dayAmt);
    //ReadInCout(nDays, dayAmt);
    //Print(nDays, dayAmt);

    int ans = 0, prevDay = 0, total = 0, remaining =0;

    for (int i = 0; i < dayAmt.size(); i++)
    {
        total += dayAmt[i].second;

        remaining -= dayAmt[i].first - prevDay;
        prevDay = dayAmt[i].first;
        remaining = max(remaining, 0) + dayAmt[i].second;
    }

    ans = total - remaining;

    WriteOut("marathon.out", ans);
}