def gcd(a, b):  # 유클리드호제법
    while True:
        if b == 0:
            return a
        else:
            return gcd(b, a % b)


A, B = map(int, input().split())

print(gcd(A, B))  # 최대 공약수
print(int((A * B) / gcd(A, B)))  # 최소 공배수
