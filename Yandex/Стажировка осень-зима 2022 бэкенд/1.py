def first_let(name: str) -> int:
    return ord(name[0].lower()) - ord('a') + 1


def count_let(fio: list) -> int:
    ans = {k for word in fio for k in word}
    return len(ans)


def sum_numbers(nums: list) -> int:
    sum = 0
    for num in nums:
        for j in num:
            sum += int(j)
    return sum


def shifr(s: str) -> str:
    s = s.split(',')
    count_let_stajrs = count_let(s[0:3])
    sum_nums = sum_numbers(s[3:5])
    num_first_let = first_let(s[0])

    num = count_let_stajrs + sum_nums * 64 + num_first_let * 256
    num = hex(num)[2:]
    num = num if len(num) <= 3 else num[-3:]
    return num.upper()


def main():
    n = int(input())

    stajrs = [input() for _ in range(n)]

    ans = [shifr(s) for s in stajrs]

    print(' '.join(i for i in ans))

main()
