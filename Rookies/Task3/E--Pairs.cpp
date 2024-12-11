#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
typedef long long ll;



int main() {

    ll n, k, pairs = 0;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll i = 0, j = 1;
    while(j < n) {
        ll diff = a[j] - a[i];
        if(diff == k) {
            pairs++;
            i++;
            j++;
        }
        else if(diff > k) i++;
        else j++;
    }

    cout << pairs << endl;

}
