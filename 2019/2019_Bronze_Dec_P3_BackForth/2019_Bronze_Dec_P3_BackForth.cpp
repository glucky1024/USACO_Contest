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

int possible_ans[2000];

bool ReadInFile(const string& sFile, vector<int>& aBuckets, vector<int>& bBuckets)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        int temp = 0;
        in >> temp;
        aBuckets.push_back(temp);
    }

    for (int i = 0; i < 10; i++)
    {
        int c = 0;
        in >> c;
        bBuckets.push_back(c);
    }

    return true;
}

void Print(const vector<int> aBuckets, const vector<int> bBuckets)
{
    for (int i = 0; i < 10; i++)
    {
        cout << aBuckets[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << bBuckets[i] << " ";
    }

    cout << endl;
}

bool WriteOut(const string& sFile, const int ans)
{
    cout << ans;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << ans << endl;

    out_file.close();

    return true;
}

void Fri(int aMilk, vector<int> aBuckets, vector<int> bBuckets)
{
    for (int i = 0; i < 10; i++)
    {
        int x = bBuckets[i];
        possible_ans[aMilk + x] = 1;
        //as you can see, you do not have to worry about double counting
        //because 1 will not increase
        // once it's found, it's found forever!
    }
}

void Thur(int aMilk, vector<int> aBuckets, vector<int> bBuckets)
{
    for (int i = 0; i < 10; i++)
    {
        int x = aBuckets[i];
        vector<int> new_bBuckets = bBuckets;
        new_bBuckets.push_back(x);

        vector<int> new_aBuckets = aBuckets;
        new_aBuckets.erase(new_aBuckets.begin() + i);

        Fri(aMilk - x, new_aBuckets, new_bBuckets);
    }
}

void Wed(int aMilk, vector<int> aBuckets, vector<int> bBuckets)
{
    for (int i = 0; i < 10; i++)
    {
        int x = bBuckets[i];
        vector<int> new_aBuckets = aBuckets;
        new_aBuckets.push_back(x);

        vector<int> new_bBuckets = bBuckets;
        new_bBuckets.erase(new_bBuckets.begin() + i);

        Thur(aMilk + x, new_aBuckets, new_bBuckets);
    }
}

void Tue(int aMilk, vector<int> aBuckets, vector<int> bBuckets)
{
    for (int i = 0; i < 10; i++)
    {
        int x = aBuckets[i];
        vector<int> new_bBuckets = bBuckets;
        new_bBuckets.push_back(x);

        vector<int> new_aBuckets = aBuckets;
        new_aBuckets.erase(new_aBuckets.begin() + i);

        Wed(aMilk - x, new_aBuckets, new_bBuckets);
    }
}

int main()
{
    vector<int> aBuckets;
    vector<int> bBuckets;

    bool bOk = ReadInFile("backforth.in", aBuckets, bBuckets);
    Print(aBuckets, bBuckets);

    int ans = 0;

    Tue(1000, aBuckets, bBuckets);

    for (int i = 0; i < 2000; i++)
    {
        ans += possible_ans[i];
    }

    WriteOut("backforth.out", ans);
}