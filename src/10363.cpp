#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char> > grid;

inline void read_grid(grid &g) {
    char c;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> c;
            g[i].push_back(c);
        }
    }
}

pair<int,int> count_marks(grid &g) {
    int x_count = 0, o_count = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(g[i][j] == 'X')
                x_count++;
            else if(g[i][j] == 'O')
                o_count++;
        }
    }
    pair<int,int> count(x_count, o_count);
    return count;
}

inline bool is_mark(char mark) {
    return (mark == 'X' || mark == 'O');
}

int complete_lines(grid &g, vector<char> &winner) {
    int count = 0;
    for(int i = 0; i < 3; i++) {
        if(is_mark(g[i][0]) && g[i][0] == g[i][1] && g[i][1] == g[i][2]) {
            winner.push_back(g[i][0]);
            count++;
        }
        if(is_mark(g[0][i]) && g[0][i] == g[1][i] && g[1][i] == g[2][i]) {
            winner.push_back(g[0][i]);
            count++;
        }
    }
    if(is_mark(g[0][0]) && g[0][0] == g[1][1] && g[1][1] == g[2][2]) {
        winner.push_back(g[0][0]);
        count++;
    }
    if(is_mark(g[2][0]) && g[2][0] == g[1][1] && g[1][1] == g[0][2]) {
        winner.push_back(g[2][0]);
        count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    while(N--) {
        grid g(3);
        read_grid(g);
        pair<int, int> count = count_marks(g);
        if(!(0 <= count.first-count.second && count.first-count.second <= 1)) {
            cout << "no\n";
            continue;
        }
        vector<char> winner;
        int lines = complete_lines(g, winner);
        if(lines > 2) {
            cout << "no\n";
            continue;
        }
        bool valid = true;
        if(lines > 0) {
            if(count.first-count.second == 0) {
                for(char c : winner) {
                    if(c != 'O') {
                        valid = false;
                        break;
                    }
                }
            } else { 
                for(char c : winner) {
                    if(c != 'X') {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if(!valid)
            cout << "no\n";
        else
            cout << "yes\n";
    }
}
