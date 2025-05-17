def Dot( u : list , v : list):
    return u[0]*v[0] + u[1]*v[1]

def len2(v : list):
    return v[0]*v[0] + v[1]*v[1]

def Proj(u : list ,v : list):
    p = [0,0]
    p[0] = Dot(u,v) * u[0]/len2(v)
    p[1] = Dot(u,v) * u[1]/len2(v)

    return p