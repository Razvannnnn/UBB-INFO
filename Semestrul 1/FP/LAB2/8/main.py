n = int(input("n="))

fr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

while n != 0:
    c = n % 10
    fr[c] = fr[c] + 1
    n = n // 10

x = 0

for i in range(9, 0, -1):
    while fr[i] != 0:
        x = x * 10 + i
        fr[i] = fr[i] - 1

print(x)
