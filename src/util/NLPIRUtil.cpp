#include "NLPIRUtil.h"

NLPIRUtil::NLPIRUtil()
{
    //初始化分词组件
    if(!NLPIR_Init(0,UTF8_CODE,0))
    {
        std::cout<<"ICTCLAS INIT FAILED!"<<std::endl;
    }
}

std::vector<SplitedHits> NLPIRUtil::SplitStringToWords(std::string str,int n_FirstWordNo,int n_SentencePos)
{
    std::vector<SplitedHits> vec_Result;
    const result_t *pVecResult;
    int nCount = 0;
    pVecResult = NLPIR_ParagraphProcessA(str.c_str(),&nCount,true);
    for (int i=0; i<nCount; i++)
    {
        std::string str_HitsWord = str.substr(pVecResult[i].start,pVecResult[i].length);
        if(StringUtil::isStringBlank(str_HitsWord) || ReadCorpus::set_StopTerm.find(str_HitsWord)!=ReadCorpus::set_StopTerm.end())
        {
            continue;
        }
        //筛选词性名词(N)、动词(V)、形容词 (A)、数词(M)、量词(Q)和时间(T)
        char ch_pos = pVecResult[i].sPOS[0];
        if(ch_pos == 'n' || ch_pos == 'v' || ch_pos == 'n' || ch_pos == 'a' || ch_pos == 'm' || ch_pos == 'q' || ch_pos == 't')
        {
            //SIMHASH_TYPE simhash = HashUtil::CalcStringHash(str_HitsWord);
            TextRange textRange =
            {
                n_SentencePos + pVecResult[i].start,//偏移值为最后一个字符的下一个字符所在的位置
                pVecResult[i].length
            };
            SplitedHits sh_hits =
            {
                str_HitsWord,
                textRange,
                pVecResult[i].sPOS,
                n_FirstWordNo
            };
            vec_Result.push_back(sh_hits);
            n_FirstWordNo++;
        }
    }
    return vec_Result;
}

NLPIRUtil::~NLPIRUtil()
{
    NLPIR_Exit();
}
