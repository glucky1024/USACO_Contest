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

bool ReadInFile(const string& sFile, vector<int>& ids)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nCows;
    in >> nCows;

    for (int i = 0; i < nCows; i++)
    {
        int temp1;
        in >> temp1;

        ids.push_back(temp1);
    }

    return true;
}

void Print(const vector<int> ids)
{
    cout << ids.size() << endl;

    for (int i = 0; i < ids.size(); i++)
    {
        cout << ids[i] << " ";
    }

    cout << endl;
}

bool ReadInCout(vector<int>& ids)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows;
    cin >> nCows;

    for (int i = 0; i < nCows; i++)
    {
        int temp1;
        cin >> temp1;

        ids.push_back(temp1);
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
    vector<int> ids;

    //bool bOk = ReadInFile("../prob2_bronze_jan21/5.in", ids);
    ReadInCout(ids);
    //Print(ids);

    //cnt all odds and evens
    int odds = 0, evens = 0;

    for (int i = 0; i < ids.size(); i++)
    {
        if (ids[i] % 2 == 0)
        {
            evens++;
        }

        else
        {
            odds++;
        }
    }

    //min of the two which is the base
    // 
    // if what's left is odd
    int cnt = 0;

    if (odds > evens)
    {
        cnt = 2 * min(odds, evens);
        odds -= evens;

        while (odds )
        {
            if (odds >= 2)
            {
                cnt++;
                odds-=2;
            }

            else
            {
                break;
            }

            if (odds > 2)
            {
                cnt++;
                odds -= 1;
            }

            else
            {
                break;
            }
        }
    }

    else
    {
        cnt = 2 * min(odds, evens);
        if (evens > odds)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
}