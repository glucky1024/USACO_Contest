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


bool ReadInFile(const string& sFile, vector<pair<int, int>>& nameChange)
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

void Print(const vector<pair<int, int>> nameChange)
{
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
    vector<pair<int, int>> nameChange;
    int prevLead = 5;

    bool bOk = ReadInFile("../measurement_bronze_dec17/1.in", nameChange);
    //Print(nameChange);


    WriteOut("measurement.out", changes);
}