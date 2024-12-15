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

bool ReadInFile(const string& sFile, vector<int>& closing, vector<int>& times, vector<int>& reqs, vector<int>& S)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nFarm = 0, nQuarry = 0;

    in >> nFarm >> nQuarry;

    for (int i = 0; i < nFarm; i++)
    {
        int temp1 = 0;
        in >> temp1;

        closing.push_back(temp1);
    }

    for (int i = 0; i < nFarm; i++)
    {
        int temp1 = 0;
        in >> temp1;

        times.push_back(temp1);
    }

    for (int i = 0; i < nQuarry; i++)
    {
        int temp1 = 0, temp2 = 0;
        in >> temp1 >> temp2;

        reqs.push_back(temp1);
        S.push_back(temp2);
    }

    return true;
}

bool ReadInCout(vector<int>& closing, vector<int>& times, vector<int>& reqs, vector<int>& S)
{
    ios::sync_with_stdio(0); cin.tie(0);


    int nFarm = 0, nQuarry = 0;

    cin >> nFarm >> nQuarry;

    for (int i = 0; i < nFarm; i++)
    {
        int temp1 = 0;
        cin >> temp1;

        closing.push_back(temp1);
    }

    for (int i = 0; i < nFarm; i++)
    {
        int temp1 = 0;
        cin >> temp1;

        times.push_back(temp1);
    }

    for (int i = 0; i < nQuarry; i++)
    {
        int temp1 = 0, temp2 = 0;
        cin >> temp1 >> temp2;

        reqs.push_back(temp1);
        S.push_back(temp2);
    }

    return true;
}

void Print(vector<int>& closing, vector<int>& times, vector<int>& reqs, vector<int>& S)
{

    cout << closing.size() << " " << reqs.size() << endl;

    for (int i = 0; i < closing.size(); i++)
    {
        cout << closing[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < times.size(); i++)
    {
        cout << times[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < reqs.size(); i++)
    {
        cout << reqs[i] << " " << S[i] << endl;
    }
}

void WriteOut(vector<bool>& ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i])
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    vector<int> c, t, reqs, S, d;
    //ReadInFile("../P3.in", c, t, reqs, S);
    //Print(closing, times, reqs, S);
    ReadInCout(c, t, reqs, S);

    vector<bool> ans;
    int N = c.size();
    int Q = S.size();

    //find the time between them, sort
    for (int i = 0; i < N; i++)
    {
        int dist1 = c[i] - t[i];
        d.push_back(dist1);
    }

    sort(d.begin(), d.end(), greater<int>());

    for (int i = 0; i < Q; i++)
    {
        int curS = S[i];
        int V = reqs[i];
        if (V > Q) {
            ans.push_back(false);
        }
        else
        {
            if (d[V - 1] > curS)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
    }

    //for (int test = 0; test < Q; test++)
    //{
    //    int curS = S[test];
    //    int cnt = 0;
    //    
    //    for (int i = 0; i < N; i++)
    //    {
    //        if (curS + t[i] < c[i])
    //        {
    //            cnt++;
    //        }

    //        if (cnt >= reqs[test]) {
    //            ans.push_back(true);
    //            break;
    //        }
    //    }

    //    if (ans.size() < test + 1)
    //        ans.push_back(false);

    //    //if (cnt >= reqs[test])
    //    //{
    //    //    ans.push_back(true);
    //    //}
    //    //else
    //    //{
    //    //    ans.push_back(false);
    //    //}
    //}

    WriteOut(ans);
}