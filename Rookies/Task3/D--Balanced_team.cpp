#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
typedef long long ll;



int main() {

    ll n, maxNum = 0;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll i = 0, k = 0;
    while(k < n) {
        if(a[k] - a[i] <= 5) {
            maxNum = max(maxNum, k - i + 1);
            k++;
        }
        else i++;
    }

    cout << maxNum << endl;

}
