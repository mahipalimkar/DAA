import heapq
from typing import Dict, List, Tuple

class Djikstra:
    def __init__(self, graph: Dict[int, List[Tuple[int]]], source):
        self.graph = graph
        self.V = list(self.graph.keys())
        self.size = len(self.V)
        self.shortest_distances = [float('inf')]*self.size
        self.parents = [-1]*self.size
        self.s = source
        self.shortest_distances[source] = 0
        

    def relax(self, u, v, w):
        if self.shortest_distances[v] > self.shortest_distances[u] + w:
            self.shortest_distances[v] = self.shortest_distances[u] + w
            self.parents[v] = u
            
    def djikstra(self):
        visited = set()
        pq = [(self.shortest_distances[u], u) for u in self.V]
        
        while pq:
            dist_u, u = heapq.heappop(pq)
            if u in visited:
                continue
            visited.add(u)
            for v, w in self.graph.get(u, []):
                self.relax(u, v, w)
                if v not in visited:
                    heapq.heappush(pq, (self.shortest_distances[v], v))
        
        print("Distances: ", self.shortest_distances)
        print("Parents: ", self.parents)
        
    def get_path(self, v):
        path = []
        while v != -1:
            path.append(v)
            v = self.parents[v]
        return "->".join(map(str, path[::-1]))
            
graph = {
    0: [(1, 10), (2, 5)],
    1: [(3, 1), (2,2)],
    2: [(1, 3), (3, 9), (4, 2)],
    3: [(4, 4)],
    4: [(0, 7), (3, 6)]
}
dij = Djikstra(graph, 0)
dij.djikstra()
for i in range(5):
    print(dij.get_path(i))
        
        
""""
Time complexity: O((V + E)logV)
We will extract each node atleast once from the heap, so VlogV time complexity from there
After that, we process the neighbours and potentially push them into the heap
In the worst case this happens E times, where E is the number of edges. -> ElogV time complexity from here
Hence it is O((V+E)logV)

intialise single source -> __init__ method -> O(V) 
relax method -> O(1)

If an unsorted array was used
Each extraction would take O(V) time, but updating shortest path would be O(1)
So time complexity would be O(V^2 + E) time
"""