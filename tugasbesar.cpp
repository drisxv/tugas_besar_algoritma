
#include <iostream>
#include <string>

using namespace std;

int main() {
    int id[100];
    string nama[100];
    int saldo[100];

    int jumlahAnggota = 0;
    int idBerikutnya = 1;
    int pilihan;

    do {
        cout << "\n===== MENU ADMIN KOPERASI =====" << endl;
        cout << "1. Tambahkan Anggota" << endl;
        cout << "2. Lihat Daftar Anggota dan Saldo" << endl;
        cout << "3. Setor Tunai Anggota" << endl;
        cout << "4. Tarik Tunai Anggota" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1: {
                if (jumlahAnggota >= 100) {
                    cout << "Kapasitas anggota penuh." << endl;
                }
                else {
                    cout << "Masukkan nama anggota: ";
                    cin >> ws;
                    getline(cin, nama[jumlahAnggota]);

                    id[jumlahAnggota] = idBerikutnya;
                    saldo[jumlahAnggota] = 0;

                    cout << "Anggota berhasil ditambahkan dengan ID "
                         << idBerikutnya << "." << endl;

                    jumlahAnggota++;
                    idBerikutnya++;
                }
                break;
            }

            case 2: {
                if (jumlahAnggota == 0) {
                    cout << "Belum ada anggota." << endl;
                }
                else {
                    cout << "\n===== DAFTAR ANGGOTA =====" << endl;

                    for (int i = 0; i < jumlahAnggota; i++) {
                        cout << "ID: " << id[i]
                             << " | Nama: " << nama[i]
                             << " | Saldo: Rp" << saldo[i] << endl;
                    }
                }
                break;
            }

            case 3: {
                if (jumlahAnggota == 0) {
                    cout << "Belum ada anggota." << endl;
                }
                else {
                    cout << "\n===== DAFTAR ANGGOTA =====" << endl;

                    for (int i = 0; i < jumlahAnggota; i++) {
                        cout << "ID: " << id[i]
                             << " | Nama: " << nama[i]
                             << " | Saldo: Rp" << saldo[i] << endl;
                    }

                    int idCari, nominal;
                    int indeks = -1;

                    cout << "Masukkan ID anggota: ";
                    cin >> idCari;

                    cout << "Masukkan nominal setoran: Rp";
                    cin >> nominal;

                    for (int i = 0; i < jumlahAnggota; i++) {
                        if (id[i] == idCari) {
                            indeks = i;
                            break;
                        }
                    }

                    if (indeks == -1) {
                        cout << "ID anggota tidak ditemukan." << endl;
                    }
                    else if (nominal <= 0) {
                        cout << "Nominal harus lebih dari 0." << endl;
                    }
                    else {
                        saldo[indeks] += nominal;

                        cout << "Setoran " << nama[indeks]
                             << " berhasil." << endl;

                        cout << "Saldo terbaru: Rp"
                             << saldo[indeks] << endl;
                    }
                }
                break;
            }

            case 4: {
                if (jumlahAnggota == 0) {
                    cout << "Belum ada anggota." << endl;
                }
                else {
                    cout << "\n===== DAFTAR ANGGOTA =====" << endl;

                    for (int i = 0; i < jumlahAnggota; i++) {
                        cout << "ID: " << id[i]
                             << " | Nama: " << nama[i]
                             << " | Saldo: Rp" << saldo[i] << endl;
                    }

                    int idCari, nominal;
                    int indeks = -1;

                    cout << "Masukkan ID anggota: ";
                    cin >> idCari;

                    cout << "Masukkan nominal penarikan: Rp";
                    cin >> nominal;

                    for (int i = 0; i < jumlahAnggota; i++) {
                        if (id[i] == idCari) {
                            indeks = i;
                            break;
                        }
                    }

                    if (indeks == -1) {
                        cout << "ID anggota tidak ditemukan." << endl;
                    }
                    else if (nominal <= 0) {
                        cout << "Nominal harus lebih dari 0." << endl;
                    }
                    else if (nominal > saldo[indeks]) {
                        cout << "Saldo " << nama[indeks]
                             << " tidak mencukupi." << endl;
                    }
                    else {
                        saldo[indeks] -= nominal;

                        cout << "Penarikan " << nama[indeks]
                             << " berhasil." << endl;

                        cout << "Saldo terbaru: Rp"
                             << saldo[indeks] << endl;
                    }
                }
                break;
            }

            case 5:
                cout << "Terima kasih telah menggunakan koperasi." << endl;
                break;

            default:
                cout << "Pilihan menu tidak valid." << endl;
        }

    } while (pilihan != 5);

    return 0;
}
