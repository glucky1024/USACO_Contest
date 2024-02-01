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

bool ReadInFile(const string& sFile, vector<int>& dice1, vector<int>& dice2)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    dice1.clear();
    dice2.clear();

    int nCows;
    in >> nCows;

    return true;
}

void Print(const vector<int> hayOrder)
{
    cout << hayOrder.size() << endl;

    for (int i = 0; i < hayOrder.size(); i++)
    {
        cout << hayOrder[i] << " ";
    }

    cout << endl;
}

bool ReadInCout(vector<int>& dice1, vector<int>& dice2)
{
    ios::sync_with_stdio(0); cin.tie(0);

    dice1.clear();
    dice2.clear();

    int nCows;
    cin >> nCows;

    return true;
}


bool WriteOut(const string& sFile, const vector<int> ans)
{
    if (ans.size() == 0)
    {
        cout << -1;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //
    ofstream out_file;
    out_file.open(sFile);

    for (int i = 0; i < ans.size(); i++)
    {
        out_file << ans[i] << " ";
    }
    cout << endl;


    out_file.close();

    return true;
}


int main()
{
    // bool bOk = ReadInFile("test.in", );
    //ReadInCout(t, dice1, dice2);

    string sFile = "test.in";
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    vector<int> ans;
    vector<pair<int, int>> place;

    int t;
    in >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> hays;
        ans.clear();
        place = { {0,0},{0,0},{0,0} };

        int nCows = 0;
        in >> nCows;
        for (int j = 0; j < nCows; j++)
        {
            int temp1 = 0;
            in >> temp1;

            hays.push_back(temp1);
        }
        //Print(hays);

        if (hays.size() == 2)
        {
            if (hays[0] == hays[1])
            {
                cout << hays[0] << endl;
            }

            else
            {
                cout << -1 << endl;
            }
        }

        for (int j = 0; j < hays.size() - 3; j++)
        {
            for (int k = j; k < j + 3; k++)
            {
                int lols = 0;

                bool found = false;
                for (int p = 0; p < 3; p++)
                {
                    if (hays[k] == place[p].first)
                    {
                        place[p].second++;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    place[lols] = std::make_pair(hays[k], 2);
                    lols++;
                }
            }

            for (int k = 0; k < place.size(); k++)
            {
                if (place[k].second == 2)
                {
                    ans.push_back(place[k].first);
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());
        WriteOut("marathon.out", ans);
    }


    //std::map<int, int> mapMax;
    //int cur = 0;
    //int old = hays[0];
    //int count = -1;
    //for (int j = 0; j < hays.size(); j++)
    //{
    //    cur = hays[j];
    //    if (cur == old) {
    //        count++;
    //    }
    //    else {
    //        old = cur;
    //        mapMax[old] = count;
    //    }
    //}

    //int iMax = -1;
    //for (std::map<int, int>::iterator it = mapMax.begin(); it != mapMax.end(); ++it) {
    //    if (it->second > iMax) {
    //        iMax = it->second;
    //    }
    //}

    //std::set<int> types;
    //for (std::map<int, int>::iterator it = mapMax.begin(); it != mapMax.end(); ++it) {
    //    if (it->second == iMax && iMax > 0) {
    //        types.insert(iMax);
    //    }
    //}

    ////for (int r = 3; r <= nCows / 2; ++r)
    ////{

    //for (int j = 0; j < hays.size() - 2; j++)
    //{
    //    int type = -1;
    //    if (hays[j] == hays[j + 1]) {
    //        type = hays[j];
    //        hays[j + 2] = type;
    //    }
    //    else if (hays[j + 1] == hays[j + 2]) {
    //        type = hays[j + 1];
    //        hays[j] = type;
    //    }
    //    else if (hays[j] == hays[j + 2]) {
    //        type = hays[j];
    //        hays[j + 1] = type;
    //    }

    //    if (type > -1)
    //        types.insert(type);
    //}


    //if (types.empty()) {
    //    cout << "-1" << endl;
    //}
    //else
    //{
    //    // Displaying set elements
    //    int c = 0;
    //    for (set<int>::iterator itr = types.begin(); itr != types.end(); itr++)
    //    {
    //        cout << *itr;
    //        c++;
    //        if (c < types.size()) {
    //            cout << " ";
    //        }
    //    }

    //    if (i < t-1)
    //        cout << endl;
    //}


}