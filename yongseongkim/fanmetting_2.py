total_case = input()
case_index = 0


def match(hyper_senior, fans):
	for idx in xrange(len(hyper_senior)):
		if hyper_senior[idx] == 'M' and fans[idx] == 'M':
			return 0
	return 1


def hug(hyper_senior, fans):
	count = 0
	return count

while case_index < total_case:
	hyper_senior = list(raw_input())
	fans = list(raw_input())
	print hug(hyper_senior, fans)
	case_index += 1
