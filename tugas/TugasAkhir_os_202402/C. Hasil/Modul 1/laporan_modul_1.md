Mata Kuliah: Sistem Operasi
Semester: Genap / Tahun Ajaran 2024–2025
Nama: Aisyah Intan Nurjannah
NIM: 240202894
Modul yang Dikerjakan: Modul 1 – System Call dan Instrumentasi Kernel

---

📌 Deskripsi Singkat Tugas
Pada modul ini, dilakukan implementasi dua system call baru pada kernel xv6-public (x86):

1. getpinfo(struct pinfo *ptable) → Menampilkan informasi proses aktif berupa PID, ukuran memori, dan nama proses.

2. getreadcount() → Mengembalikan jumlah pemanggilan fungsi read() sejak sistem booting.

Tujuan modul ini adalah untuk memahami mekanisme pendaftaran system call baru pada kernel xv6, memodifikasi kernel agar mendukung fitur tambahan, serta membuat program user-level untuk menguji fungsionalitas yang ditambahkan.

---

🛠️ Rincian Implementasi

Langkah-langkah implementasi yang dilakukan adalah:
1. Menambahkan struktur struct pinfo di file proc.h untuk menyimpan informasi proses.
2. Menambahkan counter global readcount di sysproc.c untuk menghitung jumlah pemanggilan read().
3. Mendaftarkan syscall baru dengan menambah entri di:
    a. syscall.h → nomor syscall
    b. syscall.c → fungsi handler syscall
    c. user.h dan usys.S → deklarasi fungsi syscall di user space
4. Mengimplementasikan fungsi sys_getpinfo dan sys_getreadcount di sysproc.c.
5. Memodifikasi fungsi sys_read di sysfile.c untuk menambah counter readcount.
6. Membuat dua program uji di user-level (ptest.c dan rtest.c) untuk memverifikasi hasil implementasi.
7. Mendaftarkan program uji ke dalam Makefile agar dapat dijalankan di shell xv6.

---

✅ Uji Fungsionalitas
1. Program uji yang digunakan:
    a. ptest → menguji syscall getpinfo(), menampilkan daftar proses aktif.
    b. rtest → menguji syscall getreadcount(), memantau jumlah pemanggilan fungsi read().
2. Langkah pengujian:
    a. Build xv6 dengan make clean && make qemu-nox.
    b. Jalankan program uji ptest dan rtest di dalam shell xv6.
   
---

📷 Hasil Uji
📍 Output ptest (uji getpinfo):
yaml
PID     MEM     NAME
1       4096    init
2       2048    sh
3       2048    ptest


```
Child reads: A
Parent reads: B
```

📍 Output rtest (uji getreadcount):
mathematica
Read Count Sebelum: 4
hello
Read Count Setelah: 5

---

## ⚠️ Kendala yang Dihadapi

1. Awalnya menggunakan ptable_lock yang tidak ada di xv6-public, sehingga perlu diganti dengan ptable.lock.
2. Error pointer pada argptr() jika tidak menggunakan cast (char**) untuk parameter struct di sys_getpinfo.
3. Harus memastikan urutan update Makefile agar program uji (ptest dan rtest) ikut ter-compile.

---

## 📚 Referensi

Buku xv6 MIT: https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf
Repositori xv6-public: https://github.com/mit-pdos/xv6-public
Diskusi praktikum dan dokumentasi terkait syscall xv6.

---

