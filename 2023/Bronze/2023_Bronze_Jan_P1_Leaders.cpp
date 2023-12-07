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
        vecE.push_back(ei);
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
        vecE.push_back(ei);
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
    vector<string> vecTypes;
    vector<int> vecE;
    //bool bOk = ReadIn("leaders.in", nCows, vecTypes, vecE);
    bool bOk = ReadIn(nCows, vecTypes, vecE);
    if (!bOk) { return 0; }

    //Print(vecTypes, vecE);

    int nGs = 0, nHs = 0;
    for (string s : vecTypes) {
        if (s == "G")
            nGs++;
        else
            nHs++;
    }

    // step 1
    vector<int> leaders;
    for (int i = 0; i < nCows; ++i) {
        int count = 0;
        string sType = vecTypes[i];
        for (int j = i; j <= vecE[i] - 1; ++j) {
            string sType2 = vecTypes[j];
            if (sType == sType2)
                count++;
        }

        if ((count == nGs && sType == "G") || (count == nHs && sType == "H"))
        {
            leaders.push_back(i);
        }
    }

    // step 2
    vector<pair<int, int>> pairs;
    for (int i = 0; i < nCows; ++i) {
        if (isLeader(i, leaders))
            continue;

        for (int j = i; j < nCows; ++j) {
            string sType2 = vecTypes[j];
            if (isLeader2(j, sType2, leaders, vecTypes))
                pairs.push_back(pair<int, int>(i, j));
        }
    }

    // step 3
    for (int i = 0; i < leaders.size(); ++i) {
        for (int j = i; j < leaders.size(); ++j) {
            if (vecTypes[i] == vecTypes[j])
                continue;

            pairs.push_back(pair<int, int>(i, j));
        }
    }

    // step 4
    vector<pair<int, int>> pairs2;
    for (pair<int, int> p : pairs) {
        int pf = p.first;
        int ps = p.second;
        if (pf > ps) {
            int temp = pf;
            pf = ps;
            ps = temp;
        }
        pairs2.push_back(pair<int, int>(pf, ps));
    }

    // step 5, clean up
    //vector<pair<int, int>> pairs3;
    //for (int i = 0; i < pairs2.size(); ++i) {
    //    int count = 0;
    //    for (int j = i; j < pairs2.size(); ++j) {
    //        if (pairs[i] == pairs[j]) {
    //            count++;
    //        }
    //    }

    //    if (!bFound) {
    //        pairs3.push_back(pairs2[i]);
    //    }
    //}

    WriteOut("leaders.out", pairs2.size());

    return 0;
}
