from collections import Counter
def solution(phone_book):
    _li = [set() for _ in range(21)]
    phone_book.sort(key = lambda x: len(x))
    min_len = len(phone_book[0])
    _li[len(phone_book[0])].add(phone_book[0])
    
    for i in range(1, len(phone_book)):
        for j in range(len(phone_book[i]) - min_len):
            if phone_book[i][:min_len + j] in _li[min_len + j]:
                return False
        _li[len(phone_book[i])].add(phone_book[i])
    return True