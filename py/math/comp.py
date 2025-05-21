import math

def comp(k, n):
  """
  Tính tổ hợp chập k của n (kCn).

  Args:
    k: Số phần tử được chọn.
    n: Tổng số phần tử.

  Returns:
    Giá trị của tổ hợp chập k của n.
    Trả về 0 nếu k < 0, k > n hoặc n < 0.
  """
  if k < 0 or k > n or n < 0:
    return 0
  if k == 0 or k == n:
    return 1
  if k > n // 2:
    k = n - k

  numerator = 1
  for i in range(k):
    numerator *= (n - i)

  denominator = math.factorial(k)

  return numerator // denominator

# Ví dụ sử dụng
k = 0
n = 4
result = comp(k, n)
print(f"Tô hợp chập {k} của {n} là: {result}")