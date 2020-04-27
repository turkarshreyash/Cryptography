def make_matrix(msg, key, rows, cols):
	msg_block = [['X'] * cols for i in range(rows)]
	for i in range(len(msg)):
		msg_block[i//cols][i%cols] = msg[i]
	return msg_block
	
	
def encrypt(msg, key, rows, cols, indices):
	msg_block = ""
	for i in range(cols):
		for j in range(rows):
			msg_block += msg[j][indices[i+1]-1]
			
	return msg_block
	
	


msg = "A Midsummer Night's Dream"
text = ""
for i in msg:
	if ord(i) in range(65,92) or ord(i) in range(97, 123):
		text += i.lower()
l = len(text)


key_msg = "SWINDOW"
key = [ord(i) for i in key_msg]
cols = len(key)
temp = sorted(key)
indices = {}
for i in range(cols):
	indices[i+1] = key.index(temp[i])+1
	key[key.index(temp[i])] = i+1

	
rows = l // cols
if l % cols != 0:
	rows += 1

msg_block = make_matrix(text, key, rows, cols)

encrypted = encrypt(msg_block, key, rows, cols, indices)
print (encrypted)
