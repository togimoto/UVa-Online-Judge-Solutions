#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

vector<string> list;
int ind = 0;
string word, line;

inline void add_word() {
    cout << word;
    list.insert(list.begin(), word);
    word = "";
}

inline void move_front() {
    string temp = list[ind-1];
    list.erase(list.begin()+ind-1);
    list.insert(list.begin(), temp);
    ind = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(getline(cin, line)) {
        if(line == "0")
            break;
        line += "\n";
        int length = line.length();
        for(int i = 0; i < length; i++) {
            if(isalpha(line[i])) {
                word += line[i];
                if(ind > 0) {
                    move_front();
                    cout << list[0];
                }
            }
            else if(isdigit(line[i])) {
                if(!word.empty())
                    add_word();
                ind = ind * 10 + line[i] - '0';
            } else {
                if(!word.empty())
                    add_word();
                else if(ind > 0) {
                    move_front();
                    cout << list[0];
                }
                cout << line[i];
            }
        }
    }
}
