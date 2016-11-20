#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <memory>
#include <QString>
#include <QStringList>
#include "common.h"
#include "connection_parameters.h"
#include "exception.h"

namespace meow {
namespace db {

class Query;

typedef std::shared_ptr<Query> QueryPtr;

class Connection
{
public:
    Connection(const ConnectionParameters & params);
    virtual ~Connection();

    bool active() const { return _active; }
    ConnectionParameters * connectionParams() { return &_connectionParams; }
    QString & characterSet() { return _characterSet; }
    bool isUnicode() const { return _isUnicode; }
    unsigned long serverVersionInt() const { return _serverVersionInt; }

    virtual void setCharacterSet(const QString & characterSet);
    void setIsUnicode(bool isUnicode) { _isUnicode = isUnicode; }

    QStringList getColumn(const QString & SQL, std::size_t index = 0); // H: GetCol
    QString getCell(const QString & SQL, std::size_t index = 0); //H:  GetVar
    QueryPtr getResults(const QString & SQL); // H: GetResults(SQL: String): TDBQuery;
    QStringList allDatabases();

    virtual QStringList fetchDatabases() = 0;
    virtual QueryPtr createQuery() = 0;
    virtual void setActive(bool active) = 0;
    virtual bool ping(bool reconnect) = 0;
    virtual QString getLastError() = 0;
    virtual void doBeforeConnect();
    virtual void doAfterConnect();
    virtual QString fetchCharacterSet() = 0;
    virtual void query(const QString & SQL, bool storeResult = false) = 0; // H: add LogCategory
    virtual std::size_t lastResultsCount() const { return 0; } // H: ResultCount

protected:
    bool _active;
    db::ulonglong _rowsFound;
    db::ulonglong _rowsAffected;
    int _statementNum; // TODO: why signed, usage?
    QString _serverVersionString;
    unsigned long _serverVersionInt;

    QString quoteIdentifier(const char * identifier, bool alwaysQuote = true, QChar glue = QChar::Null);
    QString quoteIdentifier(QString & identifier, bool alwaysQuote = true, QChar glue = QChar::Null);
private:
    //int _connectionStarted;
    //int _serverUptime;
    ConnectionParameters _connectionParams;
    QString _characterSet;
    bool _isUnicode;
    //bool _loginPromptDone;
    //QString _databaseName;
};

} // namespace db
} // namespace meow

#endif // DB_CONNECTION_H