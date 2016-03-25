# -*- coding: utf8 -*-
total_case = input()
case_index = 0

# 분할 정복 알고리즘

def get_max_area(fences, left, right):
	max_area = 0
	if left == right:
		return fences[left]
	mid = (left + right) / 2
	# 왼쪽 영역의 최대값
	left_area = get_max_area(fences, left, mid)
	# 오른쪽 영역의 최대값
	right_area = get_max_area(fences, mid + 1, right)
	# 가운데 걸쳐 있는 영역의 최대값
	max_area = max([left_area, right_area])
	
	overlap_left = mid
	overlap_right = mid + 1
	height = min([fences[mid], fences[mid + 1]])
	max_area = max([max_area, 2 * height])
	while left < overlap_left or overlap_right < right:
		if overlap_right < right and (left == overlap_left or fences[overlap_left] < fences[overlap_right]):
			overlap_right += 1
			height = min(height, fences[overlap_right])
		else:
			overlap_left -= 1
			height = min(height, fences[overlap_left])
		max_area = max([max_area, height *(overlap_right - overlap_left + 1)])
	return max_area


while case_index < total_case:
	number_of_fences = input()
	fences = [int(x) for x in raw_input().split(' ')]
	result = get_max_area(fences, 0, len(fences) - 1)
	print result
	case_index += 1
