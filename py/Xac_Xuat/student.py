import scipy.stats as stats
def tra_cuu_gia_tri_toi_han(alpha, n):
    
    # Tính giá trị tới hạn từ phân phối t
    t_value = stats.t.ppf(1-alpha, df=n)
    
    return t_value

#   calculate t(a,n)
# alpha = 0.05 
while True:
    alpha = float(input('Nhập α: ')) 
    # n = 20 
    n = int(input('Nhập n: ')) 

    gia_tri_toi_han = round(tra_cuu_gia_tri_toi_han(alpha, n), 4)
    print(f"--> t({alpha},{n}) = {gia_tri_toi_han}")