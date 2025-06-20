#include "course_graph.h"
using namespace std;

void CourseGraph::addCourse(const string &course)
{
    allCourses.insert(course);
    if (adjList.find(course) == adjList.end())
    {
        adjList[course] = {};
    }
}
void CourseGraph::addPrerequisite(const string &before, const string &after)
{
    // 添加先修课程
    addCourse(before);
    addCourse(after);
    adjList[before].push_back(after);
}

vector<string> CourseGraph::getCourses() const
{
    return vector<string>(allCourses.begin(), allCourses.end());
}

const unordered_map<string, vector<string>> &CourseGraph::getAdjList() const
{
    return adjList;
}
// 计算度
unordered_map<string, int> CourseGraph::computeIndegrees() const
{
    // 课程 度
    unordered_map<string, int> indegree;
    for (const auto &course : allCourses)
    {
        indegree[course] = 0;
    }
    // c++17的结构化绑定语法
    // 遍历邻接表，计算每个课程的入度
    for (const auto &[from, toList] : adjList)
    {
        for (const auto &to : toList)
        {
            indegree[to]++;
        }
    }
    return indegree;
}
