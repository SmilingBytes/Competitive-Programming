t = int(input())
while (t > 0):
    x, y, k, n = map(int,input().split())
    page = x - y
    lc = 0
    for j in range(n):
        p, c = map(int, input().split())
        if c <= k and p >= page:
            lc += 1
    print("Luckychef") if lc > 0 else print("Unluckychef")
    t -= 1