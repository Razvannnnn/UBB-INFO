from random import randint, random
from matplotlib.pyplot import plot, grid, title, show, axis
from math import dist

def probabil(n, nr_sim, probabil = False):
    k=0
    for _ in range(nr_sim):
        if len(set([randint(1,365) for _ in range(n)])) < n:
            k = k + 1
    if probabil:
        p=1
        for k in range(n):
            p*=(365-k)/365
        return 1-p
    return k/nr_sim



if __name__ == '__main__':
    """
    print(probabil(50,5000, probabil=True))
    title('Plot A')
    xs = range(2,50)
    ys = [probabil(x,10000)for x in xs]
    plot(xs,ys,'r*')
    grid()
    show()
    
    title('Plot B')
    xs = range(2, 50)
    ys = [probabil(x, 10000, probabil=True) for x in xs]
    plot(xs, ys, 'r*')
    grid()
    show()
    """

    axis('square')
    axis((0,1,0,1))
    M=[0.5,0.5]
    A = [0, 0]
    B = [1, 0]
    C = [0, 1]
    D = [1, 1]
    for i in range(2000):
        F=[random(), random()]
        if(dist(F, M) <= min(dist(F, A), dist(F, B), dist(F,C), dist(F,D))):
            plot(F[0], F[1], 'ro')
        else:
            plot(F[0], F[1], 'bo')
    show()

    axis('square')
    axis((0, 1, 0, 1))
    M = [0.5, 0.5]
    A = [0, 0]
    B = [1, 0]
    C = [0, 1]
    D = [1, 1]
    for i in range(3000):
        F = [random(), random()]
        FA,FB,FC,FD = dist(F, A), dist(F, B), dist(F, C), dist(F, D)
        tr_obtuze = (FA**2+FB**2<1)+(FB**2+FC**2<1)+(FC**2+FD**2<1)+(FD**2+FA**2<1)
        if tr_obtuze==2:
            plot(F[0], F[1], 'ro')
        else:
            plot(F[0], F[1], 'bo')
    show()
