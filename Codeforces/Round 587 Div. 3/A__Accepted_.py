import sys


def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  n = int(sys.stdin.readline())
  s = sys.stdin.readline()
  cnt = 0
  ans = []
  for i in range(0, n, 2):
    if s[i] == s[i + 1]:
      cnt += 1
      r = 'a' if s[i] == 'b' else 'b'
      ans += [r, s[i]]
    else:
      ans += [s[i], s[i+1]]
  print(cnt)
  for x in ans:
    print(x, end="")
  print()

if __name__ == "__main__":
  main()
