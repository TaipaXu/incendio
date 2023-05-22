#pragma once

#include <QQuickItem>

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

namespace Quick
{
    class Calculator : public QQuickItem
    {
        Q_OBJECT

        Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)
        Q_PROPERTY(int cpuCoresCount READ getCpuCoresCount CONSTANT)
        Q_PROPERTY(QString duration READ getDuration NOTIFY durationChanged)

    public:
        Calculator(QQuickItem *parent = nullptr);
        ~Calculator() = default;

        Q_INVOKABLE void start(int cpuCoresCount);
        Q_INVOKABLE void stop();
        bool isRunning() const;
        int getCpuCoresCount() const;
        QString getDuration() const;

    signals:
        void runningChanged();
        void durationChanged();

    private:
        void worker();
        Q_SLOT void onTimeout();
        QString humanReadableDuration(int duration) const;

    private:
        bool running = false;
        QTimer *timer = nullptr;
        int duration = 0;
    };
} // namespace Quick
