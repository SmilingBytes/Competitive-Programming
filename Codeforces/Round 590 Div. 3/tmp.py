import sys


def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  a = list(map(int, sys.stdin.readline().split()))
  print(len(a))
  
  


if __name__ == "__main__":
  main()
