# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi  
**Semester**: Genap / Tahun Ajaran 2024–2025  
**Nama**: Aisyah Intan Nurjannah 
**NIM**: 240202894 
**Modul yang Dikerjakan**:  
`Modul 5 – Audit dan Keamanan Sistem`

---

## 📌 Deskripsi Singkat Tugas

Pada modul ini, dilakukan implementasi mekanisme **Audit Log** pada kernel xv6 untuk mencatat setiap pemanggilan **system call**. Selain itu, ditambahkan syscall baru `get_audit_log()` yang hanya dapat diakses oleh proses **PID 1 (init)** untuk membaca catatan log tersebut.

---

## 🛠️ Rincian Implementasi

* Menambahkan **struktur audit log** di `syscall.c` untuk menyimpan informasi (PID, nomor syscall, waktu/tick).
* Memodifikasi fungsi `syscall()` untuk mencatat setiap pemanggilan system call ke dalam log.
* Menambahkan system call baru `get_audit_log()` di `sysproc.c` dengan pembatasan akses hanya untuk PID 1.
* Menambahkan deklarasi syscall di `defs.h`, `user.h`, `usys.S`, dan `syscall.h`.
* Membuat program uji `audit.c` untuk menampilkan isi audit log.
* Menambahkan entry `_audit` di `Makefile`.

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

* `audit`: Menampilkan daftar log system call (jika dijalankan sebagai PID 1).

---

## 📷 Hasil Uji

### 📍 Output ketika dijalankan oleh user biasa:
$ audit
Access denied or error.

shell
Copy
Edit

### 📍 Output ketika dijalankan sebagai PID 1:
=== Audit Log ===
[0] PID=1 SYSCALL=5 TICK=12
[1] PID=1 SYSCALL=6 TICK=13
...

yaml
Copy
Edit

![hasil ptest dan rtest](./screenshoot5/modul5.PNG)

---

## ⚠️ Kendala yang Dihadapi

* Perlu memastikan bahwa hanya proses PID 1 yang memiliki hak akses membaca log.
* Ukuran log terbatas (`MAX_AUDIT=128`), sehingga log dapat penuh jika sistem berjalan lama.
* Saat menguji sebagai PID 1, perlu memodifikasi `init.c` agar menjalankan `audit` sebagai proses pertama.

---

## 📚 Referensi

* Buku xv6 MIT: [https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf](https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf)  
* Source code `syscall.c`, `sysproc.c`, `proc.c` dalam xv6-public  
* Diskusi praktikum dan dokumentasi MIT xv6

---
