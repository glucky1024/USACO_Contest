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

bool ReadInFile(const string& sFile, vector<bool>& infects)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nCows = 0;
    in >> nCows;

    string s;
    in >> s;
    if (nCows != s.size()) { assert(0); return false; }

    for (int i = 0; i < nCows; i++)
    {
        if (s.substr(i, 1) == "1")
            infects.push_back(true);
        else
            infects.push_back(false);
    }

    return true;
}

bool ReadInCout(vector<bool>& infects)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows = 0;
    cin >> nCows;

    string s;
    cin >> s;
    if (nCows != s.size()) { assert(0); return false; }

    for (int i = 0; i < nCows; i++)
    {
        if (s.substr(i, 1) == "1")
            infects.push_back(true);
        else
            infects.push_back(false);
    }

    return true;
}

void Print(const vector<bool>& infects)
{
    cout << infects.size() << endl;

    for (int i = 0; i < infects.size(); i++)
    {
        cout << infects[i] ? 1 : 0;
    }
    cout << endl;
}

void WriteOut(const string& sFile, int)
{
    //cout <<  << endl;

    //ofstream out_file;
    //out_file.open(sFile);
    //out_file << a << " " << d << endl;

    //out_file.close();
}

int main()
{
    vector<bool> inf;
    //ReadInFile("2.in", inf);
    //Print(inf);
    ReadInCout(inf);

    //
    unsigned int n = inf.size();

    bool conflict = false;
    while (true)
    {
        vector<bool> inf_prev;
        for (unsigned int i = 0; i < n; ++i)
            inf_prev.push_back(false);

        for (unsigned int i = 1; i < n - 1; ++i) {
            if (inf[i] && inf[i - 1] && inf[i + 1])
                inf_prev[i] = true;
        }

        for (unsigned int i = 0; i < n; ++i) {
            if (inf[i] == false) {
                if (inf_prev[i])
                    inf_prev[i] = false;
                if (i > 0 && inf_prev[i - 1])
                    inf_prev[i - 1] = false;
                if (i < n - 1 && inf_prev[i + 1])
                    inf_prev[i + 1] = false;
            }
        }

        //check 1
        bool hasOne = false;
        for (unsigned int i = 0; i < n; ++i) {
            if (inf_prev[i]) {
                hasOne = true;
                if (!inf[i] || (i > 0 && !inf[i - 1]) || (i < n - 1 && !inf[i + 1])) {
                    conflict = true;
                    break;
                }
            }
        }

        if (conflict || !hasOne) {
            break;
        }
        else {
            inf = inf_prev;
        }
    }

    int count = 0;
    for (bool b : inf)
        if (b)
            count++;

    cout << count << endl;


    return 1;
}