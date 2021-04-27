import copy
minT = 999
maxLenth = int(input(""))
num = int(input())

fixLenth = list(map(int, input("").split()))
fixTime = list(map(int, input("").split()))

lenth = 0
way = [0 for i in range(num)]
minway = []

def move(len, index, time):
    global minT
    global way
    global minway
    ##print(len,index,time)
    ## move more than maxLenth
    if len > maxLenth :
        return 0
    ## finish
    if index == num:
        if len+fixLenth[num] > maxLenth:
            return 0
        elif minT > time:
            minT = time
            ##print(time)
            ##print(way)
            minway = copy.deepcopy(way)
            return 0
    if time >= minT :
        return 0
    else :
        ##stop
        way[index] = 1
        move(0, index+1, time+fixTime[index])
        ##not stop
        way[index] = 0
        move(len+fixLenth[index], index+1, time)




cnt = 0
move(fixLenth[0],0,0)
for i in range(num):
    if minway[i] == 1 :
        cnt = cnt +1

print(minT)
print(cnt)
for i in range(num):
    if minway[i] == 1:
        print(i+1, end=" ")
