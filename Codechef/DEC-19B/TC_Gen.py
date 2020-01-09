import sys
import random
# print(random.randint(0,9))

def randomword(length):
   letters = "10"
   return ''.join(random.choice(letters) for i in range(length))
   
def main():
  sys.stdout = open('in.txt', 'w')
  # t = random.randint(1, 3)
  print(1)
  for _ in range(1):
    n = random.randint(1, 100)
    print(n)
    # for _ in range(n):
    x = randomword(n)
    y = randomword(n)
    print(x)
    print(y)
      

if __name__ == "__main__":
  main()
