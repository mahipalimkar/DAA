from collections import defaultdict

class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n
    
    def find(self, u):
        if u == self.parent[u]:
            return u
        p = self.find(self.parent[u])
        self.parent[u] = p
        return p
    
    def union(self, u, v):
        rootu = self.find(u)
        rootv = self.find(v)
        if rootu != rootv:
            if self.rank[rootu] < self.rank[rootv]:
                self.parent[rootu] = rootv
            elif self.rank[rootv] < self.rank[rootu]:
                self.parent[rootv] = rootu
            else:
                self.parent[rootu] = rootv
                self.rank[rootv] += 1
                # Jo parent bana uska rank badega
                # Higher up parent has higher rank
                
    
def kruskal(n, edges):
    mst = defaultdict(list)
    ds = DisjointSet(n)
    edges.sort(key = lambda x: x[2])
    for u, v, w in edges:
        if ds.find(u) != ds.find(v):
            ds.union(u, v)
            mst[u].append((v, w))

    return mst

# Example usage:
# n = number of vertices
# edges = list of edges in the form (u, v, weight)
n = 4
edges = [(0, 1, 10), (0, 2, 6), (0, 3, 5), (1, 3, 15), (2, 3, 4)]
mst = kruskal(n, edges)
print(mst)