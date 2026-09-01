#this function takes an array, array size, and search query to
#return the number of times which the query appears within the array
def countOccurrences(arr, size, query):
    if not arr or size <= 0:
        return -1
    
    counter = 0

    for i in range (size):
        if arr[i] == query:
            counter = counter + 1
    
    return counter
