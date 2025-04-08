import numpy as np
import matplotlib.pyplot as plt
import matplotlib
from scipy import stats
matplotlib.use('TkAgg')
n = np.array([1000, 10000,50000, 100000,500000, 1000000])
T = np.array([96830,
              1217809,
              6816403,
              14961584,
              83445830,
              168114660])
n_log_n = n * np.log2(n)
slope, intercept, r_value, _, _ = stats.linregress(n_log_n, T)
plt.scatter(n_log_n, T, label='Data')
plt.title("Heapsort")
plt.plot(n_log_n, slope * n_log_n + intercept, 'r', label=f'Y ={slope:.4f}nlog n + {intercept:.2f}')
plt.annotate(f'r^2 = {r_value**2:.4f}', xy=(0.1, 0.8), xycoords='axes fraction')

plt.xlabel('$n \log n$')
plt.ylabel('Średni czas wykonania dla algorytmu [ns]')
plt.legend()
print("r^2:", r_value**2)
plt.show()
