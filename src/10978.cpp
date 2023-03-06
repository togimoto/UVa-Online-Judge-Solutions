#include <bits/stdc++.h>
using namespace std;

inline int increment(int index, int base) {
    return (index+1 < base) ? (index+1) : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
        int n;
        cin >> n;
        if(!n)
            break;
        string arr[n];
        int index = -1;
        for(int i = 0; i < n; i++) {
            string card, str;
            cin >> card >> str;
            int len = str.length();
            while(len--) {
                index = increment(index, n);
                while(arr[index] != "")
                    index = increment(index, n);
            }
            arr[index] = card;
        }
        for(int i = 0; i < n; i++)
            cout << arr[i] << ((i+1 < n) ? ' ' : '\n');
    }
}
