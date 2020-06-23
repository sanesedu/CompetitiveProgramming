
for a in range(1, 50):
    res = 0;
    for b in range(a, 1000):
        for c in range(b, 1000):
            if 1/a == (1/b + 1/c):
                res += 1
                #print (a, b, c)
    print (a,":", res)
