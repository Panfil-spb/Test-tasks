mass = []
a, b = None, None
for i in range(int(input())):
    a = int(input())
    if b is None:
        mass.append(a)
        b = a
    else:
        if a != b:
            mass.append(a)
            b = a
for i in mass:
    print(i)