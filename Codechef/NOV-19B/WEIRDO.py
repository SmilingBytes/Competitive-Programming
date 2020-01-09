import sys

v = {"a", "e", "i", "o", "u"}

def power(b, p):
    res = 1

    while p:
        if p & 0x1: res *= b
        b *= b
        p >>= 1

    return res

def createdBy(s):
  ln = len(s)
  for i in range(ln - 2):
    cnt = int(s[i] in v) + int(s[i + 1] in v) + int(s[i + 2] in v)
    if cnt < 2:
      return False
  return True

def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  t = int(sys.stdin.readline().strip())
  for _ in range(t):
    n, m = 0, 0
    ax, afx, bx, bfx = {}, {}, {}, {}
    ln = int(sys.stdin.readline().strip())

    for _ in range(ln):
      s = sys.stdin.readline().strip()
      alpha = set()
      alpha.clear()

      if (createdBy(s)):
        n += 1
        for ch in s:
          afx.setdefault(ch, 0)
          afx[ch] = afx[ch] + 1
          if ch not in alpha:
            ax.setdefault(ch, 0)
            ax[ch] += 1
            alpha.add(ch)
      else:
        m += 1
        for ch in s:
          bfx.setdefault(ch, 0)
          bfx[ch] += 1
          if ch not in alpha:
            bx.setdefault(ch, 0)
            bx[ch] += 1
            alpha.add(ch)

    sca, scb = 1.0, 1.0
    
    for ch in ax:
      num = power(afx[ch], n)
      sca = sca * (ax[ch] / num)
    
    for ch in bx:
      num = power(bfx[ch], m)
      scb = scb * (bx[ch] / num)

    ans = sca / scb
    
    print("Infinity") if (ans > 1e7) else print(ans)
    

if __name__ == "__main__":
  main()
