def get_id(log: list) -> int:
    return log[-2]

def get_time(logs: list) -> int:
    logs.sort(key=lambda x: int(x[0]) * 24 * 60 + \
                   int(x[1]) * 60 + \
                   int(x[2]))
    sum = 0
    cur = logs[0]
    for log in logs[1:]:
        if log[-1] in ['S', 'C']:
            sum += (int(log[0]) - int(cur[0])) * 24 * 60 + \
                   (int(log[1]) - int(cur[1])) * 60 + \
                   (int(log[2]) - int(cur[2]))
            continue
        elif log[-1] == 'A':
            cur = log
            continue
        else:
            continue
    return sum

def input_logs(n) -> dict:
    logs = dict()
    for i in range(n):
        log = input().split()
        # возможно стоит поставить проверка на вхождение
        logs[get_id(log)] = logs.get(get_id(log), [])
        logs[get_id(log)].append(log)
    return logs

def main():
    n = int(input())
    logs = input_logs(n)
    times = {id: get_time(logs[id]) for id in logs}
    keys = sorted(list(times.keys()), key=lambda x: int(x))

    print(' '.join(str(times[id]) for id in keys))

main()