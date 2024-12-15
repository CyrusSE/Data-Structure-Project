# SPADM III (Sistem Pencatatan Akademik Dosen-Mahasiswa)

## Deskripsi
SPADM III adalah sistem pencatatan akademik yang dirancang untuk memudahkan pengelolaan data dosen dan mahasiswa di perguruan tinggi. Sistem ini menggunakan konsep Multi-Level Linked List (MLL) dengan tipe MLL B, yang mengimplementasikan Single Linked List untuk data parent (dosen) dan Double Linked List untuk data child (mahasiswa). Dengan sistem ini, proses pendataan menjadi lebih terstruktur, efisien, dan minim kesalahan input.

## Model MLL
![Model MLL](https://i.imgur.com/mSwORni.png)

## Tabel Konten
1. [Data Dosen](#data-dosen)
2. [Data Mahasiswa](#data-mahasiswa)
3. [Data Relasi](#data-relasi)
4. [Spesifikasi Program](#spesifikasi-program)
5. [Anggota Kelompok](#anggota-kelompok)
5. [Compiled Version 1](https://github.com/CyrusSE/Data-Structure-Project/raw/refs/heads/main/Version%201/bin/Debug/Dosen%20Mahasiswa.exe)
6. [Compiled Version 2](https://github.com/CyrusSE/Data-Structure-Project/raw/refs/heads/main/Version%202/x64/Release/STD.exe)

## Data Dosen
![Data Dosen Tab](https://i.imgur.com/XYwYpJg.png)

### Field Data Dosen
- **Nama Dosen**
- **NIDN Dosen**
- **Kode Dosen**

## Data Mahasiswa
![Data Mahasiswa Tab](https://i.imgur.com/6YVTmS5.png)

### Field Data Mahasiswa
- **Nama Mahasiswa**
- **NIM Mahasiswa**
- **IPK Mahasiswa**

## Data Relasi
![Data Relasi Tab](https://i.imgur.com/snA45Iy.png)

## Deskripsi
Relasi antara dosen dan mahasiswa memungkinkan pengelolaan data akademik yang saling terkait. Setiap dosen dapat memiliki relasi dengan satu atau lebih mahasiswa, dan sebaliknya.

## Spesifikasi Program

### a. Insert Element Parent  
Menambahkan data dosen baru ke dalam List Dosen sebagai elemen pertama.

### b. Insert Element Child 
Menambahkan data mahasiswa baru ke dalam List Mahasiswa sebagai elemen pertama.

### c. Insert Element Relation 
Menambahkan relasi baru antara dosen dan mahasiswa ke dalam List Relasi sebagai elemen pertama.

### d. Delete Element Parent
Mencari dan menghapus elemen dosen dari List Dosen jika ditemukan.

### e. Delete Element Child
Mencari dan menghapus elemen mahasiswa dari List Mahasiswa jika ditemukan.

### f. Delete Element Relation
Menghapus relasi yang ditunjuk dari List Relasi.

### g. Find Element Parent 
Mencari elemen dosen dalam List Dosen dan mengembalikan pointer jika ditemukan.

### h. Find Element Child
Mencari elemen mahasiswa dalam List Mahasiswa dan mengembalikan pointer jika ditemukan.

### i. Find Relasi Parent dan Child Tertentu
Memeriksa apakah dosen dan mahasiswa tertentu memiliki relasi dan menampilkan hasilnya.

### j. Show All Data Parent 
Menampilkan semua data dosen dalam List Dosen.

### k. Show All Data Child
Menampilkan semua data mahasiswa dalam List Mahasiswa.

### l. Show Data Child dari Parent Tertentu
Menampilkan semua mahasiswa yang berelasi dengan dosen tertentu.

### m. Show Data Parent dari Child Tertentu 
Menampilkan semua dosen yang berelasi dengan mahasiswa tertentu.

### n. Show Setiap Data Parent Beserta Data Child yang Berelasi
Menampilkan semua relasi yang dimiliki oleh setiap dosen dalam List Dosen.

### o. Show Setiap Data Child Beserta Data Parent yang Berelasi
Menampilkan semua relasi yang dimiliki oleh setiap mahasiswa dalam List Mahasiswa.

### p. Count Jumlah Child Element Parent Tertentu
Menghitung dan menampilkan jumlah mahasiswa yang berelasi dengan dosen tertentu.

### q. Count Jumlah Parent yang Dimiliki oleh Child Tertentu
Menghitung dan menampilkan jumlah dosen yang berelasi dengan mahasiswa tertentu.

### r. Count Element Child yang Tidak Memiliki Parent
Menampilkan jumlah mahasiswa yang belum memiliki relasi dengan dosen manapun.

### s. Count Element Parent yang Tidak Memiliki Child
Menampilkan jumlah dosen yang belum memiliki relasi dengan mahasiswa manapun.

### t. Edit Relasi/Mengganti Child dari Parent Tertentu dan Mengganti Parent dari Child Tertentu
Mengubah relasi antara mahasiswa dan dosen, memindahkan relasi ke dosen atau mahasiswa lain.

## Anggota Kelompok
1. Ihab Hasanain Akmal
2. Faisal Ihsan Santoso 
3. Neng Intan Nuraeni
