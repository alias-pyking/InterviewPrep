class Graph:
    def __init__(self):
        self.numberOfNodes=0
        self.adjacentList={}
    def addVertext(self,node):
        self.adjacentList[node]=[]
        self.numberOfNodes+=1
    def addEdge(self,node1,node2):
        self.adjacentList[node1].append(node2)
        self.adjacentList[node2].append(node1)
graph=Graph()
graph.addVertext(2)
graph.addVertext(3)
graph.addVertext(4)
graph.addVertext(5)
graph.addEdge(4,5)
graph.addEdge(2,3)
myhash={}
myhash[1]=[]
myhash[2]=[]
myhash[4]=[]
myhash[5]=[]
myhash[1].append(4)
myhash[4].append(1)
myhash[2].append(5)
myhash[5].append(2)
print(myhash)