def remove(vertex_list, vertex, deleted) :
    j = 0
    for i in vertex_list[vertex] :
        if i == deleted :
            vertex_list[vertex].pop(j)
            return
        j += 1

def merge(vertex_list, vertex1, vertex2) :
    while vertex_list[vertex2] :
        i = vertex_list[vertex2].pop()
        remove(vertex_list, i, vertex2)
        if i not in vertex_list[vertex1] and i != vertex1 :
            vertex_list[vertex1].append(i)
    return len(vertex_list[vertex1])

def bfs(vertex_list, origin, target, size) :
    edge = []
    edge.append([origin, 0])
    visited = list(range(size))
    while edge :
        actual = edge.pop()
        if actual[0] == target :
            return actual[1]
        if visited[actual[0]] :
            visited[actual[0]] = 0;
            for i in vertex_list[actual[0]] :
                edge.append([i, actual[1]+1])
    return -1

vertex, edges = map(int, input().split())
vertex_list = []
for a in range(vertex) :
    vertex_list.append([])

for i in range(edges) :
    origin, target = map(int, input().split())
    if origin == target :
        continue
    if target not in vertex_list[origin] :
        vertex_list[origin].append(target)
    if origin not in vertex_list[target] :
        vertex_list[target].append(origin)
comands = int(input())
not_exist = []
for i in range(comands) :
    action, vertex1, vertex2 = input().split()
    if action == 'c' :
        print(merge(vertex_list, int(vertex1), int(vertex2)))
    else :
        print(bfs(vertex_list, int(vertex1), int(vertex2), vertex))
