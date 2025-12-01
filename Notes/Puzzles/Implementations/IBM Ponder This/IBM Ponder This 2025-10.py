import mpmath as mp
def product_mn(m,n,prec=250):
    # Set internal precision (digits)
    mp.mp.dps = prec  
    prod = mp.mpf('1')
    for k in range(1, n):
        for h in range(1, m):
            term = 4 * mp.sin(h * mp.pi / (2 * m))**2 + 4 * mp.sin(k * mp.pi / (2 * n))**2
            prod *= term
    return prod
m,n=342,357
print(product_mn(m,n))