#include <thread>
#include <mutex>
#include <iostream>

std::mutex fork_mutex[5];

void philosopher(int id) {
    while (true) {
        std::cout << "Philosopher " << id << " is thinking.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        fork_mutex[id].lock();
        fork_mutex[(id + 1) % 5].lock();

        std::cout << "Philosopher " << id << " is eating.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        fork_mutex[id].unlock();
        fork_mutex[(id + 1) % 5].unlock();
    }
}

int main() {
    std::thread philosophers[5];

    for (int i = 0; i < 5; ++i) {
        philosophers[i] = std::thread(philosopher, i);
    }

    for (int i = 0; i < 5; ++i) {
        philosophers[i].join();
    }

    return 0;
} 