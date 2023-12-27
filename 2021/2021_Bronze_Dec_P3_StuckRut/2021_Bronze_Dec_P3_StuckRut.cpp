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

//int Infinity = 1000000001;
//
//struct Cow {
//    int time_stopped; // time at which stopped
//    int x, y;         // current location
//    string dir;         // N or E
//};
//
//bool ReadInFile(const string& sFile, std::vector<Cow*>& cows)
//{
//    cows.clear();
//    fstream in;
//    in.open(sFile, ios::in);
//    if (!in.is_open())
//    {
//        cout << "Error: cannot open input file." << endl;
//        return false;
//    }
//
//    int nCows;
//    in >> nCows;
//    for (int i = 0; i < nCows; i++)
//    {
//        Cow* pCow = new Cow();
//        in >> pCow->dir >> pCow->x >> pCow->y;
//        pCow->time_stopped = Infinity;
//        cows.push_back(pCow);
//    }
//
//    return true;
//}
//
//bool ReadInCout(std::vector<Cow*>& petalOrder)
//{
//    ios::sync_with_stdio(0); cin.tie(0);
//
//    assert(0);
//    return false;
//}
//
//void Print(const std::vector<Cow*>& cows)
//{
//    cout << cows.size() << endl;
//    for (Cow* pCow : cows) {
//        cout << pCow->dir << " " << pCow->x << " " << pCow->y << endl;
//    }
//}
//
//int when_hits(int i, int j, int current_time)
//{
//    Cow I = cows[i], J = cows[j];
//    if (I.dir == J.dir) return Infinity; // never hits if moving same direction (or same cow)
//    if (I.dir == 'E') { // assume without loss of generality that I is moving north, and J east
//        swap(I.x, I.y); swap(J.x, J.y);
//    }
//    if (J.y <= I.y) return Infinity; // J isn't north of I?
//    if (J.time_stopped == Infinity) {
//        if (I.x < J.x - current_time || I.x >= J.x + J.y - I.y) return Infinity; // No insersection, J still mooving
//    }
//    else {
//        if (I.x > J.x || I.x < J.x - J.time_stopped) return Infinity; // No intersection; j stopped already
//    }
//    return current_time + J.y - I.y;
//}
//
//// Returns the next time after current_time at which a cow hits a rut and stops  (or Infinity if no such event)
//// Also move cows forward until that time and update which cows are stopped
//int advance_to_next_event(int current_time)
//{
//    // T[i] is the next time something happens to cow i; minT is the earliest of these
//    int T[50], minT = Infinity;
//
//    for (int i = 0; i < N; i++) {
//        T[i] = Infinity;
//        if (C[i].time_stopped == Infinity) { // For all cows still mooving....
//            for (int j = 0; j < N; j++) {            // What does it hit next?
//                int t = when_hits(i, j, current_time);
//                if (t < T[i]) T[i] = t;
//            }
//            if (T[i] < minT) minT = T[i];
//        }
//    }
//
//    if (minT == Infinity) return Infinity;
//
//    // Advance cows, stopping those that hit a rut
//    for (int i = 0; i < N; i++) {
//        if (C[i].time_stopped == Infinity)
//            if (C[i].dir == 'N') C[i].y += (minT - current_time);
//            else                 C[i].x += (minT - current_time);
//        if (T[i] == minT) C[i].time_stopped = minT;
//    }
//
//    return minT;
//}

