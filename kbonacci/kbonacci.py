def kbonacci(k, n):
    f = [1]*k+[k]
    if n > k:
        i = k
        while i < n:
            f += [(2 * f[-1] - f.pop(0))]
            i += 1
    r = n > k and f[k] or f[n] 
    return str(r)