//
// Created by Christopher on 5/4/2025.
//

#include "METISAdjncyFind.h"
#include <iostream>

void METISAdjncyFind(MatrixReadInFormat A, std::vector<int> &xadj, std::vector<int> &adjncy) {
    std::vector<std::vector<int>> TempAdjncy;
    TempAdjncy.resize(A.rowCount);

    for (int i = 0; i < A.rowCount; i++) {
        for (int j = 0; j < A.MatrixEntries.size(); j++) {
            if (A.RowEntry[j] == i && A.ColEntry[j] != i) {
                TempAdjncy[i].push_back(A.ColEntry[j]);
            }

            if (A.ColEntry[j] == i && A.RowEntry[j] != i) {
                TempAdjncy[i].push_back(A.RowEntry[j]);
            }
        }
    }

    /*
     * Removing duplicates from the nested vector
     */

    for (int i = 0; i < TempAdjncy.size(); i++) {
        for (int j = 0; j < TempAdjncy[i].size(); j++) {

            // Compare each element with current one
            for (int k = j + 1; k < TempAdjncy[i].size();) {
                // Erase if duplicate is found.
                if (TempAdjncy[i][k] == TempAdjncy[i][j]) {
                    TempAdjncy[i].erase(TempAdjncy[i].begin() + k);
                }
                else {
                    k++;
                }
            }
        }
    }

    /*
     * Construction of the xadj and adjncy vectors
     */
    xadj.resize(0);
    adjncy.resize(0);
    int position = 0;
    xadj.push_back(position);
    for (int i = 0; i < TempAdjncy.size(); i++) {
        for (int j = 0; j < TempAdjncy[i].size(); j++) {
            adjncy.push_back(TempAdjncy[i][j]);
        }
        position += TempAdjncy[i].size();
        xadj.push_back(position);
    }

}