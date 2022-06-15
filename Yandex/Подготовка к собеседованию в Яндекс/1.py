j = input()
s = input()

count = 0
for el in s:
    if el in j:
        count += 1

print(count)