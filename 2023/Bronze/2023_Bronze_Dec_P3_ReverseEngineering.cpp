/*
PROG: feeding the cows
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

class CTest
{
public:
    int _nLength; //1 
    int _nLines;//3
    vector<string> _vecInput; //0, 0, 1
    vector<int> _vecOutput; //0, 0, 1

public:
    CTest(int len, int line, vector<string> in, vector<int> out)
        : _nLength(len), _nLines(line), _vecInput(in), _vecOutput(out) {
    }
};

bool ReadInFile(const string& sFile, vector<CTest*>& tests)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nTests = 0;
    in_file >> nTests;
    for (int i = 0; i < nTests; ++i)
    {
        int nLength = 0, nLines = 0;
        in_file >> nLength >> nLines;
        vector <string> in;
        vector <int> out;

        for (int j = 0; j < nLines; j++)
        {
            string s;
            int o=0;
            in_file >> s >> o;
            in.push_back(s);
            out.push_back(o);
        }

        CTest* pTest = new CTest(nLength, nLines, in, out);
        tests.push_back(pTest);
    }

    return true;
}

//bool ReadInCout(vector<long>& cowMoney)
//{
//    ios::sync_with_stdio(0); cin.tie(0);
//
//    int nCows = 0;
//    cin >> nCows;
//    cowMoney.clear();
//    for (int i = 0; i < nCows; i++)
//    {
//        long m = 0;
//        cin >> m;
//        cowMoney.push_back(m);
//    }
//
//    return true;
//}

void Print(const vector<CTest*>& tests)
{
    cout << tests.size() << endl << endl;
    for (int i = 0; i < tests.size(); i++)
    {
        CTest* pt = tests[i];
        cout << pt->_nLength << " " << pt->_nLines << endl;
        for (int i = 0; i < pt->_nLines; i++)
        {
            cout << pt->_vecInput[i] <<" " << pt->_vecOutput[i] << endl;
        }
        cout << endl;
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
    vector<CTest*> tests;

    bool bOk = ReadInFile("prob3_bronze_dec22/1.in", tests);
    //bool bOk = ReadInCout(cowMoney);
    if (!bOk) { return 0; }
    Print(tests);





    //WriteOut("collegeCows.out", minPatch);

    for (CTest* t : tests)
        delete t;
    tests.clear();

    return 0;
}
