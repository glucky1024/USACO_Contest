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

bool ReadInFile(const string& sFile, vector<int>& bills, vector<int>& trucks)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }



    return true;
}

void Print(const vector<int> bills, const vector<int> trucks)
{
 
}

bool WriteOut(const string& sFile, const int ans)
{
    cout << ans;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << ans << endl;

    out_file.close();

    return true;
}

int main()
{

    bool bOk = ReadInFile("../billboard_bronze_dec17/1.in", bills, trucks);
    //Print(bills, trucks);

    WriteOut("backforth.out", ans);
}