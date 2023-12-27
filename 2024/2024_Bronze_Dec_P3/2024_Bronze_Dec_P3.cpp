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

bool ReadInFile(const string& sFile)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nTests = 0;
    in >> nTests;
    //cout << nTests << endl;

    for (int i = 0; i < nTests; i++)
    {
        int nPlants = 0;
        in >> nPlants;

        vector<long long> initHs;
        for (int j = 0; j < nPlants; ++j) {
            long long h = 0;
            in >> h;
            initHs.push_back(h);
        }

        vector<long long> a;
        for (int j = 0; j < nPlants; ++j) {
            long long h = 0;
            in >> h;
            a.push_back(h);
        }

        vector<int> t;
        for (int j = 0; j < nPlants; ++j) {
            int h = 0;
            in >> h;
            t.push_back(h);
        }

        vector<pair<long long, int> > vp;
        for (int i = 0; i < nPlants; ++i) {
            vp.push_back(make_pair(t[i], i));
        }
        sort(vp.begin(), vp.end());


        int day = 0;
        int nDays = -1;
        int ind_min = vp.front().second;
        int ind_max = vp.back().second;
        long long old_dist = 1000000;
        while (true)
        {
            vector<long long> Hs;
            Hs.resize(nPlants);
            for (int p = 0; p < nPlants; ++p) {
                Hs[p] = initHs[p] + a[p] * day;
            }

            bool match = true;
            for (int p = 0; p < nPlants - 1; ++p)
            {
                int ind = vp[p].second;
                int ind2 = vp[p + 1].second;
                if (Hs[ind] <= Hs[ind2]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                nDays = day;
                break;
            }
            else {
                long long dist_new = Hs[ind_max] - Hs[ind_min];
                if (dist_new > old_dist) {
                    nDays = -1;
                    break;
                }
                else {
                    old_dist = dist_new;
                }
            }

            day++;
        }

        cout << nDays << endl;
    }

    return true;
}

bool ReadInCout()
{
    ios::sync_with_stdio(0); cin.tie(0);


    int nTests = 0;
    cin >> nTests;
    //cout << nTests << endl;

    for (int i = 0; i < nTests; i++)
    {
        int nPlants = 0;
        cin >> nPlants;

        vector<long long> initHs;
        for (int j = 0; j < nPlants; ++j) {
            long long h = 0;
            cin >> h;
            initHs.push_back(h);
        }

        vector<long long> a;
        for (int j = 0; j < nPlants; ++j) {
            long long h = 0;
            cin >> h;
            a.push_back(h);
        }

        vector<int> t;
        for (int j = 0; j < nPlants; ++j) {
            int h = 0;
            cin >> h;
            t.push_back(h);
        }

        vector<pair<long long, int> > vp;
        for (int i = 0; i < nPlants; ++i) {
            vp.push_back(make_pair(t[i], i));
        }
        sort(vp.begin(), vp.end());

        int day = 0;
        int nDays = -1;
        int ind_min = vp.front().second;
        int ind_max = vp.back().second;
        long long old_dist = 1000000;
        bool possible = true;
        while (day < 1000)
        {
            vector<long long> Hs;
            Hs.resize(nPlants);
            for (int p = 0; p < nPlants; ++p) {
                Hs[p] = initHs[p] + a[p] * day;
            }

            bool match = true;
            for (int p = 0; p < nPlants - 1; ++p)
            {
                int ind = vp[p].second;
                int ind2 = vp[p + 1].second;
                if (Hs[ind] <= Hs[ind2]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                nDays = day;
                break;
            }
            else {
                //long long dist_new = Hs[ind_max] - Hs[ind_min];
                //if (dist_new >= old_dist) {
                //    possible = false;
                //    nDays = -1;
                //}
                //else {
                //    old_dist = dist_new;
                //}
                nDays = -1;
            }

            day++;
        }

        cout << nDays << endl;
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
    ReadInFile("1.in");
    //Print(infects);

    //ReadInCout();




    return 1;
}