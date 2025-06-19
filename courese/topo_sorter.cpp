#include "topo_sorter.h"
#include <queue>
#include <unordered_map>

// 拓扑排序 使用Kahn算法
std::vector<std::string> TopologicalSorter::kahnSort(const CourseGraph &graph, bool &hasCycle)
{
    std::unordered_map<std::string, int> indegree = graph.computeIndegrees();
    std::queue<std::string> q;
    std::vector<std::string> result;
    // 初始化入度为0的课程
    for (const auto &[course, deg] : indegree)
    {
        // 如果入度为0，则可以开始学习该课程
        if (deg == 0)
            q.push(course);
    }

    // 进行拓扑排序
    while (!q.empty())
    {
        // 取出队首元素
        std::string current = q.front();
        // 从队列中移除
        q.pop();
        // 将当前课程添加到结果中
        result.push_back(current);
        // 遍历当前课程的所有邻接课程
        for (const auto &neighbor : graph.getAdjList().at(current))
        {
            // 减少邻接课程的入度
            if (--indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    // 检查是否有环
    // 如果拓扑排序后的课程数量 少于原始图中课程总数，说明有一部分课程没有被排序到，这些课程肯定是在环中，所以说明图里有 环（cycle）。
    hasCycle = (result.size() != graph.getCourses().size());
    return result;
}
