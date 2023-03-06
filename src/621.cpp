#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int l = s.length();
        if(l <= 2)
            cout << "+\n";
        else if(s[l-2] == '3' && s[l-1] == '5')
            cout << "-\n";
        else if(s[0] == '9' && s[l-1] == '4')
            cout << "*\n";
        else
            cout << "?\n";
    }
    return 0;
}
