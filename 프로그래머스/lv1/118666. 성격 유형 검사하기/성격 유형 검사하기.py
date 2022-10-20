res = {'A': 0, 'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'N': 0}

def solve(s, c):
    if c == 1:
        res[s[0]] += 3
    elif c == 2:
        res[s[0]] += 2
    elif c == 3:
        res[s[0]] += 1
    elif c == 4:
        return
    elif c == 5:
        res[s[1]] += 1
    elif c == 6:
        res[s[1]] += 2
    elif c == 7:
        res[s[1]] += 3
    
def solution(surveys, choices):

    for i in range(len(surveys)):
        
         solve(surveys[i], choices[i])
    answer = ''
    print(res)
    if res['R'] >= res['T']:
        answer += 'R'
    else:
        answer += 'T'
    
    if res['C'] >= res['F']:
        answer += 'C'
    else:
        answer += 'F'
    
    if res['J'] >= res['M']:
        answer += 'J'
    else:
        answer += 'M'
    
    if res['A'] >= res['N']:
        answer += 'A'
    else:
        answer += 'N'
        
    return answer