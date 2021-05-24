fact_velue = [1, 1, 2]


def factorial(n):
    ans = 1
    for i in range(1, n+1):
        ans *= i
    if ans.bit_length() > 32:
        return "bit size error"
    return ans

    # Число размещений U(m,n)


def U(n, k):
    ans = pow(n, k)
    if ans.bit_length() > 32:
        return "bit size error"
    return pow(n, k)


# //Число размещений без повторений A(m,n)

def A(m, n):
    ans = 1
    for k in range(m - n + 1, m + 1):
        ans *= k
    if ans.bit_length() > 32:
        return "bit size error"
    return ans


# Число перестановок P(n)
def P(n):
    if factorial(n) != "bit size error":
        return factorial(n)
    return "bit size error"


# Число сочетаний C(m,n)
# def C(n, k):
#     if A(n, k) != "bit size error" and factorial(k) != "bit size error":
#         return A(n, k) / factorial(k)
#     return "bit size error"


def C(m, n):
    if n == 1 or m == n + 1:
        return m
    if n > m:
        return 0
    if n==m or n == 0:
        return 1
    if n > m - n:
        n = m - n
    a = m - n + 1
    k = a + 1
    for i in range(2, n + 1):
        a =int( a / i * k + a % i * k / i)
        k += 1
    if a.bit_length() > 32:
        return "bit size error"
    return a


# Число Стирлинга второго рода S(m,n)
def S(m, n):
    if m == n:
        return 1
    if n == 0:
        return 0
    if m < n:
        return 0
    if n == 1:
        return 1
    d = min(n, m - n + 1)
    s = max(n, m - n + 1)
    D = []
    for i in range(d+1):
        D.append(1)
    for i in range(2, s+1):
        for j in range(2, d+1):
            if d == n:
                D[j] = D[j - 1] + j * D[j]
            else:
                D[j] = D[j] + i * D[j - 1]
            if D[j].bit_length() > 32:
                return "bit size error"
    if D[d ].bit_length() <= 32:
        return D[d ]
    else:
        return "bit size error"


# Число Белла B(n)
def B(n):
    ans = 0

    for i in range(n+1):
        tmp = S(n, i)
        if tmp == "bit size error":
            return tmp
        ans += S(n, i)
    if ans.bit_length() <= 32:
        return ans
    else:
        return "bit size error"


def H():
    print("press H to call Help")
    print("press U Число размещений")
    print("press A Число размещений без повторений")
    print("press P Число перестановок")
    print("press C Число сочетаний")
    print("press S Число Стирлинга второго рода ")
    print("press B Число Белла ")
    print("press 33 to finish work")


if __name__ == '__main__':
    H()
    while True:
        print("введите команду")
        c = input()
        if c == "H":
            H()
        if c == "U":
            print("введите кофиценты <m> и <n>")
            m, n = map(int, input().split())
            if m.bit_length() > 32 or n.bit_length() > 32:
                print("bit size error")
                continue
            if m < 0 or n < 0:
                print("value error")
                continue
            print("U(", m, ",", n, ") = ", U(m, n))

        if c == "A":
            print("введите кофиценты <m> и <n>")
            m, n = map(int, input().split())
            if m.bit_length() > 32 or n.bit_length() > 32:
                print("bit size error")
                continue
            if m < 0 or n < 0:
                print("value error")
                continue
            print("A(", m, ",", n, ") = ", A(m, n))

        if c == "P":
            print("введите кофицент<n>")
            n = int(input())
            if n.bit_length() > 32:
                print("bit size error")
                continue
            if n < 0:
                print("value error")
                continue
            print("P(", n, ") = ", P(n))
        if c == "C":
            print("введите кофиценты <m> и <n>")
            m, n = map(int, input().split())
            if m.bit_length() > 32 or n.bit_length() > 32:
                print("bit size error")
                continue
            if m < 0 or n < 0:
                print("value error")
                continue
            print("C(", m, ",", n, ") = ", C(m, n))
        if c == "S":
            print("введите кофиценты <m> и <n>")
            m, n = map(int, input().split())
            if m.bit_length() > 32 or n.bit_length() > 32:
                print("bit size error")
                continue
            if m < 0 or n < 0:
                print("value error")
                continue
            print("S(", m, ",", n, ") = ", S(m, n))
        if c == "B":
            print("введите кофицент<n>")
            n = int(input())
            if n.bit_length() > 32:
                print("bit size error")
                continue
            if n < 0:
                print("value error")
                continue
            print("B(", n, ") = ", B(n))
        if c == "33":
            break
    # print(k.bit_length())
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