//int main()
//{
//    std::vector<Cow*> cows;
//    bool bOk = ReadInFile("../prob3_bronze_dec20/1.in", cows);
//    //Print(cows);
//
//    //bool bOk = ReadInCout(petalOrder);
//    //if (!bOk) { return 0; }
//
//      // Now just advance from one "event" to another until done...
//    int current_time = 0;
//    do { current_time = advance_to_next_event(current_time); } while (current_time != Infinity);
//
//    for (int i = 0; i < cows.size(); i++)
//        if (Cow*cows[i].time_stopped == Infinity) cout << "Infinity\n";
//        else                               cout << C[i].time_stopped << "\n";
//
//    for (Cow* pCow : cows) {
//        delete pCow;
//    }
//    cows.clear();
//
//    struct Cow {
//        int time_stopped; // time at which stopped
//        int x, y;         // current location
//        char dir;         // N or E
//    };
//
//    int N;
//    Cow C[50];
//
//    // At what time would cow i hit the rut carved out by cow j and stop?  (Infinity if no such event)
//    // (and this is only considering these two cows for the moment)
//    int when_hits(int i, int j, int current_time)
//    {
//        Cow I = C[i], J = C[j];
//        if (I.dir == J.dir) return Infinity; // never hits if moving same direction (or same cow)
//        if (I.dir == 'E') { // assume without loss of generality that I is moving north, and J east
//            swap(I.x, I.y); swap(J.x, J.y);
//        }
//        if (J.y <= I.y) return Infinity; // J isn't north of I?
//        if (J.time_stopped == Infinity) {
//            if (I.x < J.x - current_time || I.x >= J.x + J.y - I.y) return Infinity; // No insersection, J still mooving
//        }
//        else {
//            if (I.x > J.x || I.x < J.x - J.time_stopped) return Infinity; // No intersection; j stopped already
//        }
//        return current_time + J.y - I.y;
//    }
//
//    // Returns the next time after current_time at which a cow hits a rut and stops  (or Infinity if no such event)
//    // Also move cows forward until that time and update which cows are stopped
//    int advance_to_next_event(int current_time)
//    {
//        // T[i] is the next time something happens to cow i; minT is the earliest of these
//        int T[50], minT = Infinity;
//
//        for (int i = 0; i < N; i++) {
//            T[i] = Infinity;
//            if (C[i].time_stopped == Infinity) { // For all cows still mooving....
//                for (int j = 0; j < N; j++) {            // What does it hit next?
//                    int t = when_hits(i, j, current_time);
//                    if (t < T[i]) T[i] = t;
//                }
//                if (T[i] < minT) minT = T[i];
//            }
//        }
//
//        if (minT == Infinity) return Infinity;
//
//        // Advance cows, stopping those that hit a rut
//        for (int i = 0; i < N; i++) {
//            if (C[i].time_stopped == Infinity)
//                if (C[i].dir == 'N') C[i].y += (minT - current_time);
//                else                 C[i].x += (minT - current_time);
//            if (T[i] == minT) C[i].time_stopped = minT;
//        }
//
//        return minT;
//    }
int Infinity = 1000000001;

struct Cow {
    int time_stopped; // time at which stopped
    int x, y;         // current location
    char dir;         // N or E
};

int N;
Cow C[50];

// At what time would cow i hit the rut carved out by cow j and stop?  (Infinity if no such event)
// (and this is only considering these two cows for the moment)
int when_hits(int i, int j, int current_time)
{
    Cow I = C[i], J = C[j];
    if (I.dir == J.dir) return Infinity; // never hits if moving same direction (or same cow)
    if (I.dir == 'E') { // assume without loss of generality that I is moving north, and J east
        swap(I.x, I.y); swap(J.x, J.y);
    }
    if (J.y <= I.y) return Infinity; // J isn't north of I?
    if (J.time_stopped == Infinity) {
        if (I.x < J.x - current_time || I.x >= J.x + J.y - I.y) return Infinity; // No insersection, J still mooving
    }
    else {
        if (I.x > J.x || I.x < J.x - J.time_stopped) return Infinity; // No intersection; j stopped already
    }
    return current_time + J.y - I.y;
}

// Returns the next time after current_time at which a cow hits a rut and stops  (or Infinity if no such event)
// Also move cows forward until that time and update which cows are stopped
int advance_to_next_event(int current_time)
{
    // T[i] is the next time something happens to cow i; minT is the earliest of these
    int T[50], minT = Infinity;

    for (int i = 0; i < N; i++) {
        T[i] = Infinity;
        if (C[i].time_stopped == Infinity) { // For all cows still mooving....
            for (int j = 0; j < N; j++) {            // What does it hit next?
                int t = when_hits(i, j, current_time);
                if (t < T[i]) T[i] = t;
            }
            if (T[i] < minT) minT = T[i];
        }
    }

    if (minT == Infinity) return Infinity;

    // Advance cows, stopping those that hit a rut
    for (int i = 0; i < N; i++) {
        if (C[i].time_stopped == Infinity)
            if (C[i].dir == 'N') C[i].y += (minT - current_time);
            else                 C[i].x += (minT - current_time);
        if (T[i] == minT) C[i].time_stopped = minT;
    }

    return minT;
}
    int main(void)
    {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> C[i].dir >> C[i].x >> C[i].y;
            C[i].time_stopped = Infinity;
        }

        // Now just advance from one "event" to another until done...
        int current_time = 0;
        do { current_time = advance_to_next_event(current_time); } while (current_time != Infinity);

        for (int i = 0; i < N; i++)  {
            if (C[i].time_stopped == Infinity) cout << "Infinity\n";
            else                               cout << C[i].time_stopped << "\n";
    }
}
