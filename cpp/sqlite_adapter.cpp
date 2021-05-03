//
// Created by Joshua Griffin on 28/04/21.
//

#include <iostream>
#include <sstream>
#include "sqlite3.h"
#include <ctime>
#include <unistd.h>
#include <sys/stat.h>
#include <map>
#include <jsi/jsi.h>
#include <jni.h>

using namespace std;
using namespace facebook;

map<string, sqlite3 *> dbMap = map<string, sqlite3 *>();

enum ResultType {
    SequelResultOk,
    SequelResultError
};

struct SequelResult {
    ResultType type;
    string message;
    jsi::Value value;
};

string get_db_path(string const &dbName, const char *docPath)
{
    char const *subdir = "/";

    stringstream ss;
    ss << docPath << subdir << dbName;
    string dbPath = ss.str();

    return dbPath;
}

SequelResult sqlite_open(string const &dbName, const char *docPath)
{
    string dbPath = get_db_path(dbName, docPath);
    int sqlOpenFlags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;

    sqlite3 *db;
    int exit = 0;
    exit = sqlite3_open_v2(dbPath.c_str(), &db, sqlOpenFlags, nullptr);

    if (exit != SQLITE_OK)
    {
        return SequelResult{
                SequelResultError,
                "",
                jsi::Value::undefined()
        };
    }
    else
    {
        dbMap[dbName] = db;
    }

    return SequelResult{
            SequelResultOk,
            "",
            jsi::Value::undefined()};
}