
print("PERFECTION OUTPUT")

while True:

    l = list(map(int, input().split()))

    done = False

    for n in l:
        if n == 0: 
            done = True;
            break
        
        add = 0
        b = False
        
        for i in range(1, n):
            if n % i == 0:
                add += i
            if add > n:
                b = True
        
        if b:
            s = "ABUNDANT"
        elif add == n:
            s = "PERFECT"
        else: 
            s = "DEFICIENT"

        print("{:>5}  {}".format(n, s))
    
    if done:
        break
    
print("END OF OUTPUT")
