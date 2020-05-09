# Implement your solution by completing the below function
def canMessageBePassed(n, maze):
    res = True

    return res

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    s = int(row[1])
    m = int(row[2])
    
    maze = [[0 for col in range(n)] for row in range(n)]
    maze[0][0] = s

    for i in range(m):
        perPersonInput = input().split()
        x = int(perPersonInput[0])
        y = int(perPersonInput[1])
        p = int(perPersonInput[2])
        maze[x][y] = max(maze[x][y],p)
        
    result = canMessageBePassed(n, maze)
    if (result == True):
        print ("Yes")
    else:
        print ("No")
