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

bool ReadInFile(const string& sFile, string& ans, string& guess)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        string temp1;
        in >> temp1;


        ans += temp1;

    }

    for (int i = 0; i < 3; i++)
    {
        string temp1;
        in >> temp1;


        guess += temp1;

    }

    return true;
}

void Print(const string ans, const string guess)
{
    int cnt = 0;

    for (int i = 0; i < 9; i++)
    {
        cout << ans[i];
        cnt++;

        if (cnt % 3 == 0)
        {
            cout << endl;
        }
    }

    cnt = 0;
    for (int i = 0; i < 9; i++)
    {
        cout << guess[i];
        cnt++;

        if (cnt % 3 == 0)
        {
            cout << endl;
        }
    }
}

bool ReadInCout(string& ans, string& guess)
{
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < 3; i++)
    {
        string temp1;
        cin >> temp1;


        ans += temp1;

    }

    for (int i = 0; i < 3; i++)
    {
        string temp1;
        cin >> temp1;

        guess += temp1;

    }

    return true;
}


bool WriteOut(const string& sFile, const pair<int, int> greenYel)
{
    cout << greenYel.first << endl;
    cout << greenYel.second << endl;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << greenYel.first << endl;
    out_file << greenYel.second << endl;

    out_file.close();

    return true;
}

bool calc(int iteration, const string ans, const string guess)
{
    for (int i = 0; i < 9; i++)
    {
        if (guess[iteration] == ans[i])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string ans, guess;

    //bool bOk = ReadInFile("../prob1_bronze_jan22/2.in", ans, guess);
    ReadInCout(ans, guess);
    //Print(ans, guess);

    pair<int, int> greenYel;

    // Define an unordered_map
    unordered_map<char, int> alphAns, alphGuess;

    for (int i = 0; ans[i]; i++)
    {
        if (alphAns.find(ans[i]) == alphAns.end())
        {
            alphAns.insert(make_pair(ans[i], 1));
        }

        // Else update the frequency
        else
        {
            alphAns[ans[i]]++;
        }
    }

    //    
    for (int i = 0; guess[i]; i++)
    {
        if (alphGuess.find(guess[i]) == alphGuess.end())
        {
            alphGuess.insert(make_pair(guess[i], 1));
        }

        // Else update the frequency
        else
        {
            alphGuess[guess[i]]++;
        }
    }

    for (auto it = alphAns.begin(); it != alphAns.end(); it++)
    {
        for (auto its = alphGuess.begin(); its != alphGuess.end(); its++)
        {
            if (it->first == its->first)
            {
                greenYel.second += min(its->second, it->second);
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (ans.substr(i, 1) == guess.substr(i, 1))
        {
            greenYel.first++;
        }
    }

    greenYel.second -= greenYel.first;


    WriteOut("marathon.out", greenYel);
}