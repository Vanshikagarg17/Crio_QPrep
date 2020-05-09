from crio.python.io import PrintMatrix

# Implement your solution by completing the below function
def spiralOrder(matrix):
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
    result = spiralOrder(grid)
    PrintMatrix.OneDMatrix(result, " ")
    
