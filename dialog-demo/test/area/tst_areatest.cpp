#include <QString>
#include <QtTest>

class AreaTest : public QObject
{
    Q_OBJECT

public:
    AreaTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1_data();
    void testCase1();
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

void AreaTest::testCase1_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void AreaTest::testCase1()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(AreaTest)

#include "tst_areatest.moc"
