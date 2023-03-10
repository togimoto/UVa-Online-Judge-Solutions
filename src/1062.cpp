#include <iostream>
#include <vector>
#include <string>
using namespace std;

string line;
int case_num = 0, last_stack, length;

inline int get_index(char c) {
    return c - 'A';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(getline(cin, line)) {
        if(line == "end")
            break;
        case_num++;
        int location[26] = {-1};
        vector<char> stack_tops;
        stack_tops.push_back(line[0]);
        location[get_index(line[0])] = 0;
        length = line.length();
        for(int i = 1; i < length; i++) {
            if(location[get_index(line[i])] < 0) {
                int j;
                for(j = 0; stack_tops.begin()+j != stack_tops.end(); j++) {
                    if(get_index(stack_tops[j]) > get_index(line[i]))
                        break;
                }
                if(stack_tops.begin()+j != stack_tops.end()) {
                    stack_tops[j] = line[i];
                    location[get_index(line[i])] = j;
                } else {
                    stack_tops.push_back(line[i]);
                    location[get_index(line[i])] = j;
                }
            } else {
                if(get_index(stack_tops[location[get_index(line[i])]]) < get_index(line[i])) {
                    int j;
                    for(j = 0; stack_tops.begin()+j != stack_tops.end(); j++) {
                        if(get_index(stack_tops[j]) > get_index(line[i]))
                            break;
                    }
                    if(stack_tops.begin()+j != stack_tops.end()) {
                        stack_tops[j] = line[i];
                        location[get_index(line[i])] = j;
                    } else {
                        stack_tops.push_back(line[i]);
                        location[get_index(line[i])] = j;
                    }
                }
            }
        }
        cout << "Case " << case_num << ": " << stack_tops.size() << "\n";
    }
}
