#include "ui.hh"
#include "../globals.hh"
#include "../header.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include <string>
#include <vector>
#include <sstream>

static char dosen_nama[256] = "";
static char dosen_kode[64] = "";
static int  dosen_nidn = 0;

static char mhs_nama[256] = "";
static char mhs_ipk_str[32] = "";
static int  mhs_nim = 0;

static int search_nidn = 0;
static int search_nim = 0;

static int relasi_nidn = 0;
static int relasi_nim = 0;

static int hapus_relasi_nidn = 0;
static int hapus_relasi_nim = 0;

static int edit_dosen_nidn = 0;
static int edit_dosen_old_nim = 0;
static int edit_dosen_new_nim = 0;

static int edit_mhs_nim = 0;
static int edit_mhs_old_nidn = 0;
static int edit_mhs_new_nidn = 0;


static void AddLog(const std::string& text) {
    console_buffer += "> " + text + "\n";
}

void ui::render() {
    // Main window
    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);
    if (ImGui::Begin(window_title, nullptr, window_flags)) {
        if (ImGui::BeginTabBar("MainTabs")) {
            // Data Dosen Tab
            if (ImGui::BeginTabItem("Data Dosen")) {
                ImGui::Text("Tambah Dosen:");
                ImGui::InputText("Nama Dosen", dosen_nama, IM_ARRAYSIZE(dosen_nama));
                ImGui::InputText("Kode Dosen", dosen_kode, IM_ARRAYSIZE(dosen_kode));
                ImGui::InputInt("NIDN Dosen", &dosen_nidn);

                if (ImGui::Button("Simpan Dosen")) {
                    if (strlen(dosen_nama) > 0 && strlen(dosen_kode) > 0 && dosen_nidn > 0 && checkNIDN(Ld, dosen_nidn)) {
                        adr_Dosen P = new elm_Dosen;
                        P->info.nama = dosen_nama;
                        P->info.kode = dosen_kode;
                        P->info.NIDN = dosen_nidn;
                        P->next_Dosen = NULL;
                        insertDosen(Ld, P);
                        AddLog("Dosen berhasil ditambahkan: " + P->info.nama);
                        memset(dosen_nama, 0, sizeof(dosen_nama));
                        memset(dosen_kode, 0, sizeof(dosen_kode));
                        dosen_nidn = 0;
                    }
                    else {
                        AddLog("Data dosen tidak valid atau NIDN sudah ada.");
                    }
                }

                ImGui::Separator();
                ImGui::Text("Cari/Hapus Dosen:");
                ImGui::InputInt("NIDN untuk cari/hapus", &search_nidn);
                if (ImGui::Button("Cari Dosen")) {
                    adr_Dosen P;
                    findDosen(Ld, P, search_nidn);
                    if (P) {
                        std::stringstream ss;
                        ss << "Dosen ditemukan: " << P->info.nama << " (NIDN: " << P->info.NIDN << ")";
                        AddLog(ss.str());
                    }
                    else {
                        AddLog("Dosen tidak ditemukan.");
                    }
                }
                ImGui::SameLine();
                if (ImGui::Button("Hapus Dosen")) {
                    adr_Dosen P;
                    findDosen(Ld, P, search_nidn);
                    if (P) {
                        deleteRelasiDosen(Lr, P);
                        deleteDosen(Ld, P);
                        if (P) delete P;
                        AddLog("Dosen berhasil dihapus.");
                    }
                    else {
                        AddLog("Dosen tidak ditemukan.");
                    }
                }

                ImGui::Separator();
                ImGui::Text("Tampilkan Seluruh Dosen:");
                if (ImGui::Button("Tampilkan Dosen")) {
                    // use showDosen
                    showDosen(Ld);
                }

                ImGui::SameLine();
                if (ImGui::Button("Total Dosen Tanpa Mahasiswa")) {
                    hitungDosenTanpaMahasiswa(Lr, Ld);
                }

                ImGui::EndTabItem();
            }

            // Data Mahasiswa Tab
            if (ImGui::BeginTabItem("Data Mahasiswa")) {
                ImGui::Text("Tambah Mahasiswa:");
                ImGui::InputText("Nama Mahasiswa", mhs_nama, IM_ARRAYSIZE(mhs_nama));
                ImGui::InputText("IPK Mahasiswa", mhs_ipk_str, IM_ARRAYSIZE(mhs_ipk_str));
                ImGui::InputInt("NIM Mahasiswa", &mhs_nim);

                if (ImGui::Button("Simpan Mahasiswa")) {
                    float ipk = atof(mhs_ipk_str);
                    if (strlen(mhs_nama) > 0 && mhs_nim > 0 && checkNIM(Lm, mhs_nim)) {
                        adr_Mahasiswa M = new elm_Mahasiswa;
                        M->info.nama = mhs_nama;
                        M->info.IPK = ipk;
                        M->info.NIM = mhs_nim;
                        M->next_Mahasiswa = NULL;
                        M->prev_Mahasiswa = NULL;
                        insertMahasiswa(Lm, M);
                        AddLog("Mahasiswa berhasil ditambahkan: " + M->info.nama);
                        memset(mhs_nama, 0, sizeof(mhs_nama));
                        memset(mhs_ipk_str, 0, sizeof(mhs_ipk_str));
                        mhs_nim = 0;
                    }
                    else {
                        AddLog("Data mahasiswa tidak valid atau NIM sudah ada.");
                    }
                }

                ImGui::Separator();
                ImGui::Text("Cari/Hapus Mahasiswa:");
                ImGui::InputInt("NIM untuk cari/hapus", &search_nim);
                if (ImGui::Button("Cari Mahasiswa")) {
                    adr_Mahasiswa M;
                    findMahasiswa(Lm, M, search_nim);
                    if (M) {
                        std::stringstream ss;
                        ss << "Mahasiswa ditemukan: " << M->info.nama << " (NIM: " << M->info.NIM << ", IPK: " << M->info.IPK << ")";
                        AddLog(ss.str());
                    }
                    else {
                        AddLog("Mahasiswa tidak ditemukan.");
                    }
                }
                ImGui::SameLine();
                if (ImGui::Button("Hapus Mahasiswa")) {
                    adr_Mahasiswa M;
                    findMahasiswa(Lm, M, search_nim);
                    if (M) {
                        deleteRelasiMahasiswa(Lr, M);
                        deleteMahasiswa(Lm, M);
                        if (M) delete M;
                        AddLog("Mahasiswa berhasil dihapus.");
                    }
                    else {
                        AddLog("Mahasiswa tidak ditemukan.");
                    }
                }

                ImGui::Separator();
                ImGui::Text("Tampilkan Seluruh Mahasiswa:");
                if (ImGui::Button("Tampilkan Mahasiswa")) {
                    showMahasiswa(Lm);
                }
                ImGui::SameLine();
                if (ImGui::Button("Total Mahasiswa Tanpa Dosen")) {
                    hitungMahasiswaTanpaDosen(Lr, Lm);
                }

                ImGui::EndTabItem();
            }

            // Data Relasi Tab
            if (ImGui::BeginTabItem("Data Relasi")) {
                ImGui::Text("Tambah Relasi Dosen - Mahasiswa");
                ImGui::InputInt("NIDN Dosen", &relasi_nidn);
                ImGui::InputInt("NIM Mahasiswa", &relasi_nim);
                if (ImGui::Button("Tambah Relasi")) {
                    adr_Dosen Pd; findDosen(Ld, Pd, relasi_nidn);
                    adr_Mahasiswa Pm; findMahasiswa(Lm, Pm, relasi_nim);
                    if (!Pd) AddLog("Dosen tidak ditemukan");
                    if (!Pm) AddLog("Mahasiswa tidak ditemukan");
                    if (Pd && Pm) {
                        if (!checkDosenHasRelasi(Lr, Pd) && !checkMahasiswaHasRelasi(Lr, Pm)) {
                            adr_Relasi R = new elm_Relasi;
                            R->next_Dosen = Pd;
                            R->next_Mahasiswa = Pm;
                            R->next_Relasi = NULL;
                            insertRelasi(Lr, R);
                            AddLog("Relasi berhasil ditambahkan antara: " + Pd->info.nama + " dan " + Pm->info.nama);
                        }
                        else {
                            AddLog("Dosen atau Mahasiswa sudah memiliki relasi.");
                        }
                    }
                }

                ImGui::Separator();
                ImGui::Text("Hapus Relasi:");
                ImGui::InputInt("NIDN Dosen (Hapus)", &hapus_relasi_nidn);
                ImGui::InputInt("NIM Mahasiswa (Hapus)", &hapus_relasi_nim);
                if (ImGui::Button("Hapus Relasi")) {
                    adr_Dosen Pd; findDosen(Ld, Pd, hapus_relasi_nidn);
                    adr_Mahasiswa Pm; findMahasiswa(Lm, Pm, hapus_relasi_nim);
                    if (!Pd) AddLog("Dosen tidak ditemukan");
                    if (!Pm) AddLog("Mahasiswa tidak ditemukan");
                    if (Pd && Pm) {
                        adr_Relasi R;
                        checkRelasi(Lr, Pm, Pd, R);
                        if (R) {
                            deleteRelasi(Lr, R);
                            delete R;
                            AddLog("Relasi berhasil dihapus.");
                        }
                        else {
                            AddLog("Relasi tidak ditemukan.");
                        }
                    }
                }
                ImGui::Separator();
                ImGui::Text("Edit Relasi Dari Dosen:");
                ImGui::InputInt("NIDN Dosen (Relasi Lama)", &edit_dosen_nidn);
                ImGui::InputInt("NIM Mahasiswa Lama", &edit_dosen_old_nim);
                ImGui::InputInt("NIM Mahasiswa Baru", &edit_dosen_new_nim);
                if (ImGui::Button("Edit Relasi (Dari Dosen)")) {
                    adr_Dosen P, Q; // P = Dosen lama, Q = tidak digunakan untuk editDosen
                    adr_Mahasiswa C, D;
                    adr_Relasi R;

                    findDosen(Ld, P, edit_dosen_nidn);
                    findMahasiswa(Lm, C, edit_dosen_old_nim);
                    findMahasiswa(Lm, D, edit_dosen_new_nim);

                    if (!P) AddLog("Dosen tidak ditemukan");
                    if (!C) AddLog("Mahasiswa lama tidak ditemukan");
                    if (!D) AddLog("Mahasiswa baru tidak ditemukan");

                    if (P && C && D) {
                        checkRelasi(Lr, C, P, R);
                        if (!R) {
                            AddLog("Relasi lama (Dosen-Mahasiswa lama) tidak ditemukan");
                        }
                        else {
                            editDosen(Lr, P, C, D);
                            AddLog("Relasi berhasil diubah (Dari Dosen).");
                        }
                    }
                }
                ImGui::Separator();
                ImGui::Text("Edit Relasi Dari Mahasiswa:");
                ImGui::InputInt("NIM Mahasiswa (Relasi Lama)", &edit_mhs_nim);
                ImGui::InputInt("NIDN Dosen Lama", &edit_mhs_old_nidn);
                ImGui::InputInt("NIDN Dosen Baru", &edit_mhs_new_nidn);
                if (ImGui::Button("Edit Relasi (Dari Mahasiswa)")) {
                    adr_Mahasiswa C;
                    adr_Dosen P, Q;
                    adr_Relasi R;

                    findMahasiswa(Lm, C, edit_mhs_nim);
                    findDosen(Ld, P, edit_mhs_old_nidn);
                    findDosen(Ld, Q, edit_mhs_new_nidn);

                    if (!C) AddLog("Mahasiswa tidak ditemukan");
                    if (!P) AddLog("Dosen lama tidak ditemukan");
                    if (!Q) AddLog("Dosen baru tidak ditemukan");

                    if (C && P && Q) {
                        checkRelasi(Lr, C, P, R);
                        if (!R) {
                            AddLog("Relasi lama (Mahasiswa-Dosen lama) tidak ditemukan");
                        }
                        else {
                            editMahasiswa(Lr, C, P, Q);
                            AddLog("Relasi berhasil diubah (Dari Mahasiswa).");
                        }
                    }
                }

                ImGui::Separator();
                if (ImGui::Button("Tampilkan Semua Relasi (Dari Dosen)")) {
                    showAll_RelasiDosen(Ld, Lr);
                }
                ImGui::SameLine();
                if (ImGui::Button("Tampilkan Semua Relasi (Dari Mahasiswa)")) {
                    showAll_RelasiMahasiswa(Lm, Lr);
                }

                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::Separator();
        ImGui::Text("Log Output:");
        ImGui::BeginChild("LogArea", ImVec2(0, -50), true);
        ImGui::TextUnformatted(console_buffer.c_str());
        ImGui::EndChild();

        if (ImGui::Button("Clear Log")) {
            console_buffer.clear();
        }
        ImGui::Text("Anggota Kelompok :");
        ImGui::Text("Ihab Hasanain Akmal (103032330054) | Faisal Ihsan Santoso (103032300152) | Neng Intan Nuraeni (103032330031)");

    }
    ImGui::End();
}

void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;

    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 5.0f;
    style.FrameRounding = 50.0f;
    style.PopupRounding = 4.0f;
    style.ScrollbarRounding = 12.0f;
    style.GrabRounding = 4.0f;
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);


    Lr.first = NULL; Lr.last = NULL;
    Ld.first = NULL;
    Lm.first = NULL; Lm.last = NULL;

    if (window_pos.x == 0) {
        RECT screen_rect{};
        GetWindowRect(GetDesktopWindow(), &screen_rect);
        screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
        window_pos = (screen_res - window_size) * 0.5f;
    }
}
