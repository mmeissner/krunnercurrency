#pragma once

#include <KRunner/AbstractRunner>

class CurrencyRunner : public KRunner::AbstractRunner
{
    Q_OBJECT

public:
    CurrencyRunner(QObject *parent, const KPluginMetaData &data);
    ~CurrencyRunner() override;

public:
    void match(KRunner::RunnerContext &context) override;

private:
    QRegularExpression re;
};
