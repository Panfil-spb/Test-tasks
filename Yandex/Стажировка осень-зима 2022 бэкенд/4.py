def request1(orders: list, request: list) -> int:
    sum = 0
    start = int(request[0])
    end = int(request[1])
    for order in orders:
        if start <= int(order[0]):
            if int(order[0]) <= end:
                sum += int(order[-1])
            else:
                break
    return sum


def request2(orders: list, request: list) -> int:
    sum = 0
    start = int(request[0])
    end = int(request[1])
    for order in orders:
        if start <= int(order[1]):
            if int(order[1]) <= end:
                sum += int(order[1]) - int(order[0])
            else:
                break
    return sum

def main():
    count_order = int(input())
    orders = [input().split() for _ in range(count_order)]
    orders1 = sorted(orders, key=lambda x: int(x[0]))
    orders2 = sorted(orders, key=lambda x: int(x[1]))
    count_request = int(input())

    for _ in range(count_request):
        request = input().split()
        print(request1(orders1, request) if request[-1] == '1' else request2(orders2, request), end=' ')



main()