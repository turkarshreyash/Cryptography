p1 = "000100110"
p2 = "10011110"
P = "100011010"

ans = ["0" for _ in range(len(p2))]
t = ["0"]
for i in p2:
	t.append(i)
	


for i in range(len(p1)-1, -1, -1):
	print("Multiplied by X{}:".format(len(p1)-1-i), end = "\t")
	for j in t[1:]:
		print(j, end="")
	print("")
	
	t = t[1:]
	t.append("0")
	
	if t[0] == "1":
		for j in range(len(P)):
			t[j] = str(int(t[j]) ^ int(P[j]))
			
	if int(i) == 1:
		for j in range(len(p2)):
			ans[j] = str(int(ans[j]) ^ int(t[j]))
			
			

A = ""
for i in ans:
	A += i
print("P1 x P2 is {}".format(A))
