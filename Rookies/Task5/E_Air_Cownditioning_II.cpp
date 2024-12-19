

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Cow {
    int start, end, cooling;
};

struct AirConditioner {
    int start, end, power, cost;
};

int N, M;
vector<Cow> cows;
vector<AirConditioner> airConditioners;

int solve(int index, vector<int>& coolingReq) {

    bool allSatisfied = true;
    for (int req : coolingReq) {
        if (req > 0) {
            allSatisfied = false;
            break;
        }
    }
    if (allSatisfied) return 0;
    if (index == M) return INT_MAX;

    int costWithoutCurrent = solve(index + 1, coolingReq);

    vector<int> newCoolingReq = coolingReq;

    for (int j = airConditioners[index].start; j <= airConditioners[index].end; j++) {
        if (j >= 1 && j <= 100) {
            newCoolingReq[j] -= airConditioners[index].power;
        }
    }


    int costWithCurrent = solve(index + 1, newCoolingReq);

    if (costWithCurrent != INT_MAX) {
        costWithCurrent += airConditioners[index].cost;
    }

    return min(costWithoutCurrent, costWithCurrent);
}

int main() {
    cin >> N >> M;

    cows.resize(N);
    airConditioners.resize(M);

 
    for (int i = 0; i < N; i++) {
        cin >> cows[i].start >> cows[i].end >> cows[i].cooling;
    }


    for (int i = 0; i < M; i++) {
        cin >> airConditioners[i].start >> airConditioners[i].end >> airConditioners[i].power >> airConditioners[i].cost;
    }

    vector<int> coolingReq(101, 0);
    for (const Cow& cow : cows) {
        for (int j = cow.start; j <= cow.end; j++) {
            coolingReq[j] += cow.cooling;
        }
    }

    int result = solve(0, coolingReq);

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

}
