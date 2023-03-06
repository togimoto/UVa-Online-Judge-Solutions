#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--) {
        int amp, frq;
        cin >> amp >> frq;
        for(int i = 1; i <= frq; i++) {
            for(int j = 1; j <= amp; j++) {
                for(int k = 1; k <= j; k++)
                    cout << (char)('0' + j);
                cout << '\n';
            }
            for(int j = amp-1; j >= 1; j--) {
                for(int k = 1; k <= j; k++)
                    cout << (char)('0' + j);
                cout << '\n';
            }
            if(i < frq || n > 0)
                cout << '\n';
        }
    }
}
