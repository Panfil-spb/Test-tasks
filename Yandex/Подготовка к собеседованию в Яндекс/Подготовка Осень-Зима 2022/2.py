with open('input.txt', 'r') as f:
    nums = f.readline().split()

with open('output.txt', 'w') as f:
    f.write(str(int(nums[0]) + int(nums[1])))