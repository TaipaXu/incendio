#pragma once

#include <QQuickItem>

namespace Quick
{
    class Calculator : public QQuickItem
    {
        Q_OBJECT

        Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)
        Q_PROPERTY(int cpuCoresCount READ getCpuCoresCount CONSTANT)

    public:
        Calculator(QQuickItem *parent = nullptr);
        ~Calculator() = default;

        Q_INVOKABLE void start(int cpuCoresCount);
        Q_INVOKABLE void stop();
        bool isRunning() const;
        int getCpuCoresCount() const;

    signals:
        void runningChanged();

    private:
        void worker();

    private:
        bool running = false;
    };
} // namespace Quick
