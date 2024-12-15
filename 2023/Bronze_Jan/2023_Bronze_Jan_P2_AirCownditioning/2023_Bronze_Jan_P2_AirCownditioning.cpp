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

bool ReadInFile(const string& sFile, vector<int>& startCow, vector<int>& endCow, vector<int>& changeCow,
    vector<int>& startAir, vector<int>& endAir, vector<int>& changeAir, vector<int>& money)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nCows, nAirCons;
    in >> nCows >> nAirCons;

    for (int i = 0; i < nCows; i++)
    {
        int temp1, temp2, temp3;
        in >> temp1 >> temp2 >> temp3;

        startCow.push_back(temp1);
        endCow.push_back(temp2);
        changeCow.push_back(temp3);
    }

    for (int i = 0; i < nAirCons; i++)
    {
        int temp1, temp2, temp3, temp4;
        in >> temp1 >> temp2 >> temp3 >> temp4;

        startAir.push_back(temp1);
        endAir.push_back(temp2);
        changeAir.push_back(temp3);
        money.push_back(temp4);
    }

    return true;
}

void Print(const vector<int> startCow, const vector<int> endCow, const vector<int> changeCow,
    const vector<int> startAir, const vector<int> endAir, const vector<int> changeAir, const vector<int> money)
{
    cout << startCow.size() << " " << money.size() << endl;

    for (int i = 0; i < startCow.size(); i++)
    {
        cout << startCow[i] << " " << endCow[i] << " " << changeCow[i] << endl;
    }

    for (int i = 0; i < money.size(); i++)
    {
        cout << startAir[i] << " " << endAir[i] << " " << changeAir[i] << " " << money[i] << endl;
    }
}

bool ReadInCout(vector<int>& startCow, vector<int>& endCow, vector<int>& changeCow,
    vector<int>& startAir, vector<int>& endAir, vector<int>& changeAir, vector<int>& money)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows, nAirCons;
    cin >> nCows >> nAirCons;

    for (int i = 0; i < nCows; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;

        startCow.push_back(temp1);
        endCow.push_back(temp2);
        changeCow.push_back(temp3);
    }

    for (int i = 0; i < nAirCons; i++)
    {
        int temp1, temp2, temp3, temp4;
        cin >> temp1 >> temp2 >> temp3 >> temp4;

        startAir.push_back(temp1);
        endAir.push_back(temp2);
        changeAir.push_back(temp3);
        money.push_back(temp4);
    }

    return true;
}


bool WriteOut(const string& sFile, const int ans)
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
    vector<int> startCow, endCow, changeCow, startAir, endAir, changeAir, money;

    bool bOk = ReadInFile("../prob2_bronze_jan23/1.in", startCow, endCow, changeCow, startAir, endAir, changeAir, money);
    //ReadInCout(startCow, endCow, changeCow, startAir, endAir, changeAir, money);
    Print(startCow, endCow, changeCow, startAir, endAir, changeAir, money);

    int ans = 0;

    //WriteOut("marathon.out", ans);
}