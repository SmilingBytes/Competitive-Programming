import sys


def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  l, r = sys.stdin.readline().split()
  for i in range(int(l), int(r) + 1):
    s = str(i)
    a = set(s)
    if len(a) == len(s):
      print(i)
      exit()

  print(-1)

if __name__ == "__main__":
  main()
