def solution(new_id):
    answer = ''
    
    new_id = list(new_id)
    print(new_id)
    
    i = 0
    while i<len(new_id):
        a = ord(new_id[i])
        
        ##capital to small
        if 65<=a and a<=90:
            new_id[i] = chr(a + 32)
        elif (a>= 97 and a<= 122) or (a==45 or a==46 or a==95) or (a>=48 and a<=57):
            i = i+1
        else:
            print(new_id[i])
            del new_id[i]
            ##i = i-1
    print(new_id)
    
    i=0
    while i<len(new_id):
        a = ord(new_id[i])
        if a == 46 :
            i = i+1
            while i<len(new_id) and ord(new_id[i]) == 46 :
                print(i, new_id[i])
                del new_id[i]
        else:
            i = i+1
    
    if ord(new_id[0]) == 46 :
        del new_id[0]
    if len(new_id) > 0 and ord(new_id[len(new_id)-1]) == 46 :
        del new_id[len(new_id)-1]

    if len(new_id) == 0:
        new_id.insert(0,'a')
    if len(new_id) > 15:
        tmp = []
        for i in range(15):
            tmp.append(new_id[i])
        new_id = tmp
        if ord(new_id[len(new_id)-1]) == 46 : 
            del new_id[len(new_id)-1]
    if len(new_id) < 3 :
        while len(new_id) < 3 : 
            new_id.append(new_id[len(new_id)-1])
    print(new_id)
    answer = ''.join(new_id)
    return answer
