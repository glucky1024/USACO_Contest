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
#include <stack>

using namespace std;

bool ReadInFile(const string& sFile, long long& M, string& passes, vector<long long>& caps)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nCows = 0;

    in >> nCows >> M >> passes;

    for (int i = 0; i < nCows; i++)
    {
        int temp1 = 0;
        in >> temp1;

        caps.push_back(temp1);
    }

    return true;
}

bool ReadInCout(long long& M, string& passes, vector<long long>& caps)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows = 0;
    cin >> nCows >> M >> passes;

    for (int i = 0; i < nCows; i++)
    {
        int temp1 = 0;
        cin >> temp1;

        caps.push_back(temp1);
    }

    return true;
}

void Print(long long M, const string& passes, const vector<long long>& caps)
{
    cout << caps.size() << " " << M << endl;
    cout << passes << endl;

    for (int i = 0; i < caps.size(); i++)
    {
        cout << caps[i] << " ";
    }
    cout << endl;
}

void WriteOut(const string& sFile)
{
    //cout <<  << endl;

    //ofstream out_file;
    //out_file.open(sFile);
    //out_file << a << " " << d << endl;

    //out_file.close();
}

int main()
{
    long long M = 0;
    string passes;
    vector<long long> caps;

    //ReadInFile("../P2_3.in", M, passes, caps);
    //Print(M, passes, caps);
    ReadInCout(M, passes, caps);

    int N = caps.size();
    vector<long long> cur = caps;
    vector<int> loseCows;
    //for (int i = 0; i < N; i++)
    //{
    //    string sL, sR;
    //    if (i == 0) {
    //        sL = passes.substr(N - 1, 1);
    //        sR = passes.substr(i + 1, 1);
    //    }
    //    else if (i == N - 1) {
    //        sL = passes.substr(i - 1, 1);
    //        sR = passes.substr(0, 1);
    //    }
    //    else {
    //        sL = passes.substr(i - 1, 1);
    //        sR = passes.substr(i + 1, 1);
    //    }
    //    
    //    if (sL == "L" && sR == "R")
    //        loseCows.push_back(i);
    //}

    //long long lost = 0;
    //for (long long t = 0; t < M; ++t)
    //{
    //    for (int i = 0; i < loseCows.size(); ++i) 
    //    {
    //        int idx = loseCows[i];
    //        if (cur[idx] > 0)
    //            cur[idx]--;
    //        lost++;
    //    }
    //}

    //long long total = 0;
    //for (long long l : caps) {
    //    total += l;
    //}
    //cout << total - lost << endl;

    //long long sum = 0;
    //for (int i = 0; i < N; i++)
    //{
    //    sum += cur[i];
    //}
    //cout << sum << endl;


    for (long long t = 0; t < M; ++t)
    {
        for (int i = 0; i < N; i++)
        {
            if (cur[i] == 0)
                continue;

            string s = passes.substr(i, 1);
            if (s == "L")
            {
                cur[i] -= 1;
                if (i == 0)
                    cur[N - 1] += 1;
                else
                    cur[i - 1] += 1;
            }
            else if (s == "R")
            {
                cur[i] -= 1;
                if (i == N - 1)
                    cur[0] += 1;
                else
                    cur[i + 1] += 1;
            }
            else {
                assert(0);
                continue;
            }
        }

        for (int i = 0; i < N; i++)
        {
            cur[i] = min(cur[i], caps[i]);
        }
    }

    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += cur[i];
    }

    cout << sum << endl;

}
