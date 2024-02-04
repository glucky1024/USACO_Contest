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

    string s, s2;
    in >> s;

    for (int i = 0; i < s.length(); i++)
    {
        alph.push_back(s.substr(i, 1));
    }

    in >> s2;

    for (int i = 0; i < s2.length(); i++)
    {
        word.push_back(s2.substr(i, 1));
    }

    return true;
}

void Print(const vector<string> alph, const vector<string> word)
{
    for (int i = 0; i < alph.size(); i++)
    {
        cout << alph[i];
    }

    cout << endl;

    for (int i = 0; i < word.size(); i++)
    {
        cout << word[i];
    }

    cout << endl;

}

bool ReadInCout(vector<string>& alph, vector<string>& word)
{
    ios::sync_with_stdio(0); cin.tie(0);

    string s, s2;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        alph.push_back(s.substr(i, 1));
    }

    cin >> s2;

    for (int i = 0; i < s2.length(); i++)
    {
        word.push_back(s2.substr(i, 1));
    }

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

    int times = 0;

    int letterOfWord = 0;

    while (letterOfWord < word.size())
    {
        for (int i = 0; i < alph.size(); i++)
        {
            if (word[letterOfWord] == alph[i])
            {
                letterOfWord++;
            }

            if (letterOfWord == word.size())
            {
                break;
            }
        }

        times++;
    }

    cout << times << endl;
    //WriteOut("marathon.out", ans);
}