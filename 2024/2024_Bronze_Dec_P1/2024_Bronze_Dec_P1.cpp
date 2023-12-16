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

bool ReadInFile(const string& sFile)
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
            int o = 0;
            in_file >> s >> o;
            in.push_back(s);
            out.push_back(o);
        }

        //CTest* pTest = new CTest(nLength, nLines, in, out);
        //tests.push_back(pTest);
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

void Print(int n)
{

}

void WriteOut(const string& sFile, int )
{
    //cout <<  << endl;

    //ofstream out_file;
    //out_file.open(sFile);
    //out_file << a << " " << d << endl;

    //out_file.close();
}

int main()
{


    return 1;
}