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

bool ReadInFile(const string& sFile, vector<int>& Nums)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    for (int i = 0; i < 7; i++)
    {
        int temp = 0;
        in >> temp;
        Nums.push_back(temp);
    }

    return true;
}

bool ReadInCout(vector<int>& Nums)
{
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < 7; i++)
    {
        int temp = 0;
        cin >> temp;
        Nums.push_back(temp);
    }

    return true;
}

void Print(const vector<int>& Nums)
{
    for (int i = 0; i < 7; i++)
    {
        cout << Nums[i] << " ";
    }
}

int main()
{
    vector<int> Nums;

    //bool bOk = ReadInFile("../prob1_bronze_dec20/1.in", Nums);
    //Print(Nums);

    bool bOk = ReadInCout(Nums);
    if (!bOk) { return 0; }

    //code!

    sort(Nums.begin(), Nums.end());

    int a = 0; int b = 0; int c = 0;
    a = Nums[0];
    b = Nums[1];
    c = (Nums[6]) - (a + b);

    cout << a << " " << b << " " << c;
}