#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>

using std::string;
const int NUM = 26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal",
 "danger", "ensign", "florid", "garage", "health", "insult",
 "jackal", "keeper", "loaner", "manage", "nonce", "onset",
 "plaid", "quilt", "remote", "stolid", "train", "useful",
 "valid", "whence", "xenon", "yearn", "zippy"};


 int main() {
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    // std::vector<int>::iterator iter;
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    while(play == 'y') {
        string target = wordlist[std::rand() & NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length << " letters, and you guess\n" << "one letter at a time. You get " << guesses << " wrong gursses.\n";
        cout << "Your word: " << attempt << endl;
        while(guesses> 0 && attempt != target) {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
                cout << "you already guessesd that. Try again.\n";
                    continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos) {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            } else {
                cout << "Good guess!\n";
                attempt[loc]=letter;
                loc = target.find(letter, loc + 1);
                while(loc != string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt <<endl;

            if (attempt != target) {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad gursses left\n";
            }
        }
        if (guesses > 0)
            cout << "That is right:\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you paly another? <y/n>";
        cin >> play;
        play = tolower(play);

    }

    cout << "Bye\n";
    return 0;
 }