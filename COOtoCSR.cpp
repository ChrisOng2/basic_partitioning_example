//
// Created by Christopher on 5/2/2025.
//

#include "COOtoCSR.h"

CompressedSparseRow COOToCSR(MatrixReadInFormat A) {
    CompressedSparseRow AReturn;
    AReturn.rowCount = A.rowCount;
    AReturn.colCount = A.colCount;
    AReturn.Entry.reserve(A.MatrixEntries.size());
    AReturn.ColIndex.reserve(A.MatrixEntries.size());
    AReturn.RowIndex.reserve(A.rowCount+1);

    int index = 0;
    AReturn.RowIndex.push_back(index);
    for (int i = 0; i < A.rowCount; i++) {
        for (int j = 0; j < A.MatrixEntries.size(); j++) {
            if (i == A.RowEntry[j]) {
                AReturn.Entry.push_back(A.MatrixEntries[j]);
                AReturn.ColIndex.push_back(A.ColEntry[j]);
                index++;
            }
        }
        int EndingIndex = index;
        AReturn.RowIndex.push_back(EndingIndex);
    }

    return AReturn;
}