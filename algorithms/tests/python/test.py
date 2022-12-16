import sys
import time
import random

def load_modules():
    sys.path.insert(0, '/home/shishya/git_hub/learning_arena/algorithms/code/python')

def get_random_list(n, r):
    v = []
    for i in range(n):
        v.append(random.randint(0, r))
    return v

def test_bubble_sort(v):
    import bubble
    start_time = time.time()
    v = bubble.sort(v)
    print(f'bubble sort execution time    == {time.time() - start_time} seconds')

def test_insertion_sort(v):
    import insertion
    start_time = time.time()
    v = insertion.sort(v)
    print(f'insertion sort execution time == {time.time() - start_time} seconds')

def test_sort():
    load_modules()
    n = int(2e4)
    r = int(1e9)

    v = get_random_list(n, r)    
    test_bubble_sort(v)
    test_insertion_sort(v)

if __name__ == '__main__':
    test_sort()
