def buy_and_sell_stocks_once(A):
    maxi = A[0]
    mini = A[0]
    max_profit_so_far = 0
    for i in range(len(A)):
        if A[i] < mini:
            mini,maxi = A[i],A[i]
        elif A[i] > maxi:
            maxi = A[i]
        max_profit_so_far = max(max_profit_so_far, maxi - mini)
    return max_profit_so_far

A = [310,315,275,295,260,270,290,230,255,250]
B = [100,90,100,20,10,30,20,40,50,10,30,40,60]
print(buy_and_sell_stocks_once(A))
print(buy_and_sell_stocks_once(B))


def buy_and_sell_stocks_twice(A):
    max_total_profit, min_price_so_far = 0, float('inf')
    first_buy_sell_stocks = [0] *len(A)
    for i in range(len(A)):
        max_total_profit = max(max_total_profit, A[i] - min_price_so_far)
        min_price_so_far = min(min_price_so_far, A[i])
        first_buy_sell_stocks[i] = max_total_profit
    max_price_so_far = float('-inf')
    for i in reversed(range(1,len(A))):
        max_price_so_far = max(max_price_so_far, A[i]) 
        max_total_profit = max(max_total_profit, max_price_so_far - A[i] + first_buy_sell_stocks[i - 1])
    return max_total_profit          

C = [ 2,1]
 
print(buy_and_sell_stocks_twice(C))