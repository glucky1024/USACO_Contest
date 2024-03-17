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

bool ReadInFile(const string& sFile, vector<string>& alph, vector<string>& word)
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

void Print(const vector<string> alph, const vector<string> word)
{


}

bool ReadInCout(vector<string>& alph, vector<string>& word)
{
    ios::sync_with_stdio(0); cin.tie(0);



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
    vector<string> alph, word;

    //bool bOk = ReadInFile("../prob1_bronze_jan21/1.in", alph, word);
    ReadInCout(alph, word);
    //Print(alph, word);


    cout << times << endl;
    //WriteOut("marathon.out", ans);
}