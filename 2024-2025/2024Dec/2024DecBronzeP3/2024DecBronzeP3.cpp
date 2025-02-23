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
#include <set>
#include <map>

using namespace std;

bool ReadInFile(const string& sFile, int& n, int& f, std::string& s)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    in >> n >> f;
    in >> s;

    return true;
}

void Print()
{


    cout << endl;
}

bool ReadInCout()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 0;
    //cin >> n >> nDays;

    //for (int i = 0; i < n; i++)
    //{
    //    int temp1, temp2;
    //    cin >> temp1 >> temp2;
    //    dayAmt.push_back(std::make_pair(temp1, temp2));
    //}

    return true;
}

int main()
{
    int n = 0, f = 0;
    std::string s;
    ReadInFile("2.in", n, f, s);

    //std::map <int, std::string> mapIdxMoo;
    std::map<string, unsigned int> mapMoo;
    for (int i = 1; i < n - 1; i++)
    {
        string subS = s.substr(i, 1);
        string subS2 = s.substr(i + 1, 1);
        if (subS == subS2)
        {
            std::string moo = s.substr(i - 1, 1) + subS + subS;
            std::map<string, unsigned int> ::iterator it =mapMoo.find(moo);
            if (it != mapMoo.end()) {
                mapMoo[moo] = mapMoo[moo] + 1;
            }
            else {
                mapMoo[moo] = 1;
            }
            //i += 2;
        }
    }

    set<string> setStrings;
    for (const auto& moo : mapMoo)
    {
        unsigned int count = moo.second;
        if (count >= f - 1) {
            setStrings.insert(moo.first);
        }
    }
     
    cout << setStrings.size() << endl;
    for (const auto& s : setStrings) {
        cout << s << endl;
    }

    return 0;
}
