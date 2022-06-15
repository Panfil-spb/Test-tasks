max = 0
poss = 0
for i in range(int(input())):
    el = int(input())
    if el == 0:
        max = poss if poss > max else max
        poss = 0
    else:
        poss += 1
max = poss if poss > max else max
print(max)
