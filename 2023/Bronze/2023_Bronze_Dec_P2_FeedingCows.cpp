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
#include <climits>


using namespace std;

bool ReadInFile(const string& sFile, vector<long>& cowMoney)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    long nCows = 0;
    in_file >> nCows;
    cowMoney.clear();
    for (int i = 0; i < nCows; i++)
    {
        long m = 0;
        in_file >> m;
        cowMoney.push_back(m);
    }

    return true;
}

bool ReadInCout(vector<long>& cowMoney)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows = 0;
    cin >> nCows;
    cowMoney.clear();
    for (int i = 0; i < nCows; i++)
    {
        long m = 0;
        cin >> m;
        cowMoney.push_back(m);
    }

    return true;
}

void Print(const int& nCows, const vector<int>& cowMoney)
{
    cout << nCows << endl;
    for (int i = 0; i < nCows; i++)
    {
        cout << cowMoney[i] << " ";
    }
    cout << endl;
}

void WriteOut(const string& sFile, int a, int d)
{
    cout << a << " " << d << endl;

    //ofstream out_file;
    //out_file.open(sFile);
    //out_file << a << " " << d << endl;

    //out_file.close();
}

int main()
{
    // Step1: read
    vector<long> cowMoney;
    //bool bOk = ReadInFile("prob1_bronze_dec22/1.in", cowMoney);
    bool bOk = ReadInCout(cowMoney);
    if (!bOk) { return 0; }
    //Print(nCows, cowMoney);


    WriteOut("collegeCows.out", amount, dollar);

    return 0;
}
