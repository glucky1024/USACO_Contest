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

bool ReadInFile(const string& sFile, vector<long long>& hCows, vector<long long>& hCanes)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nCows = 0, nCanes = 0;
    in >> nCows >> nCanes;

    for (int i = 0; i < nCows; i++)
    {
        long long h = 0;
        in >> h;
        hCows.push_back(h);
    }

    for (int i = 0; i < nCanes; i++)
    {
        long long h = 0;
        in >> h;
        hCanes.push_back(h);
    }

    return true;
}

bool ReadInCout(vector<long long>& hCows, vector<long long>& hCanes)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows = 0, nCanes = 0;
    cin >> nCows >> nCanes;

    for (int i = 0; i < nCows; i++)
    {
        long long h = 0;
        cin >> h;
        hCows.push_back(h);
    }

    for (int i = 0; i < nCanes; i++)
    {
        long long h = 0;
        cin >> h;
        hCanes.push_back(h);
    }

    return true;
}

void Print(const vector<long long>& hCows, const vector<long long>& hCanes)
{
    cout << hCows.size() << " " << hCanes.size() << endl;

    for (int i = 0; i < hCows.size(); i++)
    {
        cout << hCows[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < hCanes.size(); i++)
    {
        cout << hCanes[i] << " ";
    }
    cout << endl;

    cout << endl;
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
    vector<long long> hCows, hCanes;
    //ReadInFile("in.txt", hCows, hCanes);
    //Print(hCows, hCanes);
    ReadInCout(hCows, hCanes);


    for (unsigned int i = 0; i < hCanes.size(); ++i) {
        long long hCane = hCanes[i];
        long long prev_pos = 0;
        for (unsigned int c = 0; c < hCows.size(); ++c) {
            long long hCow = hCows[c];

            if (hCow > prev_pos) {
                if (hCow >= hCane) {
                    long eat = hCane - prev_pos;
                    hCows[c] += eat;
                    break;
                }
                else {
                    long eat = hCow - prev_pos;
                    hCows[c] += eat;
                    prev_pos += eat;
                }
            }
        }
    }

    //
    for (unsigned int c = 0; c < hCows.size(); ++c) {
        cout << hCows[c] << endl;
    }

    return 1;
}