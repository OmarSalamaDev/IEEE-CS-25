#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;


void getAllStubidStrings(
    string &current, 
    vector<bool> &used,
    string &s,
    set<string> &result
){

    if (current.size() == s.size()) {
        result.insert(current);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        current.push_back(s[i]);

        getAllStubidStrings(current, used, s, result);

        used[i] = false;
        current.pop_back();
    }
}

int main() {

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    set<string> result;       
    string current;          
    vector<bool> used(s.size(), false);

    getAllStubidStrings(current, used, s, result);

    cout << result.size() << endl;
    for (const string &str : result) cout << str << endl;
}
