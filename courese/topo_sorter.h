#pragma once
#include "course_graph.h"
#include <vector>
#include <string>

class TopologicalSorter
{
public:
    static std::vector<std::string> kahnSort(const CourseGraph &graph, bool &hasCycle);
};
