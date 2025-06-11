#include "course_graph.h"

void CourseGraph::addCourse(const std::string &course)
{
    allCourses.insert(course);
    if (adjList.find(course) == adjList.end())
    {
        adjList[course] = {};
    }
}

void CourseGraph::addPrerequisite(const std::string &before, const std::string &after)
{
    addCourse(before);
    addCourse(after);
    adjList[before].push_back(after);
}

std::vector<std::string> CourseGraph::getCourses() const
{
    return std::vector<std::string>(allCourses.begin(), allCourses.end());
}

const std::unordered_map<std::string, std::vector<std::string>> &CourseGraph::getAdjList() const
{
    return adjList;
}

std::unordered_map<std::string, int> CourseGraph::computeIndegrees() const
{
    std::unordered_map<std::string, int> indegree;
    for (const auto &course : allCourses)
    {
        indegree[course] = 0;
    }
    for (const auto &[from, toList] : adjList)
    {
        for (const auto &to : toList)
        {
            indegree[to]++;
        }
    }
    return indegree;
}
