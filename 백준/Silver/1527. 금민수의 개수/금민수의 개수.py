made = set()
A, B = map(int, input().split())

def make(prev: int):
    if prev > B:
        return
    if A <= prev <= B:
        made.add(prev)
    make(int(str(prev) + "4"))
    make(int(str(prev) + "7"))
    
make(0)
        
print(len(made))