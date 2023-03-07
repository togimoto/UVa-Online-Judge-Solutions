#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string line;
    getline(cin, line);
    while(N--) {
        vector<string> H;
        while(getline(cin, line)) {
            if(line == "")
                break;
            H.push_back(line);
        }
        if(H.empty())
            continue;
        int M = H[0].length() - 2;
        string msg; 
        for(int j = 1; j <= M; j++) {
            vector<pair<int, int> > vec;
            for(int i = 1; i <= 8; i++) {
                pair<int, int> b(pow(2, i-1), (H[i][j] == '/') ? 0 : 1);
                vec.push_back(b);
            }
            int c = 0;
            for(int i = 0; i < 8; i++)
                if((c/vec[i].first) % 2 != vec[i].second) {
                    c++;
                    i = -1;
                }
            msg += (char)c;
        }
        cout << msg << '\n';
    }
}
