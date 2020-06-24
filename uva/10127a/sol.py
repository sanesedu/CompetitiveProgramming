
from sys import stdin

while True:
    line = stdin.readline()
    if line == '':
        break

    a = int(line)
    c = 1
    n = 1
    while n % a != 0:
        n = n*10 + 1
        n %= a
        c += 1

    print(c)
