#ifndef   STUDAO_HPP
#define   STUDAO_HPP

#include "daoBase.hpp"
#include "../models/stuModel.hpp"



class stuDao : public daoBase {
  public:
    bool addStu();
    bool deleteStu();
    students updateStu();
    students findStu();
};


void stuDao::addStudent(students& student){
   shared_ptr<Statement> stm = daoBase::getStatement();
   daoBase::conn->setSchema("test");
   shared_ptr<ResultSet> res = stm->executeQuery("INSERT INTO stuTable(idStudent, name) VALUES(?, ?)");
}


#endif


