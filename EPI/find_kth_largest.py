import random,operator
def find_kth_leargest(A,k):
    def find_kth(comp):
        def partition(left, right, pivot_idx):
            # partition the array such that A[left:pivot_idx + 1] contains
            # the elements greats than pivot
            # And A[pivot_idx+1:right] contains the elements less than pivot
            pivot_value = A[pivot_idx]
            new_pivot_idx = left
            A[pivot_idx],A[right] = A[right],A[pivot_idx]
            for i in range(left, right):
                if comp(A[i],pivot_value):
                    A[i],A[new_pivot_idx] = A[new_pivot_idx],A[i]
                    new_pivot_idx += 1
            A[new_pivot_idx],A[right] = A[right],A[new_pivot_idx]
            return new_pivot_idx
        
        left, right = 0, len(A) - 1
        while left <= right:
            pivot_idx = random.randint(left,right)
            new_pivot_idx = partition(left, right, pivot_idx)
            if new_pivot_idx == k - 1:
                return A[new_pivot_idx]
            elif new_pivot_idx > k - 1:
                right = new_pivot_idx - 1
            else:
                left = new_pivot_idx + 1
    return find_kth(operator.gt)

print(find_kth_leargest([3,4,1,2,5],4))
