# global var
size =0
cache = dict()

# same or not
def same(subnumbers):
	ret = 1
	for i in range(len(subnumbers)-1):
		if subnumbers[i] != subnumbers[i+1]:
			ret = 0	
	return ret

# monotonous increase/decrease or not
def mono(subnumbers):
	ret = 1
	diff = int(subnumbers[1])-int(subnumbers[0])
	if abs(diff) != 1:
		return 0
	for i in range(len(subnumbers)-1):
		if int(subnumbers[i])+diff != int(subnumbers[i+1]):
			ret = 0
	return ret

# alter two numbers or not
def alter(subnumbers):
	ret = 1
	diff = int(subnumbers[1])-int(subnumbers[0])
	for i in range(len(subnumbers)-1):
		if i%2 == 1:
			if int(subnumbers[i])-diff != int(subnumbers[i+1]):
				ret = 0
		else:
			if int(subnumbers[i])+diff != int(subnumbers[i+1]):
				ret = 0
	return ret

# series numbers or not
def series(subnumbers):
	ret = 1
	diff = int(subnumbers[1])-int(subnumbers[0])
	for i in range(len(subnumbers)-1):
		if int(subnumbers[i])+diff != int(subnumbers[i+1]):
			ret = 0
	return ret



def getMinValue(subnumbers):
	if same(subnumbers) == 1:
		return 1
	elif mono(subnumbers) == 1:
		return 2
	elif alter(subnumbers) == 1:
		return 4
	elif series(subnumbers) == 1:
		return 5
	else:
		return 10


def search(subnumbers,first):
	global cache,size
	# if finished
	if first == size:
		return 0

	# check cached or not
	if first in cache:
		return cache.get(first)

	ret = 987654321
	for i in range(3,6):
		if first+i <= size:
			ret = min(ret,getMinValue(subnumbers[0:i])+search(subnumbers[i:len(subnumbers)],i+first))
	cache[first] = ret

	return cache.get(first)


if __name__=="__main__":
	testcase = input()
	for i in range(testcase):
		numbers = raw_input()
		size = len(numbers)
		total = search(numbers,0)
		cache.clear()
		print total	
#		print getMinValue(numbers)
