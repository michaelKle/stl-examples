#include <chrono>
#include <iostream>
#include <thread>

void background_thread()
{
    for (size_t i = 0; i < 5; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds{1});
        std::cout << "Worker\n";
    }
    std::cout << "Worker done\n";
}


int main(int argc, char* argv[])
{
    std::thread backgroundThread(background_thread);

    for (size_t i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds{1});
        std::cout << "Main\n";
    }

    std::cout << "Main done\n";

    // still need to call join ???
    // backgroundThread.join();
}
