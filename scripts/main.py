import numpy as np
from operator import itemgetter
import matplotlib.pyplot as plt
import random 

file = "/home/little/ML/loc-gowalla_totalCheckins.txt"

def read_total(fname):
    mapa = {}
    for line in open(fname):
        line = line.split("\t")
        u_id, l_id = int(line[0]), int(line[4])
        if u_id in mapa:
            mapa[u_id].append(l_id)
        else:
            mapa[u_id] = [l_id]
    return mapa

locs = read_total(file)

def read(fname, nullLocs = True):
    mapa = {}
    for line in open(fname):
        i, c = line.split(" ")
        i = int(i)
        c= int(c)
        if nullLocs:
            if c in mapa:
                mapa[c].append(i)
            else:
                mapa[c] = [i]
        else:
            if i in locs:
                if c in mapa:
                    mapa[c].append(i)
                else:
                    mapa[c] = [i]

    return mapa

clusters = read("out.txt", False)


def topN_locs(vec, locs):
    topN = 10
    a = {}
    for i in vec:
        if i in locs:
            for j in locs[i]:
                if j in a:
                    a[j]+=1
                else:
                    a[j] = 1

    a = sorted(a.items(), key = itemgetter(1), reverse = True)

    c = 0
    out_locs = []
    for i, j in a:
        out_locs.append(i)
        c+=1
        if c> topN : break

    return out_locs

def count_intersections(users, local_locs, count, score):
    for i in users:
        for l in local_locs:
            count+=1
            if i in locs:
                if l in locs[i]:
                    score+=1
    return count, score

def count_Cluster(vec, delim):
    count, score = 0, 0
    random.shuffle(vec)
    if len(vec) >=  delim:
        tail_len = len(vec) // delim
        head_len = len(vec) - tail_len
        head = vec[:head_len]
        tail = vec[-tail_len:]
        head_locs = topN_locs(head, locs)

        count, score = count_intersections(tail, head_locs, count, score)
    return count, score

delim = 3
sscore = 0
ccount = 0
avg = 0
avg_n = 0
for i in clusters:
    if (len(clusters[i]) < delim):
        continue
    count,score = count_Cluster(clusters[i], delim)
    if(count == 0):
        continue
    sscore += score
    ccount += count
    avg += score / count
    avg_n += 1
print(avg / avg_n)
print(sscore / ccount)


