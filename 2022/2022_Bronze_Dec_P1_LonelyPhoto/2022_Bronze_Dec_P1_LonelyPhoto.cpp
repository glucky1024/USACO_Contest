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

bool ReadInFile(const string& sFile, vector<string>& cowsinLine)
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
        string temp = s.substr(i, 1);
        cowsinLine.push_back(temp);
    }

    return true;
}

bool ReadInCout(vector<string>& cowsinLine)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows = 0;
    cin >> nCows;

    string s;
    cin >> s;

    if (nCows != s.size()) { assert(0); return false; }

    for (int i = 0; i < nCows; i++)
    {
        string temp = s.substr(i, 1);
        cowsinLine.push_back(temp);
    }

    return true;
}

void Print(const vector<string> cowsinLine)
{
    cout << cowsinLine.size() << endl;

    for (int i = 0; i < cowsinLine.size(); i++)
    {
        cout << cowsinLine[i];
    }

    cout << endl;
}

bool LonelyPic(int range, int start, vector<string> cowsinLine)
{
    int cntG = 0; int cntH = 0;
    for (int i = start; i < range + start; i++)
    {
        if (cowsinLine[i] == "G")
        {
            cntG++;
        }

        else
        {
            cntH++;
        }
    }

    if (cntG == 1 || cntH == 1)
    {
        return true;
    }

    else
    {
        return false;
    }

}

int main()
{
    vector<string> cowsinLine;
    //bool bOk = ReadInFile("../prob1_bronze_dec21/1.in", cowsinLine);
    //Print(cowsinLine);

    bool bOk = ReadInCout(cowsinLine);
    if (!bOk) { return 0; }

    //code !
    int cnt = 0; 

    for (int i = 0; i < cowsinLine.size(); i++)
    {
        int cntG = 0; int cntH = 0;
        for (int j = i; j < cowsinLine.size(); j++)
        {
            if (cowsinLine[j] == "G")
            {
                cntG++;
            }

            else
            {
                cntH++;
            }

            if ((cntG == 1 || cntH == 1) && ((cntG + cntH) >= 3))
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}