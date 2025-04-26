import numpy as np

# Giả sử ma trận A là một ma trận đối xứng 7x7
A = np.array([
    [6, -1, -1, -1, -1, -1, -1],
    [-1, 6, -1, -1, -1, -1, -1],
    [-1, -1, 6, -1, -1, -1, -1],
    [-1, -1, -1, 6, -1, -1, -1],
    [-1, -1, -1, -1, 6, -1, -1],
    [-1, -1, -1, -1, -1, 6, -1],
    [-1, -1, -1, -1, -1, -1, 6]
    
])

# Tính định thức
det_A = np.linalg.det(A)
print("Định thức của ma trận A là:", det_A)