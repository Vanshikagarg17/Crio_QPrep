# Implement your solution by completing the below function
def trap(heights):
    ans = 0

    return ans

if __name__ == '__main__':
    n = int(input())
    heights = []
    if (n != 0):
        heights = input().split()
        heights = [int(i) for i in heights]
    result = trap(heights)
    print(result)
    
