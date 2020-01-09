import sys

def main():
  sys.stdin = open('in.txt', 'r')
  t = int(sys.stdin.readline())
  for _ in range(t):
    n = int(sys.stdin.readline())
    a = list(sys.stdin.readline())
    b = list(sys.stdin.readline())
    
    chk = False #1st row
    for i in range(n):
      
      if chk is False:
        if int(a[i]) > 2:
          if int(b[i]) <= 2:
            chk = False
            break
          chk = not (chk)
      else:
        if int(b[i]) > 2:
          if int(a[i]) <= 2:
            chk = False
            break
          chk = not (chk)
    print("YES") if chk is True else print("NO")

if __name__ == "__main__":
  main()
