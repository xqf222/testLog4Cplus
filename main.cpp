#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 查看数据库驱动名字
    qDebug()<<QSqlDatabase::drivers();
    // 加载驱动mysql数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //本机数据库
    db.setHostName("192.168.1.21");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("aioplat");
    db.setPort(3306);
    if(!db.open())
    {
        qDebug()<< "服务器连接失败，请稍后重新尝试";
    }
    else
    {
        qDebug()<< "服务器连接成功，进行后续数据库增删改查操作";
    }
    // 关闭数据库
    db.close();
    return a.exec();
}
