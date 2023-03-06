#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, i, j;
    while(cin >> n >> j) {
        if(n == 1) {
            cout << "Jolly\n";
            continue;
        }
        vector<bool> v(3000, 0);
        int count = 0;
        for(int k = n-1; k > 0; k--) {
            i = j;
            cin >> j;
            if(abs(i-j) < n && !v[abs(i-j)]) {
                count++;
                v[abs(i-j)] = true;
            }
        }
        cout << ((count == n-1) ? "Jolly\n" : "Not jolly\n");
    }
}
