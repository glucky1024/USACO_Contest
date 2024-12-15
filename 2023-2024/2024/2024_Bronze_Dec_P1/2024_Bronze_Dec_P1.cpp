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

typedef long long ll;

using namespace std;

bool ReadInFile(const string& sFile, vector<ll>& cows, vector<ll>& hCane)
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

    int m = 0;
    in >> m;

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        in >> x;
        cows.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x = 0;
        in >> x;
        hCane.push_back(x);
    }

    return true;
}

bool ReadInCout(vector<ll>& cows, vector<ll>& hCane)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 0;
    cin >> n;

    int m = 0;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        cows.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x = 0;
        cin >> x;
        hCane.push_back(x);
    }

    return true;
}

void Print(vector<ll> cows, vector<ll> hCanes)
{
    cout << cows.size() << " " << hCanes.size() << endl;

    for (int i = 0; i < cows.size(); i++)
    {
        cout << cows[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < hCanes.size(); i++)
    {
        cout << hCanes[i] << " ";
    }
    cout << endl;
}

void WriteOut(const string& sFile, vector<int> cows)
{
    //ofstream out_file;
    //out_file.open(sFile);

    //out_file.close();
}

void eating(ll hCane, vector<ll>& cows)
{
    int gone = 0;
    int total = hCane;

    for (int i = 0; hCane > 0 && i < cows.size(); i++)
    {
        if (gone < cows[i])
        {
            int ate = min(cows[i], ll(total)) - gone;

            cows[i] += ate;
            hCane -= ate;
            gone += ate;
        }
    }
}

int main()
{
    vector<ll> cows;
    vector<ll> hCanes;
    ReadInCout(cows, hCanes);
    //ReadInFile("prob1_bronze_dec23/2.in", cows, hCanes);
    //Print(cows, hCanes);
    //ReadInCout();

    for (int i = 0; i < hCanes.size(); i++)
    {
        eating(hCanes[i], cows);
    }

    for (int i = 0; i < cows.size(); i++)
    {
        cout << cows[i] << endl;
    }
}