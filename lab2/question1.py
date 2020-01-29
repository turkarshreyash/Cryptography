from multiplicative_inverse import inverse

def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a,a)


if __name__ == "__main__":
    inputs = input("Enter AX = B(mod N) ").split()
    a = int(inputs[0])
    b = int(inputs[1])
    n = int(inputs[2])

    c = gcd(a,n)

    if b%c != 0 :
        print("No Solution Exists!")
        exit()
    
    print(c," Solutions Exists!")

    a = a//c
    b = b//c
    n = n//c
from lab1.extended_euclidean import gcd
    a_inv = inverse(a,n)[0]

    result = (a_inv*b)%n
    for i in range(0,c):
        print(result)
        result+=n




