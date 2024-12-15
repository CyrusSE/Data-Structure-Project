#include "header.h"


void menu(List_Relasi &Lr, List_Dosen &Lp, List_Mahasiswa &Lc){
    adr_Relasi R;
    adr_Dosen P,Q;
    adr_Mahasiswa C,D;
    infotype_Relasi dataR;
    infotype_Dosen dataP;
    infotype_Mahasiswa dataC;
    long long pilihan;
    cout << "------------------------------------------------------------" << endl;
    cout << "|   SPADM III Sistem Pencatatan Akademik Dosen-Mahasiswa   |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "|        Ihab Hasanain Akmal     //   103032330054         |" << endl;
    cout << "|       Faisal Ihsan Santoso     //   103032300152         |" << endl;
    cout << "|         Neng Intan Nuraeini    //   103032330031         |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "|   1. Data Dosen                                          |" << endl;
    cout << "|   2. Data Mahasiswa                                      |" << endl;
    cout << "|   3. Data Relasi                                         |" << endl;
    cout << "|   4. Exit                                                |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    cout << endl;
    if (pilihan == 4){
        return ;
    }
    while (pilihan < 1 || pilihan > 4){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        INPUT INVALID                     |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Ihab Hasanain Akmal     //   103032330054         |" << endl;
        cout << "|       Faisal Ihsan Santoso     //   103032300152         |" << endl;
        cout << "|         Neng Intan Nuraeini    //   103032330031         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Data Dosen                                          |" << endl;
        cout << "|   2. Data Mahasiswa                                      |" << endl;
        cout << "|   3. Data Relasi                                         |" << endl;
        cout << "|   4. Keluar                                              |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
    }
    if (pilihan == 1){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        MENU Dosen                        |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Ihab Hasanain Akmal     //   103032330054         |" << endl;
        cout << "|       Faisal Ihsan Santoso     //   103032300152         |" << endl;
        cout << "|         Neng Intan Nuraeini    //   103032330031         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Dosen                                   |" << endl;
        cout << "|   2. Menghapus Dosen                                     |" << endl;
        cout << "|   3. Mencari Dosen                                       |" << endl;
        cout << "|   4. Menampilkan Dosen                                   |" << endl;
        cout << "|   5. Total Dosen Tanpa Mahasiswa                         |" << endl;
        cout << "|   6. Total Mahasiswa Dari Dosen Tertentu                 |" << endl;
        cout << "|   7. Menampilkan Mahasiswa dari Dosen Tertentu           |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cin.ignore();
            cout << "Masukkan Nama Dosen: ";
            getline(cin, dataP.nama);
            cout << "Masukkan Kode Dosen: ";
            getline(cin, dataP.kode);
            cout << "Masukkan NIDN Dosen: ";
            cin >> dataP.NIDN;
            while (!checkNIDN(Lp, dataP.NIDN) || dataP.NIDN <= 0){
                cout << "NIDN INVALID ATAU SUDAH ADA" << endl;
                cout << "Masukkan NIDN Dosen: ";
                cin >> dataP.NIDN;
            }
            P = new elm_Dosen;
            P->info = dataP;
            P->next_Dosen = NULL;
            insertDosen(Lp, P);
            cout << "Data Dosen berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            P = NULL;
            deleteDosen(Lp, P);
            if (P != NULL){
                deleteRelasiDosen(Lr, P);
                cout << "Elemen List Dosen "<< P->info.nama << " telah berhasil dihapus" << endl;
                delete P;
            }
        }else if(pilihan == 3){
            findDosen(Lp, P);
        }else if(pilihan == 4){
            showDosen(Lp);
        }else if(pilihan == 5){
            hitungDosenTanpaMahasiswa(Lr, Lp);
        }else if(pilihan == 6){
            findDosen(Lp, P);
            if (P == NULL){
                cout << "Data Dosen tidak ditemukan" << endl;
                menu(Lr, Lp, Lc);
            }else{
                hitungMahasiswa(Lr, P);
            }
        }else if(pilihan == 7){
            findDosen(Lp, P);
            if (P == NULL){
                cout << "Data Dosen tidak ditemukan" << endl;
                menu(Lr, Lp, Lc);
            }else{
                showMahasiswa_dariDosen(Lr, P);
            }
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                         MENU Mahasiswa                   |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Ihab Hasanain Akmal     //   103032330054         |" << endl;
        cout << "|       Faisal Ihsan Santoso     //   103032300152         |" << endl;
        cout << "|         Neng Intan Nuraeini    //   103032330031         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Mahasiswa                               |" << endl;
        cout << "|   2. Menghapus Mahasiswa                                 |" << endl;
        cout << "|   3. Mencari Mahasiswa                                   |" << endl;
        cout << "|   4. Menampilkan Mahasiswa                               |" << endl;
        cout << "|   5. Total Mahasiswa Tanpa Dosen                         |" << endl;
        cout << "|   6. Total Dosen Dari Mahasiswa Tertentu                 |" << endl;
        cout << "|   7. Menampilkan Dosen dari Mahasiswa Tertentu           |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cin.ignore();
            cout << "Masukkan Nama Mahasiswa: ";
            getline(cin, dataC.nama);
            cout << "Masukkan IPK Mahasiswa: ";
            cin >> dataC.IPK;
            while (dataC.IPK < 0 || dataC.IPK > 4){
                cout << "IPK INVALID" << endl;
                cout << "Masukkan IPK Mahasiswa: ";
                cin >> dataC.IPK;
            }
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> dataC.NIM;
            while (!checkNIM(Lc, dataC.NIM) || dataC.NIM <= 0){
                cout << "NIM sudah ada" << endl;
                cin >> dataC.NIM;
            }
            C = new elm_Mahasiswa;
            C->info = dataC;
            C->next_Mahasiswa = NULL;
            C->prev_Mahasiswa = NULL;
            insertMahasiswa(Lc, C);
            cout << "Data Mahasiswa berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            deleteMahasiswa(Lc, C);
            if (C != NULL){
                deleteRelasiMahasiswa(Lr, C);
                cout << "Mahasiswa dengan nama: " << C->info.nama  << " telah berhasil dihapus" << endl;
                delete C;
            }
        }else if(pilihan == 3){
            findMahasiswa(Lc, C);
        }else if(pilihan == 4){
            showMahasiswa(Lc);
        }else if(pilihan == 5){
            hitungMahasiswaTanpaDosen(Lr, Lc);
        }else if(pilihan == 6){
            findMahasiswa(Lc, C);
            if (C == NULL){
                cout << "Data Mahasiswa tidak ditemukan" << endl;
                menu(Lr, Lp, Lc);
            }else{
                hitungDosen(Lr, C);
            }
        }else if(pilihan == 7){
            findMahasiswa(Lc, C);
            if (C == NULL){
                cout << "Data Mahasiswa tidak ditemukan" << endl;
                menu(Lr, Lp, Lc);
            }else{
                showDosen_dariMahasiswa(Lr, C);
            }
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        MENU RELASI                       |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Ihab Hasanain Akmal     //   103032330054         |" << endl;
        cout << "|       Faisal Ihsan Santoso     //   103032300152         |" << endl;
        cout << "|         Neng Intan Nuraeini     //   103032330031         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Relasi                                  |" << endl;
        cout << "|   2. Menghapus Relasi                                    |" << endl;
        cout << "|   3. Check Relasi                                        |" << endl;
        cout << "|   4. Menampilkan Dosen & Relasinya                       |" << endl;
        cout << "|   5. Menampilkan Mahasiswa & Relasinya                   |" << endl;
        cout << "|   6. Edit Relasi Dari Dosen                              |" << endl;
        cout << "|   7. Edit Relasi Dari Mahasiswa                          |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            findDosen(Lp, P);
            findMahasiswa(Lc, C);
            if (P == NULL || C == NULL){
                if (P == NULL){
                    cout << "Data Dosen tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else if ( C == NULL){
                    cout << "Data Mahasiswa tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else{
                    menu(Lr, Lp, Lc);
                }
            }else{
                cout << "Masukkan Info Relasi: ";
                cin.ignore();
                getline(cin, dataR);
                R = new elm_Relasi;
                R->info = dataR;
                R->next_Dosen = P;
                R->next_Mahasiswa = C;
                R->next_Relasi = NULL;
                insertRelasi(Lr, R);
                cout << "Relasi berhasil ditambahkan" << endl;
            }
        }else if (pilihan == 2){
            findDosen(Lp, P);
            findMahasiswa(Lc, C);
            if (P == NULL || C == NULL){
                if (P == NULL){
                    cout << "Data Dosen tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else if (C == NULL){
                    cout << "Data Mahasiswa tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else{
                    menu(Lr, Lp, Lc);
                }
            }else{
                checkRelasi(Lr, C, P, R);
                if (R == NULL){
                    cout << "Relasi tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else{
                    deleteRelasi(Lr, R);
                    delete R;
                    cout << "Relasi berhasil dihapus" << endl;
                }
            }
        }else if (pilihan == 3){
            findDosen(Lp, P);
            findMahasiswa(Lc, C);
            if (P == NULL || C == NULL){
                if (P == NULL){
                    cout << "Data Dosen tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else if (C == NULL){
                    cout << "Data Mahasiswa tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else{
                    menu(Lr, Lp, Lc);
                }
            }else{
                checkRelasi(Lr, C, P, R);
            }
        }else if (pilihan == 4){
            showAll_RelasiDosen(Lp, Lr);
        }else if (pilihan == 5){
            showAll_RelasiMahasiswa(Lc, Lr);
        }else if (pilihan == 6){
            findDosen(Lp, P);
            findMahasiswa(Lc, C);
            if (P == NULL || C == NULL){
                if (P == NULL){
                    cout << "Data Dosen tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else if (C == NULL){
                    cout << "Data Mahasiswa tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else{
                    menu(Lr, Lp, Lc);
                }
            }else{
                checkRelasi(Lr, C, P, R);
                if (R != NULL){
                    findMahasiswa(Lc, D);
                    editDosen(Lr, P, C, D);
                    cout << "Relasi berhasil diubah" << endl;
                }
            }
        }else if (pilihan == 7){
            findMahasiswa(Lc, C);
            findDosen(Lp, P);
            if ( C == NULL || P == NULL){
                if (C == NULL){
                    cout << "Data Mahasiswa tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else if (P == NULL){
                    cout << "Data Dosen tidak ditemukan" << endl;
                    menu(Lr, Lp, Lc);
                }else{
                    menu(Lr, Lp, Lc);
                }
            }else{
                checkRelasi(Lr, C, P, R);
                if (R != NULL){
                    findDosen(Lp, Q);
                    editMahasiswa(Lr, C, P, Q);
                    cout << "Relasi berhasil diubah" << endl;
                }
            }
        }else if (pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    menu(Lr, Lp, Lc);
}
void insertDosen(List_Dosen &L, adr_Dosen P){
    // point A
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Dosen = L.first;
        L.first = P;
    }
}
void insertMahasiswa(List_Mahasiswa &L, adr_Mahasiswa P){
    // point B
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Mahasiswa = P;
        P->prev_Mahasiswa = L.last;
        L.last = P;
    }
}
void insertRelasi(List_Relasi &L, adr_Relasi P){
    // point C
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        P->next_Relasi = L.first;
        L.first = P;
    }
}
void deleteDosen(List_Dosen &L, adr_Dosen &P){
    // point D
    if(L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    findDosen(L, P);
    if (P == NULL){
        cout << "Data Dosen tidak ditemukan" << endl;
        return;
    }
    if(P == L.first){
        deleteFirstDosen(L, P);
    }else if (P->next_Dosen == NULL){
        deleteLastDosen(L, P);
    }else{
        deleteAfterDosen(L, P);
    }
}
void deleteMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    // point E
    if(L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    findMahasiswa(L, P);
    if (P == NULL){
        cout << "Data Mahasiswa tidak ditemukan" << endl;
        return;
    }
    if (P == L.first){
        deleteFirstMahasiswa(L, P);
    }else if (P == L.last){
        deleteLastMahasiswa(L, P);
    }else{
        deleteAfterMahasiswa(L, P);
    }
}
void deleteRelasi(List_Relasi &L ,adr_Relasi &P){
    // point F
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if(P == L.first){
            L.first = P->next_Relasi;
            P->next_Relasi = NULL;
        }else{
            adr_Relasi Q = L.first;
            while(Q->next_Relasi != P){
                Q = Q->next_Relasi;
            }
            if (P->next_Relasi != NULL){
                Q->next_Relasi = P->next_Relasi;
            }
            Q->next_Relasi = NULL;
        }
    }
}
void findDosen(List_Dosen L, adr_Dosen &P){
    // point G
    if (L.first == NULL){
        cout << "Data Dosen kosong" << endl;
        P = NULL;
        return;
    }else{
        long long NIDN;
        cout << "Masukkan NIDN Dosen: ";
        cin >> NIDN;
        P = L.first;
        while(P != NULL){
            if(P->info.NIDN == NIDN){
                cout << "Data Dosen ditemukan" << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                cout << "|   Nama Dosen: " << P->info.nama << endl;
                cout << "|   Kode Dosen: " << P->info.kode << endl;
                cout << "|   NIDN Dosen: " << P->info.NIDN << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                return;
            }else{
                P = P->next_Dosen;
            }
        }
    }
}
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P){
    // point H
    if (L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        P = NULL;
        return;
    }else{
        long long NIM;
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> NIM;
        P = L.first;
        while(P != NULL){
            if(P->info.NIM == NIM){
                cout << "Data Mahasiswa ditemukan" << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                cout << "|   Nama Mahasiswa: " << P->info.nama << endl;
                cout << "|   IPK Mahasiswa: " << P->info.IPK << endl;
                cout << "|   NIM Mahasiswa: " << P->info.NIM << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                return;
            }else{
                P = P->next_Mahasiswa;
            }
        }
    }
}
void checkRelasi(List_Relasi L, adr_Mahasiswa P, adr_Dosen Q, adr_Relasi &R){
    // point I
    R = L.first;
    while(R != NULL){
        if(R->next_Mahasiswa == P && R->next_Dosen == Q){
            cout << endl << "------------------------------------------------------------" << endl;
            cout << "|   Relasi ditemukan" << endl;
            cout << "|   Info Relasi: " << R->info << endl;
            cout << endl << "------------------------------------------------------------" << endl;
            return;
        }else{
            R = R->next_Relasi;
        }
    }
    cout << endl << "------------------------------------------------------------" << endl;
            cout << "|   Relasi Tidak Ditemukan" << endl;
    cout << endl << "------------------------------------------------------------" << endl;
}
void showDosen(List_Dosen L){
    // point J
    if(L.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else{
        adr_Dosen P = L.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama Dosen: " << setw(43) << left << P->info.nama << "|" << endl;
            cout << "|   Kode Dosen: " << setw(43) << left << P->info.kode << "|" << endl;
            cout << "|   NIDN Dosen: " << setw(43) << left << P->info.NIDN << "|" << endl;
            cout << "------------------------------------------------------------" << endl;
            P = P->next_Dosen;
        }
    }
}
void showMahasiswa(List_Mahasiswa L){
    // point K
    if(L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Mahasiswa P = L.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama Mahasiswa: " << setw(39) << left << P->info.nama << "|" << endl;
            cout << "|   IPK Mahasiswa: " << setw(40) << left << P->info.IPK << "|" << endl;
            cout << "|   NIM Mahasiswa: " << setw(40) << left << P->info.NIM << "|" << endl;
            cout << "------------------------------------------------------------" << endl;
            P = P->next_Mahasiswa;
        }
    }
}
void showMahasiswa_dariDosen(List_Relasi L, adr_Dosen P) {
    // point L
    if(L.first == NULL) {
        cout << "Data Relasi kosong" << endl;
        return;
    }

    adr_Relasi R = L.first;
    bool ada = false;
    long long count = 0;
    cout << endl << "------------------------------------------------------------" << endl;
    while(R != NULL) {
        if(R->next_Dosen == P) {
            ada = true;
            if (count == 0) {
                cout << "|    Mahasiswa Yang Memiliki Relasi Dengan Dosen Diatas    |" << endl;
                cout << "------------------------------------------------------------" << endl;
            }
            cout << "|   Nama Mahasiswa: " << setw(39) << left << R->next_Mahasiswa->info.nama << "|" << endl;
            cout << "|   IPK Mahasiswa: " << setw(40) << left << R->next_Mahasiswa->info.IPK << "|" << endl;
            cout << "|   NIM Mahasiswa: " << setw(40) << left << R->next_Mahasiswa->info.NIM << "|" << endl;
            cout << "|   Info Relasi: " << setw(42) << left << R->info << "|" << endl;
            cout << "------------------------------------------------------------" << endl;
            count++;
        }
        R = R->next_Relasi;
    }
    if (!ada) {
        cout << "|   Dosen tidak memiliki relasi dengan Mahasiswa manapun   |" << endl;
        cout << "------------------------------------------------------------" << endl;
    }
}

