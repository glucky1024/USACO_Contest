/*
PROG: cow college
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>


bool ReadIn(const std::string& sFile, int& nCows, vector<int>& cowMoney)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    in_file >> nCows;

    for (int i = 0; i < nCows; i++)
    {
        in_file >> cowMoney[i];
    }

    return true;
}

bool ReadIn(int& nCows, int& max, vector<int>& cowMoney)
{
    vecTypes.clear();
    vecE.clear();

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> nCows;

    for (int i = 0; i < nCows; i++)
    {
        cin >> cowMoney[i];
        max += cowMoney[i];
    }

    return true;
}

void Print(const int& nCows, const vector<int>& cowMoney)
{
    cout << nCows << endl;
    for (int i = 0; i < nCows; i++)
    {
        cout >> cowMoney[i];
    }
    cout << endl;
}

void WriteOut(const string& sFile, int ans)
{
    cout << nPairs << endl;

    ofstream out_file;
    out_file.open(sFile);
    out_file << ans << endl;

    out_file.close();
}

int main()
{
    int nCows = 0;
    vector<int> cowMoney;
    bool bOk = ReadIn("prob1_bronze_dec22/1.in", nCows, cowMoney);
    //bool bOk = ReadIn(nCows, cowMoney);
    if (!bOk) { return 0; }

    sort(a, a + cowMoney);
    vector<int> total;
    int ans =0;

    for (int i = 1; i < max; i++)
    {
        for (int j = 0; j < nCows; j++)
        {
            if (cowMoney[j] >= i)
            {                  
                total[i] += i;
            }
        }
    }

    for (int i = 1; i < max; i++)
    {
          ans = max(total[i], total[i-1])
    }
      
    WriteOut("collegeCows.out", ans);

    return 0;               
}
