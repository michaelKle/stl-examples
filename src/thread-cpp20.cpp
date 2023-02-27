#include <chrono>
#include <iostream>
#include <thread>
#include <stop_token>

using namespace std::chrono_literals;

void background_thread(std::stop_token stoken)
{
    for (size_t i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(1s);
        std::cout << "Worker\n";
        if (stoken.stop_requested())
        {
           std::cout << "Stop requested - finish\n";
           break;
        }
    }
}


int main(int argc, char* argv[])
{
    std::jthread backgroundThread(background_thread);

    for (size_t i = 0; i < 5; ++i)
    {
        std::this_thread::sleep_for(1000ms);
        std::cout << "Main\n";
    }

    std::cout << "Main almost done - request stop\n";
    backgroundThread.request_stop();
    std::cout << "Main will exit - implicitly calling destructors and join\n";
}
