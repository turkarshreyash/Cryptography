def additiveCipher(input_string, key):
    input_string = input_string.lower()
    output_string = ""
    for i in input_string:
        if i == ' ':
            output_string += ' '
        else:
            output_string += chr(((ord(i)+key-97)%26)+97)

    return output_string

if __name__ == "__main__":
    input_string = "ziolegxkltqodlzgofzkgrxetngxzgzithkofeohstlqfrzteifojxtlgyltexkofuegdhxztklqfregdhxztkftzvgkalvoziygexlgfofztkftzltexkoznzitegxkltoltyytezoctsnlhsozofzgzvghqkzlyoklzofzkgrxeofuzitzitgkngyeknhzgukqhinofesxrofuigvdqfnesqlloeqsqfrhghxsqkqsugkozidlvgkaturtlklqrouozqsloufqzxktlqfrltegfrhkgcorofurtzqoslgyktqsofztkftzltexkoznhkgzgegslqsugkozidlqfrziktqzltuohltecokxltlyoktvqsslitfetngxvossstqkfwgzizitgktzoeqsqlhtezlgyegdhxztkqfrftzvgkaltexkoznqlvtssqligvziqzzitgknolqhhsotrofzitofztkftzziolafgvstrutvossitshngxofrtloufofuqfrrtctsghofultexktqhhsoeqzogflqfrftzvgkahkgzgegslqlvtssqlwxosrofultexktftzvgkal"
    pairs = dict()
    length = len(input_string)
    for i in range(0,length-1):
        pair = input_string[i:i+2]
        if pair in pairs:
            pairs[pair]+=1
        else:
            pairs[pair] = 1
    
    print(pairs)
        

    # diff = (ord('e') - ord(alphabet))%26
    # print(diff)

    # print(additiveCipher(input_string,diff))
    