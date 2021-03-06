#ifndef DB_COMMON_MYSQL_SYNTAX_H
#define DB_COMMON_MYSQL_SYNTAX_H

// https://dev.mysql.com/doc/refman/5.7/en/keywords.html

#include <QStringList>

namespace meow {
namespace db {
namespace common {

QStringList mySqlReservedKeywords()
{
    // 5.7
    QString list = "ACCESSIBLE,ADD,ALL,ALTER,ANALYZE,AND,AS,ASC,ASENSITIVE,"
    "BEFORE,BETWEEN,BIGINT,BINARY,BLOB,BOTH,BY,CALL,CASCADE,CASE,CHANGE,"
    "CHAR,CHARACTER,CHECK,COLLATE,COLUMN,CONDITION,CONSTRAINT,CONTINUE,"
    "CONVERT,CREATE,CROSS,CURRENT_DATE,CURRENT_TIME,CURRENT_TIMESTAMP,"
    "CURRENT_USER,CURSOR,DATABASE,DATABASES,DAY_HOUR,DAY_MICROSECOND,"
    "DAY_MINUTE,DAY_SECOND,DEC,DECIMAL,DECLARE,DEFAULT,DELAYED,DELETE,"
    "DESC,DESCRIBE,DETERMINISTIC,DISTINCT,DISTINCTROW,DIV,DOUBLE,DROP,DUAL,"
    "EACH,ELSE,ELSEIF,ENCLOSED,ESCAPED,EXISTS,EXIT,EXPLAIN,FALSE,FETCH,"
    "FLOAT,FLOAT4,FLOAT8,FOR,FORCE,FOREIGN,FROM,FULLTEXT,GENERATED,GET,"
    "GRANT,GROUP,HAVING,HIGH_PRIORITY,HOUR_MICROSECOND,HOUR_MINUTE,"
    "HOUR_SECOND,IF,IGNORE,IN,INDEX,INFILE,INNER,INOUT,INSENSITIVE,INSERT,"
    "INT,INT1,INT2,INT3,INT4,INT8,INTEGER,INTERVAL,INTO,IO_AFTER_GTIDS,"
    "IO_BEFORE_GTIDS,IS,ITERATE,JOIN,KEY,KEYS,KILL,LEADING,LEAVE,LEFT,"
    "LIKE,LIMIT,LINEAR,LINES,LOAD,LOCALTIME,LOCALTIMESTAMP,LOCK,LONG,"
    "LONGBLOB,LONGTEXT,LOOP,LOW_PRIORITY,MASTER_BIND,MASTER_SSL_VERIFY_SERVER_CERT,"
    "MATCH,MAXVALUE,MEDIUMBLOB,MEDIUMINT,MEDIUMTEXT,MIDDLEINT,MINUTE_MICROSECOND,"
    "MINUTE_SECOND,MOD,MODIFIES,NATURAL,NOT,NO_WRITE_TO_BINLOG,NULL,NUMERIC,"
    "OLD_PASSWORD,ON,OPTIMIZE,OPTIMIZER_COSTS,OPTION,OPTIONALLY,OR,ORDER,OUT,"
    "OUTER,OUTFILE,PARTITION,PRECISION,PRIMARY,PROCEDURE,PURGE,RANGE,READ,"
    "READS,READ_WRITE,REAL,REFERENCES,REGEXP,RENAME,REPEAT,REPLACE,REQUIRE,"
    "RESIGNAL,RESTRICT,RETURN,REVOKE,RIGHT,RLIKE,SCHEMA,SCHEMAS,"
    "SECOND_MICROSECOND,SELECT,SENSITIVE,SEPARATOR,SET,SHOW,SIGNAL,SMALLINT,"
    "SPATIAL,SPECIFIC,SQL,SQLEXCEPTION,SQLSTATE,SQLWARNING,SQL_BIG_RESULT,"
    "SQL_CALC_FOUND_ROWS,SQL_SMALL_RESULT,SSL,STARTING,STORED,STRAIGHT_JOIN,"
    "TABLE,TERMINATED,THEN,TINYBLOB,TINYINT,TINYTEXT,TO,TRAILING,TRIGGER,"
    "TRUE,UNDO,UNION,UNIQUE,UNLOCK,UNSIGNED,UPDATE,USAGE,USE,USING,UTC_DATE,"
    "UTC_TIME,UTC_TIMESTAMP,VALUES,VARBINARY,VARCHAR,VARCHARACTER,VARYING,"
    "VIRTUAL,WHEN,WHERE,WHILE,WITH,WRITE,XOR,YEAR_MONTH,ZEROFILL,_FILENAME";

    // 8.0 https://dev.mysql.com/doc/refman/8.0/en/keywords.html
    list += ",ADMIN,BUCKETS,CLONE,COMPONENT,CUME_DIST,DEFINITION,DENSE_RANK,"
    "DESCRIPTION,EMPTY,EXCEPT,EXCLUDE,FIRST_VALUE,FOLLOWING,GEOMCOLLECTION,"
    "GET_MASTER_PUBLIC_KEY,GROUPING,GROUPS,HISTOGRAM,HISTORY,INVISIBLE,"
    "JSON_TABLE,LAG,LAST_VALUE,LEAD,LOCKED,MASTER_PUBLIC_KEY_PATH,NESTED,"
    "NOWAIT,NTH_VALUE,NTILE,NULLS,OF,ORDINALITY,ORGANIZATION,OTHERS,"
    "OVER,PATH,PERCENT_RANK,PERSIST,PERSIST_ONLY,PRECEDING,PROCESS,RANK,"
    "RECURSIVE,REFERENCE,REMOTE,RESOURCE,RESPECT,RESTART,REUSE,ROLE,ROW_NUMBER,"
    "SKIP,SRID,SYSTEM,THREAD_PRIORITY,TIES,UNBOUNDED,VCPU,VISIBLE,WINDOW";

    return list.split(",", QString::SkipEmptyParts);
}

QStringList mySqlBoolLiterals()
{
    QString list = "TRUE,FALSE,NULL";
    return list.split(",", QString::SkipEmptyParts);
}


} // namespace common
} // namespace db
} // namespace meow

#endif // DB_COMMON_MYSQL_SYNTAX_H
