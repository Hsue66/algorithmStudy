# -*- coding: utf8 -*-
import sys
total_case = input()
case_index = 0


def re_tree(list, str):
	while(len(str) > 0 and len(list) < 4):
		element = str.pop(0)
		if (element == 'x'):
			element = re_tree([], str)
			list.append(element)
		else:
			list.append(element)
	return list


def to_tree(str):
	return re_tree([], list(str))


def swap(list):
	if len(list) < 4:
		return
	# 처음 2개를 뒤로 붙인다.
	list.append(list.pop(0))
	list.append(list.pop(0))
	

def re_swap(tree):
	for element in tree:
		if type(element) is list:
			re_swap(element)
	swap(tree)
	

def print_result(tree):
	for i in xrange(len(tree)):
		if type(tree[i]) is list:
			sys.stdout.write('x')
			print_result(tree[i])
		else:
			sys.stdout.write(tree[i])

	
while case_index < total_case:
	str = raw_input()
	tree = to_tree(str)
	re_swap(tree)
	print_result(tree)
	print ''
	case_index += 1
  