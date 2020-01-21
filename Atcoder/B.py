import sys

def main():
  a, b = map(int, sys.stdin.readline().split())
  s = str(b)
  s1 = s*a
  s = str(a)
  s2 = s * b
  print(s1) if s1 <= s2 else print(s2)
if __name__ == "__main__":
  main()
