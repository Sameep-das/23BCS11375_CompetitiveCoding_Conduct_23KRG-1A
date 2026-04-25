def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0                
    
    gcd, x1, y1 = extended_gcd(b, a % b)
    
    x = y1
    y = x1 - (a // b) * y1
    
    return gcd, x, y

a, b = 4, 2
gcd, x, y = extended_gcd(a, b)
print(f"GCD: {gcd}, x: {x}, y: {y}")
