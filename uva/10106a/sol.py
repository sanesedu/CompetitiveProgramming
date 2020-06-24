
from sys import stdin

while True:
    line = stdin.readline()
    if line == '':
        break
    x = int(line)
    y = int(input())
    print(x * y)
