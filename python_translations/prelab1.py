def getArrayInfo (arr):
    if not arr:
        print("Error")
        return -1

    #variable value setting + 
    size = len(arr)
    uniqueArray = [arr[0]] + [0] * (size - 1)
    unique = 1
    small = arr[0]
    big = arr[0]


    for i in range (1, size):
        #uniqueness checker
        for j in range (unique):
            #'fails' -- if the element is not unique, the loop immediately breaks
            if arr[i] == uniqueArray[j]:
                break
            
            #'success' -- if the element is never found to be non-unique and reaches the last iteration of the loop, the element is registered as unique and 'unique' is incremented
            if j == unique - 1:
                uniqueArray[unique] = arr[i]
                unique += 1

        #super simple reassignments and checks against variables
        if arr[i] < small:
            small = arr[i]
        if arr[i] > big:
            big = arr[i]
    
    return unique, small, big
