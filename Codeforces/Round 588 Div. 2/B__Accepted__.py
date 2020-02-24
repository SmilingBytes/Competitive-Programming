import sys


def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  n, k = map(int, sys.stdin.readline().split())
  s = list(sys.stdin.readline())
  if (n == 1 and k > 0):
    s[0] = '0'
  elif (k > 0):
    if s[0] != '1':
      s[0] = '1'
      k -= 1
    i = 1
    while n > i and k > 0:
      if s[i] != '0':
        s[i] = '0'
        k -= 1
      i += 1

  for x in s:
    print(x, end="")

if __name__ == "__main__":
  main()
