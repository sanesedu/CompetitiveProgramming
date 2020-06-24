
index = 1

while True:
    n = int(input())
    if n == 0:
        break
    nums = list(map(int, input().split()))
    owed = 0
    given = 0
    for i in nums:
        if i == 0:
            given += 1
        else:
            owed += 1

    print("Case %d: %d" % (index, owed - given))
    index += 1
