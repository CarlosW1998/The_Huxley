def merge(vertex_list, vertex1, vertex2) :
    while vertex_list[vertex2] :
        i = vertex_list[vertex2].pop()
        vertex_list[i].
    return len(vertex_list[vertex1])

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
        print(vertex_list)
    else :
        print("NOTHING")
