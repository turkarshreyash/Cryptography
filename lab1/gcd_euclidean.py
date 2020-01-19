def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a,a)

if __name__ == "__main__":
    temp=  input("Enter Two Numbers : ").split()
    num1 = int(temp[0])
    num2 = int(temp[1])
    print(gcd(num1,num2))