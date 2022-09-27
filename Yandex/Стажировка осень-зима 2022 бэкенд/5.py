def ingedients(z, zels: dict, seen: list, count):
    if count > 15:
        return zels[z]
    new_ings = []
    if '0' in zels[z]:
        return ['0']
    for ing in zels[z]:
        if ing == z:
            return ['0']
        if ing in seen:
            return ['0']
        if ing != '1' and ing != '2':
            if z in zels[str(ing)]:
                zels[ing] = ['0']
                zels[z] = ['0']
                return ['0']
            else:
                seen.append(ing)
                check = ingedients(ing, zels, seen, count+1)
                seen.pop()
                if '0' not in check:
                    for i in check:
                        new_ings.append(i)
                else:
                    zels[z] = ['0']
                    return ['0']
        else:
            new_ings.append(ing)
    return new_ings


def main():

    zels = {}
    for i in range(int(input()) - 2):
        zels[str(i + 3)] = input().split()[1:]

    for z in zels:
        zels[z] = ingedients(z, zels, [z], 0)

    for z in zels:
        zels[z] = ingedients(z, zels, [z], 0)

    questions = [input().split() for _ in range(int(input()))]
    for quest in questions:
        if '0' in zels[quest[2]]:
            print('0', end='')
        elif zels[quest[2]].count('1') <= int(quest[0]) and zels[quest[2]].count('2') <= int(quest[1]):
            print('1', end='')
        else:
            print('0', end='')

main()