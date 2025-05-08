//
// Created by Christopher on 5/5/2025.
//

#ifndef METISWRAPPER_H
#define METISWRAPPER_H

#include <metis.h>
#include "MatrixStruct.h"

void METISwrapper(std::vector<int> xadj, std::vector<int> adjncy, int npart, std::vector<int> &part)
{
    int vtxdist = xadj.size()-1;
    int ncon     = 1;
    int *vwgt    = NULL;
    int *vsize   = NULL;
    int *adjwgt  = NULL;
    std::vector<float> tpwgts(npart, 1.0/npart);
    std::vector<float> ubvec(ncon, 1.05);
    std::vector<idx_t> options(METIS_NOPTIONS);
    METIS_SetDefaultOptions(options.data());
    int edgecut;

    part.resize(vtxdist);


    int err = METIS_PartGraphKway(&vtxdist, &ncon, xadj.data(), adjncy.data(), vwgt, vsize, adjwgt,
                        &npart, tpwgts.data(), ubvec.data(), options.data(), &edgecut, part.data());
}

#endif //METISWRAPPER_H
