# BFS Algorithm

A simple example to explain BFS Algorithm.<br>

Reference: [This Blog](https://www.cnblogs.com/javathinker/p/7783714.html)<br>

BFS算法应该是目前为之的几个路径规划算法中时间复杂度最高的一个。和之前的A*等算法不一样，它并没有搜索出一条最优的路径，而是基本上完全通过遍历的方法来搜索路径。<br>

算法的基本步骤如下：<br>

1. 从起始点开始，搜索每个点周围的方格<br>
2. 将中心节点设为周围节点的父节点<br>
3. 若终点被搜索到，则结束搜索，按顺序输出搜索路径；否则从步骤1开始循环<br>
