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
    input_string = "ymnxhtzwxjfnrxytuwtanijdtzbnymijyfnqjipstbqjiljtknrutwyfsyyjhmstqtlnjxfsifuuqnhfyntsymfyfwjzxjinsymjnsyjwsjyizjytymjgwtfisfyzwjtkymnxknjqiymjhtzwxjhtajwxtsqdxjqjhyjiytunhxkthzxxnslknwxytsxtrjfiafshjiytunhxnsnsyjwsjyyjhmstqtlnjxjlbnwjqjxxqfsxrtgnqjnsyjwsjyrzqynhfxyfsiymjsfxjqjhyntstkhzwwjsyfsisjcyljsjwfyntsfuuqnhfyntsxfsixjwanhjxjluunuyaatnudtzbnqqqjfwsmtbymjnsyjwsjybtwpxfsimtbxjwanhjxfsifuuqnhfyntsxfwjuwtanijiytzxjwxtkymjnsyjwsjyymnxpstbqjiljbnqqmjqudtz"
    alphabet = ""
    max_count = 0
    for i in "abcdefghijklmnopqrstuvwxyz":
        count = input_string.count(i)
        if count > max_count:
            max_count = count
            alphabet = i
    print(alphabet,max_count)

    diff = (ord('e') - ord(alphabet))%26
    print(diff)

    print(additiveCipher(input_string,diff))
    