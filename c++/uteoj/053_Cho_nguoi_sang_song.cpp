#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Passenger {
    int start;
    int end;
};

int main() {
    int M, N;
    cin >> N >> M;
    vector<Passenger> passengers(N);

    for (int i = 0; i < N; ++i) {
        cin >> passengers[i].start >> passengers[i].end;
    }

    // Sort passengers by their start point
    sort(passengers.begin(), passengers.end(), [](const Passenger &a, const Passenger &b) {
        return a.start < b.start;
    });

    int currentVillage = 0;
    int totalDistance = 0;

    for (const auto &p : passengers) {
        // Move to the passenger's start village
        totalDistance += abs(p.start - currentVillage);
        currentVillage = p.start;

        // Move to the passenger's end village
        totalDistance += abs(p.end - currentVillage);
        currentVillage = p.end;
    }

    // Finally, move to village M
    totalDistance += abs(M - currentVillage);

    cout << "Minimum distance Mirko has to travel: " << totalDistance << " miles" << endl;

    return 0;
}
