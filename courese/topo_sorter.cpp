#include "topo_sorter.h"
#include <queue>
#include <unordered_map>
using namespace std;
// 拓扑排序 使用Kahn算法
vector<string> TopologicalSorter::kahnSort(const CourseGraph &graph, bool &hasCycle)
{
    unordered_map<string, int> indegree = graph.computeIndegrees();
    queue<string> q;
    vector<string> result;
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
        string current = q.front();
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

void TopologicalSorter::allTopologicalSorts(const CourseGraph &graph,
                                            vector<vector<string>> &allOrders)
{
    unordered_map<string, int> indegree = graph.computeIndegrees();
    vector<string> currentPath;
    unordered_set<string> visited;
    allTopologicalSortsHelper(graph, indegree, currentPath, allOrders, visited);
}

void TopologicalSorter::allTopologicalSortsHelper(const CourseGraph &graph,
                                                  unordered_map<string, int> &indegree,
                                                  vector<string> &path,
                                                  vector<vector<string>> &allOrders,
                                                  unordered_set<string> &visited)
{
    bool hasProgressed = false;
    for (const auto &course : graph.getCourses())
    {
        if (indegree[course] == 0 && visited.find(course) == visited.end())
        {
            // 做出选择
            visited.insert(course);
            path.push_back(course);
            for (const auto &neighbor : graph.getAdjList().at(course))
                indegree[neighbor]--;

            // 递归
            allTopologicalSortsHelper(graph, indegree, path, allOrders, visited);

            // 回溯
            visited.erase(course);
            path.pop_back();
            for (const auto &neighbor : graph.getAdjList().at(course))
                indegree[neighbor]++;

            hasProgressed = true;
        }
    }

    if (!hasProgressed && path.size() == graph.getCourses().size())
    {
        allOrders.push_back(path); // 保存一条完整排序
    }
}
