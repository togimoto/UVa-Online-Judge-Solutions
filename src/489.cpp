#include <iostream>
#include <string>
using namespace std;

#define WIN "You win.\n"
#define LOSE "You lose.\n"
#define CHICKEN "You chickened out.\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int round;
    string word, guess;
    while(true) {
        cin >> round;
        if(round == -1)
            break;
        cout << "Round " << round << '\n';
        cin >> word >> guess;
        int word_len = word.length(), guess_len = guess.length();
        int arr[26] = {0};
        for(int i = 0; i < word_len; i++)
            arr[word[i] - 'a']++;
        int wrong = 0, guessed = 0;
        for(int i = 0; i < guess_len; i++) {
            if(arr[guess[i]-'a'] == 0) {
                arr[guess[i]-'a'] = -1;
                if(++wrong == 7) {
                    cout << LOSE;
                    break;
                }
            }
            else if(arr[guess[i]-'a'] > 0) {
                guessed += arr[guess[i]-'a'];
                arr[guess[i]-'a'] = -1;
                if(guessed == word_len) {
                    cout << WIN;
                    break;
                }
            }
        }
        if(wrong != 7 && guessed != word_len)
            cout << CHICKEN;
    }
}
