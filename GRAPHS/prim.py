import heapq
from collections import defaultdict

def prim_mst(graph, s):
    mst = defaultdict(list)
    v = len(graph)
    
    key = [float('inf')]*v
    parent = [-1]*v
    in_mst = [False]*v
    
    key[s] = 0
    pq = [(0, s)]
    
    while pq:
        curkey, u = heapq.heappop(pq)
        if in_mst[u]: continue
        in_mst[u] = True
        if parent[u] != -1:
            mst[parent[u]].append((u, curkey))
        
        for v, w in graph.get(u, []):
            if not in_mst[v] and w < key[v]:
                key[v] = w
                parent[v] = u
                heapq.heappush(pq, (w, v))
    
    return mst
    
graph = {
    0: [(1, 1), (2, 4)],     
    1: [(0, 1), (2, 2), (3, 5)],  
    2: [(0, 4), (1, 2), (3, 1)],  
    3: [(1, 5), (2, 1)]         
}

start_vertex = 0
mst = prim_mst(graph, start_vertex)
print(mst)