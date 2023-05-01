//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_SNAPSHOTINTERFACE_H
#define TEXTINPUT_PROJECT_SNAPSHOTINTERFACE_H

#include "../HistoryHandling/Snapshot.h"

// Abstract Class for Components that have ability to have snapshot(for ctrl-z) purposes
class SnapshotInterface {
    virtual Snapshot getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot &snapshot) = 0;
};

#endif //TEXTINPUT_PROJECT_SNAPSHOTINTERFACE_H
