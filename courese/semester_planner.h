#pragma once
#include "course_graph.h"
#include <vector>
#include <map>
#include <string>

class SemesterPlanner
{
public:
    static std::map<int, std::vector<std::string>> planSemesters(const CourseGraph &graph);
};
