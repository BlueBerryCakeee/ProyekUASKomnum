import matplotlib.pyplot as plt
import pandas as pd

# Membaca data dari file output.csv
data = pd.read_csv("output.csv")

# Ambil kolom data
t = data['t']
q = data['q(t)']
i = data['i(t)']

# Plot arus i(t)
plt.figure(figsize=(10, 5))
plt.plot(t, i, label='Arus i(t)', color='blue')
plt.title('Grafik Arus i(t) terhadap Waktu')
plt.xlabel('Waktu (s)')
plt.ylabel('Arus i(t) (A)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()

# Plot muatan q(t)
plt.figure(figsize=(10, 5))
plt.plot(t, q, label='Muatan q(t)', color='green')
plt.title('Grafik Muatan q(t) terhadap Waktu')
plt.xlabel('Waktu (s)')
plt.ylabel('Muatan q(t) (C)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
