//
// Created by Christopher on 5/2/2025.
//

#include "MatrixGen.h"

MatrixReadInFormat OnlyDiagionals(int Row, int Col, double Diagional) {
    MatrixReadInFormat Local;
    Local.rowCount = Row;
    Local.colCount = Col;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            if (i == j) {
                Local.MatrixEntries.push_back(Diagional);
                Local.RowEntry.push_back(i);
                Local.ColEntry.push_back(j);
            }
        }
    }

    return Local;
}

MatrixReadInFormat OnlyTop(int Row, int Col, int Top) {
    MatrixReadInFormat Local;
    Local.rowCount = Row;
    Local.colCount = Col;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            if (i <= j) {
                Local.MatrixEntries.push_back(Top);
                Local.RowEntry.push_back(i);
                Local.ColEntry.push_back(j);
            }
        }
    }
    return Local;
}

MatrixReadInFormat OnlyBottom(int Row, int Col, int Bottom);

MatrixReadInFormat RandomEntries(int Row, int Col);