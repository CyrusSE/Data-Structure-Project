#include "header.h"

extern std::string console_buffer;


static void AddLog(const std::string& text) {
    console_buffer += "> " + text + "\n";
}

void showDosen(List_Dosen L) {
    if (L.first == NULL) {
        AddLog("Data Dosen kosong");
    }
    else {
        adr_Dosen P = L.first;
        AddLog("------- Data Dosen -------");
        while (P != NULL) {
            std::stringstream ss;
            ss << "Nama Dosen: " << P->info.nama << ", Kode: " << P->info.kode << ", NIDN: " << P->info.NIDN;
            AddLog(ss.str());
            P = P->next_Dosen;
        }
    }
}

void showMahasiswa(List_Mahasiswa L) {
    if (L.first == NULL) {
        AddLog("Data Mahasiswa kosong");
    }
    else {
        adr_Mahasiswa P = L.first;
        AddLog("------- Data Mahasiswa -------");
        while (P != NULL) {
            std::stringstream ss;
            ss << "Nama: " << P->info.nama << ", IPK: " << P->info.IPK << ", NIM: " << P->info.NIM;
            AddLog(ss.str());
            P = P->next_Mahasiswa;
        }
    }
}

void showMahasiswa_dariDosen(List_Relasi L, adr_Dosen P) {
    if (L.first == NULL) {
        AddLog("Data Relasi kosong");
        return;
    }

    adr_Relasi R = L.first;
    bool ada = false;
    AddLog("Mahasiswa yang terkait dengan Dosen: " + P->info.nama);
    while (R != NULL) {
        if (R->next_Dosen == P) {
            std::stringstream ss;
            ss << "   Nama: " << R->next_Mahasiswa->info.nama << ", IPK: " << R->next_Mahasiswa->info.IPK << ", NIM: " << R->next_Mahasiswa->info.NIM;
            AddLog(ss.str());
            ada = true;
        }
        R = R->next_Relasi;
    }
    if (!ada) {
        AddLog("   (Tidak ada mahasiswa terkait)");
    }
}

void showDosen_dariMahasiswa(List_Relasi L, adr_Mahasiswa P) {
    if (L.first == NULL) {
        AddLog("Data Relasi kosong");
        return;
    }

    adr_Relasi R = L.first;
    bool ada = false;
    AddLog("Dosen yang terkait dengan Mahasiswa: " + P->info.nama);
    while (R != NULL) {
        if (R->next_Mahasiswa == P) {
            std::stringstream ss;
            ss << "   Nama Dosen: " << R->next_Dosen->info.nama << ", Kode: " << R->next_Dosen->info.kode << ", NIDN: " << R->next_Dosen->info.NIDN;
            AddLog(ss.str());
            ada = true;
        }
        R = R->next_Relasi;
    }
    if (!ada) {
        AddLog("   (Tidak ada dosen terkait)");
    }
}

void showAll_RelasiDosen(List_Dosen Lp, List_Relasi Lr) {
    if (Lp.first == NULL) {
        AddLog("Data Dosen kosong");
        return;
    }

    adr_Dosen P = Lp.first;
    AddLog("------- Seluruh Relasi (Dari Dosen) -------");
    while (P != NULL) {
        std::stringstream ss;
        ss << "Dosen: " << P->info.nama << " (NIDN:" << P->info.NIDN << ")";
        AddLog(ss.str());
        showMahasiswa_dariDosen(Lr, P);
        P = P->next_Dosen;
    }
}

void showAll_RelasiMahasiswa(List_Mahasiswa Lc, List_Relasi Lr) {
    if (Lc.first == NULL) {
        AddLog("Data Mahasiswa kosong");
        return;
    }

    adr_Mahasiswa M = Lc.first;
    AddLog("------- Seluruh Relasi (Dari Mahasiswa) -------");
    while (M != NULL) {
        std::stringstream ss;
        ss << "Mahasiswa: " << M->info.nama << " (NIM:" << M->info.NIM << ")";
        AddLog(ss.str());
        showDosen_dariMahasiswa(Lr, M);
        M = M->next_Mahasiswa;
    }
}

void hitungMahasiswa(List_Relasi L, adr_Dosen P) {
    if (L.first == NULL) {
        AddLog("Data Relasi kosong");
    }
    else {
        adr_Relasi R = L.first;
        int hitung = 0;
        while (R != NULL) {
            if (R->next_Dosen == P) {
                hitung++;
            }
            R = R->next_Relasi;
        }
        std::stringstream ss;
        ss << "Total Mahasiswa di Dosen " << P->info.nama << ": " << hitung;
        AddLog(ss.str());
    }
}

