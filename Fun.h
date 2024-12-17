#pragma once
#include <mysql.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define str string 
#define ll long long int
class Car
{
private:
    str Car_Card;
    str Car_Owner_Name;
    str Car_Owner_ID;
public:
    void set_Car_Card()
    {
        str ccard;cout << "输入车牌号:";
        cin >> ccard;
        this->Car_Card = ccard;
    }
    str get_Car_Card()
    {
        return this->Car_Card;
    }
    void set_Car_Owner_Name()
    {
        str coname; cout << "输入车主名字:";
        cin >> coname;
        this->Car_Owner_Name = coname;
    }
    str get_Car_Owner_Name()
    {
        return this->Car_Owner_Name;
    }
    void set_Car_Owner_ID()
    {
        str coid; cout << "输入车主ID:";
        cin >> coid;
        this->Car_Owner_ID = coid;
    }
    str get_Car_Owner_ID()
    {
        return this->Car_Owner_ID;
    }
};
class User
{
private:
    str User_ID;
    str User_Name;
    str User_Sex;
public:
    void set_User_ID()
    {
        str uid; cout << "用户ID：";
        cin >> uid;
        this->User_ID = uid;
    }
    void set_User_Name()
    {
        str uname; cout << "用户名字：";
        cin >> uname;
        this->User_Name = uname;

    }
    void set_User_Sex()
    {
        str usex; cout << "用户性别：";
        cin >> usex;
        this->User_Sex = usex;

    }
    str get_User_ID()
    {
        return this->User_ID;
    }
    str get_User_Name()
    {
        return this->User_Name;
    }
    str get_User_Sex()
    {
        return this->User_Sex;
    }
};
class Parking
{
private:
    str Park_Index;
    str Cur_Car_Owner_ID;
public:
    void set_Park_Index();
    void set_Cur_Car_Card();

};
class Bill
{
    str Bill_ID;
    str Begin_Time;
    str End_Time;
    str Cost;
    str Car_Card;
    str state;
    str ParkIndex;
};
class sql
{
private:
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
public:
    int initsql();
    void closesql();
    void fun() ;
    int query(str Obj);
    void Add();
    void Del();
    void Mod();
    void Que();
    void Bil();
    sql();
    ~sql();
    void insertUser();
    void insertCar();
    void delUser();
    void delCar();
    void ModUser();
    void ModCar();
    int chg(str chgstr);
    int upinpark(str carc);
    int upoutpark(str carc);
};