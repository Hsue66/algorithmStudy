total_case = input()
case_index = 0


def get_max_area(fences):
	max = 0
	return max


while case_index < total_case:
	number_of_fences = input()
	fences = [int(x) for x in raw_input().split(' ')]
	result = get_max_area(fences)
	print result
	case_index += 1
