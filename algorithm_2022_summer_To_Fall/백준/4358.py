import sys

input = sys.stdin.readline
dic = {}
count = 0

while True:
    species = input().strip()
    if not species:
        break
    dic.setdefault(species, 0)
    dic[species] += 1
    count += 1

for species in sorted(dic.keys()):
    print('{0} {1:0.4f}'.format(species, dic[species] * 100 / count))

