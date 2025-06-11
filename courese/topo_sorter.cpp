#include "topo_sorter.h"
#include <queue>
#include <unordered_map>

std::vector<std::string> TopologicalSorter::kahnSort(const CourseGraph &graph, bool &hasCycle)
{
    std::unordered_map<std::string, int> indegree = graph.computeIndegrees();
    std::queue<std::string> q;
    std::vector<std::string> result;

    for (const auto &[course, deg] : indegree)
    {
        if (deg == 0)
            q.push(course);
    }

    while (!q.empty())
    {
        std::string current = q.front();
        q.pop();
        result.push_back(current);

        for (const auto &neighbor : graph.getAdjList().at(current))
        {
            if (--indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    hasCycle = (result.size() != graph.getCourses().size());
    return result;
}
