#include "semester_planner.h"
#include <queue>
#include <unordered_map>

std::map<int, std::vector<std::string>> SemesterPlanner::planSemesters(const CourseGraph &graph)
{
    std::unordered_map<std::string, int> indegree = graph.computeIndegrees();
    std::queue<std::string> q;
    std::map<int, std::vector<std::string>> semesterMap;
    std::unordered_map<std::string, int> levelMap;
    // 初始化入度为0的课程
    for (const auto &[course, deg] : indegree)
    {
        if (deg == 0)
        {
            q.push(course);
            levelMap[course] = 1;
        }
    }
    // 进行拓扑排序并分配学期
    while (!q.empty())
    {
        // 取出队首元素
        std::string curr = q.front();
        q.pop();
        // 获取当前课程的学期级别
        int currLevel = levelMap[curr];
        // 将当前课程添加到对应学期的课程列表中
        semesterMap[currLevel].push_back(curr);
        // 遍历当前课程的所有邻接课程
        for (const auto &neighbor : graph.getAdjList().at(curr))
        {
            indegree[neighbor]--;
            // 如果邻接课程的入度变为0，则可以安排到下一个学期
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
                levelMap[neighbor] = currLevel + 1;
            }
        }
    }

    return semesterMap;
}
