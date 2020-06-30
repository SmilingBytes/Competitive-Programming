import sys

def isAnagram(s1, s2) : 
	s1 = list(s1); 
	s2 = list(s2); 
	s1 = s1.sort(); 
	s2 = s2.sort(); 
	
	return (s1 == s2)

def CountSteps(s1, s2, n) : 
	s1 = list(s1)
	s2 = list(s2) 
	i = 0
	j = 0
	result = 0
	while (i < n) : 
		j = i; 
		while (s1[j] != s2[i]) : 
			j += 1
		while (i < j) : 
			temp = s1[j]
			s1[j] = s1[j - 1]
			s1[j - 1] = temp
			j -= 1
			result += 1
			
		i += 1; 
		
	return result; 


if __name__ == "__main__": 

	s1, s2 = sys.stdin.readline().split()
	n = len(s2); 
	if (isAnagram(s1, s2)) : 
		print(CountSteps(s1, s2, n))
	else : 
		print(-1)
