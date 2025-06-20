#include <iostream>
#include <fstream>
#include <string>
#include "course_graph.h"
#include "topo_sorter.h"
#include "semester_planner.h"
using namespace std;
int main()
{
    CourseGraph graph;
    ifstream fin("data-2.txt");    // 输入文件
    ofstream fout("output-2.txt"); // 添加文件输出流
    string pre, post;

    // 自定义一个 lambda 同时写入控制台和文件
    auto print = [&](const string &msg)
    {
        cout << msg;
        fout << msg;
    };
    // 输入
    while (fin >> pre >> post)
    {
        print("读取课程关系: " + pre + " -> " + post + "\n");
        graph.addCourse(pre);
        graph.addCourse(post);
        graph.addPrerequisite(pre, post);
    }

    // 判断是否有环的存在
    bool hasCycle = false;
    auto topoOrder = TopologicalSorter::kahnSort(graph, hasCycle);
    print("总课程数：" + to_string(graph.getCourses().size()) + "\n");
    if (hasCycle)
    {
        print("课程依赖中存在循环，无法安排课程！\n");
        return 1;
    }

    print("所有可能的拓扑排序（修课顺序）如下：\n");

    vector<vector<string>> allOrders;
    TopologicalSorter::allTopologicalSorts(graph, allOrders);

    int orderIdx = 1;
    for (const auto &order : allOrders)
    {
        print("排序 #" + to_string(orderIdx++) + ": ");
        for (const auto &course : order)
            print(course + " ");
        print("\n");
    }

    // for (const auto &course : topoOrder)
    // {
    //     print(course + " ");
    // }
    // print("\n\n");
    // // 添加输出到文件
    // auto semesters = SemesterPlanner::planSemesters(graph);

    // print("学期课程安排如下:\n");
    // for (const auto &[sem, courses] : semesters)
    // {
    //     print("第 " + to_string(sem) + " 学期: ");
    //     for (const auto &c : courses)
    //         print(c + " ");
    //     print("\n");
    // }

    return 0;
}
