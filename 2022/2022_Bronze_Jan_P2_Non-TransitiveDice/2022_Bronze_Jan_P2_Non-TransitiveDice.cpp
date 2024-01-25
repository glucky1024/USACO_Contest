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


bool ReadInFile(const string& sFile, int& t, vector<int>& dice1, vector<int>& dice2)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    dice1.clear();
    dice2.clear();

    in >> t;

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp1;
            in >> temp1;

            dice1.push_back(temp1);
        }

        for (int j = 0; j < 4; j++)
        {
            int temp1;
            in >> temp1;

            dice2.push_back(temp1);
        }
    }

    return true;
}

void Print(const int t, vector<int> dice1, vector<int> dice2)
{
    cout << t << endl;

    for (int i = 0; i < t * 4; i++)
    {
        cout << dice1[i] << " ";
    }

    for (int i = 0; i < t * 4; i++)
    {
        cout << dice2[i] << " ";
    }

    cout << endl;

}

bool ReadInCout(int& t, vector<int>& dice1, vector<int>& dice2)
{
    ios::sync_with_stdio(0); cin.tie(0);

    dice1.clear();
    dice2.clear();

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp1;
            cin >> temp1;

            dice1.push_back(temp1);
        }

        for (int j = 0; j < 4; j++)
        {
            int temp1;
            cin >> temp1;

            dice2.push_back(temp1);
        }
    }

    return true;
}


bool WriteOut(const string& sFile, const vector<bool> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i])
        {
            cout << "yes" << endl;
        }

        else
        {
            cout << "no" << endl;
        }
    }

    //
    ofstream out_file;
    out_file.open(sFile);

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i])
        {
            out_file << "yes" << endl;
        }

        else
        {
            out_file << "no" << endl;
        }
    }

    out_file.close();

    return true;
}

bool beats(vector<int> dX, vector<int> dY)
{
    int wins = 0, losses = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (dX[i] > dY[j])
            {
                wins++;
            }

            if (dX[i] < dY[j])
            {
                losses++;
            }
        }
    }

    return wins > losses;
}

bool bruh(vector<int> curDice1, vector<int> curDice2)
{
    for (int a = 1; a <= 10; a++)
    {
        for (int b = 1; b <= 10; b++)
        {
            for (int c = 1; c <= 10; c++)
            {
                for (int d = 1; d <= 10; d++)
                {
                    vector<int> dice3;
                    dice3.push_back(a);
                    dice3.push_back(b);
                    dice3.push_back(c);
                    dice3.push_back(d);

                    if (beats(curDice1, curDice2) && beats(curDice2, dice3) && beats(dice3, curDice1))
                    {
                        return true;
                    }

                    if (beats(curDice2, curDice1) && beats(dice3, curDice2) && beats(curDice1, dice3))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    int t = 0;
    vector<int> dice1, dice2;
    vector<bool> ans;
    int winner = 0;

    //bool bOk = ReadInFile("../prob2_bronze_jan22/1.in", t, dice1, dice2);
    ReadInCout(t, dice1, dice2);
    //Print(t, dice1, dice2);

    vector<int> curDice1, curDice2;

    for (int i = 1; i <= t; i++)
    {
        curDice1.clear();
        curDice2.clear();

        for (int j = 4 * i + -4; j < 4 * i; j++)
        {
            int iter1 = dice1[j];
            curDice1.push_back(iter1);
        }

        for (int j = 4 * i + -4; j < 4 * i; j++)
        {
            int iter1 = dice2[j];
            curDice2.push_back(iter1);
        }

        ans.push_back(bruh(curDice1, curDice2));
    }

    WriteOut("marathon.out", ans);
}