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
//
//bool ReadInFile(const string& sFile, vector <pair<string, string>>& demand)
//{
//    fstream in;
//    in.open(sFile, ios::in);
//    if (!in.is_open())
//    {
//        cout << "Error: cannot open input file." << endl;
//        return false;
//    }
//
//    int demands;
//
//    in >> demands;
//
//    for (int i = 0; i < demands; i++)
//    {
//        string aa; string b; string t;
//        in >> aa >> t >> t >> t >> t >> b;
//        demand.push_back({ aa, b });
//    }
//
//    return true;
//}
//
//void Print(const vector <pair<string, string>>& demand)
//{
//    cout << demand.size() << endl;
//
//    for (int i = 0; i < demand.size(); i++)
//    {
//        cout << demand[i].first << " must be milked beside " << demand[i].second << endl;
//    }
//
//    cout << endl;
//}
//
//int where(string c)
//{
//    for (int i = 0; i < 8; i++)
//        if (cows[i] == c) return i;
//    return -1;
//}
//
//bool satisfies_constraints(void)
//{
//    for (int i = 0; i < N; i++)
//        if (abs(where(beside_a[i]) - where(beside_b[i])) != 1) return false;
//    return true;
//}
//
//
//bool WriteOut(const string& sFile, const vector<string> ans)
//{
//    for (int i = 0; i < 8; i++)
//    {
//        cout << ans[i] << endl;
//    }
//
//    //
//    ofstream out_file;
//    out_file.open(sFile);
//
//    do {
//        if (satisfies_constraints()) {
//            for (int i = 0; i < 8; i++)
//            {
//                out_file << cows[i] << endl;
//            }
//            break;
//        }  while (next_permutation(cows.begin(), cows.end()));
//
//    out_file.close();
//
//    return true;
//}
//
//int main()
//{
//    vector<string> cows;
//    cows.push_back("Beatrice");
//    cows.push_back("Belinda");
//    cows.push_back("Bella");
//    cows.push_back("Bessie");
//    cows.push_back("Betsy");
//    cows.push_back("Blue");
//    cows.push_back("Buttercup");
//    cows.push_back("Sue");
//
//    vector <pair<string, string>> demand;
//
//    vector<string> ans;
//    int count = 0;
//
//    bool bOk = ReadInFile("lineup.in", demand);
//    Print(demand);
//
//    int demands = demand.size();
//
//    WriteOut("lineup.out");
//}

vector<string> cows, beside_a, beside_b;
int N;
 
int where(string c)
{
  for (int i=0; i<8; i++)
    if (cows[i]==c) return i;
  return -1;
}
 
bool satisfies_constraints(void)
{
  for (int i=0; i<N; i++)
    if (abs(where(beside_a[i]) - where(beside_b[i])) != 1) return false;
  return true;
}
 
int main(void)
{
  ifstream fin ("lineup.in");
  ofstream fout ("lineup.out");
  fin >> N;
  cows.push_back("Beatrice");
  cows.push_back("Belinda");
  cows.push_back("Bella");
  cows.push_back("Bessie");
  cows.push_back("Betsy");
  cows.push_back("Blue");
  cows.push_back("Buttercup");
  cows.push_back("Sue");
  string a, b, t;
  for (int i=0; i<N; i++) {
    fin >> a;
    fin >> t; // must
    fin >> t; // be
    fin >> t; // milked
    fin >> t; // beside
    fin >> b;
    beside_a.push_back(a);
    beside_b.push_back(b);
  }
  do {
    if (satisfies_constraints()) {
      for (int i=0; i<8; i++) fout << cows[i] << "\n";
      break;
    }
  } while (next_permutation(cows.begin(), cows.end()));
  return 0;
}