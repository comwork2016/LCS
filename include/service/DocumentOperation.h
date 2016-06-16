#ifndef DOCUMENTOPERATION_H
#define DOCUMENTOPERATION_H

#include <dirent.h>

#include "Document.h"
#include "DocumentDao.h"
#include "NLPIRUtil.h"

class DocumentOperation
{
    public:
        DocumentOperation();
        virtual ~DocumentOperation();
        static int AddDocument(const std::string& str_DocPath);
        static int AddDirectoryDocuments(const std::string& str_InputDir);
        static int SearchLeak(const std::string& str_DocPath);
    protected:
    private:
};

#endif // DOCUMENTOPERATION_H
