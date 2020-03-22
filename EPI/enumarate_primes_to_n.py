def generate_primes(n):
    prime = [True for i in range(n + 1)]
    prime[0] = False
    prime[1] = False
    result = []
    for p in range(2, n +1):
        if prime[p]:
            result.append(p)
            for i in range(p, n + 1, p):
                prime[i] = False
    return result
print(generate_primes(10))
print(generate_primes(100))
print(generate_primes(18))