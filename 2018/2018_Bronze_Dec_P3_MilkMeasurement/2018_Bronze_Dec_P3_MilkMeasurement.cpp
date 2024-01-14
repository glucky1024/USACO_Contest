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


bool ReadInFile(const string& sFile, vector<pair<int, int>>& nameChange)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nDays = 0;
    in >> nDays;

    for (int i = 0; i < nDays; ++i)
    {
        int temp = 0, change = 0, realname = 0;
        string name;
        in >> temp >> name >> change;

        if (name == "Bessie")
        {
            realname = 0;
        }

        else if (name == "Elsie")
        {
            realname = 1;
        }

        else
        {
            realname = 2;
        }

        nameChange.push_back(std::make_pair(realname, change));
    }

    return true;
}

void Print(const vector<pair<int, int>> nameChange)
{
    cout << nameChange.size() << endl;

    for (int i = 0; i < nameChange.size(); i++)
    {
        cout << nameChange[i].first << " " << nameChange[i].second << endl;
    }

    cout << endl;
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

bool updated(vector<pair<int, int>> nameChange, vector<pair<int, int>> rates, int& prevLead)
{
    int maxi = 0, leader = 5;

    for (int i = 0; i < 3; i++)
    {
        if (maxi < rates[i].second)
        {
            leader = i;
        }
    }

    if (leader != prevLead)
    {
        prevLead = leader;
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (maxi == rates[i].second && rates[i].second != prevLead)
        {
            prevLead = leader;
            return true;
        }
    }


    return false;
}

int main()
{
    vector<pair<int, int>> nameChange;
    int prevLead = 5;

    bool bOk = ReadInFile("../measurement_bronze_dec17/1.in", nameChange);
    //Print(nameChange);

    int changes = 0, nDays = nameChange.size();
    vector<pair<int, int>> rates;

    for (int i = 0; i < 3; i++)
    {
        rates.push_back(std::make_pair(i, 7));
    }

    for (int i = 0; i < nDays; i++)
    {
        if (nameChange[i].first == 0)
        {
            rates[0].second += nameChange[i].second;
        }

        else if (nameChange[i].first == 1)
        {
            rates[1].second += nameChange[i].second;
        }
        else
        {
            rates[2].second += nameChange[i].second;
        }

        if (updated(nameChange, rates, prevLead))
        {
            changes++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << rates[i].first << " " << rates[i].second << endl;
    }

    WriteOut("measurement.out", changes);
}