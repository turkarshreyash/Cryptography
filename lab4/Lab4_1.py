def make_matrix(msg, key, rows, cols):
	msg_block = [['X'] * cols for i in range(rows)]
	for i in range(len(msg)):
		msg_block[i//cols][i%cols] = msg[i]
	return msg_block


def encrypt(msg, key, rows, cols, count = 1):
	msg_block = ""
	for i in range(cols):
		for j in range(rows):
			msg_block += msg[j][key[i]-1]
			
	if count == 2:
		return msg_block
	msg = make_matrix(msg_block, key, rows, cols)
	
	return encrypt(msg, key, rows, cols, count+1)


msg = "Enemy attacks tonight"
key = [3,1,4,5,2]

msg = ''.join(msg.split())
msg = msg.lower()
l = len(msg)

rows = l // len(key)
if l % len(key) != 0:
	rows += 1

msg_block = make_matrix(msg, key, rows, len(key))
	
	
encrypted = encrypt(msg_block, key, rows, len(key))
	
	
print(encrypted)
