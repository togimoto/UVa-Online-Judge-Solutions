#include <iostream>
#include <vector>
#include <string>
using namespace std;

char digit_template[10][5][3] = {
{ //zero
    {' ', '-', ' '},
    {'|', ' ', '|'},
    {' ', ' ', ' '},
    {'|', ' ', '|'},
    {' ', '-', ' '}
},

{ //one
    {' ', ' ', ' '},
    {' ', ' ', '|'},
    {' ', ' ', ' '},
    {' ', ' ', '|'},
    {' ', ' ', ' '}
},

{ //two
    {' ', '-', ' '},
    {' ', ' ', '|'},
    {' ', '-', ' '},
    {'|', ' ', ' '},
    {' ', '-', ' '}
},

{ //three
    {' ', '-', ' '},
    {' ', ' ', '|'},
    {' ', '-', ' '},
    {' ', ' ', '|'},
    {' ', '-', ' '}
},

{ //four
    {' ', ' ', ' '},
    {'|', ' ', '|'},
    {' ', '-', ' '},
    {' ', ' ', '|'},
    {' ', ' ', ' '}
},

{ //five
    {' ', '-', ' '},
    {'|', ' ', ' '},
    {' ', '-', ' '},
    {' ', ' ', '|'},
    {' ', '-', ' '}
},

{ //six
    {' ', '-', ' '},
    {'|', ' ', ' '},
    {' ', '-', ' '},
    {'|', ' ', '|'},
    {' ', '-', ' '}
},

{ //seven
    {' ', '-', ' '},
    {' ', ' ', '|'},
    {' ', ' ', ' '},
    {' ', ' ', '|'},
    {' ', ' ', ' '}
},

{ //eight
    {' ', '-', ' '},
    {'|', ' ', '|'},
    {' ', '-', ' '},
    {'|', ' ', '|'},
    {' ', '-', ' '}
},

{ //nine
    {' ', '-', ' '},
    {'|', ' ', '|'},
    {' ', '-', ' '},
    {' ', ' ', '|'},
    {' ', '-', ' '}
}
};

void print_line(vector<int> &digits, int s, int line_num, int lines) {
    string output;
    int len = digits.size();
    for(int i = 0; i < len; i++) {
        output += digit_template[digits[i]][line_num][0];
        for(int j = 0; j < s; j++)
            output += digit_template[digits[i]][line_num][1];
        output += digit_template[digits[i]][line_num][2];
        if(i+1 < len)
            output += ' ';
    }
    output += '\n';
    for(int i = 0; i < lines; i++)
        cout << output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
        int s;
        cin >> s;
        if(s == 0)
            break;
        char c;
        while((c = cin.get()) == ' ')
            continue;
        vector<int> digits;
        do
            digits.push_back(c - '0');
        while((c = cin.get()) != '\n');
        print_line(digits, s, 0, 1);
        print_line(digits, s, 1, s);
        print_line(digits, s, 2, 1);
        print_line(digits, s, 3, s);
        print_line(digits, s, 4, 1);
        cout << '\n';
    }
}
