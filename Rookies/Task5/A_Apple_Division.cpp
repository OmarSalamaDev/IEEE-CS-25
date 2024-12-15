#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll minDiff(ll index, ll currentSum, ll totalSum, const vector<ll>& weights);

int main() {
    ll n;
    cin >> n;
    vector<ll> weights(n);
    ll totalSum = 0;

    for (ll i = 0; i < n; ++i) {
        cin >> weights[i];
        totalSum += weights[i];
    }

    ll result = minDiff(0, 0, totalSum, weights);
    cout << result << endl;

    return 0;
}


ll minDiff(ll index, ll currentSum, ll totalSum, const vector<ll>& weights) {
    if (index == weights.size()) {
        return abs((totalSum - currentSum) - currentSum);
    }

    ll include = minDiff(index + 1, currentSum + weights[index], totalSum, weights);
    ll exclude = minDiff(index + 1, currentSum, totalSum, weights);

    return min(include, exclude);
}