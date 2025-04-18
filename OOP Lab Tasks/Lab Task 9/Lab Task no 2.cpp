#include <bits/stdc++.h>
using namespace std;

class Logger {
private:
    vector<string> logEntries;

    string formatLog(string level, string source, string msg) {
        return "[" + level + "][" + source + "] " + msg;
    }

    void saveLog(string entry) {
        logEntries.push_back(entry);
    }

public:
    void logInfo(string source, string msg) {
        saveLog(formatLog("INFO", source, msg));
    }

    void logWarning(string source, string msg) {
        saveLog(formatLog("WARNING", source, msg));
    }

    void logError(string source, string msg) {
        saveLog(formatLog("ERROR", source, msg));
    }

    friend class LogAuditor;
};

class LogAuditor {
private:
    string authKey;

public:
    LogAuditor(string key) : authKey(key) {}

    vector<string> getLogs(const Logger& loggerRef) const {
        if (authKey == "admin123") {
            return loggerRef.logEntries;
        } else {
            cout<<"Access denied: Invalid credentials"<<endl;
            return {};
        }
    }
};

void networkModule(Logger& logRef) {
    logRef.logInfo("Network", "Successfully connected to server.");
    logRef.logError("Network", "Unable to resolve hostname.");
}

void databaseModule(Logger& logRef) {
    logRef.logWarning("Database", "Query took too long to execute.");
    logRef.logInfo("Database", "New user record inserted successfully.");
}

int main() {
    Logger systemLogger;

    networkModule(systemLogger);
    databaseModule(systemLogger);

    LogAuditor auditor("admin123");
    vector<string> logs = auditor.getLogs(systemLogger);

    cout<<"\n--- System Logs ---\n";
    for (string entry : logs) {
        cout<<entry<<endl;
    }

    return 0;
}

