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

bool ReadInFile(const string& sFile, int& start, vector<int>& types, vector<int>& powers)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    types.clear();
    powers.clear();

    int nLong;
    in >> nLong >> start;

    for (int i = 0; i < nLong; i++)
    {
        int temp1, temp2;
        in >> temp1 >> temp2;

        types.push_back(temp1);
        powers.push_back(temp2);
    }

    return true;
}

void Print(const int start, const vector<int> types, const vector<int> powers)
{
    cout << types.size() << " " << start << endl;

    for (int i = 0; i < types.size(); i++)
    {
        cout << types[i] << " " << powers[i] << endl;
    }

    cout << endl;
}

bool ReadInCout(long long& start, vector<int>& types, vector<int>& powers)
{
    ios::sync_with_stdio(0); cin.tie(0);

    types.clear();
    powers.clear();

    long long nLong;
    cin >> nLong >> start;

    for (long long i = 0; i < nLong; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        types.push_back(temp1);
        powers.push_back(temp2);
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
    long long start = 0;
    vector<int> types, powers;
    long long ans = 0;

    //bool bOk = ReadInFile("test2.in", start, types, powers);
    ReadInCout(start, types, powers);
    //Print(start, types, powers);

    int curPower = 1;
    vector<bool> landed;
    landed.resize(types.size());
    long long rend = types.size();
    bool goRight = true;
    long long count = 0;
    while (count < 1e6)
    {
        long long idx = start - 1;
        if (types[idx] == 0)
        {
            curPower += powers[idx];
            goRight = !goRight;
        }
        else
        {
            if (!landed[idx])
            {
                if (curPower >= powers[idx])
                {
                    ans++;
                    landed[idx] = true;
                }
            }
        }

        start = goRight ? start + curPower : start - curPower;
        if (start > rend || start < 1) {
            break;
        }
        count++;
    }

    WriteOut("marathon.out", ans);
}