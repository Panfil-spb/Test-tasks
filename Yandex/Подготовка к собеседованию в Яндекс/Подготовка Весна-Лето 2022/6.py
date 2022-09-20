def lens(cr1, cr2):
    return abs(cr1[0] - cr2[0]) + abs(cr1[1] - cr2[1])

def bfs(s,stop, adj):
    # Тут храним стоимость прохода до вершины
    cost = []
    for i in range(adj.__len__()):
        cost.append(-1)
    # 'Стоимость' пути s -> s = 0
    cost[s] = 0
    queue = [s]
    while queue:
        v = queue.pop(0)
        # запускаем обход из вершины v
        for w in adj[v]:
            # проверка на посещенность
            if cost[w] == -1:
                # добавление вершины в очередь
                queue.append(w)
                # подсчитываем стоимость пути до вершины
                cost[w] = cost[v] + 1

    return cost

coords = []

n = int(input())
for i in range(n):
    coords.append([int(i) for i in input().split()])


len = int(input())

start, stop = map(int, input().split())

graf = []

for i, cr1 in enumerate(coords):
    graf.append([])
    for j, cr2 in enumerate(coords):
        if len >= lens(coords[i], coords[j]):
            graf[i].append(j)

start -= 1
stop -= 1

ans = bfs(start, stop, graf)

print(ans[stop])

