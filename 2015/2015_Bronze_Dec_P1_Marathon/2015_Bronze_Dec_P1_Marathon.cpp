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


bool ReadInFile(const string& sFile, vector<int>& x, vector<int>& y)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nChecks;
    in >> nChecks;

    for (int i = 0; i < nChecks; i++)
    {
        int temp1, temp2;
        in >> temp1 >> temp2;

        x.push_back(temp1);
        y.push_back(temp2);
    }


    return true;
}

void Print(const vector<int> x, const vector<int> y)
{
    cout << x.size() << endl;
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " " << y[i] << endl;
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

int total(vector<int> x, vector<int> y)
{
    int dist = 0;
    for (int i = 1; i < x.size(); i++)
    {
        dist += abs(x[i] - x[i - 1]);
        dist += abs(y[i] - y[i - 1]);
    }

    return dist;
}


int main()
{
    vector<int> x, y;

    bool bOk = ReadInFile("../marathon_bronze/2.in", x, y);
    //Print(x, y);

    int ans = 0;
    pair<int, int> idk;
    vector<pair<int, int>> each;

    int olddist = total(x, y);

    for (int i = 1; i < x.size(); i++)
    {
        int temp = 0;
        temp += abs(x[i] - x[i - 1]);
        temp += abs(y[i] - y[i - 1]);

        each.push_back(std::make_pair(temp, i));
    }

    //int hm=0, maxi =0;

    //for (int i = 0; i < each.size(); i++)
    //{
    //    if (maxi < each[i].first)
    //    {
    //        maxi =each[i].first;
    //        hm = i;
    //    }
    //}

    idk = make_pair(maxi, hm+1);

    x.erase(x.begin() + idk.second);
    y.erase(y.begin() + idk.second);

    ans = total(x, y);

    WriteOut("marathon.out", ans);
}