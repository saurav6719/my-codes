#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
};

bool compare(Process p1, Process p2) {
    return p1.priority < p2.priority;
}

void priorityScheduling(vector<Process>& processes) {
    int n = processes.size();
    vector<int> waiting_time(n, 0);
    vector<int> turnaround_time(n, 0);

    sort(processes.begin(), processes.end(), compare);

    int current_time = 0;
    for (int i = 0; i < n; ++i) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        waiting_time[i] = current_time - processes[i].arrival_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;

        current_time += processes[i].burst_time;
    }

    double avg_waiting_time = accumulate(waiting_time.begin(), waiting_time.end(), 0.0) / n;
    double avg_turnaround_time = accumulate(turnaround_time.begin(), turnaround_time.end(), 0.0) / n;

    cout << "Process\t Arrival Time\t Burst Time\t Priority\t Waiting Time\t Turnaround Time" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "P" << processes[i].id << "\t " << processes[i].arrival_time << "\t\t "
             << processes[i].burst_time << "\t\t " << processes[i].priority << "\t\t "
             << waiting_time[i] << "\t\t " << turnaround_time[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main() {
    vector<Process> processes = {
        {1, 0, 11, 2},
        {2, 5, 28, 0},
        {3, 12, 2, 3},
        {4, 2, 10, 1},
        {5, 9, 16, 4}
    };

    priorityScheduling(processes);

    return 0;
}
