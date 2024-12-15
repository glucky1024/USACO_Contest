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

bool ReadInFile(const string& sFile, vector<string>& type, vector<string>& cowa, vector<string>& cowb, vector<string>& prevNext)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nLines;
    in >> nLines;

    for (int i = 0; i < nLines; i++)
    {
        string cowa1, cowb1, born, ing, type1, years, from, pv;
        in >> cowa1 >> born >> ing >> pv >> type1 >> years >> from >> cowb1;

        cowa.push_back(cowa1);
        cowb.push_back(cowb1);
        type.push_back(type1);
        prevNext.push_back(pv);
    }

    return true;
}

void Print(const vector<string> type, const vector<string> cowa, const vector<string> cowb, const vector<string> prevNext)
{
    cout << cowa.size() << endl;

    for (int i = 0; i < cowa.size(); i++)
    {
        cout << cowa[i] << " born in " << prevNext[i] << " " << type[i] << " year from " << cowb[i] << endl;
    }
}

bool ReadInCout(vector<string>& type, vector<string>& cowa, vector<string>& cowb, vector<string>& prevNext)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nLines;
    cin >> nLines;

    for (int i = 0; i < nLines; i++)
    {
        string cowa1, cowb1, born, ing, type1, years, from, pv;
        cin >> cowa1 >> born >> ing >> pv >> type1 >> years >> from >> cowb1;

        cowa.push_back(cowa1);
        cowb.push_back(cowb1);
        type.push_back(type1);
        prevNext.push_back(pv);
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

int dist(const vector<string> cowa, const vector<string> cowb, const int whereBessieIs, const vector<string>zodiac, const vector<string> prevNext, const vector<string> type)
{
    int d = 0;
    string cowAOfBessieType = type[whereBessieIs];
    string cowAOfBessie = cowa[whereBessieIs];
    int whereCowATypeIs = 0;
    int newBessiePlace = 0;
    string newBessieType;

    for (int i = 0; i < cowb.size(); i++)
    {
        if (cowAOfBessie == cowb[i])
        {
            newBessiePlace = i;
        }
    }

    return newBessiePlace;
}

int main()
{
    vector<string> type, cowa, cowb, prevNext;

    bool bOk = ReadInFile("../prob1_bronze_feb21/2.in", type, cowa, cowb, prevNext);
    //ReadInCout(type, cowa, cowb, prevNext);
    //Print(type,cowa, cowb, prevNext);

    //1. Ox, 2. Tiger, 3. Rabbit, 4.Dragon, 5.Snake, 6.Horse, 7.Goat, 8. Monkey, 9.Rooster, 10.Dog, 11.Pig, 12. Rat,

    vector<string> zodiac {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};   // if adding +1

    int whereBessieIs = 0;

    for (int i = 0; i < cowb.size(); i++)
    {
        if (cowb[i] == "Bessie")
        {
            whereBessieIs = i;
            break;
        }
    }

    vector<int> yearborn;

    //once we find elsie
    bool found = false;
    string newBessieType = "Ox"; // mildred is a dragon
    int d = 0;
    int oldBorn = 0;

    while (!found)
    {
        //find dist between cowa[i] and cow[b]
        string cowAOfBessieType = type[whereBessieIs];   //dragon
        string cowAOfBessiePrevNext = prevNext[whereBessieIs];
        string cowAOfBessie = cowa[whereBessieIs];       //mildred

        int posa = 0, posb = 0;

        for (int i = 0; i < zodiac.size(); i++)
        {
            if (cowAOfBessieType == zodiac[i])
            {
                posa = i;
                break;
            }
        }

        for (int i = 0; i < zodiac.size(); i++)
        {
            if (newBessieType == zodiac[i])
            {
                posb = i;
                break;
            }
        }

        if (posb> posa && cowAOfBessiePrevNext == "next")
        {
            int temp1 = 12 - (posb + 1) + (posa + 1);
            yearborn.push_back(temp1 + oldBorn);
            oldBorn = temp1 + oldBorn;
        }

        else if (posb > posa && cowAOfBessiePrevNext == "previous")
        {
            int temp1 = posb-posa;
            yearborn.push_back(-temp1 + oldBorn);
            oldBorn = -temp1 + oldBorn;
        }

        else if (posb < posa && cowAOfBessiePrevNext == "next")
        {
            int temp1 = posa- posb;
            yearborn.push_back(temp1 + oldBorn);
            oldBorn = temp1 + oldBorn;
        }

        else if (posb < posa && cowAOfBessiePrevNext == "previous")
        {
            int temp1 = posb + (12-posa);
            yearborn.push_back(-temp1 + oldBorn);
            oldBorn = -temp1 + oldBorn;
        }

        else if(posb == posa && cowAOfBessiePrevNext == "previous")
        {
            int temp1 = 12;
            yearborn.push_back(-temp1 + oldBorn);
            oldBorn = -temp1 + oldBorn;
        }

        else
        {
            int temp1 = 12;
            yearborn.push_back(temp1 + oldBorn);
            oldBorn = temp1 + oldBorn;
        }

        if (cowAOfBessie == "Elsie")
        {
            d = abs(0 - yearborn.back());
            break;
        }

        newBessieType = type[whereBessieIs];

        for (int i = 0; i < cowb.size(); i++)
        {
            if (cowAOfBessie == cowb[i])
            {
                whereBessieIs = i;
                break;
            }
        }
    }

    cout << d << endl;

    //WriteOut("marathon.out", ans);
}