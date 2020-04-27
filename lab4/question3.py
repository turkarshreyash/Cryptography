alphabets_list = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
def transposition(string,key):
    string = string.lower()
    key_len = len(key)
    
    string = string_changer(string,key_len)
    
    new_str = position_changer(string , key)
    
    char_mat = [[0 for i in range(len(key))] for i in range(len(new_str)//len(key))]   
    
    
    for i in range(len(new_str)):
        char_mat[i//len(key)][i%len(key)] = new_str[i] 
     
    trans_mat = [[char_mat[j][i] for j in range(len(new_str)//len(key))] for i in range(len(key))] 
    
    enc_str = ''
    for i in range(len(key)):
        for j in range(len(new_str)//len(key)):
            enc_str += trans_mat[i][j]
    
    return enc_str
def index_sorter(key_string):
    l = []
    key_string = key_string.lower()
    for i in key_string:
        l.append(alphabets_list.index(i))
        
    #use min and list to sort the list 
    
    new_l = [0 for i in range(len(key_string))]
    
    max =26
    
    lk = l.copy()
    
    count = 1
    for i in range(len(key_string)):
        mini = min(lk)
        min_index = lk.index(mini)
        new_l[min_index] = count
        count += 1
        lk[min_index] = max
        
    return new_l

key2 = index_sorter('swindon')

transposition("A Midsummer Night's Dream",key2)


