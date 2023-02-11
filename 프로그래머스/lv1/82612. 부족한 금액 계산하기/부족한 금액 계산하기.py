def solution(price, money, count):
    total = 0
    for i in range(1, count + 1):
        total += (price * (i))

    return total - money if total - money > 0 else 0