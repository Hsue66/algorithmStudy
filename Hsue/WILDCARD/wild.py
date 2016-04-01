# global var
cache = [[-1 for col in range(101)]for row in range(101)]

def compare(pattern,sample,p,s):
	if cache[p][s] != -1:
		return cache[p][s]
	
	while s < len(sample) and p < len(pattern):
		print "%d %d" %(p,s)
		if pattern[p] == '?':
			p =p+1
			s = s+1
		elif pattern[p] == '*':
			pass
		elif pattern[p] != sample[s]:
			cache[p][s] = 0
			return cache[p][s]
		elif pattern[p] == sample[s]:
			cache[p][s] = 1
			p = p+1
			s = s+1
	
	return cache[p-1][s-1]

def find(pattern,samples):
	for i in range(len(samples)):
		print samples[i]
		cache = [[-1 for col in range(101)]for row in range(101)]
		ret = compare(pattern,samples[i],0,0)
		print "ret %d"%ret
		if ret==0:
			samples[i] = 0

	# sort list
	samples.sort()

	for samp in samples:
		if samp !=0:
			print samp


if __name__ == "__main__":
	testcase = input()

	for t in range(testcase):
		temp = raw_input()

		# simplify pattern
		pattern= []
		for i in range(len(temp)):
			if i==0:
				pattern.append(temp[i])
			elif temp[i]=="*" and  pattern[len(pattern)-1]=="*":
					pass
			else:
				pattern.append(temp[i])	
		pattern = "".join(pattern)

		# input samples	
		samples = []
		number = input()

		for i in range(number):
			temp = raw_input()
			samples.append(temp)


		find(pattern,samples)
