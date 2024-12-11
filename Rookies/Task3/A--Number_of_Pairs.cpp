#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;

int main(){

    ll t;
    cin >> t;
    vector<ll> ans(t, 0);

    for (int i = 0; i < t; i++) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for (ll j = 0; j < n; j++) 
            cin >> a[j];

        sort(a.begin(), a.end());

        for (ll j = 0; j < n; j++) {
            ll min = l - a[j];
            ll max = r - a[j];

            auto lowerBound = lower_bound(a.begin() + j + 1, a.end(), min);
            auto upperBound = upper_bound(a.begin() + j + 1, a.end(), max);

            ans[i] += (upperBound - lowerBound);
        }
    }

    for(ll i : ans) cout << i << endl;

}
