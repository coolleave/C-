#pragma once
#include "course_graph.h"
#include <vector>
#include <string>
#include <unordered_set>
class TopologicalSorter
{
    // public:
    //     static std::vector<std::string> kahnSort(const CourseGraph &graph, bool &hasCycle);

public:
    static std::vector<std::string> kahnSort(const CourseGraph &graph, bool &hasCycle);

    static void allTopologicalSorts(const CourseGraph &graph,
                                    std::vector<std::vector<std::string>> &allOrders);

private:
    static void allTopologicalSortsHelper(const CourseGraph &graph,
                                          std::unordered_map<std::string, int> &indegree,
                                          std::vector<std::string> &path,
                                          std::vector<std::vector<std::string>> &allOrders,
                                          std::unordered_set<std::string> &visited);
};
