def Decryptadditive(input_string, key):
    input_string = input_string.lower()
    output_string = ""
    for i in input_string:
        if i == ' ':
            output_string += ' '
        else:
            output_string += chr(((ord(i)-key-97)%26)+97)

    return output_string

def Decryptmultiplicative(input_string,key):
    input_string = input_string.lower()
    output_string = ""
    for i in input_string:
        if i == ' ':
            output_string += ' '
        else:
            output_string += chr((((ord(i)-97)*key)%26)+97)

    return output_string

def Decryptaffine(input_string,key1,key2):
    input_string = input_string.lower()
    output_string = ""
    for i in input_string:
        if i == ' ':
            output_string += ' '
        else:
            output_string += chr((((ord(i)-97-key2)*key1)%26)+97)

    return output_string





if __name__ == "__main__":
    input_string = "YMJHFJXFWHNUMJWNXTSJTKYMJJFWQNJXYPSTBSFSIXNRUQJXYHNUMJWX"
    print("Additive Brute Force : ")
    for i in range(0,26):
        print(Decryptadditive(input_string,i))
    
    # print("Multiplicative Brute Force : ")
    # for i in range(0,26):
    #     print(Decryptmultiplicative(input_string,i))


    # print("Affine Brute Force : ")
    # for i in range(0,26):
    #     for j in range(0,26):
    #         print(Decryptaffine(input_string,i,j))
