fr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

n = int(input("n="))
ok = 0

while n != 0:
    c = n % 10
    fr[c] = fr[c] + 1
    if c == 0:
        ok = 1
    n = n // 10

x = 0

for i in range(1, 9):
    if fr[i] != 0:
        while fr[i] != 0:
            x = x * 10 + i
            fr[i] = fr[i] - 1
            if ok == 1:
                while fr[0] != 0:
                    x = x * 10
                    fr[0] = fr[0] - 1
                ok = 0

print(x)
