import sys


def main():
  n = int(sys.stdin.readline())
  n = n-1
  cf = 'codeforces'
  s = 's'
  print((cf.ljust(n + len(cf), s)))


if __name__ == "__main__":
  main()
