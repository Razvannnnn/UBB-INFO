n=int(input("n="))
x=0
while n!=0:
    c=n%10
    x=x*10+c
    n=n//10
print(x)