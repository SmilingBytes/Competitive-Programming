import sys


def countMinus1(a, i):
    cnt = 0
    for j in range(i, n):
        if (a[j] == -1):
            cnt += 1
        else:
            break
    return cnt


t = int(sys.stdin.readline())

for _ in range(t):
    n, k = map(int, sys.stdin.readline().split())
    a = [0]
    a.extend(list(map(int, sys.stdin.readline().split())))
    a.extend([0])

    flag = True
    if (n == 1):
        a[0] = 1 if (a[0] == -1) else a[0]
    elif (k == 2):
        for i in range(1, n + 1):
            if (a[i] == -1):
                cnt = countMinus1(a, i)
                fst = a[i - 1]
                lst = a[i + cnt]
                if (cnt == n):
                    for d in range(1, k + 1):
                        if (a[i - 1] != d and a[i + 1] != d):
                            a[i] = d
                            chk = True
                            break
    else:
        for i in range(n):
            if (a[i] == -1):
                fst = -1 if (i == 0) else a[i - 1]
                cnt = countMinus1(a, i)
                lst = a[i + cnt]
                if (k == 2):
                    if (0 < i < n - 1):
                        if (k == 2 and fst != lst and cnt & 1):
                            flag = False
                            break
                        elif (k == 2 and fst == lst and cnt % 2 == 0):
                            flag = False
                            break
                if (0 < i < n - 1):

                    for d in range(1, k + 1):
                        if (a[i - 1] != d and a[i + 1] != d):
                            a[i] = d
                            chk = True
                            break
                    if (chk is not True):
                        flag = False
                        break
                elif (a[i] == -1 and i == 0):
                    a[i] = 1 if (a[i + 1] != 1) else 2
                elif (a[i] == -1 and i == n - 1):
                    a[i] = 1 if (a[i - 1] != 1) else 2

    if (flag is True):
        print("YES")
        for i in range(n):
            print(a[i], end=' ')
        print('')
    else:
        print("NO")
