import itertools as it
import numpy as np
import sys, math

sys.stdin = open('in.txt', 'r') 
sys.stdout = open('out.txt', 'w')

n, m = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

cnt, cnt2, total, ans = 0, 0, 0 ,0

for i in range(2, m+1): 
  for val in it.combinations(a, i):
    cnt2 +=1
    if len(set(val)) == i:
      cnt += 1
      # print("==> ", end=" ")
    # else:
    #   for d in val:
    #     print(d, end=" ")
    #   print()
  # print("\nFor", i, "Ignored =", cnt2-cnt, "Counted =", cnt, '\n')
  ans += cnt
  total += cnt2
  cnt, cnt2 = 0, 0

print(" Ans = ", ans+1+n, " Ignored = ", total - ans)