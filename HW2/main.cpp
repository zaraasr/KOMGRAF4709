#include <iostream>
#include<vector>

using namespace std;

//fungsi untuk menampilkan element matriks
void tampilanMatriks(const vector<vector<int>>& matriks){ //parameter fungsi yg akan ditampilkan
    for(const auto& baris : matriks){ // Loop pertama, mengiterasi melalui setiap baris dalam matriks
        cout << "|" ;
        for(int element : baris){ // Loop kedua, mengiterasi melalui setiap elemen dalam baris matriks.
            cout << element << " ";
        }
        cout << "|" << endl;
    }
}

//fungsi penjumlahan matriks
    vector<vector<int>> penjumlahanMatriks(const vector<vector<int>>& matriks1, const vector<vector<int>>& matriks2){ //parameter 1 & 2 yg akan dijumlahkan & diberi tanda const agar matriks gabisa diubah oleh fungsi
        //const untuk memastikan bahwa matriks input tersebut tidak akan dimodifikasi selama proses penjumlahan didalam fungsi penjumlahanMatriks
        //ukuran matriks
        int baris = matriks1.size();
        int kolom = matriks1[0].size();

        vector<vector<int>> hasil(baris, vector<int>(kolom, 0)); //kolm&barismatriks hasil

        for(int i = 0; i < baris; ++i){
            for(int j = 0; j < kolom; ++j){
                hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            }
        }

        return hasil;
}

//fungsi pengurangan matriks
    vector<vector<int>> penguranganMatriks(const vector<vector<int>>& matriks1, const vector<vector<int>>& matriks2){
        //memakai const untuk memastikan bahwa matriks input tersebut tidak akan dimodifikasi selama proses penjumlahan di dalam fungsi masukkanMatriks
        int baris = matriks1.size();
        int kolom = matriks1[0].size();

        vector<vector<int>> hasil(baris, vector<int>(kolom, 0));

        for(int i = 0; i<baris; ++i){
            for(int j = 0; j < kolom; ++j){
                hasil[i][j] = matriks1[i][j] - matriks2[i][j];
            }
        }

        return hasil;
}

//fungsi untuk perkalian skalar
    vector<vector<int>> skalarMatriks(const vector<vector<int>>& matriks, int angka){
        //memakai const untuk memastikan bahwa matriks input tersebut tidak akan dimodifikasi selama proses penjumlahan di dalam fungsi masukkanMatriks
        int baris = matriks.size();
        int kolom = matriks[0].size();

        vector<vector<int>> hasil(baris, vector<int>(kolom, 0));

        for (int i = 0; i < baris; ++i) {
            for (int j = 0; j < kolom; ++j) {
                hasil[i][j] = matriks[i][j] * angka;
            }
        }

        return hasil;
}

int main(){
    int pilihan;
    int baris, kolom;

    cout << "Masukkan jumlah baris matriks : ";
    cin >> baris;
    cout << "=================================================" << endl;
    cout << "Masukkan jumlah kolom matriks : ";
    cin >> kolom;
    cout << "=================================================" << endl;

    vector<vector<int>> matriks1(baris, vector<int>(kolom));
    vector<vector<int>> matriks2(baris, vector<int>(kolom));

    cout << "***** Matriks A *****\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << "- Masukkan angka baris " << i + 1 << " kolom " << j + 1 << " : ";
            cin >> matriks1[i][j];
        }
    }
    cout << "=================================================" << endl;

    cout << "***** Matriks B *****\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << "- Masukkan angka baris " << i + 1 << " kolom " << j + 1 << " : ";
            cin >> matriks2[i][j];
        }
    }
    cout << "=================================================" << endl;

    cout << "Pilih operasi yang diinginkan : " << endl;
    cout << " 1. Penjumlahan Matriks\n";
    cout << " 2. Pengurangan Matriks\n";
    cout << " 3. Perkalian Skalar Matriks\n";
    cout << "=================================================" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    cout << "=================================================" << endl;

    switch (pilihan) {
        case 1:
            cout << "Matriks A:\n";
            tampilanMatriks(matriks1);
            cout << "Matriks B:\n";
            tampilanMatriks(matriks2);
            cout << "Hasil penjumlahan matriks:\n";
            tampilanMatriks(penjumlahanMatriks(matriks1, matriks2));
            break;
        case 2:
            cout << "Matriks A:\n";
            tampilanMatriks(matriks1);
            cout << "Matriks B:\n";
            tampilanMatriks(matriks2);
            cout << "Hasil pengurangan matriks:\n";
            tampilanMatriks(penguranganMatriks(matriks1, matriks2));
            break;
        case 3:
            int angka;
            cout << "Masukkan skalar: ";
            cin >> angka;
            cout << "=================================================" << endl;
            cout << "Matriks:\n";
            tampilanMatriks(matriks1);
            cout << "Hasil perkalian skalar :\n";
            tampilanMatriks(skalarMatriks(matriks1, angka));
            break;
        default:
            cout << " Not Found \n";
            break;
    }

    return 0;
}
