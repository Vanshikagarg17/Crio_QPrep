from crio.python.io import PrintMatrix

# Implement your solution by completing the below function
def merge(nums):
    res = []

    return res

if __name__ == '__main__':
    n = int(input())
    nums = []
    for i in range(n):
        row = input().split()
        row = [int(i) for i in row]
        nums.append(row)
    result = merge(nums)
    PrintMatrix.TwoDMatrix(result)
    
