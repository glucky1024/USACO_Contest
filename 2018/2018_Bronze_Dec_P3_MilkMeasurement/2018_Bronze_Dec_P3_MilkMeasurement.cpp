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


bool ReadInFile(const string& sFile, vector<pair<int, int>>& sus)
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
    vector<int> order;
    vector<pair<int, int>> nameChange;

    for (int i = 0; i < nDays; ++i)
    {
        int temp = 0, change = 0, realname = 0;
        string name;
        in >> temp >> name >> change;

        order.push_back(temp);

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

    vector<pair<int, int>> present;

    for (int i = 0; i < nDays; ++i) {
        present.push_back(make_pair(order[i], i));
    }

    sort(present.begin(), present.end());

    for (int i = 0; i < nDays; i++)
    {
        sus.push_back(std::make_pair(nameChange[present[i].second].first, nameChange[present[i].second].second));
    }

    return true;
}

void Print(const vector<pair<int, int>> sus)
{
    cout << sus.size() << endl;

    for (int i = 0; i < sus.size(); i++)
    {
        cout << sus[i].first << " " << sus[i].second << endl;
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

bool updated(vector<pair<int, int>> rates, int& prevMaxi, int& prevLead, int& prevCnt)
{
    int maxi = 0, leader = 0, cnt = 0;

    for (int i = 0; i < 3; i++)
    {
        if (maxi < rates[i].second)
        {
            maxi = rates[i].second;
            leader = i;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (maxi == rates[i].second)
        {
            cnt++;
        }
    }

    if (leader != prevLead || cnt != prevCnt)
    {
        prevCnt = cnt;
        prevMaxi = maxi;
        prevLead = leader;
        return true;
    }

    return false;
}

int main()
{
    vector<pair<int, int>> sus;
    int prevLead = 5, prevMaxi = 0, prevCnt = 0;

    bool bOk = ReadInFile("measurement.in", sus);
    //Print(sus);

    int changes = 0, nDays = sus.size();
    vector<pair<int, int>> rates;

    for (int i = 0; i < 3; i++)
    {
        rates.push_back(std::make_pair(i, 7));
    }

    for (int i = 0; i < nDays; i++)
    {
        if (sus[i].first == 0)
        {
            rates[0].second += sus[i].second;
        }

        else if (sus[i].first == 1)
        {
            rates[1].second += sus[i].second;
        }
        else
        {
            rates[2].second += sus[i].second;
        }

        if (updated(rates, prevMaxi, prevLead, prevCnt))
        {
            changes++;
        }
    }

    WriteOut("measurement.out", changes);
}