import sys
t = int(sys.stdin.readline())
bodd = 0
beven = 0
mix = 0
M = 1000000007
for _ in range(t):
    n = int(sys.stdin.readline())
    for _ in range(n):
        n1, n2 = map(int, sys.stdin.readline().split())
        if (n1 & 1) and (n2 & 1):
            bodd += 1
        elif (n1 & 1) or (n2 & 1):
            mix += 1
        else:
            beven = +1
    a = (4 * bodd * beven) % M
    b = (2 * bodd * mix) % M
    c = (2 * beven * mix) % M
    d = (mix * (mix - 1)) % M
    ans = (a + b + c + d) % M
    print(ans)
    # print("Bodd = ", bodd, "beven = ", beven, "mix = ", mix)
