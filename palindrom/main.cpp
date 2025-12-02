#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cout << "Zadej slovo: ";
    cin >> text;

    bool jePalindrom = true;
    int n = text.length();

    for (int i = 0; i < n/2; i++) {
        if(text[i] != text[n - 1 - i]) {
            jePalindrom = false;
            break;
        }
    }
    if (jePalindrom)
        cout << "Slovo \"" << text << "\" je palindrom." << endl;
    else
        cout << "Slovo \"" << text << "\" neni palindrom." << endl;
    
    return 0;


}