import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

# méthode qui retourne la matrice de rotation en fonction de l'angle en x t en y. La matrice a été calculé à la main
def f(thetaX, thetaY):
    cX, sX = np.cos(np.degrees(thetaX)), np.sin(np.degrees(thetaX))
    cY, sY = np.cos(np.degrees(thetaY)), np.sin(np.degrees(thetaY))
    return np.array(((cY, 0, -sY), (-sX*sY, cX, -sX*cY), (cX*sY, sX, cX*cY)))

# Matrice de rotation qui prend 2 angles
R = f(0, 0)

fig = plt.figure()
ax = Axes3D(fig)

x = [1, 1, 0, 0]
y = [0, 1, 1, 0]
z = [0.5, 0.5, 0.5, 0.5]
center = 0.5
v = [x, y, z]
vo = np.array(v)

# Il faut prendre les points initiaux et soustraire le centre de rotation (ex: 0.5, 0.5, 0.5)
# Multiplier matrice de rotation avec ces nouveaux points
# Additionner le centre de rotation au résultat

# Permet de multiplier une matrice 3x3 par une 4x3 = matrice 3x4...
# ... avec comme résulats: 1ere ligne = les x, 2e ligne = les y et 3e ligne = les z
result = [[sum(a*b for a, b in zip(X_row, Y_col)) for Y_col in zip(*vo)] for X_row in R]

e = np.array(result)
print(e)



verts = [list(zip(e[0], e[1], e[2]))]
ax.add_collection(Poly3DCollection(verts))
plt.axis([-2,2,-2,2])
plt.show()