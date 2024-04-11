# Dijkstra 最短路径算法
  
  贪心算法思想<br>
  算法实现前提:	优先队列

## 优先队列/最小堆实现

  使用最小堆实现最小优先队列，[链接](../sort/heap/README.md)

## 最短路径算法

  ***1、***  **RELAX**(Vertex v, Vertex u, Weight w)<br>
  对于最短路径算法，需要**松弛**技术。对于每个结点v来说，维持一个属性v.d ，用来记录从源结点s到结点v的最短路径的上界。
  称v.d为s到v的**最短路径的估计**同时算法也要维护**v.π**属性，表示源结点s到结点v的最短路径上，结点v的前驱。
  算法运行最初，v.d的值统一为** ∞ **，v.π的值统一为**NULL**。<br>
  <br>
  对于一条边的**松弛**过程为:先检测v.d 是否大于u.d + w(u, v)，如果大于的话
  对v.d和v.π进行更新。<br>

  ```c, no_run
  void RELAX(Vertex v, Vertex, u, Weight w)
  {
  	if v.d > (u.d + w(v, u)):
		v.d = u.d + w(v, u);
		v.π = u;
  }
  ```



