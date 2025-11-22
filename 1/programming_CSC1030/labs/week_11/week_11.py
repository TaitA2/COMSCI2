# array to be sorted
arr = [9, 2, 1, 5, 6, 4, 8, 7, 3]


# Q1 Merge Sort
def merge_sort(arr):
    # base case
    if len(arr) <= 1:
        return arr

    # divide
    left = arr[: len(arr) // 2]
    right = arr[len(arr) // 2 :]

    # recursively sort
    left = merge_sort(left)
    right = merge_sort(right)

    # merge
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result


print(merge_sort(arr))


# Q2 quick sort
def quick_sort(arr, left=0, right=None):
    if not right:
        right = len(arr) - 1
    # base case
    if len(arr) <= 1:
        return
    if left >= right:
        return

    # assign pivot
    pivot = arr[right]
    i = left - 1
    for j in range(left, right):
        if arr[j] < pivot:
            i += 1
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
    i += 1
    temp = arr[i]
    arr[i] = arr[right]
    arr[right] = temp

    # recursively sort two halves
    quick_sort(arr, i + 1, right)
    quick_sort(arr, left, i - 1)
    return arr


print(quick_sort(arr))


# Q3 selection sort
def selection_sort(arr):
    for i in range(len(arr)):
        min = -1
        for j in range(i, len(arr)):
            if arr[j] < arr[min]:
                min = j
        temp = arr[i]
        arr[i] = arr[min]
        arr[min] = temp
    return arr


print(selection_sort(arr))


# Q4 Insertion sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i - 1]:
            arr[i], arr[i - 1] = arr[i - 1], arr[i]
    return arr


print(insertion_sort(arr))


# Q5 Bubble sort
def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            if arr[j] < arr[i]:
                arr[i], arr[j] = arr[j], arr[i]
                break
        else:
            break
    return arr


print(bubble_sort(arr))
