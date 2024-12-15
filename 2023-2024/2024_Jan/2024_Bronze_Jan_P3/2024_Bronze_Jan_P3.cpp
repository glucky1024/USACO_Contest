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
#define ll long long

bool ReadInFile(const string& sFile, vector<ll>& grass)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int n = 0;
    in >> n;

    for (ll i = 0; i < n; i++)
    {
        ll x = 0;
        in >> x;
        grass.push_back(x);
    }

    return true;
}

void Print(const vector<int> patches)
{

}

bool ReadInCout(vector<ll>& grass)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll x = 0;
        cin >> x;
        grass.push_back(x);
    }

    return true;
}


bool WriteOut(const string& sFile, const int& ans)
{
    cout << ans << endl;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << ans << endl;


    out_file.close();

    return true;
}

int main()
{
    vector<ll> grass;
    //bool bOk = ReadInFile("1.in", grass);
    ReadInCout(grass);
    //Print(patches);

    ll cnt = 0;

    for (int i = 0; i < grass.size(); i++)
    {
        ll L = 2;
        ll diff = abs(grass[i] - 0);

        if (grass[i] > 0)
        {
            for (int j = i + 1; j < grass.size(); j++)
            {
                grass[j] -= diff * L;
                L++;
            }
        }
        else if (grass[i] < 0)
        {
            for (int j = i + 1; j < grass.size(); j++)
            {
                grass[j] += diff * L;
                L++;
            }
        }

        cnt += diff;
    }

    cout << cnt << endl;
    return 0;
}