#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
        string score;
        getline(cin, score);
        if(score[0] == 'G')
            break;
        int len = score.length();
        vector<int> values;
        for(int i = 0; i < len; i+=2) {
            switch(score[i]) {
            case 'X':
                values.push_back(10);
                break;
            case '/':
                values.push_back('9' - score[i-2] + 1);
                break;
            default:
                values.push_back(score[i] - '0');
                break;
            }
        }
        int total = 0, frame = 1, roll = 1, size = values.size();
        for(int i = 0, j = 0; i < len; i+=2, j++) {
            switch(score[i]) {
            case 'X':
                if(frame == 10)
                    total += values[j];
                else {
                    total += values[j] + values[j+1] + values[j+2];
                    frame++;
                }
                break;
            case '/':
                if(frame == 10)
                    total += values[j];
                else {
                    total += values[j] + values[j+1];
                    roll = 1;
                    frame++;
                }
                break;
            default:
                total += values[j];
                if(roll == 1)
                    roll = 2;
                else {
                    roll--;
                    frame++;
                }
                break;
            }
        }
        cout << total << '\n';
    }
}
