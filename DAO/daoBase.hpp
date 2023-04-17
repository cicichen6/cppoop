#ifndef DAOBASE_HPP
#define DAOBASE_HPP

#include <iostream>
#include <stdlib.h>
#include <memory>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;


namespace cyz_oopcpp_dao {

class daoBase {
  private:
    static Driver* driver;
    static bool initFlag;

    daoBase();

  protected:
    //array<shared_ptr<Statement>, 2> getStatement();
    shared_ptr<Connection> getConnection();
};

Driver* daoBase::driver = get_driver_instance();

bool daoBase::initFlag = false;
/*bool daoBase::initFlag = [](){
  daoBase initDB;  
  shared_ptr<Statement> stmt = initDB.getStatement();
  initDB.conn->setSchema("test");
  stmt->executeQuery("CREATE TABLE stuTable(idStudent INT, name VARCHAR(10))");
  stmt->executeQuery("CREATE TABLE teacherTable(idTeacher INT, name VARCHAR(10))");
    return true;
}();*/

daoBase::daoBase(){
  if(!initFlag){
    auto initConn = getConnection();
    initConn->setSchema("test");
    shared_ptr<Statement> initStmt(initConn->createStatement());
    initStmt->execute("CREATE TABLE stuTable(idStudent INT, name VARCHAR(10))");
    initFlag = true;

  }
}

shared_ptr<Connection> daoBase::getConnection(){
  shared_ptr<Connection> conn (driver->connect("127.0.0.1:3306", "root", "111111"));
    if(!conn->isValid()){
            cout << "数据库连接无效" << endl; 
            return NULL; }
    else{
            cout << "数据库连接成功" << endl;
            return conn; }
}

/*array<shared_ptr<Statement>, 2> daoBase::getStatement(){
    shared_ptr<Connection> t_conn(driver->connect("127.0.0.1:3306", "root", "111111"));
    conn = t_conn;
    if(!conn->isValid()){
            cout << "数据库连接无效" << endl;
    
    }
    else{
            cout << "数据库连接成功" << endl;
    }
    shared_ptr<Statement> stmt(conn->createStatement());
    shared_ptr<Statement> stmm(conn->createStatement());
    std::array<shared_ptr<Statement>, 2> s{stmt, stmm};

    return s;

}*/


}



#endif
