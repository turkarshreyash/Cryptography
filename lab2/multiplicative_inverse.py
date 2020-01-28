def inverse(a, n):
    t = 0
    newt = 1
    r = n
    newr = a

    while not newr == 0:
        quotient = r//newr
        t, newt = newt, t - quotient * newt
        r, newr = newr, r - quotient * newr

    if r > 1 :
        return "a is not invertible"
    
    return t,t+n

if __name__ == "__main__":
    temp=  input("Enter a and n Numbers : ").split()
    num1 = int(temp[0])
    num2 = int(temp[1])
    print(inverse(num1,num2))