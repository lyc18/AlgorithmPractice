

n = int(input())
language_scores = list(map(int, input().split()))
math_scores = list(map(int, input().split()))

n = [i for i in range(n)]
s = [language_scores[i] + math_scores[i] for i in range(len(language_scores))]
ret = list(zip(n, language_scores, math_scores, s))

ret.sort(key = lambda x:(x[3], x[2], -x[0]), reverse = True)

for i in ret:
    for j in i:
        print(j,end=' ')
    print()


#
# print(n)
# print(language_scores)
# print(math_scores)
# print(ret)