void showDosen_dariMahasiswa(List_Relasi L, adr_Mahasiswa P) {
    // point M
    if(L.first == NULL) {
        cout << "Data Relasi kosong" << endl;
        return;
    }

    adr_Relasi R = L.first;
    bool ada = false;
    long long count = 0;
    cout << endl << "------------------------------------------------------------" << endl;
    while(R != NULL) {
        if(R->next_Mahasiswa == P) {
            ada = true;
            if (count == 0) {
                cout << "|    Dosen Yang Memiliki Relasi Dengan Mahasiswa Diatas    |" << endl;
                cout << "------------------------------------------------------------" << endl;
            }
            cout << "|   Nama Dosen: " << setw(43) << left << R->next_Dosen->info.nama << "|" << endl;
            cout << "|   Kode Dosen: " << setw(43) << left << R->next_Dosen->info.kode << "|" << endl;
            cout << "|   NIDN Dosen: " << setw(43) << left << R->next_Dosen->info.NIDN << "|" << endl;
            cout << "|   Info Relasi: " << setw(42) << left << R->info << "|" << endl;
            cout << "------------------------------------------------------------" << endl;
            count++;
        }
        R = R->next_Relasi;
    }
    if (!ada) {
        cout << "|   Mahasiswa tidak memiliki relasi dengan Dosen manapun   |" << endl;
        cout << "------------------------------------------------------------" << endl;
    }
}

