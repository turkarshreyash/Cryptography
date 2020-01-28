def additive_multiplicative(n):
    additive = []
    multiplicative = []

    for i in range(n):
        for j in range(i,n):
            if (i+j)% n == 0:
                additive.append((i,j))
            if (i*j)% n == 1:
                multiplicative.append((i,j))

    print(f"Additive Inverse : {additive}")
    print(f"Multiplicative Inverse : {multiplicative}")



if __name__ == "__main__":
    temp=  int(input("Enter A Number : "))

    additive_multiplicative(temp)

