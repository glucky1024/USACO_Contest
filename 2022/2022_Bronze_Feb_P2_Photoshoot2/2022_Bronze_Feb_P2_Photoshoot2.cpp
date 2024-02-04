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

bool ReadInFile(const string& sFile, vector<int>& curr, vector<int>& want, vector<int>& a)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int n;
    in >> n;

    for (int i = 0; i < n; i++)
    {
        int temp1;
        in >> temp1;

        curr.push_back(temp1);
        a.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        int temp1;
        in >> temp1;

        want.push_back(temp1);
    }

    return true;
}

void Print(const vector<int> curr, const vector<int>& want)
{
    cout << want.size() << endl;

    for (int i = 0; i < want.size(); i++)
    {
        cout << curr[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < want.size(); i++)
    {
        cout << want[i] << " ";
    }

    cout << endl;

}

bool ReadInCout(vector<int>& curr, vector<int>& want)
{
    ios::sync_with_stdio(0); cin.tie(0);              

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp1;
        cin >> temp1;

        curr.push_back(temp1);
    }

    for (int i = 0; i < n; i++)
    {
        int temp1;
        cin >> temp1;

        want.push_back(temp1);
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
    vector<int> curr, want, idxA;

    bool bOk = ReadInFile("../prob2_bronze_feb22/2.in", curr, want, idxA);
    //ReadInCout(curr, want, idxA);
    //Print(curr, want);

    int currIdx = 0;
    int moved[100010];
    int cnt = 0;

    for (int i = 0; i < curr.size(); i++)
    {
        while (moved[currIdx]) currIdx++;

        if (curr[currIdx] == want[i])
        {
            currIdx++;
        }

        else
        {
            moved[idxA[want[i]]] = true;
            cnt++;
        }
    }

    cout << cnt << endl;

    //WriteOut("marathon.out", ans);
}