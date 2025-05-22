#include "HistoryData.h"
#include <fstream>

std::vector <RecordDisplayFrame*> HistoryData;

void deleteRecord(RecordDisplayFrame* recdisp) {

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

std::vector <std::array <std::string, 4>> parseCSV(std::ifstream& fout) {
    std::vector <std::array <std::string, 4>> records;
    std::array <std::string, 4> currentRecord;
    std::string field;
    int iField = 0;
    bool insideQuotes = false;

    char chr;
    while(fout.get(chr)) {

        if (chr == '"') {
            insideQuotes = ! insideQuotes;
        } else if (chr == ',') {
            if (insideQuotes) {
                field += chr;
            } else {
                if (iField < 4) {
                    currentRecord[iField] = field;
                    field = "";
                }
            }
        } else if (chr == '\n') {
            if (insideQuotes) {
                field += chr;
            } else {
                currentRecord[iField] = field;
                records.push_back(currentRecord);

                iField = 0;
                currentRecord = {};
                field = "";
            }
        } else {
            field += chr;
        }
    }

    if (field != "" || iField == 3) {
        currentRecord[iField] = field;
        records.push_back(currentRecord);
    }

    return records;
}

void displayRecords() {
    // QVBoxLayout* History = this->getHistoryLayout();
    // for (int i = 0; i < records.size(); i++) {
    //     RecordDisplayFrame* recdisp = new RecordDisplayFrame;
    //     recdisp->Reading = std::stoi(records[i][0]);
    //     recdisp->Description = QString::fromStdString(records[i][1]);
    //     recdisp->RecentMealDateTime = QDateTime::fromString(QString::fromStdString(records[i][2]), "ddd MMM dd HH:mm:ss yyyy");
    //     recdisp->DateTimeCreation = QDateTime::fromString(QString::fromStdString(records[i][3]), "ddd MMM dd HH:mm:ss yyyy");


    //     History->insertWidget(0, recdisp);
    //     addRecord(recdisp);
    // }
}
