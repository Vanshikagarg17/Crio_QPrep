from crio.python.io import PrintMatrix

# Implement your solution by completing the below function
def traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove):
    res = []

    return res

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    grid = []
    for i in range(n):
        nums = input().split()
        nums = [int(i) for i in nums]
        grid.append(nums)

    position = input().split()
    currPosX = int(position[0])
    currPosY = int(position[1])
    move = input().split()
    dirToMove = int(move[0])
    stepsToMove = int(move[1])
        
    result = traversalPath(grid, currPosX, currPosY, dirToMove, stepsToMove)
    PrintMatrix.OneDMatrix(result, " ")
    
