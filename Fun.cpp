#include "Fun.h"
using namespace std;
#define str string
#define sys system("cls")
sql::sql()
{
    initsql();
    fun();
    //query();
    //closesql();
};
sql::~sql()
{   
    closesql();
    cout << "数据库已断开连接" << endl;
}
void sql::fun()
{
    sys;
    while(1){
        sys;
        int x = INT_MAX;
        cout << "-----------------------------------------------------" << endl;
        cout << "--------------停车场管理系统功能选择:----------------" << endl;
        cout << "--------------1.增加数据-----------------------------" << endl;
        cout << "--------------2.删除数据-----------------------------" << endl;
        cout << "--------------3.修改数据-----------------------------" << endl;
        cout << "--------------4.查询数据-----------------------------" << endl;
        cout << "--------------5.订单处理-----------------------------" << endl;
        cout << "--------------6.退出系统-----------------------------" << endl;
        cout << "-------------(停车费十元一天)------------------------" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "输入功能:";
        cin >> x;
        switch (x)
        {
        case 1:Add(); break;
        case 2:Del(); break;
        case 3:Mod(); break;
        case 4:Que(); break;
        case 5:Bil(); break;
        case 6:return; break;
        default: { cout << "没有该功能"<<endl << endl; break; }
        }
    }
}
int sql::initsql()
{
    {
        str loc,user,pswd,sqlname;
        std::cout << "输入主机名："; std::cin >> loc;
        std::cout << "输入用户名："; std::cin >> user;
        std::cout << "输入密码："; std::cin >> pswd;
        std::cout << "输入连接名："; std::cin >> sqlname;
        const char* cloc = loc.c_str();
        const char* cuser = user.c_str();
        const char* cpswd = pswd.c_str();
        const char* csqlname = sqlname.c_str();
        //localhost
        //root
        // Qq147258.
        // sql_test
        // 初始化连接环境
        this->conn = mysql_init(NULL);
        if (this->conn == NULL) {
            fprintf(stderr, "mysql_init failed\n");
            return 1;
        }

        // 连接数据库
        if (mysql_real_connect(this->conn, cloc ,cuser, cpswd, csqlname, 0, NULL, 0) == NULL) {
            fprintf(stderr, "mysql_real_connect failed: %s\n", mysql_error(this->conn));
            mysql_close(this->conn);
            return 1;
        }

        // 设置字符集为utf8mb4
        if (mysql_set_character_set(this->conn, "utf8mb4") != 0) {
            fprintf(stderr, "mysql_set_character_set failed: %s\n", mysql_error(this->conn));
            mysql_close(this->conn);
            return 1;
        }

        printf("mysql api使用的默认编码: %s\n", mysql_character_set_name(this->conn));
    }
}
void sql::closesql()
{
    // 释放结果集并关闭连接
    mysql_free_result(this->res);
    mysql_close(this->conn);
}
int sql::query(str Obj)
{

    str questr = "SELECT * FROM "+Obj;
    const char* cquestr = questr.c_str();
    // 执行查询
    if (mysql_query(this->conn, cquestr)) {
        fprintf(stderr, "mysql_query failed: %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return 1;
    }
    // 获取结果集
    this->res = mysql_store_result(this->conn);
    int column_count = mysql_field_count(this->conn);

    while ((this->row = mysql_fetch_row(this->res)) != NULL) {
        // 输出结果
        for(int i=0;i<column_count;++i)
        {
            cout <<left<<setw(14)<< this->row[i]<<" ";
        }
        cout<<endl;
    }
    cout <<endl<<"当前mysql查询指令：" << cquestr << endl << endl << endl;

}
void sql::Add()
{
    int a = INT_MAX;
    cout << " ----------------------------------------------------" << endl;
    cout << " ---------------增加功能选择:------------------------" << endl;
    cout << "--------------1.增加用户信息-------------------------" << endl;
    cout << "--------------2.增加车辆信息-------------------------" << endl;
    cout << "--------------其他：退出系统-------------------------" << endl;
    cout << " ----------------------------------------------------" << endl;
    cout << "增加功能选择:";
    cin >> a;
    sys;
    switch (a)
    {
    case 1:
    {
        insertUser();
        break;
    }
    case 2:
    {
        insertCar();
        break;
    }
    default: { break; }
    }
}
void sql::Del()
{
    int b= INT_MAX;
    cout << "-----------------------------------------------------" << endl;
    cout << "----------------增加功能选择:------------------------" << endl;
    cout << "--------------1.删除用户信息-------------------------" << endl;
    cout << "--------------2.删除车辆信息-------------------------" << endl;
    cout << "--------------其他：退出系统-------------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "删除功能选择:";
    cin >> b;
    sys;
    switch (b)
    {
    case 1:
    {
        delUser();
        break;
    }
    case 2:
    {
        delCar();
        break;
    }
    default: { break; }
    }
}
void sql::Mod()
{
    int a = INT_MAX;
    cout << "-----------------------------------------------------" << endl;
    cout << "----------------修改功能选择:------------------------" << endl;
    cout << "--------------1.修改用户信息-------------------------" << endl;
    cout << "--------------2.修改车辆信息-------------------------" << endl;
    cout << "--------------其他数字：返回主菜单-------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "修改功能选择:";
    cin >> a;
    sys;
    switch (a)
    {
    case 1: { sys; ModUser(); break; }
    case 2: { sys; ModCar(); break; }
    default:
        break;
    }
    char x; cout << "输入任意键加回车返回主菜单..." << endl; cin >> x; sys;
    return;
}
void sql::Que()
{
    int a ;
    cout << " ----------------------------------------------------" << endl;
    cout << " ---------------查询功能选择:------------------------" << endl;
    cout << "--------------1.查询用户-----------------------------" << endl;
    cout << "--------------2.查询车辆-----------------------------" << endl;
    cout << "--------------3.查询停车场---------------------------" << endl;
    cout << "--------------4.查询订单-----------------------------" << endl;
    cout << "--------------其他数字：返回-------------------------" << endl;
    cout << " ----------------------------------------------------" << endl;
    cout << "查询功能选择:";
    cin >> a;
    sys;
    switch (a)
    {
    case 1:
    {
        {
            cout << "------------------------------------------------------" << endl;
            cout << "--------------1.查询全部用户--------------------------" << endl;
            cout << "--------------2.查询某个用户--------------------------" << endl;
            cout << "--------------其他：返回------------------------------" << endl;
            cout << "------------------------------------------------------" << endl;
            int x = INT_MAX; cout << "输入你选择的功能："; cin >> x;
            switch (x)
            {
            case 1:sys; query("User"); break;
            case 2: {
                sys; cout << "输入你要查询的用户姓名或者ID(名字不一定唯一，ID是唯一的):"; str Obj; cin >> Obj;
                //str Objstr = /*" User WHERE User_ID=" + Obj + " OR User_Name='" + Obj + "'"*/;
                int flag = 0; for (auto s : Obj) { if (s - 48 >= 9) { flag++; break; } }
                flag==0?query(" User WHERE User_ID=" + Obj ): query(" User WHERE User_Name='"+Obj+"'");
                break;
                    }
            default:break;
            }
        }
        break;
    }
    case 2:
    {
        {
            cout << "------------------------------------------------------" << endl;
            cout << "--------------1.查询全部车----------------------------" << endl;
            cout << "--------------2.查询某辆车----------------------------" << endl;
            cout << "--------------其他：返回------------------------------" << endl;
            cout << "------------------------------------------------------" << endl;
            int x = INT_MAX; cout << "输入你选择的功能："; cin >> x;
            switch (x)
            {
            case 1: {
                sys;
                cout << left << setw(15) << "车牌号" << left << setw(15) << "车主姓名" << left << setw(15) << "车主ID" << endl;
                query("Car"); break;
                    }
            case 2: {
                sys; cout << "输入你要查询的车牌号、车主姓名或者车主ID(车牌号对应车主信息是唯一的，反之未必):"; str Obj; cin >> Obj;
                cout << left << setw(15) << "车牌号" << left << setw(15) << "车主姓名" << left << setw(15) << "车主ID" << endl;
                int flag = 0; for (auto s : Obj) { if (s - 48 >= 9) { flag++; break; } }
                flag!=0? query("Car WHERE Car_Card='" + Obj+"' or Car_Owner_Name='"+Obj+"'"):query("Car WHERE Car_Owner_ID="+Obj);
                break;
                     }
            }
        }
        break;
    }
    case 3: {
        cout << left << setw(15) << "车位号" << left << setw(15) << "当前车位停放车主ID" << endl;
        query("Parking");
        break;
    }
    case 4:
    {
        cout << left << setw(15) << "订单ID" <<
            left << setw(20) << "开始时间" << left << setw(20) << "结束时间" <<
            left << setw(15) << "停车费" << left << setw(15) << "车牌号" << left << setw(15) << "订单状态" <<left<<setw(15)<<"所停车位" << endl;
        query("Bill");
        break;
    }
    default: { break; }
    }
    char x; cout << "输入任意键加回车返回菜单..." << endl; cin >> x; sys;
    return;
}
void sql::Bil()
{
        sys;
        int x = INT_MAX;
        cout << "-----------------------------------------------------" << endl;
        cout << "--------------停车场订单系统功能选择:----------------" << endl;
        cout << "--------------1.停入车辆-----------------------------" << endl;
        cout << "--------------2.开走车辆(顺便结账)-------------------" << endl;
        cout << "--------------其他:退出系统--------------------------" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "输入功能:";
        cin >> x;
        switch (x)
        {
        case 1: {

            cout << "输入你要停放的车的车牌号:";
            str incar; cin >> incar;
            cout << "这是要停放的车的信息：" << endl;
            cout << left << setw(15) << "车牌号" << left << setw(15) << "车主姓名" << left << setw(15) << "车主ID" << endl;
            query("Car WHERE Car_Card='" + incar + "'");
            cout << "输入1确定停入";
            int cont = INT_MAX; if (cin >> cont && cont == 1) {
                sys;
                upinpark(incar);
            }
            break;
        }
        case 2: {
            cout << "输入你要开走的车的车牌号:";
            str outcar; cin >> outcar;
            cout << "这是您要开走的车的订单：" << endl;
            cout << left << setw(15) << "订单ID" <<
                left << setw(20) << "开始时间" << left << setw(20) << "结束时间" <<
                left << setw(15) << "停车费" << left << setw(15) << "车牌号" << left << setw(15) << "订单状态" << left << setw(15) << "所停车位" << endl;
            query("Bill WHERE Car_Card='" + outcar + "' and state=0"); 
            cout << "输入1确定开走";
            int cont = INT_MAX; if (cin >> cont && cont == 1) {
                sys;
                upoutpark(outcar);
            }
            break;
        }
        default: {
            break;
        }
        }
        cout << left << setw(15) << "车位号" << left << setw(15) << "当前车位停放车主ID" << endl;
        query("Parking");
        cout << "||||||||||PS：没车位显示车位为0||||||||||" << endl;
        cout << left << setw(15) << "订单ID" <<
            left << setw(20) << "开始时间" << left << setw(20) << "结束时间" <<
            left << setw(15) << "停车费" << left << setw(15) << "车牌号" << left << setw(15) << "订单状态" << left << setw(15) << "所停车位" << endl;
        query("Bill");
        str c; cout << "输入任意键加回车返回主菜单..." << endl; cin >> c; sys;
        return;
}

void sql::insertUser()
{
    User insert;
    //insert.set_User_ID();
    insert.set_User_Name();
    insert.set_User_Sex();
    str insertstr = "INSERT INTO `User` (User_Name,User_Sex)VALUES('"  + insert.get_User_Name() + "', '" + insert.get_User_Sex() + "') ";
    const char* cinsertstr = insertstr.c_str();
    cout << cinsertstr<<endl<<endl<<endl;
    if (mysql_query(this->conn, cinsertstr)) {
        fprintf(stderr, "mysql_query failed: %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return ;
    }
    system("cls");
    cout <<left<<setw(15)<< "用户ID" << left << setw(15) << "用户姓名" << left << setw(15) << "用户性别" << endl;
    query("User");
    str x; cout << "输入任意键加回车返回主菜单..." << endl; cin >> x; sys;
    return;
}
void sql::insertCar()
{
    Car insert;
    insert.set_Car_Card();
    insert.set_Car_Owner_Name();
    insert.set_Car_Owner_ID();
    str insertstr = "INSERT INTO `Car` (Car_Card,Car_Owner_Name,Car_Owner_ID)VALUES('" + insert.get_Car_Card() + "', '" + insert.get_Car_Owner_Name() + "','"+insert.get_Car_Owner_ID()+"') ";
    const char* cinsertstr = insertstr.c_str();
    cout <<"mysql语句：" << cinsertstr << endl << endl << endl;
    if (mysql_query(this->conn, cinsertstr)) {
        fprintf(stderr, "添加失败，错误原因: %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return;
    }else cout << "插入成功，新表："<<endl;
    cout << left << setw(15) << "车牌号" << left << setw(15) << "车主姓名" << left << setw(15) << "车主ID" << endl;
    query("Car");
    str x; cout << "输入任意键加回车返回主菜单..." << endl; cin >> x; sys;
    return;
}
void sql::delUser()
{
    sys;
    cout << "输入你要删除的用户的信息:\n(id(只能ID因为生活中可能存在同名存在),在定义数据库中进行了外键约束：当车主里面有这个人时删除失败):";
    str deluser; cin >> deluser;
    str delstr = "DELETE FROM User where User_ID='"+deluser+"';";
    const char* cdelstr = delstr.c_str();
    cout << cdelstr << endl << endl << endl;
    if (mysql_query(this->conn, cdelstr)) {
        fprintf(stderr, "----这个ID存在于汽车表，受外键约束，删除失败。自动返回菜单----\n\n %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return;
    }
    sys;
    cout << "新表：" << endl;
    cout << left << setw(15) << "用户ID" << left << setw(15) << "用户姓名" << left << setw(15) << "用户性别" << endl;
    query("User");

}
void sql::delCar()
{
    sys;
    cout << "输入你要删除的车牌号(当它存在停车场订单时会删除失败):";
    str delcar; cin >> delcar;
    str delstr = "DELETE FROM Car where Car_Card='" + delcar + "';";
    const char* cdelstr = delstr.c_str();
    cout << cdelstr << endl << endl << endl;
    if (mysql_query(this->conn, cdelstr)) {
        fprintf(stderr, "----这个ID存在于订单未结算，受外键约束，删除失败。自动返回菜单----\n\n %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return;
    }
    sys;
    cout << "新表：" << endl;
    cout << left << setw(15) << "车牌号" << left << setw(15) << "车主姓名" << left << setw(15) << "车主ID" << endl;
    query("Car");

}
void sql::ModCar()
{
    sys;
    Car change; str CarCard;
    cout << "-----------------------------------------------------" << endl;
    cout << "----------------修改功能选择:(需要车牌号才能改)------" << endl;
    cout << "----------------修改车主(有主键唯一性约束)-----------" << endl;
    cout << "----------------目标用户需要存在才能修改-------------" << endl;
    cout << "----------------------------------------------------" << endl;
    {
        cout << "输入要修改的车牌号：";cin>>CarCard;
        cout << "新"; change.set_Car_Owner_Name();
        cout << "新"; change.set_Car_Owner_ID();
        str to = "UPDATE `Car`  \nSET Car_Owner_Name = '"+change.get_Car_Owner_Name() +"', Car_Owner_ID = "+change.get_Car_Owner_ID() + "\n WHERE Car_Card = '"+CarCard+"'; ";
        cout << "mysql语句为：" << endl << to << endl << endl;
        chg(to);
        cout <<endl<<endl<< left << setw(15) << "车牌号" << left << setw(15) << "车主姓名" << left << setw(15) << "车主ID" << endl;
        query("Car"); 
        cout << endl << endl;
    }
    int x; cout << "输入数字加回车返回主菜单..." << endl; cin >> x; sys;
    return;
}
void sql::ModUser()
{
    int c = INT_MAX; User change; str ObjID;
    cout << " ----------------------------------------------------" << endl;
    cout << " ---------------修改功能选择:(需要ID才能改)----------" << endl;
    cout << "--------------1.修改用户姓名-------------------------" << endl;
    cout << "--------------2.修改用户性别-------------------------" << endl;
    cout << " ----------------------------------------------------" << endl;
    cout << "修改功能选择:";
    cin >> c;
    switch (c)
    {
    case 1: { cout << "输入要修改的ID:"; cin >> ObjID;cout<<"新"; change.set_User_Name();
        str to = "UPDATE `User` SET User_Name='" + change.get_User_Name() + "' WHERE User_ID='" + ObjID + "';";
        cout << "当前mysql更新语句：" << to << endl;
        chg(to); cout << endl << "修改成功，新表：" << endl;
        cout << left << setw(15) << "用户ID" << left << setw(15) << "用户姓名" << left << setw(15) << "用户性别" << endl;
        query("User");
        break;
    }
    case 2: { cout << "输入要修改的ID:"; cin >> ObjID; cout << "新"; change.set_User_Sex();
        str to = "UPDATE `User` SET User_Sex='" + change.get_User_Sex() + "' WHERE User_ID='" + ObjID + "';";
        cout << "当前mysql更新语句：" << to << endl;
        chg(to); cout << endl << "修改成功，新表：" << endl;
        cout << left << setw(15) << "用户ID" << left << setw(15) << "用户姓名" << left << setw(15) << "用户性别" << endl;
        query("User");
        break;
    }
    default:break;
    }
    int x; cout << "输入数字加回车返回主菜单..." << endl; cin >> x; sys;
    return;
}
int sql::chg(str chgstr)
{

    const char* cchgstr = chgstr.c_str();
    // 执行UPDATE
    if (mysql_query(this->conn, cchgstr)) {
        fprintf(stderr, "数据库更新失败: %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return 1;
    }
}
int sql::upinpark(str carc)
{
    str update = "UPDATE `Parking` SET Cur_Car_Card = '" + carc + "' where Cur_Car_Card = '' LIMIT 1; ";
    const char* cupdate = update.c_str();
    //cout << endl << "当前mysql查询指令：" << cupdate << endl << endl << endl;
        // 执行更新park
        if (mysql_query(this->conn, cupdate)) {
            fprintf(stderr, "无法停车，没有空车位 %s\n", mysql_error(this->conn));
            return 1;
        }
            str upbill = "INSERT INTO `Bill` (Begin_Time,End_Time,Cost,Car_Card,State,Park_Index)VALUES(NOW(),NOW(),0,'" + carc + "',0,(SELECT Park_Index FROM `Parking` WHERE Parking.Cur_Car_Card = Bill.Car_Card LIMIT 1));";
            const char* cupbill = upbill.c_str();
            //cout << cupbill;
            // 执行更新Bill
            if (mysql_query(this->conn, cupbill)) {
                fprintf(stderr, "Bill增加失败 %s\n", mysql_error(this->conn));
                return 1;
            }
            str afuppark = "UPDATE `Bill` SET Park_Index=0 WHERE Park_Index is NULL";
            const char* cafuppark = afuppark.c_str();
            if (mysql_query(this->conn, cafuppark)) {
                fprintf(stderr, "%s\n", mysql_error(this->conn));
                return 1;
            }
            return 0;
}
int sql::upoutpark(str carc)
{
    str update = "UPDATE `Parking` SET Cur_Car_Card = '' where Cur_Car_Card = '" + carc + " ' LIMIT 1; ";
    const char* cupdate = update.c_str();
    // 执行更新park
    if (mysql_query(this->conn, cupdate)) {
        fprintf(stderr, "车库删车失败 %s\n", mysql_error(this->conn));
        return 1;
    }
    //更新开走时间：
    str uptime = "UPDATE `Bill` SET End_Time=NOW() where Car_Card='" + carc + "' and State=0;";
    const char* cuptime = uptime.c_str();
    if (mysql_query(this->conn, cuptime)) {
        fprintf(stderr, "时间更新失败 %s\n", mysql_error(this->conn));
        return 1;
    }

    //结账
    str upbillcost = "UPDATE `Bill` SET Cost = DATEDIFF(End_Time, Begin_Time) * 10  where Car_Card='" + carc + "' and State=0;";
    const char* cupbillcost = upbillcost.c_str();
    if (mysql_query(this->conn, cupbillcost)) {
        fprintf(stderr, "账单更新失败 %s\n", mysql_error(this->conn));
        return 1;
    }

    str ouc = "SELECT Cost FROM `Bill` where Car_Card='" + carc + "' and State=0;";
    const char* couc = ouc.c_str();
    if (mysql_query(this->conn,couc )) {
        fprintf(stderr, "账单输出失败 %s\n", mysql_error(this->conn));
        return 1;
    }
    cout << "-------------------------" << endl;
    cout << "出库成功！！应付车费：";

    {
        // 获取结果集
        this->res = mysql_store_result(this->conn);
        int column_count = mysql_field_count(this->conn);

        while ((this->row = mysql_fetch_row(this->res)) != NULL) {
            // 输出结果
            for (int i = 0; i < column_count; ++i)
            {
                cout << left << setw(14) << this->row[i] << " ";
            }
            cout << endl;
        }
    }
    cout << "-------------------------" << endl;


    str upsta = "UPDATE `Bill` SET State =1 where Car_Card='" + carc + "' and State=0;";
    const char* cupsta = upsta.c_str();
    if (mysql_query(this->conn, cupsta)) {
        fprintf(stderr, "状态更新失败 %s\n", mysql_error(this->conn));
        return 1;
    }

}