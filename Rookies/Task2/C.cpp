#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
typedef long long ll;
ll getMinDiff(vector<ll> &v, ll x);


int main() {
    
    ll n, m, r = 0;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i < n; i++) {
            ll diff = getMinDiff(b, a[i]);
            if(diff > r) r = diff;
    }

    cout << r << "\n";
}


ll getMinDiff(vector<ll> &v, ll x) {
    ll b = 0, e = v.size() - 1;
    ll minDiff = LONG_MAX;
    while (b <= e) {
        ll c = b + (e - b) / 2;
        minDiff = min(minDiff, abs(v[c] - x));
        if (v[c] < x) b = c + 1;
        else e = c - 1;
    }
    
    return minDiff;
}
