import sys
 
 
def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  t = int(sys.stdin.readline())
  for _ in range(t):
    s = set(sys.stdin.readline())
    t = set(sys.stdin.readline())
    flag = False
    for x in s:
      if x in t:
        flag = True
        break
    print("YES") if (flag is True) else print("NO")
 
if __name__ == "__main__":
  main()