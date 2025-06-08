
## Judul Program
**Simulasi Respons Transien Rangkaian RLC Seri Menggunakan Metode Runge-Kutta Orde 4 (RK4)**

## Data Mahasiswa
| Nama Lengkap  | NPM         |
|---------------|-------------|
| Samih Bassam  | 2306250623  |

## Deskripsi Program

Program ini dibuat untuk mensimulasikan respons arus dan muatan dari suatu rangkaian RLC seri terhadap tegangan masukan sinusoidal \( V(t) = 10\sin(100t) \), menggunakan metode numerik **Runge-Kutta orde 4 (RK4)**.  
Persamaan diferensial orde dua dari sistem dikonversi menjadi sistem dua persamaan diferensial orde satu, kemudian diselesaikan secara numerik menggunakan bahasa C.

Nilai arus \( i(t) \) dan muatan \( q(t) \) dihitung dan disimpan dalam file `.csv` untuk divisualisasikan. Program ini membantu menganalisis perilaku transien dan steady-state dari sistem, tanpa solusi analitik eksplisit.

**Fitur utama program:**
- Transformasi model orde dua ke dua ODE orde satu.
- Implementasi metode RK4 dalam bahasa C.
- Output data simulasi ke file `output.csv`.
- Kompatibel untuk visualisasi dengan Python, GNUPlot, atau Excel.

---

##  Parameter Rangkaian

| Komponen         | Simbol | Nilai           |
|------------------|--------|-----------------|
| Resistor         | R      | 10 Ohm          |
| Induktor         | L      | 0.5 Henry       |
| Kapasitor        | C      | 0.01 Farad      |
| Tegangan Masukan | V(t)   | 10 sin(100t) V  |

##  Konfigurasi Simulasi

| Parameter       | Nilai                 |
|----------------|-----------------------|
| Waktu awal     | 0 detik               |
| Waktu akhir    | 0.1 detik             |
| Langkah waktu  | 0.001 detik           |
| Kondisi awal   | q(0) = 0, i(0) = 0    |

---

##  Cara Menjalankan

### 1. Kompilasi kode
```bash
gcc main.c -o rlc_sim
```

### 2. Jalankan program
```bash
./rlc_sim
```

### 3. Output
File `output.csv` akan dihasilkan dengan format:
- `t` (waktu)
- `q(t)` (muatan)
- `i(t)` (arus)

File ini dapat digunakan untuk visualisasi data.

---

## Deskripsi Program Python untuk Grafik

Visualisasi data simulasi dilakukan menggunakan program Python dengan library `matplotlib`.  
Grafik yang ditampilkan meliputi:
- **Grafik arus terhadap waktu** \( i(t) \)
- **Grafik muatan terhadap waktu** \( q(t) \)

Program Python membaca file `output.csv` yang dihasilkan dari program C dan menampilkan dua grafik untuk membantu memahami bagaimana sistem RLC merespons input sinusoidal seiring waktu.  
Grafik ini menunjukkan fase transien dan kemudian kondisi steady-state.

---

**Catatan:**  
- `main.c` berisi kode utama simulasi RLC menggunakan metode RK4.  
- `output.csv` berisi hasil simulasi.  
- `plot.py` (jika ada) digunakan untuk memvisualisasikan hasil.  