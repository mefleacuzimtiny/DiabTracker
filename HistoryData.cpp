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
