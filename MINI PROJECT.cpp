#include <iostream>
#include <string>
using namespace std;

void tampilkanMenu(string items[], int harga[], int stok[], int ukuran) {
    cout << "\n          DAFTAR BARANG TOKO YAYAYA " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "ID\tNama Barang\t        Harga\tStok" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < ukuran; i++) {
        cout << i + 1 << "\t" << items[i] << "\t\tRp" << harga[i] << "\t" << stok[i] << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

int hitungTotalBelanja(int totalSebelumDiskon) {
    int diskon = 0;
    
    if (totalSebelumDiskon >= 100000) {
        diskon = 10000; 
        cout << "[PROMO] Selamat! Anda mendapatkan diskon Rp10.000" << endl;
    } else if (totalSebelumDiskon >= 50000) {
        diskon = 5000; 
        cout << "[PROMO] Selamat! Anda mendapatkan diskon Rp5.000" << endl;
    }
    else {
    	cout << endl;
	}
    
    return totalSebelumDiskon - diskon;
}


int main() {
    const int JUMLAH_BARANG = 12;
    string namaBarang[JUMLAH_BARANG] = {"Buku Tulis A5 ", "Buku Tulis B5 ", "Buku Gambar ", "Pena Gel  ", "Pensil    ", "Penggaris ", "Penghapus ", "Kotak Pensil ", "Lem Kertas ", "Corection Tape ", "Stabilo ", "Pensil Warna"};
    int hargaBarang[JUMLAH_BARANG] = {5000, 10000, 10000, 4000, 2000, 5000, 5000, 15000, 12000, 10000, 5000, 20000};
    int stokBarang[JUMLAH_BARANG] = {20, 15, 10, 30, 15, 20, 30, 18, 21, 34, 26, 35};

    int keranjangJumlah[JUMLAH_BARANG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
    
    int pilihanMenu;
    int totalKotor = 0;
    char lanjutBelanja = 'y';

    cout << "   =========================================" << endl;
    cout << "       SELAMAT DATANG DI APLIKASI KASIR    " << endl;
    cout << "   =========================================" << endl;

    while (lanjutBelanja == 'y' || lanjutBelanja == 'Y'){
        tampilkanMenu(namaBarang, hargaBarang, stokBarang, JUMLAH_BARANG);
        
        int idPilihan, jumlahBeli;
        
        cout << "Masukkan ID Barang yang ingin dibeli (1-12): ";
        cin >> idPilihan;
        
        if (idPilihan < 1 || idPilihan > JUMLAH_BARANG) {
            cout << "ID tidak valid! Silakan pilih kembali." << endl;
            continue; 
        }

        cout << "Masukkan Jumlah yang ingin dibeli: ";
        cin >> jumlahBeli;

        int indeks = idPilihan - 1; 

        if (jumlahBeli > stokBarang[indeks]) {
            cout << "Maaf, stok tidak mencukupi! Stok tersisa: " << stokBarang[indeks] << endl;
        
        } else {
            stokBarang[indeks] -= jumlahBeli;
            keranjangJumlah[indeks] += jumlahBeli;
            totalKotor += hargaBarang[indeks] * jumlahBeli;
            cout << "Berhasil menambahkan " << jumlahBeli << " " << namaBarang[indeks] << " ke keranjang." << endl;
        }

        cout << "\nApakah ada barang lain yang ingin dibeli? (y/n): ";
        cin >> lanjutBelanja;

    }


    cout << "\n=========================================" << endl;
    cout << "             NOTA PEMBAYARAN             " << endl;
    cout << "=========================================" << endl;
    
    for (int i = 0; i < JUMLAH_BARANG; i++) {
        if (keranjangJumlah[i] > 0) {
            cout << namaBarang[i] << " x " << keranjangJumlah[i] << " \t= Rp" << hargaBarang[i] * keranjangJumlah[i] << endl;
        }
    }
    cout << "-----------------------------------------" << endl;
    cout << "Total Kotor\t\t: Rp" << totalKotor << endl;
    
    int totalAkhir = hitungTotalBelanja(totalKotor);
    cout << "Total Bersih\t\t: Rp" << totalAkhir << endl;
    cout << "=========================================" << endl;
    
    int uangBayar;
    cout << "Masukkan uang pembayaran: Rp";
    cin >> uangBayar;

    if (uangBayar >= totalAkhir) {
        cout << "Kembalian Anda\t\t: Rp" << (uangBayar - totalAkhir) << endl;
        cout << "\nTerima kasih telah berbelanja di toko kami!" << endl;
    } else {
        cout << "Uang Anda kurang\t: Rp" << (totalAkhir - uangBayar) << endl;
        cout << "Transaksi dibatalkan. Silakan hitung ulang pembayaran Anda." << endl;
    }

    return 0;
}
