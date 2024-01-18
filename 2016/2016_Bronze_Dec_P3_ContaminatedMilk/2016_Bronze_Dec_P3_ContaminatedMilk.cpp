//#include <iostream>
//#include <fstream>
//#include <cassert>
//#include <map>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <unordered_map>
//#include <climits>
//
//using namespace std;
//
//
//bool ReadInFile(const string& sFile, vector<int>& pDrank, vector<int>& milkDrank, vector<int>& timeDrank, vector<int>& pSick, vector<int>& timeSick)
//{
//    fstream in;
//    in.open(sFile, ios::in);
//    if (!in.is_open())
//    {
//        cout << "Error: cannot open input file." << endl;
//        return false;
//    }
//
//    int nFriend, nMilkTypes, nLines, nLines2;
//
//    in >> nFriend >> nMilkTypes >> nLines >> nLines2;
//
//    for (int i = 0; i < nLines; i++)
//    {
//        int temp1, temp2, temp3;
//        in >> temp1 >> temp2 >> temp3;
//
//        pDrank.push_back(temp1);
//        milkDrank.push_back(temp2);
//        timeDrank.push_back(temp3);
//    }
//
//    for (int i = 0; i < nLines2; i++)
//    {
//        int temp1, temp2;
//        in >> temp1 >> temp2;
//
//        pSick.push_back(temp1);
//        timeSick.push_back(temp2);
//    }
//
//    return true;
//}
//
//void Print(const vector<int> pDrank, const vector<int> milkDrank, const vector<int> timeDrank, const vector<int> pSick, const vector<int> timeSick)
//{
//    for (int i = 0; i < milkDrank.size(); i++)
//    {
//        cout << pDrank[i] << " " << milkDrank[i] << " " << timeDrank[i] << endl;
//    }
//
//    for (int i = 0; i < pSick.size(); i++)
//    {
//        cout << pSick[i] << " " << timeSick[i] << endl;
//    }
//}
//
//bool WriteOut(const string& sFile, const int ans)
//{
//    cout << ans << endl;
//
//    //
//    ofstream out_file;
//    out_file.open(sFile);
//
//    out_file << ans << endl;
//
//    out_file.close();
//
//    return true;
//}
//
//
//int main()
//{
//    vector<int> pDrank, milkDrank, timeDrank, pSick, timeSick;
//
//    bool bOk = ReadInFile("../badmilk_bronze_dec15/1.in", pDrank, milkDrank, timeDrank, pSick, timeSick);
//    //Print(pDrank, milkDrank, timeDrank, pSick, timeSick);
//
//    int ans = 0, spoiled = 0, cnt = 0, possible = 0;
//
//    for (int i = 0; i < pDrank.size(); i++)
//    {
//        for (int j = 0; j < timeSick.size(); j++)
//        {
//            if (pDrank[i] == pSick[j] && timeDrank[i] < timeSick[j])
//            {
//                cnt++;
//            }
//        }
//
//        if (cnt == pSick.size())
//        {
//            spoiled = milkDrank[i];              

//    WriteOut("speeding.out", ans);
//}

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
 * Let's treat someone drinking milk and someone getting sick
 * as both "events".
 * We can differentiate the two by setting the value of milk
 * as -1 for someone getting sick.
 */
struct Event {
	int person;
	int milk = -1;
	int time;
};

int main() {
	std::ifstream read("badmilk.in");
	int people_num;
	int milk_num;
	int drink_times;
	int sick_times;
	read >> people_num >> milk_num >> drink_times >> sick_times;

	vector<Event> events(drink_times + sick_times);
	for (int e = 0; e < events.size(); e++) {
		Event& ev = events[e];
		if (e < drink_times) {
			read >> ev.person >> ev.milk >> ev.time;
			ev.milk--;
		}
		else {
			read >> ev.person >> ev.time;
		}
		ev.person--;
	}

	/*
	 * Sort the events based on when they occurred.
	 * Note that since one can only get sick if they drank
	 * the milk at a *strictly* earlier point in time, we have to put
	 * the sick events before the drinking events if they occur at
	 * the same point in time.
	 */
	std::sort(
		events.begin(), events.end(), [&](const Event& e1, const Event& e2) {
			return e1.time != e2.time ? e1.time < e2.time : e1.milk < e2.milk;
		});

	int max_med = 0;
	// Go through each milk and check if it could be the bad one.
	for (int m = 0; m < milk_num; m++) {
		vector<bool> can_be_sick(people_num);
		bool possible = true;
		// Simulate the events, marking if each person could possibly be sick.
		for (const Event& e : events) {
			if (e.milk == -1) {
				if (!can_be_sick[e.person]) {
					possible = false;
					break;
				}
			}
			else if (e.milk == m) {
				can_be_sick[e.person] = true;
			}
		}

		/*
		 * If this milk could possibly be the bad one,
		 * we see how many people could possibly be sick in total.
		 */
		if (possible) {
			int meds = 0;
			for (bool p : can_be_sick) { meds += p; }
			max_med = std::max(max_med, meds);
		}
	}

	std::ofstream("badmilk.out") << max_med << endl;
}
