#pragma once

#include <KRunner/AbstractRunner>
#include <QtNetwork/QNetworkReply>

class CurrencyAPI : public QObject
{
    Q_OBJECT

public:
    CurrencyAPI(KRunner::AbstractRunner*, KRunner::RunnerContext&, const double, const QString &, const QString &, const QString &, const QString &);

private Q_SLOTS:
   void parseResult(QNetworkReply*);

Q_SIGNALS:
	void finished();

private:
   KRunner::AbstractRunner * m_runner;
   QNetworkAccessManager * m_manager;
   KRunner::RunnerContext m_context;
   const double m_amount;
   const QString & m_curr_1;
   const QString & m_curr_1_des;
   const QString & m_curr_2;
   const QString & m_curr_2_desc;
};
