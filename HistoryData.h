#ifndef HISTORYDATA_H
#define HISTORYDATA_H

#include <list>
#include <fstream>
#include <vector>
#include <array>
#include <string>

#include "recorddisplayframe.h"

// declare a container for HistoryData (which is shared in mainwindow.cpp and recorddisplayframe.cpp as the buttons for the record CRUD
// are defined in those files). I'm using a list (instead of a vector or deque), because my main priority in this program is deletion, potential insertion,
// linear file storage, and range selection for looping and statistics. Hence, random access is not a priority for me.
// Both deletion and insertion would be complex in vectors because shifting is necessary, whereas with lists, only traversal is necessary
// However, since I've made wrapper functions to interact with HistoryData, if I wanted to use a different container, I could, and all I would have to do
// is edit the function deleteRecord()

extern std::vector <RecordDisplayFrame*> HistoryData; // extern means it's defined elsewhere

void deleteRecord(RecordDisplayFrame* recdisp);
void addRecord(RecordDisplayFrame* recdisp);
void dumpRecords();
void writeRecordsToFile();
void displayRecords();
std::vector <std::array <std::string, 4>> parseCSV(std::ifstream& fout);

#endif // HISTORYDATA_H
