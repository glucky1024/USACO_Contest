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

bool ReadInFile(const string& sFile, int& constRate, vector<long long>& day)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int n =0;
    in >> n >> constRate;

    for (int i = 0; i < n; i++)
    {
        long long temp1 =0;
        in >> temp1;

        day.push_back(temp1);
    }

    return true;
}

void Print(const int constRate, const vector<long long> day)
{
    cout << day.size() << " " << constRate << endl;

    for (int i = 0; i < day.size(); i++)
    {
        cout << day[i] << " ";
    }
}

bool ReadInCout(int& constRate, vector<long long>& day)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 0;
    cin >> n >> constRate;

    for (int i = 0; i < n; i++)
    {
        long long temp1 = 0;
        cin >> temp1;

        day.push_back(temp1);
    }

    return true;
}


bool WriteOut(const string& sFile, const long long ans)
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
    vector<long long> day;
    int constRate;

    //bool bOk = ReadInFile("../prob3_bronze_feb23/3.in", constRate, day);
    ReadInCout(constRate, day);
    //Print(constRate, day);

    long long ans = 0;

    for (int i = 0; i < day.size(); i++)
    {
        if (i == 0)
        {
            ans += constRate + 1;
        }

        else
        {
            long long endSub = constRate + 1;
            long long continueSub =day[i] - day[i - 1];

            ans += min(endSub, continueSub);
        }

    }

    WriteOut("marathon.out", ans);
}