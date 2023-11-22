from collections import defaultdict
def solution(today, terms, privacies):
    term_dict = defaultdict()
    for term in terms:
        t, month = term.split()
        term_dict[t] = int(month) * 28
    today = getDays(today)
    
    answer = []
    for i, privacy in enumerate(privacies):
        date, term = privacy.split()
        days = getDays(date)
        if today >= term_dict[term] + days:
            answer.append(i + 1)

    return answer

def getDays(today):
    y, m, d = map(int, today.split("."))
    return (y - 2000) * 12 * 28 + m * 28 + d