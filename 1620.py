a, fir, sec = input().split()
s = list(a)
arr = []
num = []
count = 0
err = False
#preprosesor
i=-1
for k in range(len(s)):
    i = i+1
    if count > 4:
        err = True
        break
    if s[i] == '-' or i == len(s)-1:
       # j = i-1
       # if(i == len(s)-1) :
       #     j = i
       #     count = count+1
       # index = 1
       # sum = 0
       # while count >0:
       #     sum = sum + int(s[j])*index
       #     index = index*10
       #     count = count -1
       #     j = j-1
       # num.append(sum)
        if i == len(s)-1:
            if s[i] == '-':
                s.append("0")
                s.append("0")
                s.append("0")
                s.append("0")

            else:
               count = count + 1
               i = i+1

        if count <4 :
            # print("padding" + str(i))
            index = i
            while count < 4:
                s.insert(i -count, "0")
                # print(s)
                # print(index, end=" ")
                count = count+1
                # print(count,end=" ")
                i = i+1
                # print(i)
                # index = index -1
            #i = i+1
            # print(i)
        count = 0
    else :
        count = count +1

fir = int(fir)
sec = int(sec)-1


def range_err(index):
    if index <0 or index*5 > len(s):
        return True
    else:
        return False


if range_err(sec) or err:
     print("INPUT ERROR!")
else:
    result = []
    sec = sec * 5
    for i in range(4):
        sum = fir + int(s[sec+i])
        if(sum > 9 ):
            sum = sum %10
        result.append(sum)
    for i in range(4):
        print(result[i],end="")
