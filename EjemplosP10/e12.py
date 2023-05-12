x= np.linspace.pylot as plt
print(x)

fig, ax= plt.subplots(facecolor='w', edgecolor='k')
ax.plot(x, np.sin(x), marker='o', color='r', linestyle'None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y = sen(x)")

plt.title("Funcón senoidal")
plt.show()