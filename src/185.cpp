#include <bits/stdc++.h>
using namespace std;

char roman_chars[7] = {'I', 'X', 'C', 'M', 'V', 'L', 'D'};
int roman_vals[7] = {1, 10, 100, 1000, 5, 50, 500};

inline int roman_char_to_arab(char roman) {
    for(int i = 0; i < 7; i++)
        if(roman == roman_chars[i])
            return roman_vals[i];
    return -1;
}

inline int roman_num_to_arab(string roman) {
    int arabic = 0, len = roman.length();
    for(int i = 0; i < len-1; i++) {
        int curr = roman_char_to_arab(roman[i]);
        arabic += (curr < roman_char_to_arab(roman[i+1]) ? -curr : curr);
    }
    arabic += roman_char_to_arab(roman[len-1]);
    return arabic;
}

inline int roman_num_to_arab(string roman, vector<char> &char_set, vector<int> &vals) {
    int num = 0, len = roman.length(), size = char_set.size();
    for(int i = 0; i < len; i++)
        for(int j = 0; j < size; j++)
            if(roman[i] == char_set[j]) {
                if(num == 0 && vals[j] == 0)
                    return 0;
                num = num * 10 + vals[j];
                break;
            }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1) {
        string line;
        getline(cin, line);
        if(line == "#")
            break;
        bool appeared[7] = {false};
        vector<char> char_set;
        string first, second, sum;
        int index = 0, len = line.length();
        while(line[index] != '+') {
            for(int i = 0; i < 7; i++)
                if(line[index] == roman_chars[i]) {
                    if(!appeared[i]) {
                        char_set.push_back(roman_chars[i]);
                        appeared[i] = true;
                    }
                    break;
                }
            first += line[index++];
        }
        index++;
        while(line[index] != '=') {
            for(int i = 0; i < 7; i++)
                if(line[index] == roman_chars[i]) {
                    if(!appeared[i]) {
                        char_set.push_back(roman_chars[i]);
                        appeared[i] = true;
                    }
                    break;
                }
            second += line[index++];
        }
        index++;
        while(index < len) {
            for(int i = 0; i < 7; i++)
                if(line[index] == roman_chars[i]) {
                    if(!appeared[i]) {
                        char_set.push_back(roman_chars[i]);
                        appeared[i] = true;
                    }
                    break;
                }
            sum += line[index++];
        }
        int first_arab = roman_num_to_arab(first);
        int second_arab = roman_num_to_arab(second);
        int sum_arab = roman_num_to_arab(sum);
        cout << (first_arab + second_arab == sum_arab ? "Correct" : "Incorrect") << ' ';
        int size = char_set.size();
        vector<int> perm;
        for(int i = 0; i <= 9; i++)
            perm.push_back(i);
        int prev_first = -1, prev_second = -1, prev_sum = -1, count = 0;
        do {
            if((first_arab = roman_num_to_arab(first, char_set, perm)) == 0)
                continue;
            if((second_arab = roman_num_to_arab(second, char_set, perm)) == 0)
                continue;
            if((sum_arab = roman_num_to_arab(sum, char_set, perm)) == 0)
                continue;
            if(first_arab + second_arab != sum_arab)
                continue;
            if(!(first_arab == prev_first && second_arab == prev_second && sum_arab == prev_sum)) {
                prev_first = first_arab;
                prev_second = second_arab;
                prev_sum = sum_arab;
                if(count++ > 1)
                    break;
            }
        } while(next_permutation(perm.begin(), perm.end()));
        if(count == 0)
            cout << "impossible\n";
        else if(count == 1)
            cout << "valid\n";
        else
            cout << "ambiguous\n";
    }
}
