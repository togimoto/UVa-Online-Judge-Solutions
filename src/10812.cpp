#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--) {
        int sum, diff;
        cin >> sum >> diff;
        if((sum + diff) % 2) {
            cout << "impossible\n";
            continue;
        }
        int greater = (sum + diff) / 2;
        int smaller = sum - greater;
        if(greater < 0 || smaller < 0)
            cout << "impossible\n";
        else
            cout << greater << " " << smaller << "\n";
    }
}
