import sys
sys.stdin = open('in.txt', 'r')
t = int(sys.stdin.readline())
  # sys.stdout = open('out.txt', 'w')
for q in range(t):
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))

    flag = True
    if (n == 1):
        a[0] = 1 if (a[0] == -1) else a[0]
    elif k == 1:
        flag = False
    elif k == 2:
      if (a[0] != -1):
        for i in range(1, n):
          if (a[i] == -1):
            a[i] = (a[i - 1] % 2) + 1
          elif a[i] == a[i - 1]:
            flag = False
            break
      elif a[n - 1] != 0:
        for i in range(n-2, -1, -1):
          if (a[i] == -1):
            a[i] = (a[i + 1] % 2) + 1
          elif a[i] == a[i + 1]:
            flag = False
            break
      else:
        i = 0
        while a[i] == -1:
          i += 1
        if (i == n):
          for i in range(n):
            a[i] = (i % 2) + 1
        else:
          j = i
          i -= 1
          while (i >= 0):
            a[i] = (a[i + 1] % 2) + 1
          for i in range(j, n):
            if (a[i] == -1):
              a[i] = (a[i - 1] % 2) + 1
            elif a[i] == a[i - 1]:
              flag = False
              break
    else:
      for i in range(n):
        chk = False
        if (a[i] == -1 and 0 < i < n - 1):
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
