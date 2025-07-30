# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi  
**Semester**: Genap / Tahun Ajaran 2024–2025  
**Nama**: `<Nama Lengkap>`  
**NIM**: `<Nomor Induk Mahasiswa>`  
**Modul yang Dikerjakan**:  
`Modul 4 – Subsistem Kernel Alternatif (xv6-public)`

---

## 📌 Deskripsi Singkat Tugas

* **Modul 4 – Subsistem Kernel Alternatif**:  
  1. Menambahkan system call `chmod(path, mode)` untuk mengatur mode file menjadi **read-only** atau **read-write**.  
  2. Mengembangkan driver pseudo-device `/dev/random` yang menghasilkan data acak saat dibaca.  

Tujuan modul ini adalah memperluas pemahaman terkait manajemen sistem file, system call, dan subsistem device driver pada kernel xv6.

---

## 🛠️ Rincian Implementasi

### A. System Call `chmod()`
* Menambahkan field `mode` pada `struct inode` di `fs.h`.
* Membuat syscall baru `chmod()` di `sysfile.c` untuk mengubah mode file.
* Registrasi syscall di `syscall.c`, `syscall.h`, `user.h`, dan `usys.S`.
* Memodifikasi `filewrite()` di `file.c` untuk memblokir penulisan pada file ber-mode read-only.
* Membuat program uji `chmodtest.c`.

### B. Device `/dev/random`
* Membuat file baru `random.c` sebagai driver pseudo-device generator bilangan acak.
* Menambahkan device driver ke tabel `devsw[]` di `file.c`.
* Menambahkan node device `/dev/random` di `init.c` menggunakan `mknod`.
* Membuat program uji `randomtest.c`.

---

## ✅ Uji Fungsionalitas

### 1. **Program Uji `chmodtest`**
File `myfile.txt` dibuat, diubah menjadi read-only, lalu dites untuk penulisan.

**Output yang diharapkan:**
Write blocked as expected

markdown
Copy
Edit

### 2. **Program Uji `randomtest`**
Membaca 8 byte dari `/dev/random` dan mencetak nilai acak.

**Contoh output:**
241 6 82 99 12 201 44 73

yaml
Copy
Edit

---

## 📷 Hasil Uji

### Output `chmodtest`:
Write blocked as expected

shell
Copy
Edit

### Output `randomtest`:
19 45 232 11 89 77 254 1

yaml
Copy
Edit

Jika disertai screenshot:


yaml
Copy
Edit


---

## ⚠️ Kendala yang Dihadapi

* Awalnya lupa menambahkan pengecekan mode file di `filewrite()`, sehingga file read-only masih bisa ditulis.  
* Salah dev major number saat registrasi `/dev/random` menyebabkan error saat membuka device.  
* Kesalahan update inode `mode` ke disk menyebabkan nilai tidak tersimpan setelah reboot.

---

## 📚 Referensi

* Buku xv6 MIT: [https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf](https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf)  
* xv6-public repository: [https://github.com/mit-pdos/xv6-public](https://github.com/mit-pdos/xv6-public)  

---

## ✅ Kesimpulan

Pada modul ini berhasil diimplementasikan:
* System call `chmod` untuk mengatur izin file (read-only / read-write).  
* Driver device baru `/dev/random` yang menyediakan byte acak.  

Modul ini memperdalam pemahaman tentang integrasi system call, mekanisme akses file inode, serta pengembangan driver sederhana di kernel xv6.
