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
    int _nCows; // 5
    int _nMoves; // 0
    string _sTypes; // GHHGG

public:
    CTest(int c, int m, const string& s)
        : _nCows(c), _nMoves(m), _sTypes(s) {
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
        int nCows = 0, nMoves = 0;
        in_file >> nCows >> nMoves;
        string s;
        in_file >> s;

        CTest* pTest = new CTest(nCows, nMoves, s);
        tests.push_back(pTest);
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

void Print(const vector<CTest*>& tests)
{
    cout << tests.size() << endl;
    for (int i = 0; i < tests.size(); i++)
    {
        CTest* pT = tests[i];
        cout << pT->_nCows << " " << pT->_nMoves << endl;
        cout << pT->_sTypes << endl;
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

void addPatch()
{

}

int main2()
{
    // Step1: read
    vector<CTest*> tests;

    bool bOk = ReadInFile("prob2_bronze_dec22/1.in", tests);
    //bool bOk = ReadInCout(cowMoney);
    if (!bOk) { return 0; }
    //Print(tests);

    for (int i = 0; i < tests.size(); i++)
    {
        CTest* pT = tests[i];
        int nSlots = pT->_sTypes.size();
        int count = 0;
        string sGP;
        for (int j = 0; j < nSlots; ++j)
            sGP += ".";
        for (int j = 0; j < nSlots; ++j)
        {
            bool bFound = false;
            string sCow = pT->_sTypes.substr(j, 1);
            //for (int k = max(0, j - pT->_nMoves); k <= min(nSlots - 1, j + pT->_nMoves); ++k) {
            //    if (sCow == sGP.substr(k, 1)) {
            //        bFound = true;
            //        break;
            //    }
            //}
            for (int k = j + pT->_nMoves; k > j - pT->_nMoves; --k) {
                if (k >= nSlots || k < 0)
                    continue;
                if (sCow == sGP.substr(k, 1)) {
                    bFound = true;
                    break;
                }
            }

            if (!bFound) {
                int pos = min(nSlots - 1- pT->_nMoves, j + pT->_nMoves);
                while (sGP.substr(pos, 1) != ".") {
                    pos--;
                }

                sGP.replace(pos, 1, sCow);
                count++;
            }
        }

        cout << count << endl;
        cout << sGP << endl;
    }
    
    //WriteOut("collegeCows.out", count, );

    for (CTest* t : tests)
        delete t;
    tests.clear();

    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        int k;
        cin >> n >> k;
        string s;
        cin >> s;

        int patchG = -k - 1; // first patch location which does not cover cow 1
        int patchH = -k - 1; // first patch location which does not cover cow 1

        int cnt = 0;
        string ans(n, '.');

        for (int i = 0; i < n; i++) {
            if (s[i] == 'G' && i - patchG > k) {
                // the nearest G patch we placed does not cover cow i
                ++cnt;
                if (i + k >= n) {
                    patchG = i;
                    if (ans[patchG] == 'H') { patchG--; }
                }
                else {
                    patchG = i + k; // place the G patch k away
                }
                ans[patchG] = 'G';
            }
            if (s[i] == 'H' && i - patchH > k) {
                // the nearest H patch we placed does not cover cow i
                ++cnt;
                if (i + k >= n) {
                    patchH = i;
                    if (ans[patchH] == 'G') { patchH--; }
                }
                else {
                    patchH = i + k; // place the H patch k away
                }
                ans[patchH] = 'H';
            }
        }
        cout << cnt << endl << ans << endl;
    }
}