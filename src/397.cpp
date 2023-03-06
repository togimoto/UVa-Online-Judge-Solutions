#include <bits/stdc++.h>
using namespace std;

inline void print(vector<int> &operands, vector<char> &operators, string &var) {
    for(pair<vector<int>::iterator, vector<char>::iterator> it(operands.begin(), operators.begin());
    it.second != operators.end();
    it.first++, it.second++)
        cout << *it.first << ' ' << *it.second << ' ';
    cout << operands.back() << " = " << var << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    char op;
    while(cin >> num >> op) {
        vector<int> operands;
        vector<char> operators;
        while(op != '=') {
            operands.push_back(num);
            operators.push_back(op);
            cin >> num >> op;
        }
        operands.push_back(num);
        string var;
        cin >> var;
        int size = operators.size();
        print(operands, operators, var);
        for(int i = 0; i < size; i++) {
            if(operators[i] == '+' || operators[i] == '-')
                continue;
            int operand_1 = operands[i], operand_2 = operands[i+1];
            operands.erase(operands.begin()+i, operands.begin()+i+2);
            op = operators[i];
            operators.erase(operators.begin()+i);
            int result;
            switch(op) {
            case '*':
                result = operand_1 * operand_2;
                break;
            case '/':
                result = operand_1 / operand_2;
                break;
            }
            operands.insert(operands.begin()+i, result);
            i--; size--;
            print(operands, operators, var);
        }
        for(int i = 0; size != 0; size--) {
            int operand_1 = operands[i], operand_2 = operands[i+1];
            operands.erase(operands.begin()+i, operands.begin()+i+2);
            op = operators[i];
            operators.erase(operators.begin()+i);
            int result;
            switch(op) {
            case '+':
                result = operand_1 + operand_2;
                break;
            case '-':
                result = operand_1 - operand_2;
                break;
            }
            operands.insert(operands.begin()+i, result);
            print(operands, operators, var);
        }
        cout << '\n';
    }
}
