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


bool ReadInFile(const string& sFile, vector<pair<int, int>>& limits, vector<pair<int, int>>& cSpeeds)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nStops, cStops;
    in >> nStops >> cStops;
    int cnt = 1, cnt2 = 1;

    for (int i = 0; i < nStops; i++)
    {
        int temp1, temp2;
        in >> temp1 >> temp2;

        for (int j = 0; j < temp1; j++)
        {
            limits.push_back(std::make_pair(cnt, temp2));
            cnt++;
        }
    }

    for (int i = 0; i < cStops; i++)
    {
        int temp1, temp2;
        in >> temp1 >> temp2;

        for (int j = 0; j < temp1; j++)
        {
            cSpeeds.push_back(std::make_pair(cnt2, temp2));
            cnt2++;
        }
    }

    return true;
}

void Print(const vector<pair<int, int>> limits, const vector<pair<int, int>> cSpeeds)
{
    cout << limits.size() << " " << cSpeeds.size() << endl;

    for (int i = 0; i < limits.size(); i++)
    {
        int cnt = 0;
        cout << limits[i].first - cnt << " " << limits[i].second << endl;
        cnt += limits[i].first;
    }

    for (int i = 0; i < cSpeeds.size(); i++)
    {
        int cnt = 0;
        cout << cSpeeds[i].first - cnt << " " << cSpeeds[i].second << endl;
        cnt += cSpeeds[i].first;
    }
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
    vector<pair<int, int>> limits;
    vector<pair<int, int>> cSpeeds;

    bool bOk = ReadInFile("speeding.in", limits, cSpeeds);
    //Print(limits, cSpeeds);

    int ans = 0;
    int maxi = 0;

    for (int i = 0; i < 100; i++)
    {
        if (cSpeeds[i].second > limits[i].second)
        {
            int temp = cSpeeds[i].second - limits[i].second;
            maxi = max(maxi, temp);
        }
    }

    ans = maxi;

    WriteOut("speeding.out", ans);
}