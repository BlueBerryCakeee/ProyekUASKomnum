#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Parameter RLC
#define R 10.0      // Ohm
#define L 0.5       // Henry
#define C 0.01      // Farad

// Simulasi
#define T_START 0.0
#define T_END 0.1
#define H 0.001     // Langkah waktu

// Fungsi tegangan input V(t) = 10 sin(100t)
double V(double t) {
    return 10.0 * sin(100.0 * t);
}

// Turunan y1 = dq/dt = i(t)
double dy1_dt(double t, double y1, double y2) {
    return y2;
}

// Turunan y2 = di/dt = (1/L)(V - R*i - (1/C)*q)
double dy2_dt(double t, double y1, double y2) {
    return (1.0 / L) * (V(t) - R * y2 - (1.0 / C) * y1);
}

int main() {
    FILE *f = fopen("output.csv", "w");
    if (!f) {
        printf("Gagal membuka file output.csv\n");
        return 1;
    }

    // Header CSV
    fprintf(f, "t,q(t),i(t)\n");

    // Inisialisasi kondisi awal
    double t = T_START;
    double y1 = 0.0; // muatan q(t)
    double y2 = 0.0; // arus i(t)

    // Simulasi dengan RK4
    while (t <= T_END) {
        fprintf(f, "%.6f,%.6f,%.6f\n", t, y1, y2);

        // Hitung koefisien RK4
        double k1_1 = H * dy1_dt(t, y1, y2);
        double k1_2 = H * dy2_dt(t, y1, y2);

        double k2_1 = H * dy1_dt(t + H / 2.0, y1 + k1_1 / 2.0, y2 + k1_2 / 2.0);
        double k2_2 = H * dy2_dt(t + H / 2.0, y1 + k1_1 / 2.0, y2 + k1_2 / 2.0);

        double k3_1 = H * dy1_dt(t + H / 2.0, y1 + k2_1 / 2.0, y2 + k2_2 / 2.0);
        double k3_2 = H * dy2_dt(t + H / 2.0, y1 + k2_1 / 2.0, y2 + k2_2 / 2.0);

        double k4_1 = H * dy1_dt(t + H, y1 + k3_1, y2 + k3_2);
        double k4_2 = H * dy2_dt(t + H, y1 + k3_1, y2 + k3_2);

        // Update solusi
        y1 += (k1_1 + 2 * k2_1 + 2 * k3_1 + k4_1) / 6.0;
        y2 += (k1_2 + 2 * k2_2 + 2 * k3_2 + k4_2) / 6.0;
        t += H;
    }

    fclose(f);
    printf("Simulasi selesai. Data disimpan ke 'output.csv'\n");
    return 0;
}