void showAll_RelasiDosen(List_Dosen Lp, List_Relasi Lr) {
    // point N
    if(Lp.first == NULL) {
        cout << "Data Dosen kosong" << endl;
        return;
    }

    adr_Dosen P = Lp.first;
    cout << endl << "------------------------------------------------------------" << endl;
    while(P != NULL) {
        cout << "|   Nama Dosen: " << setw(43) << left << P->info.nama << "|" << endl;
        cout << "|   Kode Dosen: " << setw(43) << left << P->info.kode << "|" << endl;
        cout << "|   NIDN Dosen: " << setw(43) << left << P->info.NIDN << "|" << endl;
        showMahasiswa_dariDosen(Lr, P);
        P = P->next_Dosen;
    }
}

void showAll_RelasiMahasiswa(List_Mahasiswa Lc, List_Relasi Lr) {
    // point O
    if(Lc.first == NULL) {
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }

    adr_Mahasiswa P = Lc.first;
    cout << endl << "------------------------------------------------------------" << endl;
    while(P != NULL) {
        cout << "|   Nama Mahasiswa: " << setw(40) << left << P->info.nama << "|" << endl;
        cout << "|   IPK Mahasiswa: " << setw(41) << left << P->info.IPK << "|" << endl;
        cout << "|   NIM Mahasiswa: " << setw(41) << left << P->info.NIM << "|" << endl;
        showDosen_dariMahasiswa(Lr, P);
        P = P->next_Mahasiswa;
    }
}
void hitungMahasiswa(List_Relasi L, adr_Dosen P){
    // point P
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        long long hitung = 0;
        while(R != NULL){
            if(R->next_Dosen == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "|   Total Mahasiswa di Dosen " << P->info.nama << ": " << hitung << endl;
    }
}
void hitungDosen(List_Relasi L, adr_Mahasiswa P){
    // point Q
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        long long hitung = 0;
        while(R != NULL){
            if(R->next_Mahasiswa == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "|   Total Dosen dari Mahasiswa " << P->info.nama << ": " << hitung << endl;
    }
}
void hitungDosenTanpaMahasiswa(List_Relasi Lr, List_Dosen Lp){
    // point R
    if(Lr.first == NULL){
        showDosen(Lp);
    }else{
        adr_Dosen P = Lp.first;
        bool found;
        long long hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_Dosen == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_Dosen;
        }
        cout << "|   Total Dosen yang tidak memiliki Mahasiswa: " << hitung << endl;
    }
}
void hitungMahasiswaTanpaDosen(List_Relasi Lr, List_Mahasiswa Lc){
    // point S
    if(Lr.first == NULL){
        showMahasiswa(Lc);
    }else{
        adr_Mahasiswa P = Lc.first;
        bool found;
        long long hitung = 0;
        adr_Relasi R;
        while (P != NULL){
            R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_Mahasiswa == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_Mahasiswa;
        }
        cout << "|   Total Mahasiswa yang tidak memiliki Dosen: " << hitung << endl;
    }
}
void editDosen(List_Relasi &L, adr_Dosen P, adr_Mahasiswa Q, adr_Mahasiswa R){
    // point T
    adr_Relasi T = NULL;
    checkRelasi(L, Q, P, T);
    T->next_Mahasiswa = R;
}
void editMahasiswa(List_Relasi &L, adr_Mahasiswa P, adr_Dosen Q, adr_Dosen R){
    // point T
    adr_Relasi T = NULL;
    checkRelasi(L, P, Q, T);
    T->next_Dosen = R;
}
void deleteRelasiMahasiswa(List_Relasi &L, adr_Mahasiswa &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_Mahasiswa == P){
            deleteRelasi(L,R);
            R = L.first;
        }
        R = R->next_Relasi;
    }
}
void deleteRelasiDosen(List_Relasi &L, adr_Dosen &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_Dosen == P){
            deleteRelasi(L, R);
            R = L.first;
        }else{
            R = R->next_Relasi;
        }
    }
}
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    if(L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.first = P->next_Mahasiswa;
        P->next_Mahasiswa = NULL;
        L.first->prev_Mahasiswa = NULL;
    }
}
void deleteLastMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    if(L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.last = P->prev_Mahasiswa;
        P->prev_Mahasiswa = NULL;
        L.last->next_Mahasiswa = NULL;
    }
}
void deleteAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    if(L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    P->next_Mahasiswa->prev_Mahasiswa = P->prev_Mahasiswa;
    P->prev_Mahasiswa->next_Mahasiswa = P->next_Mahasiswa;
    P->next_Mahasiswa = NULL;
    P->prev_Mahasiswa = NULL;
}
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P){
    if(L.first == NULL){
        cout << "Data Dosen kosong" << endl;
        return;
    }
    if(L.first->next_Dosen == NULL){
        L.first = NULL;
    }else{
        L.first = P->next_Dosen;
        P->next_Dosen = NULL;
    }
}
void deleteLastDosen(List_Dosen &L, adr_Dosen &P){
    if(L.first == NULL){
        cout << "Data Dosen kosong" << endl;
        return;
    }
    if(L.first->next_Dosen == NULL){
        L.first = NULL;
    }else{
        adr_Dosen Q = L.first;
        while (Q->next_Dosen != P){
            Q = Q->next_Dosen;
        }
        Q->next_Dosen = NULL;
    }
}
void deleteAfterDosen(List_Dosen &L, adr_Dosen &P){
    if(L.first == NULL){
        cout << "Data Dosen kosong" << endl;
        return;
    }
    adr_Dosen Q = L.first;
    while (Q->next_Dosen != P){
        Q = Q->next_Dosen;
    }
    Q->next_Dosen = P->next_Dosen;
    P->next_Dosen = NULL;
}
bool checkNIM(List_Mahasiswa L, long long NIM){
    adr_Mahasiswa P = L.first;
    while (P != NULL){
        if (P->info.NIM == NIM){
            return false;
        }
        P = P->next_Mahasiswa;
    }
    return true;
}
bool checkNIDN(List_Dosen L, long long NIDN){
    adr_Dosen P = L.first;
    while (P != NULL){
        if (P->info.NIDN == NIDN){
            return false;
        }
        P = P->next_Dosen;
    }
    return true;
}
