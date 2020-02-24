import sys

sys.stdin = open('in.txt', 'r') 
sys.stdout = open('out.txt', 'w')
x = 2048
while x > 1:
  x = x // 2
  print(x)