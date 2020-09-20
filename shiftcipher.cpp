#include<iostream>
#include<string>

using namespace std;

void encrypt() {
    string x, y;
    int i, k;
    char c;
    bool gagal;
    gagal = false;

    cout << "Plain text : ";
    cin.ignore();
    getline(cin, x);
    cout << "Key : "; cin >> k;
    y = " ";

    for (i = 0; i < x.length(); i++) {
        c = x[i];
        //ascii huruf kecil dari indeks ke 97 - 122
        if (c >= 97 && c <= 122) {
            c = c - 97;
            c = (c + k) % 26;
            c = c + 97;
        }
        //ascii huruf kapital dari indeks 65 - 90
        else if (c >= 65 && c <= 90) {
            c = c - 65;
            c = (c + k) % 26;
            c = c + 65;
        }
        else {
            cout << "Hanya menerima input abjad" << endl;
            gagal = true;
            break;
        }
        y = y + c;
    }
    if (gagal == true) {
        cout << "Gagal mengenkripsi, input tidak sesuai";
    } else {
        cout << "Ciphertext: " << y << endl;
    }
}

void decrypt() {
    string x, y;
    int i, k;
    char c;
    bool gagal;
    gagal = false;

    cout << "Cipher text : ";
    cin.ignore();
    getline(cin, y);
    cout << "Key : "; cin >> k;
    x = " ";

    for (i = 0; i < y.length(); i++) {
        c = y[i];
        //ascii huruf kecil dari indeks ke 97 - 122
        if (c >= 97 && c <= 122) {
            c = c - 97;
            if (c - k < 0) {
                c = 26 + (c - k);
            }
            else {
                c = (c - k) % 26;
            }
            c = c + 97;
        }
        //ascii huruf kapital dari indeks 65 - 90
        else if (c >= 65 && c <= 90) {
            c = c - 65;
            if (c - k < 0) {
                c = 26 + (c - k);
            }
            else {
                c = (c - k) % 26;
            }
            c = c + 65;
        }
        else {
            cout << "Hanya menerima input abjad" << endl;
            gagal = true;
            break;
        }
        x = x + c;
    }
    if (gagal == true) {
        cout << "Gagal mendekripsi, input tidak sesuai";
    } else {
        cout << "Plaintext: " << x << endl;
    }
}

main() {
    int menu;

    do
    {
        cout << "1. Enkripsi" << endl;
        cout << "2. Dekripsi" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (menu >= 3);
    
}