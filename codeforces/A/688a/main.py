n, d = map(int, input().split())

ans = ""

for i in range(d):
    a = input().find("0")
    if a != -1:
        ans += "1"
    else:
        ans += "0"

#print(ans)

ans = ans.split("0") 

#print(ans)

ans = list(filter(None, ans))

if len(ans) == 0:
    print('0')
else:
    print(max(list(map(len, ans))))