void hitungDosen(List_Relasi L, adr_Mahasiswa P) {
    if (L.first == NULL) {
        AddLog("Data Relasi kosong");
    }
    else {
        adr_Relasi R = L.first;
        int hitung = 0;
        while (R != NULL) {
            if (R->next_Mahasiswa == P) {
                hitung++;
            }
            R = R->next_Relasi;
        }
        std::stringstream ss;
        ss << "Total Dosen dari Mahasiswa " << P->info.nama << ": " << hitung;
        AddLog(ss.str());
    }
}

void hitungDosenTanpaMahasiswa(List_Relasi Lr, List_Dosen Ld) {
    if (Lr.first == NULL) {
        AddLog("Karena Data Relasi kosong, semua dosen ditampilkan:");
        showDosen(Ld);
    }
    else {
        adr_Dosen P = Ld.first;
        int hitung = 0;
        while (P != NULL) {
            adr_Relasi R = Lr.first;
            bool found = false;
            while (R != NULL) {
                if (R->next_Dosen == P) {
                    found = true;
                    break;
                }
                R = R->next_Relasi;
            }
            if (!found) {
                hitung++;
            }
            P = P->next_Dosen;
        }
        std::stringstream ss;
        ss << "Total Dosen yang tidak memiliki Mahasiswa: " << hitung;
        AddLog(ss.str());
    }
}

void hitungMahasiswaTanpaDosen(List_Relasi Lr, List_Mahasiswa Lm) {
    if (Lr.first == NULL) {
        AddLog("Karena Data Relasi kosong, semua Mahasiswa ditampilkan:");
        showMahasiswa(Lm);
    }
    else {
        adr_Mahasiswa P = Lm.first;
        int hitung = 0;
        while (P != NULL) {
            adr_Relasi R = Lr.first;
            bool found = false;
            while (R != NULL) {
                if (R->next_Mahasiswa == P) {
                    found = true;
                    break;
                }
                R = R->next_Relasi;
            }
            if (!found) {
                hitung++;
            }
            P = P->next_Mahasiswa;
        }
        std::stringstream ss;
        ss << "Total Mahasiswa yang tidak memiliki Dosen: " << hitung;
        AddLog(ss.str());
    }
}

void editDosen(List_Relasi& L, adr_Dosen P, adr_Mahasiswa Q, adr_Mahasiswa R) {
    adr_Relasi T = NULL;
    checkRelasi(L, Q, P, T);
    if (T) {
        T->next_Mahasiswa = R;
        AddLog("Relasi berhasil diubah (editDosen).");
    }
    else {
        AddLog("Relasi tidak ditemukan (editDosen).");
    }
}

void editMahasiswa(List_Relasi& L, adr_Mahasiswa P, adr_Dosen Q, adr_Dosen R) {
    adr_Relasi T = NULL;
    checkRelasi(L, P, Q, T);
    if (T) {
        T->next_Dosen = R;
        AddLog("Relasi berhasil diubah (editMahasiswa).");
    }
    else {
        AddLog("Relasi tidak ditemukan (editMahasiswa).");
    }
}

void insertDosen(List_Dosen& L, adr_Dosen P) {
    if (L.first == NULL) {
        L.first = P;
    }
    else {
        P->next_Dosen = L.first;
        L.first = P;
    }
}
void insertMahasiswa(List_Mahasiswa& L, adr_Mahasiswa P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    }
    else {
        L.last->next_Mahasiswa = P;
        P->prev_Mahasiswa = L.last;
        L.last = P;
    }
}
void insertRelasi(List_Relasi& L, adr_Relasi P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    }
    else {
        P->next_Relasi = L.first;
        L.first = P;
    }
}

void deleteDosen(List_Dosen& L, adr_Dosen& P) {
    if (L.first == NULL)return;
    if (P == L.first) {
        deleteFirstDosen(L, P);
    }
    else if (P->next_Dosen == NULL) {
        deleteLastDosen(L, P);
    }
    else {
        deleteAfterDosen(L, P);
    }
}
void deleteMahasiswa(List_Mahasiswa& L, adr_Mahasiswa& P) {
    if (L.first == NULL)return;
    if (P == L.first) {
        deleteFirstMahasiswa(L, P);
    }
    else if (P == L.last) {
        deleteLastMahasiswa(L, P);
    }
    else {
        deleteAfterMahasiswa(L, P);
    }
}
void deleteRelasi(List_Relasi& L, adr_Relasi& P) {
    if (L.first == NULL) {
        return;
    }
    else {
        if (P == L.first) {
            L.first = P->next_Relasi;
            P->next_Relasi = NULL;
            if (L.first == NULL) L.last = NULL;
        }
        else {
            adr_Relasi Q = L.first;
            while (Q->next_Relasi != P && Q->next_Relasi != NULL) {
                Q = Q->next_Relasi;
            }
            if (Q->next_Relasi == P) {
                Q->next_Relasi = P->next_Relasi;
                if (Q->next_Relasi == NULL) L.last = Q;
            }
            P->next_Relasi = NULL;
        }
    }
}
void findDosen(List_Dosen L, adr_Dosen& P, int NIDN) {
    P = L.first;
    while (P != NULL) {
        if (P->info.NIDN == NIDN) {
            return;
        }
        P = P->next_Dosen;
    }
    P = NULL;
}
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa& P, int NIM) {
    P = L.first;
    while (P != NULL) {
        if (P->info.NIM == NIM) {
            return;
        }
        P = P->next_Mahasiswa;
    }
    P = NULL;
}
void checkRelasi(List_Relasi L, adr_Mahasiswa PM, adr_Dosen PD, adr_Relasi& R) {
    R = L.first;
    while (R != NULL) {
        if (R->next_Mahasiswa == PM && R->next_Dosen == PD) {
            return;
        }
        R = R->next_Relasi;
    }
    R = NULL;
}

