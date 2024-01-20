/*
PROG: leaders
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

bool ReadIn(const std::string& sFile, int& nCows, vector<string>& vecTypes, vector<int>& vecE)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    vecTypes.clear();
    vecE.clear();

    in_file >> nCows;
    string sLine2;
    in_file >> sLine2;
    for (int i = 0; i < nCows; ++i) {
        string s = sLine2.substr(i, 1);
        vecTypes.push_back(s);
    }

    for (int i = 0; i < nCows; ++i) {
        int ei;
        in_file >> ei;
        vecE.push_back(ei - 1);
    }

    return true;
}

bool ReadIn(int& nCows, vector<string>& vecTypes, vector<int>& vecE)
{
    vecTypes.clear();
    vecE.clear();

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> nCows;
    string sLine2;
    cin >> sLine2;
    for (int i = 0; i < nCows; ++i) {
        string s = sLine2.substr(i, 1);
        vecTypes.push_back(s);
    }

    for (int i = 0; i < nCows; ++i) {
        int ei;
        cin >> ei;
        vecE.push_back(ei-1);
    }

    return true;
}

void Print(const vector<string>& vecTypes, const vector<int>& vecE)
{
    cout << vecTypes.size() << endl;
    for (string s : vecTypes) {
        cout << s;
    }
    cout << endl;

    for (int e : vecE) {
        cout << e;
    }
    cout << endl;
}

void WriteOut(const string& sFile, int nPairs)
{
    cout << nPairs << endl;

    ofstream out_file;
    out_file.open(sFile);
    out_file << nPairs << endl;

    out_file.close();
}

bool isLeader(int i, const vector<int>& leaders)
{
    for (int l : leaders) {
        if (i == l)
            return true;
    }

    return false;
}

bool isLeader2(int id, const string& s, const vector<int>& leaders, const vector<string>& sTypes)
{
    for (int l = 0; l < leaders.size(); ++l) {
        if (leaders[l] == id && sTypes[l] != s)
            return true;
    }

    return false;
}



int main()
{
    int nCows = 0;
    vector<string> s;
    vector<int> arr;
    //bool bOk = ReadIn("prob1_bronze_jan23/1.in", nCows, s, arr);
    bool bOk = ReadIn(nCows, s, arr);
    if (!bOk) { return 0; }
    //Print(vecTypes, vecE);

    // step 1
    int eG = 0, lG=0, eH=0, lH=0;
    int ans =0;

    for (int i = 0; i < nCows; i++)
    {
        if (s[i] == "G")
        {
            eG = i;
            break;
        }
    }

    for (int i = 0; i < nCows; i++)
    {
        if (s[nCows - i - 1] == "G")
        {
            lG = nCows - i - 1;
            break;
        }
    }

    for (int i = 0; i < nCows; i++)
    {
        if (s[i] == "H")
        {
            eH = i;
            break;
        }
    }

    for (int i = 0; i < nCows; i++)
    {
        if (s[nCows - i - 1] == "H")
        {
            lH = nCows - i - 1;
            break;
        }
    }

    // step 2
    if (arr[eG] >= lG)
    {
        for (int i = 0; i < eG; i++)
        {
            if (i == eH) {
                continue;
            }

            if (s[i] == "H" && arr[i] >= eG)
            {
                ans++;
            }
        }
    }

    // step 3
    if (arr[eH] >= lH)
    {
        for (int i = 0; i < eH; i++)
        {
            if (i == eG) {
                continue;
            }

            if (s[i] == "G" && arr[i] >= eH)
            {
                ans++;
            }
        }
    }

    // step 4
    if ((arr[eG] >= lG || (eG < eH && arr[eG] >= eH)) && (arr[eH] >= lH || (eH < eG && arr[eH] >= eG)))
        ans++;

    WriteOut("leaders.out", ans);

    return 0;
}
