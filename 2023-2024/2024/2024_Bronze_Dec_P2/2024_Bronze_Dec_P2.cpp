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

bool ReadInFile(const string& sFile, vector<int>& chains, bool& start, bool& end)
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

    string x = "";
    in >> x;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '1')
        {
            cnt++;
        }

        else if (x[i] == '0' && cnt > 0)
        {
            chains.push_back(cnt);
            cnt = 0;
        }
    }

    if (cnt > 0)
    {
        chains.push_back(cnt);
    }

    if (x[0] == '1')
    {
        start = true;
    }

    if (x[x.size() - 1] == '1')
    {
        end = true;
    }

    return true;
}

bool ReadInCout(vector<int>& chains, bool& start, bool& end)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 0;
    cin >> n;

    string x = "";
    cin >> x;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '1')
        {
            cnt++;
        }

        else if (x[i] == '0' && cnt > 0)
        {
            chains.push_back(cnt);
            cnt = 0;
        }
    }

    if (cnt > 0)
    {
        chains.push_back(cnt);
    }

    if (x[0] == '1')
    {
        start = true;
    }

    if (x[x.size() - 1] == '1')
    {
        end = true;
    }

    return true;
}

void Print(vector<int> chains)
{
    for (int i = 0; i < chains.size(); i++)
    {
        cout << chains[i] << endl;
    }
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
    vector<int> chains; bool start = false, end = false;
    int days = 0, minCows = 0;
    //ReadInFile("2.in", chains ,start, end);
    //Print(chains);
    ReadInCout(chains, start, end);

    int mini = INT_MAX;
    int index = 0;

    for (int i = 0; i < chains.size(); i++)
    {
        if (mini > chains[i])
        {
            mini = chains[i];
            index = i;
        }
    }

    if ((index == 0 && start) || (index == chains.size() - 1 && end))
    {
        days = mini - 1;
    }

    else if (mini % 2 == 0)
    {
        days = (mini - 2) / 2;
    }

    else
    {
        days = (mini - 1) / 2;
    }

    // now you have the number of days so find each interval cows

    for (int i = 0; i < chains.size(); i++)
    {
        minCows += ceil(chains[i] / (2.0 * days + 1));
    }

    cout << minCows << endl;
}