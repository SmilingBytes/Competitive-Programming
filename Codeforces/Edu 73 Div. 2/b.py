import sys


def main():
  sys.stdin = open('in.txt', 'r') 
  sys.stdout = open('out.txt', 'w')
  n = int(sys.stdin.readline())
  for i in range(1, n+1):
    if (i % 2 == 1):
      p = 'W'
      for _ in range(n):
        print(p, end="")
        p = 'B' if p =='W' else 'W'
    else:
      p = 'B'
      for _ in range(n):
        print(p, end="")
        p = 'B' if p =='W' else 'W'
    print()


  


if __name__ == "__main__":
  main()
