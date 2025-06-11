#include "semester_planner.h"
#include <queue>
#include <unordered_map>

std::map<int, std::vector<std::string>> SemesterPlanner::planSemesters(const CourseGraph &graph)
{
    std::unordered_map<std::string, int> indegree = graph.computeIndegrees();
    std::queue<std::string> q;
    std::map<int, std::vector<std::string>> semesterMap;
    std::unordered_map<std::string, int> levelMap;

    for (const auto &[course, deg] : indegree)
    {
        if (deg == 0)
        {
            q.push(course);
            levelMap[course] = 1;
        }
    }

    while (!q.empty())
    {
        std::string curr = q.front();
        q.pop();
        int currLevel = levelMap[curr];
        semesterMap[currLevel].push_back(curr);

        for (const auto &neighbor : graph.getAdjList().at(curr))
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
                levelMap[neighbor] = currLevel + 1;
            }
        }
    }

    return semesterMap;
}
