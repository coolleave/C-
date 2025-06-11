#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <set>

class CourseGraph
{
public:
    void addCourse(const std::string &course);
    void addPrerequisite(const std::string &before, const std::string &after);
    std::vector<std::string> getCourses() const;
    const std::unordered_map<std::string, std::vector<std::string>> &getAdjList() const;
    std::unordered_map<std::string, int> computeIndegrees() const;

private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;
    std::set<std::string> allCourses;
};
