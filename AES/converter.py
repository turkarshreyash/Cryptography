rows = []
for i in range(0,16):
    temp = input()
    temp = temp.split()
    temp = ["0x"+i for i in temp]
    temp = ",".join(temp)
    rows.append(temp)


print("{")

for i in rows:
    print("\t{",i,"},")
print("}")