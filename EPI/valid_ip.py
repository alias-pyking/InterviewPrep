def get_valid_ip_addresses(s):
    def is_valid(ip):
        ip = list(ip.split('.'))
        for i in ip:
            if len(i) > 3 or int(i) < 0 or int(i) > 255 :
                return False
            if len(i) > 1 and int(i) == 0:
                return False
            if len(i) > 1 and int(i) != 0 and i[0] == '0':
                return False
        return True
    n = len(s)
    ip = s
    res = []
    for i in range(1,n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1,n):
                ip = ip[:k] + '.' + ip[k:]
                ip = ip[:j] + '.' + ip[j:]
                ip = ip[:i] + '.' + ip[i:]
                if is_valid(ip):
                    res.append(ip)
                ip = s
    return res

if __name__ == "__main__":
    tests= ['19216811','25519011']
    for test in tests:
        print(get_valid_ip_addresses(test))

     

        