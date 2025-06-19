#include "semester_planner.h"
#include <queue>
#include <unordered_map>
using namespace std;

map<int, vector<string>> SemesterPlanner::planSemesters(const CourseGraph &graph)
{
    // 课程，度
    unordered_map<string, int> indegree = graph.computeIndegrees();
    // 初始化排序队列
    queue<string> q;
    // 存储每个学期的课程，使用vector
    map<int, vector<string>> semesterMap;
    // 存储每个课程的学期级别
    unordered_map<string, int> levelMap;
    // 初始化入度为0的课程
    for (const auto &[course, deg] : indegree)
    {
        if (deg == 0)
        {
            q.push(course);
            levelMap[course] = 1; // 学期为1
        }
    }
    // 分配学期
    while (!q.empty())
    {
        // 取出队首元素
        string curr = q.front();
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
