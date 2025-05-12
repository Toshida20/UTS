#include <iostream>
#include <conio.h>
using namespace std;

int nilai[5];
int n = 0;

void Bersih() { //biar mempermudah bersih bersih layar terminal
    system("cls");
}
//MENU 4
void info() {
    Bersih(); //copy ini
    cout << "==========INFORMASI TENTANG SAYA==========\n";
    cout << "Nama saya Ahmad Tijani\n";
    cout << "Saya berkuliah di Politeknik Negeri Banjarmasin\n";
    cout << "Dengan NIM C030324062\n";
    cout << "Saya elas 2B D3 Teknik Informatika\n";
    cout << "Dan hobi saya adalah suka belajar hal baru! :D\n";
    cout << "\nTekan [E] untuk kembali ke menu utama...";
    while (getch() != 'e' && getch() != 'E');
}
//MENU UTAMA
void dMenu() {
    Bersih();
    cout << "==========APLIKASI TAMPILAN MENU==========\n";  
    cout << "1. Memasukkan nilai ke array\n";
    cout << "2. Menampilkan array\n";
    cout << "3. Menyortir array (Metode Bubble Sort)\n";
    cout << "4. Informasi \n";
    cout << "5. Exit\n";
    cout << "Masukan pilihan opsi: ";        
}
//MENU 1
void mPertama() {
    Bersih();
    cout << "Masukkan nilai array (Maksimal 5 angka) \n";
    n = 5;
    for (int i = 0; i < n; ) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> nilai[i];

        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Input tidak tersedia!, coba lagi\n";
            continue;
        }
        i++;
    }

    cout << "Data berhasil dimasukkan!\n";
    cout << "\nTekan [E] untuk kembali ke menu utama...";
    while (getch() != 'e' && getch() != 'E');
}

//MENU 2
void mKedua() {
    Bersih();
    if (n == 0) {
        cout << "Nilai masih kosong. Silakan masukkan nilai dulu pada menu 1\n";
    } else {
        cout << "Isi array saat ini:\n";
        for (int i = 0; i < n; i++) {
            cout << nilai[i] << " ";
        }
        cout << "\n";
    }
    cout << "\nTekan [E] untuk kembali ke menu utama...";
    while (getch() != 'e');
}
//LOGIKA SORTIR NILAI
void tukar(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void kecilKeBesar(int data[], int Jum) {
    for (int i = 1; i < Jum; i++) {
        for (int j = Jum - 1; j >= i; j--) {
            if (data[j] < data[j - 1]) {
                tukar(&data[j], &data[j-1]);
            }
        }
    }
}

void besarKeKecil(int data[], int Jum) {
    for (int i = 1; i < Jum; i++) {
        for (int j = 0; j < Jum - i; j++) {
            if (data[j] < data[j + 1]) {
                tukar(&data[j], &data[j+1]);
            }
        }
    }
}


void mKetiga() {
    if (n == 0) {
        Bersih();
        cout << "Nilai masih kosong. Tidak ada yang bisa disortir.\n";
        cout << "\nTekan [E] untuk kembali ke menu utama...";
        while (getch() != 'e' && getch() != 'E');
        return;
    }

    char pilih;
    do {
        Bersih();
        cout << "==========MENU SORTIR==========\n";
        cout << "1. Dari kecil ke besar (ascending)\n";
        cout << "2. Dari besar ke kecil (descending)\n";
        cout << "Pilih [E] untuk kembali ke menu utama...\n";
        cout << "Pilih salahsatu opsi: ";
        cin >> pilih;
        //codingan sortir kecil ke besar dan sebaliknya (DONEEEE)
        if (pilih == '1') {
            kecilKeBesar(nilai, n);
            cout << "Nilai berhasil disortir dari kecil ke besar:\n";
            for (int i = 0; i < n; i++) cout << nilai[i] << " ";
            cout << "\n\nTekan [E] untuk kembali ke menu sortir...";
            while (getch() != 'e' && getch() != 'E');
        } else if (pilih == '2') {
            besarKeKecil(nilai, n);
            cout << "Nilai berhasil disortir dari besar ke kecil:\n";
            for (int i = 0; i < n; i++) cout << nilai[i] << " ";
            cout << "\n\nTekan [E] untuk kembali ke menu sortir...";
            while (getch() != 'e' && getch() != 'E');
        } else if (pilih != 'e' && pilih != 'E') {
            cout << "Pilihan tidak tersedia!\n";
            cout << "\nTekan [E] untuk kembali ke menu sortir...";
            while (getch() != 'e' && getch() != 'E');
        }
    } while (pilih != 'e' && pilih != 'E');
}
//tumbul pilihan
int main() {
    char pl;
    do {
        dMenu();
        pl = getch();
        switch (pl) {
            case '1':
            mPertama();
            break;
            case '2':
            mKedua();
            break;
            case '3':
            mKetiga();
            break;
            case '4':
            info();
            break;
            case '5':
            break;

            //bagian mun kdd pilihan
            default:
                Bersih();
                cout << "Pilihan tidak tersedia!\n";
                cout << "\nTekan [E] untuk kembali ke menu utama...";
                while (getch() != 'e');
                break;
        }
    } while (pl != '5');
    Bersih();
    cout << "Keluar dari program... bye!\n";
    return 0;
}