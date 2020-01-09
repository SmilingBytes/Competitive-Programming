import sys, math

def main():
  sys.stdin = open('in.txt', 'r')
  n = int(sys.stdin.readline())
  a = list(map(int, sys.stdin.readline().split()))
  mx = max(a)
  s, z = 0, 0
  for i in range(n):
    a[i] = mx - a[i]
    s += a[i]
    z = math.gcd(a[i], z)
    
  y = s // z
  print(y, z)

if __name__ == "__main__":
  main()
