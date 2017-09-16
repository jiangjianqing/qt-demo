#include <QString>
#include <QtTest>

class StringTest : public QObject
{
    Q_OBJECT

public:
    StringTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testToLower_data();
    void testToLower();
};

StringTest::StringTest()
{
}

void StringTest::initTestCase()
{
}

void StringTest::cleanupTestCase()
{
}

//数据驱动测试时用于提供数据的方法，后缀_data是约定,不能改变
void StringTest::testToLower_data()
{
    //创建测试数据列信息
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");
    //添加测试数据行,lower、mixed代表测试数据行的名称，后面为Column的数据，有几个Column就加入几个参数
    QTest::newRow("lower") << "hello" << "hello";
    QTest::newRow("mixed") << "heLLO" << "hello";
    QTest::newRow("upper") << "HELLO" << "hello";
}

void StringTest::testToLower()
{
    QFETCH(QString, string);
    QFETCH(QString, result);
    QCOMPARE(string.toLower(),result);//转为lower进行对比,确保所有测试数据都通过测试
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(StringTest)

#include "tst_stringtest.moc"
