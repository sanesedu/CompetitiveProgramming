
t = int(input())

for i in range(0, t):
    line = list(map(int, input().split()))
    s = int(line[0])
    d = int(line[1])
    if s < d:
        print("impossible")
    else:
        a = int((s + d)/2)
        if (a * 2) != (s + d):
            print("impossible")
        else:
            b = int(s - a)
            print(a, b)
