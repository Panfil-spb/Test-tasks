def sort(mas: list, s: int, f: int) -> None:
    if s < f:
        q = (s + f) // 2
        sort(mas, s, q)
        sort(mas, q + 1, f)
        merge(mas, s, q, f)


def merge(mas: list, s: int, q: int, f: int) -> None:
    mas1 = mas[s:q+1]
    mas2 = mas[q+1:f+1]
    print('_____________________________________')
    print(s, q, f)
    print(mas1, mas2)
    print(mas)
    k, i, j = s, 0, 0
    while i < len(mas1) and j < len(mas2):
        if mas1[i] < mas2[j]:
            mas[k] = mas1[i]
            i += 1
            k += 1
        else:
            mas[k] = mas2[j]
            j += 1
            k += 1
    while i < len(mas1):
        mas[k] = mas1[i]
        k += 1
        i += 1
    while j < len(mas2):
        mas[k] = mas2[j]
        k += 1
        j += 1
    print(mas)
    print('_____________________________________')







def main():
    mas = [132, 54, 3, 56, 1, 45, 6, 7, 876, 34, 11, 234]
    print(f'no sort: [{" ".join(str(i) for i in mas)}]')
    sort(mas, 0, len(mas)-1)
    print(f'sort: [{" ".join(str(i) for i in mas)}]')

main()
