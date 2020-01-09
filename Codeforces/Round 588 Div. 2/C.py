import sys


def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  n, m = map(int, input().split())
 
  if n < 7:
      print(m)
  else:
      g = []
      for i in range(7):
          g.append(set())
  
      for _ in range(m):
          x, y = map(int, input().split())
          g[x-1].add(y)
          g[y-1].add(x)
  
      mn = 1000
      for i in range(7):
          for j in range(i+1,7):
  
              s = g[i] & g[j]
  
              if len(s) < mn:
                  mn = len(s)
  
      print(m - mn)
    


if __name__ == "__main__":
  main()
