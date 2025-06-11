#include <iostream>
#include <fstream>
#include <string>
#include "course_graph.h"
#include "topo_sorter.h"
#include "semester_planner.h"

int main()
{
    CourseGraph graph;
    std::ifstream fin("data.txt");
    std::string pre, post;

    while (fin >> pre >> post)
    {
        graph.addCourse(pre);
        graph.addCourse(post);
        graph.addPrerequisite(pre, post);
    }

    bool hasCycle = false;
    auto topoOrder = TopologicalSorter::kahnSort(graph, hasCycle);
    if (hasCycle)
    {
        std::cout << "课程依赖中存在循环，无法安排课程！" << std::endl;
        return 1;
    }

    std::cout << "拓扑排序结果（推荐修课顺序）:\n";
    for (const auto &course : topoOrder)
    {
        std::cout << course << " ";
    }
    std::cout << "\n\n";

    auto semesters = SemesterPlanner::planSemesters(graph);
    std::cout << "学期课程安排如下:\n";
    for (const auto &[sem, courses] : semesters)
    {
        std::cout << "第 " << sem << " 学期: ";
        for (const auto &c : courses)
            std::cout << c << " ";
        std::cout << "\n";
    }

    return 0;
}
