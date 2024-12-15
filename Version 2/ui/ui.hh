#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"

namespace ui {
    void init(LPDIRECT3DDEVICE9);
    void render();
}

namespace ui {
    inline LPDIRECT3DDEVICE9 dev;
    inline const char* window_title = "SPADM III Sistem Pencatatan Akademik Dosen-Mahasiswa";

    inline ImVec2 screen_res{ 0, 0 };
    inline ImVec2 window_pos{ 0, 0 };
    inline ImVec2 window_size{ 800, 800 };
    inline DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
}
