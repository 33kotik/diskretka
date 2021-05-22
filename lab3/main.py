def show(card):
    for string in card:
        print(" ".join(string))


def count_ways(card, x, y):
    ans = 0
    if card[x][y + 1] == 0:
        ans += 1
    if card[x][y - 1] == 0:
        ans += 1
    if card[x + 1][y] == 0:
        ans += 1
    if card[x - 1][y] == 0:
        ans += 1
    return ans


def maze2graph(maze):
    height = len(maze)
    width = len(maze[0]) if height else 0
    graph = {(i, j): [] for j in range(width) for i in range(height) if maze[i][j]}
    for row, col in graph.keys():
        if row < height - 1 and maze[row + 1][col]:
            graph[(row, col)].append(("S", (row + 1, col)))
            graph[(row + 1, col)].append(("N", (row, col)))
        if col < width - 1 and maze[row][col + 1]:
            graph[(row, col)].append(("E", (row, col + 1)))
            graph[(row, col + 1)].append(("W", (row, col)))
    return graph


way = []


def rec_step(x, y):
    # if count_ways(maze, x, y) == 0:
    #     return 0
    if x - 1 < 0 or y - 1 < 0 or x + 1 >= len(maze) or y + 1 >= len(maze[0]):
        maze[x][y] = "_"
        print("человечек выбрался")
        return True
    maze[x][y] = "O"
    if maze[x][y + 1] == '0':
        if rec_step(x, y + 1):
            maze[x][y] = "_"
            return True
    if maze[x][y - 1] == '0':
        if rec_step(x, y - 1):
            maze[x][y] = "_"
            return True
    if maze[x + 1][y] == '0':
        if rec_step(x + 1, y):
            maze[x][y] = "_"
            return True
    if maze[x - 1][y] == '0':
        if rec_step(x - 1, y):
            maze[x][y] = "_"
            return True
    return False

maze = []
if __name__ == '__main__':

    print("Введите высоту лаберинта ")
    # h = map(int, input().split())
    h = int(input())
    maze = []
    print("Введите лаберинт 1= стена, 0=проход")
    for i in range(h):
        # tmp = map(int, input().split())
        tmp = input().split()
        maze.append(tmp)
    # print(card)
    print("вот ваш лаберинт ")
    show(maze)
    print("куда вы поставите человека x, y? (x=вправо, y=вниз ,нуль номерация)")
    x, y = map(int, input().split())
    maze[y][x] = "*"
    print("вот ваш лаберинт c человеком ")
    show(maze)
    rec_step(y, x)
    show(maze)
    # print(maze2graph(card))
