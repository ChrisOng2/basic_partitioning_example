#include <iostream>
#include "MatrixGen.h"
#include "COOtoCSR.h"
#include "METISAdjncyFind.h"
#include "METISWrapper.h"

int main() {
    int Row = 10;
    int Col = 10;
    int Val = 1;

    MatrixReadInFormat Identity = OnlyDiagionals(Row, Col, Val);
    Identity = OnlyTop(Row, Col, Val);


    int RowCounter = 0;
    int ColCounter = 0;

    for (int i = 0; i < Identity.colCount * Identity.rowCount; i++) {
        int PostFlag   = 0;
        for (int j = 0; j < Identity.MatrixEntries.size(); j++) {
            if (Identity.RowEntry[j] == RowCounter && Identity.ColEntry[j] == ColCounter) {
                std::cout << Identity.MatrixEntries[j] << " ";
                PostFlag = 1;
            }
        }
        if (PostFlag != 0) {
            PostFlag = 0;
        }
        else {
            std::cout << "0 ";
        }
        ColCounter++;

        if (ColCounter >= Identity.colCount) {
            ColCounter = 0;
            RowCounter++;
            std::cout << "\n";
        }
    }

    CompressedSparseRow CSROutput = COOToCSR(Identity);

    int PostCounter = 0;

    for (int i = 0; i < CSROutput.rowCount; i++) {
        PostCounter = CSROutput.RowIndex[i];
        for (int j = 0; j < CSROutput.colCount; j++) {
            if (PostCounter < CSROutput.RowIndex[i+1] && j == CSROutput.ColIndex[PostCounter]) {
                std::cout << CSROutput.Entry[PostCounter] << " ";
                PostCounter++;
            }
            else {
                std::cout << "0 ";
            }
        }
        std::cout << "\n";
    }
    std::vector<int> xadj;
    std::vector<int> adjncy;
    METISAdjncyFind(Identity, xadj, adjncy);

    for (int i = 0; i < xadj.size(); i++) {
        std::cout << xadj[i] << "\n";
    }

    for (int i = 0; i < adjncy.size(); i++) {
        std::cout << adjncy[i] << "\n";
    }

    std::vector<int> part;
    METISwrapper(xadj, adjncy, 4, part);

    for (auto j : part) {
        std::cout << j << " ";
    }
    return 0;
}
