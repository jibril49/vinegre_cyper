# vinegre_cyper
vinegere cyper with plain text, key , encrpyt and decrypt

### Fungsi `encryptVigenere`:

```cpp
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
            ciphertext += plainChar;  // Menjaga karakter non-alfabet
        }
    }

    return ciphertext;
}
```

- `string ciphertext = "";`: Menginisialisasi string kosong untuk menyimpan teks terenkripsi.
- `int keyLength = key.length();`: Menghitung panjang kunci.
- `for (int i = 0; i < plaintext.length(); i++) {`: Melakukan iterasi pada setiap karakter dalam teks masukan.

  - `char plainChar = plaintext[i];`: Mengambil karakter saat ini dari teks masukan.
  - `char keyChar = key[i % keyLength];`: Mengambil karakter yang sesuai dari kunci, dengan pembungkus jika panjang kunci lebih pendek dari panjang teks masukan.

  - `if (isalpha(plainChar)) {`: Memeriksa apakah karakter saat ini adalah karakter alfabet.

    - `char base = isupper(plainChar) ? 'A' : 'a';`: Menentukan karakter dasar ('A' untuk huruf besar, 'a' untuk huruf kecil).
    - `char encryptedChar = (plainChar + keyChar - 2 * base) % 26 + base;`: Menggunakan rumus enkripsi Vigenère untuk mendapatkan karakter terenkripsi.
    - `ciphertext += encryptedChar;`: Menambahkan karakter terenkripsi ke dalam ciphertext.

  - `else { ciphertext += plainChar; }`: Menjaga karakter non-alfabet dalam ciphertext.

- `return ciphertext;`: Mengembalikan teks terenkripsi.

### Fungsi `decryptVigenere`:

```cpp
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
            decryptedText += cipherChar;  // Menjaga karakter non-alfabet
        }
    }

    return decryptedText;
}
```

- Mirip dengan `encryptVigenere`, fungsi ini mendekripsi ciphertext yang dienkripsi menggunakan Vigenère.
- `char decryptedChar = (cipherChar - keyChar + 26) % 26 + base;`: Menggunakan rumus dekripsi Vigenère untuk mendapatkan karakter terdekripsi.
- Logika selanjutnya mirip dengan fungsi enkripsi.

### Fungsi `main`:

```cpp
int main() {
    string plaintext;
    string key;

    cout << "Masukkan teks: ";
    getline(cin, plaintext);

    cout << "Masukkan kunci: ";
    getline(cin, key);

    string ciphertext = encryptVigenere(plaintext, key);
    cout << "Teks terenkripsi: " << ciphertext << endl;

    string decryptedText = decryptVigenere(ciphertext, key);
    cout << "Teks terdekripsi: " << decryptedText << endl;

    return 0;
}
```

- Mengambil input untuk teks dan kunci dari pengguna.
- Memanggil `encryptVigenere` untuk mengenkripsi teks dengan kunci yang diberikan.
- Menampilkan teks terenkripsi.
- Memanggil `decryptVigenere` untuk mendekripsi ciphertext dengan kunci yang sama.
- Menampilkan teks terdekripsi.

Program lengkap ini memungkinkan pengguna untuk memasukkan teks dan kunci, kemudian mengenkripsi dan mendekripsi teks menggunakan cipher Vigenère, dan menampilkan hasilnya.
