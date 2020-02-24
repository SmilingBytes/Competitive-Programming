n, m, k = map(int, input().split())
spItem = list(map(int, input().split()))

lnum = k
ans = 0


def sp_item_checker():
    i = 0
    while spItem[0] <= lnum:
        del spItem[0]
        i += 1
        if len(spItem) == 0:
            break
    return i


while len(spItem) > 0:
    if spItem[0] > lnum:
        ln = spItem[0] - lnum
        pg = ln // k if ln % k == 0 else (ln // k) + 1
        lnum = pg * k + lnum

    lnum += sp_item_checker()
    ans += 1

print(ans)


#
# 1 3 5 7 8 9 10 = 7 > 17
# 16 = 1 > 18
# 18 = 1 > 19
#
# 21 22 23 24 25 27 30 32 35 36 37 38 39 40 43 45 47 49 50 51 52 54 57 59 61 64 66 67 68 69 70 71 72 73 80 83 86 87 88 89 90 91 92 96 97 98
