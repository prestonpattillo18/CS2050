#this function takes an array, array size, and search query to
#return the number of values in the array which are greater than or equal to the query 
def greaterOrEqual (arr, size, query):
    if (not arr or size <= 0):
        return -1
    
    counter = 0

    for i in range (size):
        if (arr[i] >= query):
            counter = counter + 1

    return counter 
