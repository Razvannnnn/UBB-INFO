def prim(x):
    if x<=1:
        return 0
    if x==2:
        return 1
    if x%2==0:
        return 0
    for i in range(3,x,2):
        if x%i==0:
            return 0
    return 1

def main():
        n=int(input("n="))
        q=n+3
        p=n+1

        while prim(q)==0 and prim(p)==0:
            q=q+1
            p=p+1

        print(p,q)


if __name__=="__main__":
    main()