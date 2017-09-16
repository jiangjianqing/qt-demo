#include <QString>
#include <QtTest>

#include "../../functions/area.h"

//重要：必须将Area对象声明为metatype，这样所有基于模板的函数才都可以使用Area
//不将声明放入 area.h中是为了保证area.h的纯c++特性

Q_DECLARE_METATYPE(Area)

class AreaTest : public QObject
{
    Q_OBJECT

public:
    AreaTest();

private Q_SLOTS://测试槽
    void initTestCase();
    void cleanupTestCase();
    void toArea_data();
    void toArea();
    void testBenchmark();
};

AreaTest::AreaTest()
{
}

void AreaTest::initTestCase()
{
}

void AreaTest::cleanupTestCase()
{
}

void AreaTest::toArea_data()
{
    //定义测试数据列
    QTest::addColumn<Area>("area");
    QTest::addColumn<double>("r");
    //建立测试数据
    QTest::newRow("1") <<Area(1)<<3.14; //Area被声明为metatype，不再需要使用new来分配
    QTest::newRow("2") <<Area(2)<<12.56;
    QTest::newRow("3") <<Area(3)<<28.26;
}

void AreaTest::toArea()
{
    QFETCH(Area, area);
    QFETCH(double, r);
    //判断double数据是否相等的方式不能用 = 号
    QVERIFY2(qAbs(area.countArea()-r)<0.0000001, "Failure");
}

void AreaTest::testBenchmark(){
    QString str("heLLO");
    //用于性能测试的代码
    QBENCHMARK{
        str.toLower();
    }
    QVERIFY2(true,"Failure");
}

QTEST_APPLESS_MAIN(AreaTest)

#include "tst_areatest.moc"
