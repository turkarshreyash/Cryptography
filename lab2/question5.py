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
    input_string = "XPALASXYFGFUKPXUSOGEUTKCDGFXANMGNVS"
    test_string = "gl"

    
    print("Affine Brute Force : ")
    for i in range(0,26):
        for j in range(0,26):
            if Decryptaffine(test_string,i,j) == "ab":
                print(i,j)
                print(Decryptaffine(input_string,i,j))
                break