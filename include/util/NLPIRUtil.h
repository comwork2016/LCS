#ifndef NLPIRUTIL_H
#define NLPIRUTIL_H

#include "DataStructure.h"
#include "ReadCorpus.h"
#include "StringUtil.h"

#include "NLPIR.h"

class NLPIRUtil
{
    public:
        NLPIRUtil();
        virtual ~NLPIRUtil();
        std::vector<SplitedHits> SplitStringToWords(std::string str,int n_FirstWordNo = 0,int n_SentencePos=0);
    protected:
    private:
};

#endif // NLPIRUTIL_H
