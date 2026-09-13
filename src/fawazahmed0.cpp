#include "fawazahmed0.h"

#include <QtGlobal>
#include <QJsonArray>
#include <QJsonDocument>
#include <QLocale>
#include <QUrlQuery>

#include <cmath>

CurrencyAPI::CurrencyAPI(KRunner::AbstractRunner *runner, KRunner::RunnerContext &context, const double amount, const QString &curr_1,
               const QString &curr_1_desc, const QString &curr_2, const QString &curr_2_desc)
        : m_runner(runner), m_context(context), m_amount(amount), m_curr_1(curr_1), m_curr_1_des(curr_1_desc), m_curr_2(curr_2), m_curr_2_desc(curr_2_desc) {
    m_manager = new QNetworkAccessManager(this);

    QUrl url = QUrl(QStringLiteral("https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/%1.json").arg(curr_1));
    QNetworkRequest request(url);
    m_manager->get(request);
    connect(m_manager, &QNetworkAccessManager::finished, this, &CurrencyAPI::parseResult);
}

void CurrencyAPI::parseResult(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "krunner_currency: network request failed:" << reply->errorString();
    }
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (!jsonDoc.isNull() && jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();

            double rate = jsonObj[m_curr_1].toObject()[m_curr_2].toDouble();
            double result = m_amount * rate;

            // Human-readable formatting: thousands grouping, no scientific
            // notation; 2 decimals for values >= 1, 4 significant digits below
            QLocale locale;
            QString formatted;
            if (qFuzzyIsNull(result)) {
                formatted = locale.toString(0.0, 'f', 2);
            } else {
                int decimals = 2;
                if (std::abs(result) < 1.0) {
                    decimals = qBound(2, 3 - static_cast<int>(std::floor(std::log10(std::abs(result)))), 12);
                }
                formatted = locale.toString(result, 'f', decimals);
                // drop trailing zeros and a dangling decimal separator
                while (formatted.endsWith(locale.zeroDigit())) {
                    formatted.chop(1);
                }
                if (formatted.endsWith(locale.decimalPoint())) {
                    formatted.chop(1);
                }
            }

            QString data = QStringLiteral("%1 %2").arg(formatted, m_curr_2_desc);

            KRunner::QueryMatch match(m_runner);
            match.setText(data);
            match.setData(data);
            match.setId(data);
            match.setIconName(QStringLiteral("view-currency-list"));
            match.setRelevance(1.0);

            QList<KRunner::QueryMatch> matches;
            matches.append(match);
            m_context.addMatches(matches);
        }
    }

    Q_EMIT finished();
}

#include "moc_fawazahmed0.cpp"
