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
    cout << "���ݿ��ѶϿ�����" << endl;
}
void sql::fun()
{
    sys;
    while(1){
        sys;
        int x = INT_MAX;
        cout << "-----------------------------------------------------" << endl;
        cout << "--------------ͣ��������ϵͳ����ѡ��:----------------" << endl;
        cout << "--------------1.��������-----------------------------" << endl;
        cout << "--------------2.ɾ������-----------------------------" << endl;
        cout << "--------------3.�޸�����-----------------------------" << endl;
        cout << "--------------4.��ѯ����-----------------------------" << endl;
        cout << "--------------5.��������-----------------------------" << endl;
        cout << "--------------6.�˳�ϵͳ-----------------------------" << endl;
        cout << "-------------(ͣ����ʮԪһ��)------------------------" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "���빦��:";
        cin >> x;
        switch (x)
        {
        case 1:Add(); break;
        case 2:Del(); break;
        case 3:Mod(); break;
        case 4:Que(); break;
        case 5:Bil(); break;
        case 6:return; break;
        default: { cout << "û�иù���"<<endl << endl; break; }
        }
    }
}
int sql::initsql()
{
    {
        str loc,user,pswd,sqlname;
        std::cout << "������������"; std::cin >> loc;
        std::cout << "�����û�����"; std::cin >> user;
        std::cout << "�������룺"; std::cin >> pswd;
        std::cout << "������������"; std::cin >> sqlname;
        const char* cloc = loc.c_str();
        const char* cuser = user.c_str();
        const char* cpswd = pswd.c_str();
        const char* csqlname = sqlname.c_str();
        //localhost
        //root
        // Qq147258.
        // sql_test
        // ��ʼ�����ӻ���
        this->conn = mysql_init(NULL);
        if (this->conn == NULL) {
            fprintf(stderr, "mysql_init failed\n");
            return 1;
        }

        // �������ݿ�
        if (mysql_real_connect(this->conn, cloc ,cuser, cpswd, csqlname, 0, NULL, 0) == NULL) {
            fprintf(stderr, "mysql_real_connect failed: %s\n", mysql_error(this->conn));
            mysql_close(this->conn);
            return 1;
        }

        // �����ַ���Ϊutf8mb4
        if (mysql_set_character_set(this->conn, "utf8mb4") != 0) {
            fprintf(stderr, "mysql_set_character_set failed: %s\n", mysql_error(this->conn));
            mysql_close(this->conn);
            return 1;
        }

        printf("mysql apiʹ�õ�Ĭ�ϱ���: %s\n", mysql_character_set_name(this->conn));
    }
}
void sql::closesql()
{
    // �ͷŽ�������ر�����
    mysql_free_result(this->res);
    mysql_close(this->conn);
}
int sql::query(str Obj)
{

    str questr = "SELECT * FROM "+Obj;
    const char* cquestr = questr.c_str();
    // ִ�в�ѯ
    if (mysql_query(this->conn, cquestr)) {
        fprintf(stderr, "mysql_query failed: %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return 1;
    }
    // ��ȡ�����
    this->res = mysql_store_result(this->conn);
    int column_count = mysql_field_count(this->conn);

    while ((this->row = mysql_fetch_row(this->res)) != NULL) {
        // ������
        for(int i=0;i<column_count;++i)
        {
            cout <<left<<setw(14)<< this->row[i]<<" ";
        }
        cout<<endl;
    }
    cout <<endl<<"��ǰmysql��ѯָ�" << cquestr << endl << endl << endl;

}
void sql::Add()
{
    int a = INT_MAX;
    cout << " ----------------------------------------------------" << endl;
    cout << " ---------------���ӹ���ѡ��:------------------------" << endl;
    cout << "--------------1.�����û���Ϣ-------------------------" << endl;
    cout << "--------------2.���ӳ�����Ϣ-------------------------" << endl;
    cout << "--------------�������˳�ϵͳ-------------------------" << endl;
    cout << " ----------------------------------------------------" << endl;
    cout << "���ӹ���ѡ��:";
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
    cout << "----------------���ӹ���ѡ��:------------------------" << endl;
    cout << "--------------1.ɾ���û���Ϣ-------------------------" << endl;
    cout << "--------------2.ɾ��������Ϣ-------------------------" << endl;
    cout << "--------------�������˳�ϵͳ-------------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "ɾ������ѡ��:";
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
    cout << "----------------�޸Ĺ���ѡ��:------------------------" << endl;
    cout << "--------------1.�޸��û���Ϣ-------------------------" << endl;
    cout << "--------------2.�޸ĳ�����Ϣ-------------------------" << endl;
    cout << "--------------�������֣��������˵�-------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "�޸Ĺ���ѡ��:";
    cin >> a;
    sys;
    switch (a)
    {
    case 1: { sys; ModUser(); break; }
    case 2: { sys; ModCar(); break; }
    default:
        break;
    }
    char x; cout << "����������ӻس��������˵�..." << endl; cin >> x; sys;
    return;
}
void sql::Que()
{
    int a ;
    cout << " ----------------------------------------------------" << endl;
    cout << " ---------------��ѯ����ѡ��:------------------------" << endl;
    cout << "--------------1.��ѯ�û�-----------------------------" << endl;
    cout << "--------------2.��ѯ����-----------------------------" << endl;
    cout << "--------------3.��ѯͣ����---------------------------" << endl;
    cout << "--------------4.��ѯ����-----------------------------" << endl;
    cout << "--------------�������֣�����-------------------------" << endl;
    cout << " ----------------------------------------------------" << endl;
    cout << "��ѯ����ѡ��:";
    cin >> a;
    sys;
    switch (a)
    {
    case 1:
    {
        {
            cout << "------------------------------------------------------" << endl;
            cout << "--------------1.��ѯȫ���û�--------------------------" << endl;
            cout << "--------------2.��ѯĳ���û�--------------------------" << endl;
            cout << "--------------����������------------------------------" << endl;
            cout << "------------------------------------------------------" << endl;
            int x = INT_MAX; cout << "������ѡ��Ĺ��ܣ�"; cin >> x;
            switch (x)
            {
            case 1:sys; query("User"); break;
            case 2: {
                sys; cout << "������Ҫ��ѯ���û���������ID(���ֲ�һ��Ψһ��ID��Ψһ��):"; str Obj; cin >> Obj;
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
            cout << "--------------1.��ѯȫ����----------------------------" << endl;
            cout << "--------------2.��ѯĳ����----------------------------" << endl;
            cout << "--------------����������------------------------------" << endl;
            cout << "------------------------------------------------------" << endl;
            int x = INT_MAX; cout << "������ѡ��Ĺ��ܣ�"; cin >> x;
            switch (x)
            {
            case 1: {
                sys;
                cout << left << setw(15) << "���ƺ�" << left << setw(15) << "��������" << left << setw(15) << "����ID" << endl;
                query("Car"); break;
                    }
            case 2: {
                sys; cout << "������Ҫ��ѯ�ĳ��ƺš������������߳���ID(���ƺŶ�Ӧ������Ϣ��Ψһ�ģ���֮δ��):"; str Obj; cin >> Obj;
                cout << left << setw(15) << "���ƺ�" << left << setw(15) << "��������" << left << setw(15) << "����ID" << endl;
                int flag = 0; for (auto s : Obj) { if (s - 48 >= 9) { flag++; break; } }
                flag!=0? query("Car WHERE Car_Card='" + Obj+"' or Car_Owner_Name='"+Obj+"'"):query("Car WHERE Car_Owner_ID="+Obj);
                break;
                     }
            }
        }
        break;
    }
    case 3: {
        cout << left << setw(15) << "��λ��" << left << setw(15) << "��ǰ��λͣ�ų���ID" << endl;
        query("Parking");
        break;
    }
    case 4:
    {
        cout << left << setw(15) << "����ID" <<
            left << setw(20) << "��ʼʱ��" << left << setw(20) << "����ʱ��" <<
            left << setw(15) << "ͣ����" << left << setw(15) << "���ƺ�" << left << setw(15) << "����״̬" <<left<<setw(15)<<"��ͣ��λ" << endl;
        query("Bill");
        break;
    }
    default: { break; }
    }
    char x; cout << "����������ӻس����ز˵�..." << endl; cin >> x; sys;
    return;
}
void sql::Bil()
{
        sys;
        int x = INT_MAX;
        cout << "-----------------------------------------------------" << endl;
        cout << "--------------ͣ��������ϵͳ����ѡ��:----------------" << endl;
        cout << "--------------1.ͣ�복��-----------------------------" << endl;
        cout << "--------------2.���߳���(˳�����)-------------------" << endl;
        cout << "--------------����:�˳�ϵͳ--------------------------" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "���빦��:";
        cin >> x;
        switch (x)
        {
        case 1: {

            cout << "������Ҫͣ�ŵĳ��ĳ��ƺ�:";
            str incar; cin >> incar;
            cout << "����Ҫͣ�ŵĳ�����Ϣ��" << endl;
            cout << left << setw(15) << "���ƺ�" << left << setw(15) << "��������" << left << setw(15) << "����ID" << endl;
            query("Car WHERE Car_Card='" + incar + "'");
            cout << "����1ȷ��ͣ��";
            int cont = INT_MAX; if (cin >> cont && cont == 1) {
                sys;
                upinpark(incar);
            }
            break;
        }
        case 2: {
            cout << "������Ҫ���ߵĳ��ĳ��ƺ�:";
            str outcar; cin >> outcar;
            cout << "������Ҫ���ߵĳ��Ķ�����" << endl;
            cout << left << setw(15) << "����ID" <<
                left << setw(20) << "��ʼʱ��" << left << setw(20) << "����ʱ��" <<
                left << setw(15) << "ͣ����" << left << setw(15) << "���ƺ�" << left << setw(15) << "����״̬" << left << setw(15) << "��ͣ��λ" << endl;
            query("Bill WHERE Car_Card='" + outcar + "' and state=0"); 
            cout << "����1ȷ������";
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
        cout << left << setw(15) << "��λ��" << left << setw(15) << "��ǰ��λͣ�ų���ID" << endl;
        query("Parking");
        cout << "||||||||||PS��û��λ��ʾ��λΪ0||||||||||" << endl;
        cout << left << setw(15) << "����ID" <<
            left << setw(20) << "��ʼʱ��" << left << setw(20) << "����ʱ��" <<
            left << setw(15) << "ͣ����" << left << setw(15) << "���ƺ�" << left << setw(15) << "����״̬" << left << setw(15) << "��ͣ��λ" << endl;
        query("Bill");
        str c; cout << "����������ӻس��������˵�..." << endl; cin >> c; sys;
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
    cout <<left<<setw(15)<< "�û�ID" << left << setw(15) << "�û�����" << left << setw(15) << "�û��Ա�" << endl;
    query("User");
    str x; cout << "����������ӻس��������˵�..." << endl; cin >> x; sys;
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
    cout <<"mysql��䣺" << cinsertstr << endl << endl << endl;
    if (mysql_query(this->conn, cinsertstr)) {
        fprintf(stderr, "���ʧ�ܣ�����ԭ��: %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return;
    }else cout << "����ɹ����±�"<<endl;
    cout << left << setw(15) << "���ƺ�" << left << setw(15) << "��������" << left << setw(15) << "����ID" << endl;
    query("Car");
    str x; cout << "����������ӻس��������˵�..." << endl; cin >> x; sys;
    return;
}
void sql::delUser()
{
    sys;
    cout << "������Ҫɾ�����û�����Ϣ:\n(id(ֻ��ID��Ϊ�����п��ܴ���ͬ������),�ڶ������ݿ��н��������Լ���������������������ʱɾ��ʧ��):";
    str deluser; cin >> deluser;
    str delstr = "DELETE FROM User where User_ID='"+deluser+"';";
    const char* cdelstr = delstr.c_str();
    cout << cdelstr << endl << endl << endl;
    if (mysql_query(this->conn, cdelstr)) {
        fprintf(stderr, "----���ID�����������������Լ����ɾ��ʧ�ܡ��Զ����ز˵�----\n\n %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return;
    }
    sys;
    cout << "�±�" << endl;
    cout << left << setw(15) << "�û�ID" << left << setw(15) << "�û�����" << left << setw(15) << "�û��Ա�" << endl;
    query("User");

}
void sql::delCar()
{
    sys;
    cout << "������Ҫɾ���ĳ��ƺ�(��������ͣ��������ʱ��ɾ��ʧ��):";
    str delcar; cin >> delcar;
    str delstr = "DELETE FROM Car where Car_Card='" + delcar + "';";
    const char* cdelstr = delstr.c_str();
    cout << cdelstr << endl << endl << endl;
    if (mysql_query(this->conn, cdelstr)) {
        fprintf(stderr, "----���ID�����ڶ���δ���㣬�����Լ����ɾ��ʧ�ܡ��Զ����ز˵�----\n\n %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return;
    }
    sys;
    cout << "�±�" << endl;
    cout << left << setw(15) << "���ƺ�" << left << setw(15) << "��������" << left << setw(15) << "����ID" << endl;
    query("Car");

}
void sql::ModCar()
{
    sys;
    Car change; str CarCard;
    cout << "-----------------------------------------------------" << endl;
    cout << "----------------�޸Ĺ���ѡ��:(��Ҫ���ƺŲ��ܸ�)------" << endl;
    cout << "----------------�޸ĳ���(������Ψһ��Լ��)-----------" << endl;
    cout << "----------------Ŀ���û���Ҫ���ڲ����޸�-------------" << endl;
    cout << "----------------------------------------------------" << endl;
    {
        cout << "����Ҫ�޸ĵĳ��ƺţ�";cin>>CarCard;
        cout << "��"; change.set_Car_Owner_Name();
        cout << "��"; change.set_Car_Owner_ID();
        str to = "UPDATE `Car`  \nSET Car_Owner_Name = '"+change.get_Car_Owner_Name() +"', Car_Owner_ID = "+change.get_Car_Owner_ID() + "\n WHERE Car_Card = '"+CarCard+"'; ";
        cout << "mysql���Ϊ��" << endl << to << endl << endl;
        chg(to);
        cout <<endl<<endl<< left << setw(15) << "���ƺ�" << left << setw(15) << "��������" << left << setw(15) << "����ID" << endl;
        query("Car"); 
        cout << endl << endl;
    }
    int x; cout << "�������ּӻس��������˵�..." << endl; cin >> x; sys;
    return;
}
void sql::ModUser()
{
    int c = INT_MAX; User change; str ObjID;
    cout << " ----------------------------------------------------" << endl;
    cout << " ---------------�޸Ĺ���ѡ��:(��ҪID���ܸ�)----------" << endl;
    cout << "--------------1.�޸��û�����-------------------------" << endl;
    cout << "--------------2.�޸��û��Ա�-------------------------" << endl;
    cout << " ----------------------------------------------------" << endl;
    cout << "�޸Ĺ���ѡ��:";
    cin >> c;
    switch (c)
    {
    case 1: { cout << "����Ҫ�޸ĵ�ID:"; cin >> ObjID;cout<<"��"; change.set_User_Name();
        str to = "UPDATE `User` SET User_Name='" + change.get_User_Name() + "' WHERE User_ID='" + ObjID + "';";
        cout << "��ǰmysql������䣺" << to << endl;
        chg(to); cout << endl << "�޸ĳɹ����±�" << endl;
        cout << left << setw(15) << "�û�ID" << left << setw(15) << "�û�����" << left << setw(15) << "�û��Ա�" << endl;
        query("User");
        break;
    }
    case 2: { cout << "����Ҫ�޸ĵ�ID:"; cin >> ObjID; cout << "��"; change.set_User_Sex();
        str to = "UPDATE `User` SET User_Sex='" + change.get_User_Sex() + "' WHERE User_ID='" + ObjID + "';";
        cout << "��ǰmysql������䣺" << to << endl;
        chg(to); cout << endl << "�޸ĳɹ����±�" << endl;
        cout << left << setw(15) << "�û�ID" << left << setw(15) << "�û�����" << left << setw(15) << "�û��Ա�" << endl;
        query("User");
        break;
    }
    default:break;
    }
    int x; cout << "�������ּӻس��������˵�..." << endl; cin >> x; sys;
    return;
}
int sql::chg(str chgstr)
{

    const char* cchgstr = chgstr.c_str();
    // ִ��UPDATE
    if (mysql_query(this->conn, cchgstr)) {
        fprintf(stderr, "���ݿ����ʧ��: %s\n", mysql_error(this->conn));
        //mysql_close(this->conn);
        return 1;
    }
}
int sql::upinpark(str carc)
{
    str update = "UPDATE `Parking` SET Cur_Car_Card = '" + carc + "' where Cur_Car_Card = '' LIMIT 1; ";
    const char* cupdate = update.c_str();
    //cout << endl << "��ǰmysql��ѯָ�" << cupdate << endl << endl << endl;
        // ִ�и���park
        if (mysql_query(this->conn, cupdate)) {
            fprintf(stderr, "�޷�ͣ����û�пճ�λ %s\n", mysql_error(this->conn));
            return 1;
        }
            str upbill = "INSERT INTO `Bill` (Begin_Time,End_Time,Cost,Car_Card,State,Park_Index)VALUES(NOW(),NOW(),0,'" + carc + "',0,(SELECT Park_Index FROM `Parking` WHERE Parking.Cur_Car_Card = Bill.Car_Card LIMIT 1));";
            const char* cupbill = upbill.c_str();
            //cout << cupbill;
            // ִ�и���Bill
            if (mysql_query(this->conn, cupbill)) {
                fprintf(stderr, "Bill����ʧ�� %s\n", mysql_error(this->conn));
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
    // ִ�и���park
    if (mysql_query(this->conn, cupdate)) {
        fprintf(stderr, "����ɾ��ʧ�� %s\n", mysql_error(this->conn));
        return 1;
    }
    //���¿���ʱ�䣺
    str uptime = "UPDATE `Bill` SET End_Time=NOW() where Car_Card='" + carc + "' and State=0;";
    const char* cuptime = uptime.c_str();
    if (mysql_query(this->conn, cuptime)) {
        fprintf(stderr, "ʱ�����ʧ�� %s\n", mysql_error(this->conn));
        return 1;
    }

    //����
    str upbillcost = "UPDATE `Bill` SET Cost = DATEDIFF(End_Time, Begin_Time) * 10  where Car_Card='" + carc + "' and State=0;";
    const char* cupbillcost = upbillcost.c_str();
    if (mysql_query(this->conn, cupbillcost)) {
        fprintf(stderr, "�˵�����ʧ�� %s\n", mysql_error(this->conn));
        return 1;
    }

    str ouc = "SELECT Cost FROM `Bill` where Car_Card='" + carc + "' and State=0;";
    const char* couc = ouc.c_str();
    if (mysql_query(this->conn,couc )) {
        fprintf(stderr, "�˵����ʧ�� %s\n", mysql_error(this->conn));
        return 1;
    }
    cout << "-------------------------" << endl;
    cout << "����ɹ�����Ӧ�����ѣ�";

    {
        // ��ȡ�����
        this->res = mysql_store_result(this->conn);
        int column_count = mysql_field_count(this->conn);

        while ((this->row = mysql_fetch_row(this->res)) != NULL) {
            // ������
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
        fprintf(stderr, "״̬����ʧ�� %s\n", mysql_error(this->conn));
        return 1;
    }

}