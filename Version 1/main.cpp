#include "header.h"

int main()
{
    List_Relasi Lr;
    List_Dosen Ld;
    List_Mahasiswa Lm;
    Lr.first = NULL;
    Ld.first = NULL;
    Lm.first = NULL;
    Lm.last = NULL;
    menu(Lr, Ld, Lm);
    return 0;
}
