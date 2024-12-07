#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
typedef long long ll;



int main() {

    ll n, t, maxNum = 0, time = 0;
    cin >> n >> t;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll b = 0;
    for (ll e = 0; e < n; e++) {
        time += a[e];
        while(time > t) {
            time -= a[b];
            b++;
        }
        maxNum = max(maxNum, e - b + 1);
    }

    cout << maxNum << "\n";

}

