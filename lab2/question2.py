def additiveCipher(input_string, key):
    input_string = input_string.lower()
    output_string = ""
    for i in input_string:
        if i == ' ':
            output_string += ' '
        else:
            output_string += chr(((ord(i)+key-97)%26)+97)

    return output_string


def multiplicativeCipher(input_string,key):
    input_string = input_string.lower()
    output_string = ""
    for i in input_string:
        if i == ' ':
            output_string += ' '
        else:
            output_string += chr((((ord(i)-97)*key)%26)+97)

    return output_string


def affineCipher(input_string,key1,key2):
    input_string = input_string.lower()
    output_string = ""
    for i in input_string:
        if i == ' ':
            output_string += ' '
        else:
            output_string += chr((((ord(i)-97)*key1 + key2)%26)+97)

    return output_string



if __name__ == "__main__":
    input_string = input("Enter String : ")
    print("Additive : ",additiveCipher(input_string,20),"\nMultiplicative : ",multiplicativeCipher(input_string,15),"\nAffine : ",affineCipher(input_string,15,20))