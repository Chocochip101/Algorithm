import math
from collections import defaultdict

def returnTime(t1, t2):
    h1, m1 = t1.split(":")
    h2, m2 = t2.split(":")
    return 60 * (abs(int(h1) - int(h2))) - int(m1) + int(m2)

def calFee(base_time,base_fee, per_time, per_fee, ti):
    if ti <= base_time:
        return base_fee

    return base_fee + per_fee * math.ceil((ti - base_time) / per_time)

def solution(fees, records):
    base_time = fees[0]
    base_fee = fees[1]
    per_time = fees[2]
    per_fee = fees[3]

    time_dict = defaultdict(int)
    is_in = defaultdict(str)
    answer = []

    for record in records:
        ti, car_num, ord = record.split()
        if ord == 'IN':
            is_in[car_num] = ti
        else:
            time_dict[car_num] += returnTime(is_in[car_num], ti)
            is_in[car_num] = '-1'

    for car_num in sorted(is_in.keys()):
        if is_in[car_num] != '-1':
            time_dict[car_num] += returnTime(is_in[car_num], "23:59")
            answer.append(calFee(base_time, base_fee, per_time, per_fee, time_dict[car_num]))
        else:
            answer.append(calFee(base_time, base_fee, per_time, per_fee, time_dict[car_num]))

    return answer

print(solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))
