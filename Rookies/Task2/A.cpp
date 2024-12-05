#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    
    cin >> q;
    vector<int> m(q);
    vector<int> ans(q);
    
    for(int i = 0; i < q; i++) {
        int in;
        cin >> in;
        m[i] = in;
        
        ans[i] = upper_bound(x.begin(), x.end(), in) - x.begin();
        
    }
    
    for(int i : ans) cout << i << "\n";

}