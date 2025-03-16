N = int(input())
LIST = [[] for _ in range(N)] #(b,p,q)
visited = [False] * (N)
value_list = [0] * N    #[a->b 비율, b->a 비율]
MINgcd = 1

#1. 최대공약수 재귀로 구현
def MAX_gcd(a,b):
    if b ==0:
        return a
    else:
        return MAX_gcd(b, a%b)
        
#2. DFS구현, LIST 구현
def DFS(v):
    visited[v] = True
    for i in LIST[v]:
        next = i[0]   #[next, p, q]
        if not visited[next]:
            value_list[next] = value_list[v] * i[2] // i[1]
            DFS[next]
        
#3. 도선 비율과 최소공배수 구현
for i in range(N-1):
    a,b,p,q = map(int, input().split())
    LIST[a].append((b,p,q))
    LIST[b].append((a,q,p))
    MINgcd *= (p*q // MAX_gcd(p,q))
    
#4. 답구현 : 칵테일을 만드는데 필요한 각 재료의 질량
value_list[0] = MINgcd
DFS(0)

max_gcd = value_list[0]
for i in range(1,N):
    max_gcd = MAX_gcd(max_gcd, value_list[i]) #(105, 35) : 35 -> (35, 21) : 7 -> (7, 15) :  1!!
    
for i in range(N):
    print(int(value_list[i]//max_gcd), end ='')