def tem_par(sapatos, l) :
	k = 0
	for a in sapatos :
		if a[0] == l[0] and a[1] != l[1]:
			sapatos.pop(k)
			return True
		k += 1
	return False


i = int(input())
sapatos = []
while i != -1 :
	n = 0
	print(*sapatos)
	for a in range(i) :
		l = input().split();
		if tem_par(sapatos, l) :
			n += 1
		else :
			sapatos.append(l)
	print(n)
	i = int(input())