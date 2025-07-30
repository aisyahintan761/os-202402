# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi  
**Semester**: Genap / Tahun Ajaran 2024–2025  
**Nama**: Aisyah Intan Nurjannah  
**NIM**: 240202894
**Modul yang Dikerjakan**:  
`Modul 3 – Manajemen Memori Tingkat Lanjut (xv6-public x86)`

---

## 📌 Deskripsi Singkat Tugas

* **Modul 3 – Manajemen Memori Tingkat Lanjut**:  
  Mengimplementasikan dua fitur manajemen memori baru pada xv6, yaitu:  
  1. **Copy-on-Write (CoW) Fork** untuk mengoptimalkan pemanggilan `fork()` agar tidak langsung menyalin seluruh memori proses.  
  2. **Shared Memory ala System V** dengan system call `shmget()` dan `shmrelease()` untuk memungkinkan proses berbagi memori.

---

## 🛠️ Rincian Implementasi

* Menambahkan array `ref_count[]` dan fungsi `incref()` serta `decref()` di `vm.c` untuk reference counting halaman fisik.
* Mendefinisikan flag baru `PTE_COW` di `mmu.h` untuk menandai halaman Copy-on-Write.
* Membuat fungsi `cowuvm()` di `vm.c` sebagai pengganti `copyuvm()` pada `fork()`.
* Menangani page fault di `trap.c` untuk menduplikasi halaman jika ada write pada halaman COW.
* Membuat tabel `shmtab[]` di `vm.c` untuk mengelola shared memory.
* Menambahkan system call `shmget()` dan `shmrelease()` di `sysproc.c`, serta mendaftarkannya di `syscall.c`, `syscall.h`, `user.h`, dan `usys.S`.
* Membuat dua program uji: `cowtest.c` untuk CoW dan `shmtest.c` untuk shared memory.

---

## ✅ Uji Fungsionalitas

* `cowtest`: Menguji implementasi Copy-on-Write dengan memodifikasi memori child tanpa memengaruhi parent.  
* `shmtest`: Menguji berbagi memori antar proses menggunakan `shmget()` dan `shmrelease()`.

---

## 📷 Hasil Uji

### 📍 Output `cowtest`:
Child sees: Y
Parent sees: X

shell
Copy
Edit

<img width="670" height="316" alt="modul 3a" src="https://github.com/user-attachments/assets/f9fa8165-3073-432e-bbd3-45d459353fc2" />

### 📍 Output `shmtest`:
Child reads: A
Parent reads: B

yaml
Copy
Edit

Jika ada screenshot hasil uji:  


yaml
Copy
Edit


<img width="736" height="337" alt="modul 3b" src="https://github.com/user-attachments/assets/1f7825ea-3fff-4ce4-8d9e-0856131d2866" />

---

## ⚠️ Kendala yang Dihadapi

* Salah indeks pada array `ref_count` menyebabkan kernel panic.  
* Lupa menghapus flag write (`PTE_W`) saat menandai halaman sebagai `PTE_COW`.  
* Salah memetakan alamat shared memory terlalu dekat dengan heap pengguna sehingga terjadi overlap.

---

## 📚 Referensi

* Buku xv6 MIT: [https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf](https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf)  
* Repositori xv6-public: [https://github.com/mit-pdos/xv6-public](https://github.com/mit-pdos/xv6-public)  
* Diskusi praktikum, Stack Overflow, dan GitHub Issues terkait implementasi xv6.

---
