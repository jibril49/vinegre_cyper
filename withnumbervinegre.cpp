#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(string plaintext, string key) {
    string ciphertext = "";
    int keyLength = key.length();

    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        if (isalnum(plainChar)) {
            char base;
            int charRange;

            if (isalpha(plainChar)) {
                base = isupper(plainChar) ? 'A' : 'a';
                charRange = 26;
            } else if (isdigit(plainChar)) {
                base = '0';
                charRange = 10;
            }

            char encryptedChar = (plainChar + keyChar - 2 * base) % charRange + base;
            ciphertext += encryptedChar;
        } else {
            ciphertext += plainChar;  // Preserve non-alphanumeric characters
        }
    }

    return ciphertext;
}

string decryptVigenere(string ciphertext, string key) {
    string decryptedText = "";
    int keyLength = key.length();

    for (int i = 0; i < ciphertext.length(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLength];

        if (isalnum(cipherChar)) {
            char base;
            int charRange;

            if (isalpha(cipherChar)) {
                base = isupper(cipherChar) ? 'A' : 'a';
                charRange = 26;
            } else if (isdigit(cipherChar)) {
                base = '0';
                charRange = 10;
            }

            char decryptedChar = (cipherChar - keyChar + charRange) % charRange + base;
            decryptedText += decryptedChar;
        } else {
            decryptedText += cipherChar;  // Preserve non-alphanumeric characters
        }
    }

    return decryptedText;
}

int main() {
    string plaintext;
    string key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    getline(cin, key);

    string ciphertext = encryptVigenere(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;

    string decryptedText = decryptVigenere(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
