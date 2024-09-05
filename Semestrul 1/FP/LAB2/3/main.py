def zile_luna(luna,an):
    ok=0
    if an%400==0 or an%4==0:
        ok=1
    if(ok==1 and luna==2):
        return 29
    if(luna==2):
        return 28
    if(luna==1 or luna==3 or luna==5 or luna==7 or luna==8 or luna==10 or luna==12):
        return 31
    return 30

def main():
    an=int(input("an="))
    nrord=int(input("zi="))
    z=0
    l=1

    while nrord>0:
        z=z+1
        nrord=nrord-1
        zile=zile_luna(l,an)
        if z>zile:
            z=1
            l=l+1

    print(z,l,an)

if __name__==("__main__"):
    main()