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

bool ReadInFile(const string& sFile, vector<int>& patches)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    patches.clear();

    int nPatches;
    in >> nPatches;

    for (int i = 0; i < nPatches; i++)
    {
        int temp1;
        in >> temp1;

        patches.push_back(temp1);
    }

    return true;
}

void Print(const vector<int> patches)
{
    cout << patches.size() << endl;

    for (int i = 0; i < patches.size(); i++)
    {
        cout << patches[i] << " ";
    }

    cout << endl;
}

bool ReadInCout(vector<int>& patches)
{
    ios::sync_with_stdio(0); cin.tie(0);

    patches.clear();

    int nPatches;
    cin >> nPatches;

    for (int i = 0; i < nPatches; i++)
    {
        int temp1;
        cin >> temp1;

        patches.push_back(temp1);
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

bool updatePatches(int power, int nApply, vector<int>& patches)
{
    long long n = patches.size();
    if (power > n || power < -n) {
        assert(0);
        cout << "wrong power value: " << power << endl;
        return false;
    }

    if (power > 0)
    {
        for (long long i = 0; i < power; i++)
        {
            long long idx = n - i - 1;
            patches[idx] += (power - i) * nApply;
        }
    }
    else
    {
        for (long long i = 0; i < abs(power); i++)
        {
            long long idx = n - i - 1;
            patches[idx] += (power + i) * nApply;
        }
    }

    return true;
}

int main()
{
    vector<int> patches;

    //bool bOk = ReadInFile("test2.in", patches);
    ReadInCout(patches);
    //Print(patches);
    //cout << patches.size() << endl;

    int first = patches[0];
    long long n = patches.size();

    bool bInc = false;
    for (long long i = 0; i < n; ++i) {
        if (patches[i] == 0) {
            continue;
        }
        else if (patches[i] > 0) {
            bInc = true;
            break;
        }
        else {
            bInc = false;
            break;
        }
    }


    long long idx = 1;
    int ans = 0;
    while (idx < n)
    {
        int cur = patches[idx];
        if (cur == 0)
            continue;

        int prev = patches[idx - 1];
        if (bInc)
        {
            if (cur == prev + 1) {
                idx++;
                continue;
            }
            else
            {
                int diff = prev - cur + 1;
                int nApply = std::abs(diff);
                if (nApply < 0) {
                    assert(0);
                    cout << "nApply is negative: " << nApply << endl;
                    break;
                }

                int power = diff > 0 ? n - idx : idx - n;

                ans += nApply;
                updatePatches(power, nApply, patches);
            }
        }
        else {
            if (cur == prev - 1) {
                idx++;
                continue;
            }
            else
            {
                int diff = cur - prev + 1;
                int nApply = std::abs(diff);
                if (nApply < 0) {
                    assert(0);
                    cout << "nApply is negative: " << nApply << endl;
                    break;
                }

                int power = diff > 0 ? idx - n : n - idx;
                //int power = idx - n;

                ans += nApply;
                updatePatches(power, nApply, patches);
            }
        }
    }


    for (long long i = 0; i < n; ++i) 
    {
        if (patches[i] == 0) {
            continue;
        }

        int firstNonZero = patches[i];
        ans += std::abs(firstNonZero);
        break;
    }

    cout << ans << endl;
    //WriteOut("marathon.out", ans);

    return 0;
}