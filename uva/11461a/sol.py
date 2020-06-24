
import math

while True:
    lst = list(map(int, input().split()))
    a = lst[0]
    b = lst[1]
   
    if a == 0 and b == 0:
        break

    ini = int(math.ceil(math.sqrt(a)))
    end = int((math.sqrt(b)))
    
    res = 0

    for i in range(ini, end+1):
        if i * i > b:
            break
        else:
            res += 1
    
    print(res)
