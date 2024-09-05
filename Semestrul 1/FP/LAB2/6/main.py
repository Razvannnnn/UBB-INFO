n=int(input("n="))
a=1
b=1
c=a+b
while c<=n:
    c=a+b
    a=b
    b=c

print(c)