### Praktikum Pemrograman Berorientasi Objek (PBO)

Dokumentasi ini dibuat berdasarkan file-file kode dan dokumen yang Anda berikan. Proyek ini merupakan koleksi tugas dan proyek akhir semester yang mencakup berbagai konsep dasar Pemrograman Berorientasi Objek (PBO) dalam C++.

---

#### 📁 Direktori `Tugas`

Direktori ini berisi kode-kode program C++ yang dirancang untuk mendemonstrasikan konsep-konsep PBO secara terpisah.

* `Tugas_1.cpp` - Demonstrasi dasar penggunaan kelas dan objek dengan kelas `MataKuliah`.
* `Tugas_2_C1.cpp` - Program sederhana yang menunjukkan penggunaan kelas (`Pesawat`) dan struct (`JenisPesawat`).
* `Tugas_2_C2.cpp` - Contoh lain yang menggunakan kelas (`Gedung`) dan struct (`Dubai`), dengan constructor untuk menginisialisasi objek.
* `Tugas_3.cpp` - Menjelaskan konsep enkapsulasi dan penggunaan hak akses (`private` dan `public`). Program ini juga menggunakan *constructor* untuk membuat objek `User` dan *destructor* untuk menghapus objek.
* `Tugas_4.cpp` - Mengilustrasikan penggunaan *constructor* dan *destructor* pada kelas `Kendaraan` serta penggunaan `struct` di dalamnya.
* `Tugas_5.cpp` - Contoh implementasi *polimorfisme* dan *pewarisan* dengan kelas dasar `Permainan` dan kelas turunan `MesinSlot` dan `Dadu`. Program ini mensimulasikan permainan kasino sederhana.
* `Tugas_UTS.cpp` - Menggunakan kelas `Pegawai` untuk menunjukkan konsep *constructor* dan *destructor* dalam mengelola data pegawai.
* `Quiz.cpp` - Implementasi *polimorfisme* dengan kelas dasar `Kendaraan` dan kelas turunan `Mobil`, `Motor`, dan `Truk`. Setiap turunan meng-override fungsi `pengecekan()` untuk menampilkan informasi spesifik.

---

#### 📁 Direktori `MCV` (Model-View-Controller)

Direktori ini memuat beberapa versi implementasi pola desain MVC. Pola MVC memisahkan logika aplikasi (Model), antarmuka pengguna (View), dan interaksi pengguna (Controller) menjadi komponen-komponen yang berbeda.

* `mcv tanpa poly/` - Implementasi MVC sederhana tanpa menggunakan polimorfisme. `StudentController` berinteraksi langsung dengan `StudentModel` dan `StudentView` tanpa melalui interface.
* `mvc input/` - Versi MVC yang lebih maju dengan antarmuka polimorfik (`IModel`, `IView`, `IController`). `Controller` berfungsi untuk mengkoordinasi input dari `View` ke `Model`.
* `mvc tanpa const/` - Menunjukkan implementasi MVC dengan *polimorfisme* tetapi tanpa menggunakan keyword `const`.
* `mvc mengunakan const/` - Menunjukkan praktik baik dalam OOP dengan menggunakan keyword `const` pada fungsi-fungsi yang tidak memodifikasi data.

---

#### 📁 Direktori `UAS` (Proyek Akhir Semester)

Proyek ini adalah implementasi MVC yang kompleks untuk sistem manajemen buku. Program ini menunjukkan penggunaan polimorfisme untuk dua jenis pengguna berbeda, yaitu `Mahasiswa` (mahasiswa) dan `Dosen` (dosen).

* `model.hpp` - Berisi kelas `IMODEL` sebagai antarmuka dasar, serta kelas turunan `MahasiswaModel` dan `DosenModel`.
* `view.hpp` - Berisi antarmuka `IVIEW` dan implementasi `MahasiswaView` dan `DosenView` yang menampilkan data sesuai dengan jenis penggunanya.
* `controller.hpp` - Berisi antarmuka `ICONTROLLER` dan implementasi `MahasiswaController` dan `DosenController` untuk mengelola interaksi antara model dan view.
* `main.cpp` - Program utama yang menginisialisasi objek-objek MVC untuk `Mahasiswa` dan `Dosen` dan menjalankan alur program.

---

#### 📄 Dokumentasi Tambahan

Dua file dokumen ini berfungsi sebagai landasan teoretis untuk kode-kode program yang ada di direktori `Tugas`.

* **"[PBO] - Fachrezi Bachri - 2401020010 - TUGAS 1.docx/pdf"**:
    * **Hak Akses** - Dokumen ini menjelaskan tiga hak akses utama (`public`, `private`, dan `protected`) dan perbedaannya.
    * **Constructor & Destructor** - Mendefinisikan *constructor* sebagai metode yang dipanggil secara otomatis saat objek dibuat, dan *destructor* sebagai metode yang dipanggil saat objek dihapus atau keluar dari cakupan. Dokumen ini juga mencantumkan perbedaan utama antara keduanya.

* **"[PBO] - Fachrezi Bachri - 2401020010 - TUGAS 2.docx/pdf"**:
    * **Enkapsulasi** - Menjelaskan enkapsulasi sebagai proses pembungkusan data dan fungsi dalam satu unit, yaitu kelas.
    * **Pewarisan (Inheritance)** - Menggambarkan pewarisan sebagai kemampuan kelas untuk memperoleh properti dari kelas lain. Dokumen ini menguraikan berbagai jenis pewarisan dalam C++:
        * **Single Inheritance**
        * **Multiple Inheritance**
        * **Multilevel Inheritance**
        * **Hierarchical Inheritance**
        * **Hybrid Inheritance**

---

#### ⚙️ Direktori `.vscode`

Direktori ini berisi file konfigurasi untuk Visual Studio Code (`settings.json` dan `tasks.json`) yang digunakan untuk membantu proses kompilasi dan debugging kode C++ di dalam IDE tersebut.
