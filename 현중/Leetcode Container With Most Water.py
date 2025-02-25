# Leetcode Container With Most Water(투포인터?)

def Mostwater(height):
    left =0
    right =len(height) -1
    max_area = 0
    
    
    while left < right:
        width = right - left
        min_height = min(height[left], height[right])
        area = width * min_height
        
        max_area = max(max_area, area)
        
        
        if height[left] < height[right]:
            left +=1
        else:
            right -=1
            
    return max_area