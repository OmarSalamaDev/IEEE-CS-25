
#include <iostream>

using namespace std;

int main(void) {

    char c;
    cin >> c;
    string str;
    cin >> str;

    string seq = "qwertyuiopasdfghjkl;zxcvbnm,./";

    for(int i = 0; i < str.length(); i++) {
        int index = seq.find(str[i]);
        if(c == 'L') str[i] = seq[index + 1];
        else str[i] = seq[index - 1];
    }

    cout << str << endl;

}