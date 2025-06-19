#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
using namespace std;
class CourseGraph
{
public:
    // 添加课程
    void addCourse(const string &course);
    // 添加依赖关系
    void addPrerequisite(const string &before, const string &after);
    // 获取全部课程
    vector<string> getCourses() const;
    // 返回只读的邻接表
    const unordered_map<string, vector<string>> &getAdjList() const;
    unordered_map<string, int> computeIndegrees() const;

private:
    // 存储课程的邻接表
    unordered_map<string, vector<string>> adjList;
    // 课程集合，防止有重复课程
    set<string> allCourses;
};
