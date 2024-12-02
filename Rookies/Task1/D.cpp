
#include <iostream>


using namespace std;
typedef long long ll;

int main(void) {
    ll n, minTime = -1;
    cin >> n;
    char dir[n];
    ll coor[n];

    for(int i = 0; i < n; i++) cin >> dir[i];
    for(int i = 0; i < n; i++) cin >> coor[i];

    for(int i = 0; i < n - 1; i++) {
        if(dir[i] == 'R' && dir[i + 1] == 'L') {
            ll time = (coor[i + 1] - coor[i]) / 2;
            if(minTime == -1 || time < minTime) minTime = time;
        }
    }

    cout << minTime << endl;

}