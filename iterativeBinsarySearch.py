def binSearch(elements,n,key):
    low,high=0,n
    while low<=high :
        mid = (low+high)//2
        if elements[mid] == key :
            return mid
        elif elements[mid]<key :
            low = mid+1
        else :
            high = mid-1
    return False

elements = list(map(int,input().split()))
sorted_elements = sorted(elements)
print(sorted_elements)
key =int(input("Enter an element to search :"))
result = binSearch(sorted_elements,len(sorted_elements),key)
print("Element found at ",result+1," position.") if result!=False else print("Element doesn't exists") 
