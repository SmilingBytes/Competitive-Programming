import sys


def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  t = int(sys.stdin.readline().strip())
  for _ in range(t):
    n, r = map(int, sys.stdin.readline().split())
    a = set(map(int, sys.stdin.readline().split()))
    if n == 1 or len(a) == 1:
      print(1)
      continue
    a = sorted(a, reverse=True)
    ans = 0
    for i in range(len(a)-1):
      ans += 1
      if a[i + 1] <= ans * r:
        break
    
    if a[len(a) - 1] > ans * r:
        ans+=1
    print(ans)
    
    


if __name__ == "__main__":
  main()
