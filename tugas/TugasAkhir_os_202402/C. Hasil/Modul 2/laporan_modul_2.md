# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi  
**Semester**: Genap / Tahun Ajaran 2024–2025  
**Nama**: Aisyah Intan Nurjannah  
**NIM**: 240202894
**Modul yang Dikerjakan**:  
`Modul 2 – Penjadwalan CPU Lanjutan (Priority Scheduling Non-Preemptive)`

---

## 📌 Deskripsi Singkat Tugas

Modul ini bertujuan untuk **mengubah algoritma penjadwalan CPU di xv6-public dari Round Robin menjadi Non-Preemptive Priority Scheduling**.  
Langkah-langkah utama yang dilakukan adalah:
* Menambahkan field **`priority`** pada setiap proses.
* Membuat system call baru **`set_priority(int)`** untuk mengatur prioritas proses.
* Memodifikasi fungsi **`scheduler()`** agar selalu memilih proses RUNNABLE dengan prioritas tertinggi (angka terkecil).

---

## 🛠️ Rincian Implementasi

Berikut perubahan yang dilakukan pada kode sumber:

1. **File `proc.h`**  
   * Menambahkan field `int priority;` pada struktur `struct proc`.

2. **File `proc.c`**
   * Pada `allocproc()`, inisialisasi prioritas default:  
     ```c
     p->priority = 60; // default
     ```
   * Modifikasi fungsi `scheduler()` untuk memilih proses RUNNABLE dengan prioritas tertinggi (nilai terkecil) secara **non-preemptive**.

3. **File `syscall.h`**
   * Menambahkan nomor syscall baru:  
     ```c
     #define SYS_set_priority 24
     ```

4. **File `syscall.c`**
   * Registrasi syscall baru `set_priority` ke dalam array `syscalls[]`.

5. **File `sysproc.c`**
   * Implementasi fungsi `sys_set_priority()` untuk mengatur prioritas proses.

6. **File `user.h` dan `usys.S`**
   * Deklarasi dan entri syscall `set_priority(int)`.

7. **File `Makefile`**
   * Menambahkan program uji baru `ptest.c` ke daftar `UPROGS`.

8. **Program Uji `ptest.c`**
   * Membuat dua child process dengan prioritas berbeda (10 dan 90), lalu mengamati urutan eksekusi.

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:  

* **`ptest`**:  
  Menguji penjadwalan **non-preemptive priority**.  
  - Child dengan prioritas tinggi (10) harus selesai lebih dulu.  
  - Child dengan prioritas rendah (90) dijalankan setelahnya.

---

## 📷 Hasil Uji

### 📍 Output Program `ptest`
$ ptest
Child 2 selesai // prioritas tinggi (10)
Child 1 selesai // prioritas rendah (90)
Parent selesai

yaml
Copy
Edit

Output ini sesuai ekspektasi: proses dengan prioritas tertinggi (angka terkecil) dieksekusi terlebih dahulu.

![hasil ptest dan rtest](./screenshoot2/modul2.PNG)

---

## ⚠️ Kendala yang Dihadapi

* Pada awal implementasi, lupa memanggil `sti()` dalam `scheduler()`, menyebabkan CPU tidak menerima interrupt.
* Salah validasi range prioritas pada `sys_set_priority`, menyebabkan panic saat diberi nilai negatif.
* Perlu memastikan scheduler berjalan **non-preemptive**, sehingga tidak menggunakan timer interrupt untuk preemption.

---

## 📚 Referensi

* Buku xv6 MIT: [https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf](https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf)  
* Repositori xv6-public: [https://github.com/mit-pdos/xv6-public](https://github.com/mit-pdos/xv6-public)  
* Diskusi forum Stack Overflow dan GitHub Issues terkait xv6 scheduling.  
