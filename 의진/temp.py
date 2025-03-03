import bisect

lst = [10, 20, 25, 30]

left = bisect.bisect_left(lst, 25)
right = bisect.bisect_right(lst, 25)

print("bisect_left(25):", left)
print("bisect_right(25):", right)
