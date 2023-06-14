from cyaron import *

n,m,w = 10,15,10
g = Graph.graph(n,m,weight_limit=w,self_loop=False,repeated_edges=False)
io = IO("1.in")
io.input_writeln(g.to_str())