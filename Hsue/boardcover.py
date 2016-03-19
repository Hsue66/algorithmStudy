#global var
height =0
width =0
pattern = [[0,1,1,0],[1,0,1,-1],[1,0,1,1],[0,1,1,1]]
total=0

def setBlock(MAP,px,py,px1,py1,px2,py2):
#	print "in the function"

	# copy 
	subMAP = [[0 for col in range(width)]for row in range(height)]
	for row in range(height):
		for col in range(width):
			subMAP[row][col]=MAP[row][col];

	# mark
	if px==-1 and py ==-1 and px1 == -1 and py1==-1 and px2==-1 and py2==-1:
		pass
	else:
		subMAP[px][py]=1
		subMAP[px1][py1]=1
		subMAP[px2][py2]=1

	
#	print "-----------------------"
#	print "after mark"
#	for row in subMAP:
#		print row

	# full
	TorF =0;
	for row in range(height):
		if TorF ==0:
			for col in range(width):
				if subMAP[row][col]==0:
					TorF=1
					break

	startx=-1
	starty=-1
	
	# finish or not
	if TorF==0:
		global total
		total = total +1
#		print "total %d" %total
	else:
		for row in range(height):
			if startx==-1 or starty==-1:
				for col in range(width):
					if subMAP[row][col]==0:
						startx = row
						starty = col
						break

#		print "start : %d %d" %(startx,starty)
		# set
		for idx in range(4):
			x1 = startx+pattern[idx][0]
			y1 = starty+pattern[idx][1]
			x2 = startx+pattern[idx][2]
			y2 = starty+pattern[idx][3]
#			print "-----%d ------------" %idx
#			print "(%d %d)  (%d %d)" %(startx+pattern[idx][0],starty+pattern[idx][1],startx+pattern[idx][2],starty+pattern[idx][3])
			
			if (0<=x1 and x1<height) and (0<=y1 and y1<width) and (0<=x2 and x2<height) and (0<=y2 and y2<width):
				if subMAP[x1][y1] == 0 and subMAP[x2][y2] == 0:
#					print "empty"
					setBlock(subMAP,startx,starty,x1,y1,x2,y2)
#				else:
#					for row in subMAP:
#						print row




if __name__ == "__main__":
	testcase = input()

	for t in range(testcase):
		value = raw_input()
		h1,w1 = value.split(" ")
		height = int(h1)
		width = int(w1)
		total = 0
		# make empty map
		MAP = [[0 for col in range(width)]for row in range(height)]

		# mark the place
		space = 0
		for row in range(height):
			temp = raw_input()
			for col in range(width):
				if temp[col] == '#':
					MAP[row][col]=-1
				else:
					space = space+1
					MAP[row][col]=0

		# place possible or not
		if space%3!= 0:
			print "0"
		else:
			setBlock(MAP,-1,-1,-1,-1,-1,-1)
			print "%d" %total

