#include <iostream>
using namespace std;

int adj[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

inline void toCoords(int coords[2], int index) {
    coords[0] = index/8;
    coords[1] = index%8;
    return;
}

inline bool out_of_bounds(int coord) {
    if(coord < 0 || 7 < coord)
        return true;
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int first, second, third;
    while(cin >> first >> second >> third) {
        if(first == second) {
            cout << "Illegal state\n";
            continue;
        }
        int king[2], queen[2], move[2];
        toCoords(king, first);
        toCoords(queen, second);
        toCoords(move, third);
        if((queen[0] != move[0] && queen[1] != move[1]) || second == third) {
            cout << "Illegal move\n";
            continue;
        }
        if(queen[0] == move[0]) { //same row
            if(queen[0] == king[0]) {
                if(queen[1] < king[1]) {
                    if(move[1] - queen[1] >= king[1] - queen[1]) {
                        cout << "Illegal move\n";
                        continue;
                    }
                } else {
                    if(queen[1] - move[1] >= queen[1] - king[1]) {
                        cout << "Illegal move\n";
                        continue;
                    }
                }
            }
        } else { //same col
            if(queen[1] == king[1]) {
                if(queen[0] < king[0]) {
                    if(move[0] - queen[0] >= king[0] - queen[0]) {
                        cout << "Illegal move\n";
                        continue;
                    }
                } else {
                    if(queen[0] - move[0] >= queen[0] - king[0]) {
                        cout << "Illegal move\n";
                        continue;
                    }
                }
            }
        }
        bool allowed = true;
        for(int i = 0; i < 4; i++)
            if((move[0] == king[0] + adj[i][0]) && (move[1] == king[1] + adj[i][1])) {
                allowed = false;
                break;
            }
        if(!allowed) {
            cout << "Move not allowed\n";
            continue;
        }
        bool cont = false;
        for(int i = 0; i < 4; i++) {
            if(out_of_bounds(king[0] + adj[i][0]) || out_of_bounds(king[1] + adj[i][1]))
                continue;
            if((king[0] + adj[i][0] != move[0]) && (king[1] + adj[i][1] != move[1])) {
                cont = true;
                break;
            }
        }
        if(!cont)
            cout << "Stop\n";
        else
            cout << "Continue\n";
    }
    return 0;
}
