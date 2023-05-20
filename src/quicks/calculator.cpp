#include "./calculator.hpp"
#include <thread>
#include <vector>

namespace Quick
{
    Calculator::Calculator(QQuickItem *parent)
        : QQuickItem(parent)
    {
    }

    void Calculator::start(int cpuCoresCount)
    {
        running = true;
        emit runningChanged();

        std::vector<std::thread> workers;
        for (int i = 0; i < cpuCoresCount; ++i)
        {
            workers.emplace_back(&Calculator::worker, this);
        }

        for (auto &worker : workers)
        {
            worker.detach();
        }
    }

    void Calculator::stop()
    {
        running = false;
        emit runningChanged();
    }

    bool Calculator::isRunning() const
    {
        return running;
    }

    int Calculator::getCpuCoresCount() const
    {
        return std::thread::hardware_concurrency();
    }

    void Calculator::worker()
    {
        int i = 0;
        while (running)
        {
            i++;
        }
    }
} // namespace Quick
