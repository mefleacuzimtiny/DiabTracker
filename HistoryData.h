#ifndef HISTORYDATA_H
#define HISTORYDATA_H

#include <list>

#include "recorddisplayframe.h"

// declare a container for HistoryData (which is shared in mainwindow.cpp and recorddisplayframe.cpp as the buttons for the record CRUD
// are defined in those files). I'm using a vector (instead of a list or deque), because my main priority in this program is deletion, potential insertion,
// linear file storage, and range selection for looping and statistics. Hence, random access is not a priority for me.
// Both deletion and insertion would be similarly complex in both vectors and queues because for deletion, shifting is necessary, and for lists,
// traversal is necessary.

std::list <RecordDisplayFrame*> HistoryData;

void deleteRecord(RecordDisplayFrame* recdisp) {

}

void dumpRecords() {
    for (RecordDisplayFrame* recdisp : HistoryData) {
        qDebug() << recdisp->repr();
    }
}

#endif // HISTORYDATA_H