bool checkNIM(List_Mahasiswa L, int NIM) {
    adr_Mahasiswa P = L.first;
    while (P != NULL) {
        if (P->info.NIM == NIM) {
            return false;
        }
        P = P->next_Mahasiswa;
    }
    return true;
}
bool checkNIDN(List_Dosen L, int NIDN) {
    adr_Dosen P = L.first;
    while (P != NULL) {
        if (P->info.NIDN == NIDN) {
            return false;
        }
        P = P->next_Dosen;
    }
    return true;
}
bool checkMahasiswaHasRelasi(List_Relasi L, adr_Mahasiswa P) {
    adr_Relasi R = L.first;
    while (R != NULL) {
        if (R->next_Mahasiswa == P) {
            return true;
        }
        R = R->next_Relasi;
    }
    return false;
}
bool checkDosenHasRelasi(List_Relasi L, adr_Dosen P) {
    adr_Relasi R = L.first;
    while (R != NULL) {
        if (R->next_Dosen == P) {
            return true;
        }
        R = R->next_Relasi;
    }
    return false;
}
void deleteRelasiMahasiswa(List_Relasi& L, adr_Mahasiswa& P) {
    adr_Relasi R = L.first;
    while (R != NULL) {
        if (R->next_Mahasiswa == P) {
            adr_Relasi temp = R;
            R = R->next_Relasi;
            deleteRelasi(L, temp);
        }
        else {
            R = R->next_Relasi;
        }
    }
}
void deleteRelasiDosen(List_Relasi& L, adr_Dosen& P) {
    adr_Relasi R = L.first;
    while (R != NULL) {
        if (R->next_Dosen == P) {
            adr_Relasi temp = R;
            R = R->next_Relasi;
            deleteRelasi(L, temp);
        }
        else {
            R = R->next_Relasi;
        }
    }
}

void deleteFirstMahasiswa(List_Mahasiswa& L, adr_Mahasiswa& P) {
    if (L.first == NULL) return;
    P = L.first;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    }
    else {
        L.first = P->next_Mahasiswa;
        L.first->prev_Mahasiswa = NULL;
        P->next_Mahasiswa = NULL;
    }
}
void deleteLastMahasiswa(List_Mahasiswa& L, adr_Mahasiswa& P) {
    if (L.first == NULL)return;
    P = L.last;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    }
    else {
        L.last = P->prev_Mahasiswa;
        L.last->next_Mahasiswa = NULL;
        P->prev_Mahasiswa = NULL;
    }
}
void deleteAfterMahasiswa(List_Mahasiswa& L, adr_Mahasiswa& P) {
    if (L.first == NULL)return;
    P->prev_Mahasiswa->next_Mahasiswa = P->next_Mahasiswa;
    if (P->next_Mahasiswa != NULL) {
        P->next_Mahasiswa->prev_Mahasiswa = P->prev_Mahasiswa;
    }
    else {
        L.last = P->prev_Mahasiswa;
    }
    P->next_Mahasiswa = NULL;
    P->prev_Mahasiswa = NULL;
}

void deleteFirstDosen(List_Dosen& L, adr_Dosen& P) {
    if (L.first == NULL)return;
    P = L.first;
    L.first = P->next_Dosen;
    P->next_Dosen = NULL;
}
void deleteLastDosen(List_Dosen& L, adr_Dosen& P) {
    if (L.first == NULL)return;
    if (L.first->next_Dosen == NULL) {
        P = L.first;
        L.first = NULL;
    }
    else {
        adr_Dosen Q = L.first;
        while (Q->next_Dosen->next_Dosen != NULL) {
            Q = Q->next_Dosen;
        }
        P = Q->next_Dosen;
        Q->next_Dosen = NULL;
    }
}
void deleteAfterDosen(List_Dosen& L, adr_Dosen& P) {
    if (L.first == NULL)return;
    adr_Dosen Q = L.first;
    while (Q->next_Dosen != P && Q->next_Dosen != NULL) {
        Q = Q->next_Dosen;
    }
    if (Q->next_Dosen == P) {
        Q->next_Dosen = P->next_Dosen;
        P->next_Dosen = NULL;
    }
}
