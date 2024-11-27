import numpy as np

INF = 2**31 - 1
def floyd_warshall(graph):
    n = len(graph)
    dist = np.array([[INF]*n for _ in range(n)])

    for i in range(n):
        for j in range(n):
            dist[i, j] = graph[i, j]
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i, j] = min(dist[i, j], dist[i, k] + dist[k, j])
    
    return dist.astype(int)
    

graph = np.array([
    [0, 3, INF, 7],
    [8, 0, 2, INF],
    [5, INF, 0, 1],
    [2, INF, INF, 0]
])

shortest_paths = floyd_warshall(graph)
for row in shortest_paths:
    print(row)