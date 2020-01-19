def extended_gcd(a, b):
    s = 0
    old_s = 1
    t = 1
    old_t = 0
    r = b
    old_r = a
    
    while not r == 0:
        quotient = old_r//r
        old_r, r = r, old_r - quotient * r
        old_s, s = s, old_s - quotient * s
        old_t, t = t, old_t - quotient * t
    
    print(f"Bézout coefficients: {old_s}, {old_t}")
    print(f"greatest common divisor: {old_r}")
    print(f"quotients by the gcd: {t} {s}")
    
    return


if __name__ == "__main__":
    temp=  input("Enter Two Numbers : ").split()
    num1 = int(temp[0])
    num2 = int(temp[1])
    extended_gcd(num1,num2)