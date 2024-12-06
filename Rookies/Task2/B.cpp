#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;
ll getGroups(vector<ll>& x, int d);


int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    cout << getGroups(x, d) << "\n";
}


ll getGroups(vector<ll>& x, int d) {
    int n = x.size();
    ll ans = 0;
    ll k = 0;

    for (int i = 0; i < n; i++) {
        while (k < n && x[k] - x[i] <= d) k++;
        if (k - i >= 2) {
            ans += (k - i - 1) * ((k - i - 1) - 1) / 2;
        }
    }

    return ans;
}
