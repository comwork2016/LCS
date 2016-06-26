#include <iostream>
#include <ctime>

#include "ReadCorpus.h"
#include "GlossaryDao.h"
//to delete
#include "SentenceSimilarity.h"

//静态变量的初始化
std::map<std::string,double> ReadCorpus::map_CorpusTF;
std::set<std::string> ReadCorpus::set_StopTerm;
std::vector<Sememe> ReadCorpus::vec_Sememe;

int main()
{
    //设置全局环境本地化
    std::locale::global(std::locale(""));
    struct timeval start,finish;
    double duration;
    gettimeofday(&start,NULL);

    /*//将词语义项存入数据库中
    GlossaryDao* glossaryDao = new GlossaryDao();
    std::string str_GlossaryPath="./dat/glossary.dat";
    glossaryDao->ReadGlossaryToDB(str_GlossaryPath);
    delete glossaryDao;*/

    //读取语料库中的词频信息
    //ReadCorpus::ReadCorpusTF("./Corpus/Corpus.csv");
    ReadCorpus::ReadStopTerm("./Corpus/StopTerm.txt");
    ReadCorpus::ReadSememe("./dat/whole.dat");

    //DocumentOperation::AddDocument("./in/utf_23.txt");
    std::string str_InputDir = "./in/";
    //DocumentOperation::AddDirectoryDocuments(str_InputDir);

    //查询数据泄露
    std::string str_LeakDoc = "./test/leak.txt";
    //DocumentOperation::SearchLeak(str_LeakDoc);

    //Document* doc = new Document("./in/utf_742.txt",true);
    //doc->Display();


    SentenceSimilarity* ss = new SentenceSimilarity();
    //三句话分别为：
    //std::string str1 = "2月15号，装备司令部向集团支付了980万美元的支票，除了高中、高职应届生外，军方也第一次招募女性士兵。";
    //std::string str2 = "装备司令部已于2月15日向公司支付了980万美元的首批款额，用于无人机地面控制台、支持包和相关附件的生产。";
    std::string str1 = "中国婉拒俄助造航母 有望加入第五代战机研制";
    std::string str2 = "中国拒绝俄罗斯协助建造航母，可能加入研制第五代战斗机";

    //std::string str3 = "台军方今日公布了年度第3梯次募兵讯息，据了解，本梯次除针对高中、职应届毕业生加强倡导外，也将首次办理女性士兵招募甄选工作。";
    //std::string str1 = "机上的拐角、口盖边缘、接缝和铰链线除适当进行隐身处理外，还使用吸波材料(RAM)";
    //std::string str2 = "线衔接。机上的拐角、口盖边缘、接缝和铰链线除适当进行隐身处理外，还使用吸波材料(RAM)。RAM";
    ss->GetSimBoundary(str1,str2);
    //std::cout<<ss->CalcSentenceSimilarity(str1,str3)<<std::endl;
    delete ss;

    gettimeofday(&finish,NULL);
    duration = 1000000 * (finish.tv_sec - start.tv_sec) + finish.tv_usec - start.tv_usec;
    duration /= 1000000;
    std::cout<<std::endl<<std::endl<<"cost "<<duration<<" s"<<std::endl<<std::endl;
    return 0;
}
