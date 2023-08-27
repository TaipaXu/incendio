#include "./calculator.hpp"
#include <thread>
#include <vector>
#include <QTimer>
#include <QStringBuilder>

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

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Calculator::onTimeout);
        timer->setInterval(1000);
        timer->start();

        duration = 0;
    }

    void Calculator::stop()
    {
        running = false;
        emit runningChanged();

        delete timer;
        timer = nullptr;
    }

    bool Calculator::isRunning() const
    {
        return running;
    }

    int Calculator::getCpuCoresCount() const
    {
        return std::thread::hardware_concurrency();
    }

    QString Calculator::getDuration() const
    {
        return humanReadableDuration(duration);
    }

    void Calculator::worker()
    {
        int i = 0;
        while (running)
        {
            static int result = i++;
        }
    }

    void Calculator::onTimeout()
    {
        duration++;
        emit durationChanged();
    }

    QString Calculator::humanReadableDuration(int duration) const
    {
        int minutes = duration / 60;
        int seconds = duration % 60;
        return QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    }
} // namespace Quick
