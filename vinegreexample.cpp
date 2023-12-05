#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(string plaintext, string key) {
    string ciphertext = "";
    int keyLength = key.length();

    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        if (isalpha(plainChar)) {
            char base = isupper(plainChar) ? 'A' : 'a';
            char encryptedChar = (plainChar + keyChar - 2 * base) % 26 + base;
            ciphertext += encryptedChar;
        } else {
            ciphertext += plainChar;  // Preserve non-alphabetic characters
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

        if (isalpha(cipherChar)) {
            char base = isupper(cipherChar) ? 'A' : 'a';
            char decryptedChar = (cipherChar - keyChar + 26) % 26 + base;
            decryptedText += decryptedChar;
        } else {
            decryptedText += cipherChar;  // Preserve non-alphabetic characters
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
