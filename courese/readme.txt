 拓扑排序（Kahn算法） 和 学期分层规划。
 拓扑排序
 时间
O(V + E)
V 是课程数（顶点数），E 是依赖关系数（边数）。
每个节点最多进队出队一次（O(V)）
每条边最多访问一次（在减少入度的过程里）（O(E)）
空间
O(V + E)
使用了邻接表存图 adjList（O(V + E)）
入度表 indegree（O(V)）
队列 queue<string>（最多 O(V)）
拓扑结果数组 result（O(V)）

学期规划（SemesterPlanner）
时间
O(V + E)
与拓扑排序一样，遍历每门课程和它的所有依赖关系。
每个课程进队出队一次，处理邻居时遍历所有边。

空间
O(V + E)
indegree：O(V)
levelMap：存储每门课的所在学期，O(V)
semesterMap：学期到课程列表的映射，O(V)


