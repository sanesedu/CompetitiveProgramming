
t = int(input())

freq = {}

while t > 0:
    
    country = input().split()[0]
    if country in freq:
        freq[country] += 1
    else:
        freq[country] = 1
    t -= 1

for k,v in sorted(freq.items()):
    print(k, v)
