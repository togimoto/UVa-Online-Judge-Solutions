#include <bits/stdc++.h>
using namespace std;

void print(const list<char> &l) {
    for(char c : l)
        cout << c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char c;
    while(cin.get(c)) {
        list<list<char> > beiju;
        list<char> output;
        bool end = false;
        do {
            switch(c) {
            case '[': {
                list<char> l;
                cin.get(c);
                while(c != '\n' && c != ']') {
                    if(c == '[') {
                        if(!l.empty()) {
                            beiju.insert(beiju.begin(), l);
                            l.clear();
                        }
                    } else
                        l.insert(l.end(), c);
                    cin.get(c);
                }
                if(!l.empty())
                    beiju.insert(beiju.begin(), l);
                if(c == '\n')
                    end = true;
                break;
            }
            case ']':
                break;
            default:
                output.insert(output.end(), c);
                break;
            }
            if(end)
                break;
            cin.get(c);
        } while(c != '\n');
        for(const list<char> l : beiju)
            print(l);
        print(output);
        cout << "\n";
    }
}
