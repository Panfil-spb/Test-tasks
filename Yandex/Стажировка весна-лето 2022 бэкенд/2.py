n, m = map(int, input().split())
mat = [[j for j in input()] for i in range(n)]

new_mat = []

for i in range(n):
    new_mat.append([])
    for j in range(m - 1, -1, -1):
        if mat[i][j] == '/':
            new_mat[i].append('\\')
        elif mat[i][j] == '\\':
            new_mat[i].append('/')
        else:
            new_mat[i].append(mat[i][j])


mat = [['.' for j in range(m)] for i in range(n)]
for i in range(n - 1, -1, -1):
    for j in range(m):
        if new_mat[i][j] == '/':
            mat[n-i][j] = '\\'
        elif new_mat[i][j] == '\\':
            mat[n-i][j] = '/'
        elif new_mat[i][j] != '.':
            mat[n-i-1][j] = new_mat[i][j]


for i in mat:
    for j in i:
        print(j, end='')
    print()

