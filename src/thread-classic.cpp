#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

std::atomic<bool> shouldRun{true};

void background_thread()
{
    for (size_t i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(1s);
        std::cout << "Worker\n";
        if (!shouldRun)
        {
           std::cout << "Stop requested - finish\n";
           break;
        }
    }
}


int main(int argc, char* argv[])
{
    std::thread backgroundThread(background_thread);

    for (size_t i = 0; i < 5; ++i)
    {
        std::this_thread::sleep_for(1000ms);
        std::cout << "Main\n";
    }

    std::cout << "Main almost done - request stop\n";
    shouldRun = false;

    backgroundThread.join();
}
