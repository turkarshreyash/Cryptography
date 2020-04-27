seed = '0001'
b = [int(i) for i in seed]
b.reverse()
b.append(b[0] ^ b[1])
k = 0

print ("States\tb4\tb3\tb2\tb1\tb0\tk")
print("Initial {}\t{}\t{}\t{}\t{}".format(b[4], b[3], b[2], b[1], b[0]))

for i in range(20):
	k = b[0]
	b2 = b[1:]
	b2.append(b2[0] ^ b2[1])
	b = b2
	
	print("{}\t{}\t{}\t{}\t{}\t{}\t{}".format(i+1, b[4], b[3], b[2], b[1], b[0], k))
