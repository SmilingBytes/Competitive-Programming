import sys

def primeFactor(n):
  if (n % 2 == 0):
    return True
  d = 3
  while d*d <= n:
    if (n % d == 0):
      return True
    d += 2
  if (n > 1):
    return True
  return False

def binpower(base, e, mod):
  result = 1
  base %= mod
  while (e):
    if (e & 1):
      result = result * base % mod
    base = base * base % mod
    e >>= 1
  return result

def check_composite( n,  a, d, s):
  x = binpower(a, d, n)
  if (x == 1 or x == n - 1):
     return False
  for _ in range(1,int(s)):
    x = x * x % n
    if (x == n - 1):
      return False
  return True

def MillerRabin(n): #returns True if n is prime, else returns False.
  if (n < 2):
    return False
  r = 0
  d = n - 1
  while ((d & 1) == 0):
    d >>= 1
    r += 1
    
  for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
    if (n == a):
      return True
    if (check_composite(n, a, d, r)):
      return False
  return True

def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  t = int(sys.stdin.readline().strip())
  for _ in range(t):
    x, y = map(int, sys.stdin.readline().split())
    n = x - y
    if (MillerRabin(n) and ):
      print("YES")
      continue
    ans = primeFactor(n)
    if ans is True:
      print("YES")
    else:
      print("NO")
      


  if (MillerRabin(101)):
    print(" Message ")
  else:
    print("No")
    


if __name__ == "__main__":
  main()
