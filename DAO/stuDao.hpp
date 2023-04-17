#ifndef   STUDAO_HPP
#define   STUDAO_HPP

#include "daoBase.hpp"
#include "../models/stuModel.hpp"


class stuDao : public cyz_oopcpp_dao::daoBase {
  public:
    void addStudent(students& student);
    //bool deleteStu();
    //students updateStu();
    //students findStu();
};


void stuDao::addStudent(students& student){
  shared_ptr<Connection> conn = daoBase::getConnection(); 
  conn->setSchema("test");
  shared_ptr<PreparedStatement> pstmt(conn->prepareStatement("INSERT INTO stuTable(idStudent, name) VALUES(?, ?)"));
  //shared_ptr<ResultSet> res = stm->executeQuery("INSERT INTO stuTable(idStudent, name) VALUES(?, ?)");
  pstmt->setInt(1, student.studentId);
  pstmt->setString(2, student.name);
  pstmt->execute();
}


#endif


