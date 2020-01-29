from multiplicative_inverse import inverse

def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a,a)


if __name__ == "__main__":
    inputs = input("Enter AX - C = B(mod N) ").split()
    a = int(inputs[0])
    c = int(inputs[1])
    b = int(inputs[2])
    n = int(inputs[3])

    b = b - c
    if b < 0 :
        print("No Solution !")
        exit()

    c = gcd(a,n)

    if b%c != 0 :
        print("No Solution Exists!")
        exit()
    
    print(c," Solutions Exists!")

    a = a//c
    b = b//c
    n = n//c

    a_inv = inverse(a,n)[0]

    result = (a_inv*b)%n
    for i in range(0,c):
        print(result)
        result+=n




