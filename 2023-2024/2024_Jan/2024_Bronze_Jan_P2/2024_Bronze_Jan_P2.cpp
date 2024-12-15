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

bool ReadInFile(const string& sFile, int& start, vector<pair<int, int>>& theMap)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int n = 0;
    in >> n >> start;

    for (int i = 0; i < n; i++)
    {
        int q = 0, v = 0;
        in >> q >> v;
        theMap.push_back(make_pair(q, v));
    }

    return true;
}

void Print()
{
    cout << endl;
}

bool ReadInCout(int& start, vector<pair<int, int>>& theMap)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 0;
    cin >> n >> start;

    for (int i = 0; i < n; i++)
    {
        int q = 0, v = 0;
        cin >> q >> v;
        theMap.push_back(make_pair(q, v));
    }

    return true;
}


bool WriteOut(const string& sFile, const int& ans)
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
    vector<pair<int, int>> theMap;
    int start = 0;

    //bool bOk = ReadInFile("2.in", start, theMap);
    ReadInCout(start, theMap);
    //Print();

    int curSpot = start - 1;
    int speed = 1;
    int total = 0;
    long long cnt = 0;
    int direction = 1; //true is right, false is left
    vector<bool> vis(theMap.size()); 
    fill(vis.begin(), vis.end(), false);

    while (curSpot >= 1 && curSpot <= theMap.size() && cnt != 200000000)
    {
        if (theMap[curSpot].first == 0)
        {
            speed += theMap[curSpot].second;
            direction *= -1;
        }

        else if (!vis[curSpot] && theMap[curSpot].second <= speed)
        {
            vis[curSpot] = true;
            total++;
        }

        curSpot += speed * direction;
        cnt++;
    }

    cout << total << endl;
}