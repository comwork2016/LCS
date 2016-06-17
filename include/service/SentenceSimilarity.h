#ifndef SENTENCESIMILARITY_H
#define SENTENCESIMILARITY_H

#include <string>
#include <vector>

#include "WordSimilarity.h"
#include "NLPIR.h"
#include "NLPIRUtil.h"
#include "GlossaryDao.h"

class SentenceSimilarity
{
    public:
        SentenceSimilarity();
        virtual ~SentenceSimilarity();

        double CalcSentenceSimilarity(const std::string str_Sen1,const std::string str_Sen2);

    protected:
        void DivideWordsByPOS(const std::vector<SplitedHits>& vec_Word,std::vector<std::string>& vec_NWord,std::vector<std::string>& vec_VWord,std::vector<std::string>& vec_AWord,std::vector<std::string>& vec_MWord,std::vector<std::string>& vec_QWord,std::vector<std::string>& vec_TWord);
        double CalcVectorSimilarity(std::vector<std::string>& vec1,std::vector<std::string>& vec2,std::map<std::string,std::vector<std::string> > map_WordConceptsVector);
    private:
        GlossaryDao* glossaryDao;
};

#endif // SENTENCESIMILARITY_H
