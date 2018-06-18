def largestPlateau(m):
    r = 0
    q = len(m)
    if q:
        p = len(m[0])
        def f(k,i,j):
            if 0<=i<q and 0<=j<p and m[i][j]==k:
                m[i][j]=-2
                return 1 + f(k,i,j+1)+f(k,i-1,j)+f(k,i+1,j)+f(k,i,j-1)
            return 0
        for i in range(q):
            for j in range(p):
                k = m[i][j]
                if k!=-2:
                    r = max(r, f(k,i,j))
    return r