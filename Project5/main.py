import sys

end = 0
maxCost = 0

def DFS(G, v, c, d):
    if c > maxCost:
        return float('inf')
    if v == end:
        return d

    validDurations = []
    for e in G[v]:
        validDurations.append(DFS(G, e[0], c+e[1], d+e[2]))

    if len(validDurations) == 0:
        return float('inf')

    return min(validDurations)

with open(sys.argv[1]) as f:
    V, E = map(int, f.readline().split())
    edges = [[] for _ in range(V)]
    for i in range(E):
        l = tuple(map(int, f.readline().split()))
        edges[l[0]].append(l[1:])

    start = int(sys.argv[2])
    end = int(sys.argv[3])
    maxCost = int(sys.argv[4])

    result = DFS(edges, start, 0, 0)
    if result == float('inf'):
        print('0')
    else:
        print(result)