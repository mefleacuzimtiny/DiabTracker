#include "HistoryData.h"

#include <fstream>
#include <algorithm>

#include <QVBoxLayout>

std::vector <RecordDisplayFrame*> HistoryData;

void deleteRecord(RecordDisplayFrame* recdisp) {
    auto it = std::find(HistoryData.begin(), HistoryData.end(), recdisp);
    if (it != HistoryData.end()) {
        HistoryData.erase(it);
    }
}

void addRecord(RecordDisplayFrame* recdisp) {
    HistoryData.push_back(recdisp);
}

void dumpRecords() {
    for (RecordDisplayFrame* recdisp : HistoryData) {
        qDebug() << recdisp->repr();
    }
}

void writeRecordsToFile() {
    std::ofstream fout("RecordHistory.txt");
    if (!fout.is_open()) {
        return;
    }
    for (RecordDisplayFrame* recdisp : HistoryData) {
        fout << recdisp->repr() << "\n";
    }
    fout.close();
}

using rec_vect = std::vector<std::array<std::string, 4>>;

rec_vect parseCSV(std::ifstream& file) {
    rec_vect records;
    std::array<std::string, 4> currentRecord;
    std::string currentField;
    int fieldIndex = 0;
    bool insideQuotes = false;

    char c;
    while (file.get(c)) {
        if (c == '"') {
            insideQuotes = !insideQuotes; // Toggle quote state
        } else if (c == ',') {
            if (insideQuotes) {
                currentField += c;
            } else {
                if (fieldIndex < 4) {
                    currentRecord[fieldIndex++] = currentField;
                    currentField.clear();
                }
            }
        } else if (c == '\n') {
            if (insideQuotes) {
                currentField += c; // Preserve newline inside quotes
            } else {
                currentRecord[fieldIndex] = currentField;
                records.push_back(currentRecord);

                // Reset state
                currentRecord = {};
                currentField.clear();
                fieldIndex = 0;
            }
        } else {
            currentField += c;
        }
    }

    // Handle last record if file doesn’t end with newline
    if (!currentField.empty() || fieldIndex == 3) {
        currentRecord[fieldIndex] = currentField;
        records.push_back(currentRecord);
    }

    // store records in file

    return records;
}

void loadRecords(QVBoxLayout* History, std::string filename) {

    rec_vect records;

    std::ifstream file(filename, std::ios::app);
    if (file.is_open()) {
        records = parseCSV(file);
        file.close();
    }


    for (int i = 0; i < records.size(); i++) {
        RecordDisplayFrame* recdisp = new RecordDisplayFrame;
        // todo: fix the damn CSV parser!!!
        qDebug() << "Value: " << records[i][0] << "\n"
                 << "Description: " << records[i][1] << "\n"
                 << "RecentMealTime: " << records[i][2] << "\n"
                 << "Date Created: " << records[i][3] << "\n"
                 << "--------------------------\n";


        recdisp->Reading = std::stoi(records[i][0]);
        recdisp->Description = QString::fromStdString(records[i][1]);
        recdisp->RecentMealDateTime = QDateTime::fromString(QString::fromStdString(records[i][2]), "ddd MMM dd HH:mm:ss yyyy");
        recdisp->DateTimeCreation = QDateTime::fromString(QString::fromStdString(records[i][3]), "ddd MMM dd HH:mm:ss yyyy");

        recdisp->updateValues();

        History->insertWidget(0, recdisp);
        addRecord(recdisp);
    }
}

void sortRecords() {
    // simple bubble sort
    for (int i = 0; i < HistoryData.size() - 1; ++i) {
        for (int j = 0; j < HistoryData.size() - i - 1; ++j) {
            if (HistoryData[j]->DateTimeCreation > HistoryData[j + 1]->DateTimeCreation) {
                std::swap(HistoryData[j], HistoryData[j + 1]);
            }
        }
    }
}
