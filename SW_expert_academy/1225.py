##f = open("input.txt", "r")
for i in range(10):
    test = input()
    arr = list(map(int, input().split()))
    i=0
    num = 1
    index = 0
    while True:
        if i == 8 :
            i = 0
        if num == 6:
            num = 1
        arr[i] -= num
        if arr[i] <= 0:
            index = i+1
            arr[i] = 0
            break
        num = num+1
        i = i+1

    print("#" + test, end = " " )
    for i in range(8):
        print( arr[(index)%8], end = " ")
        index = index +1
    print()
