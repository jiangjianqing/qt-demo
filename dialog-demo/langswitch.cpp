#include "langswitch.h"
#include <QVBoxLayout>
#include <QTranslator>
#include <QApplication>
#include <QDebug>

#include "util/translatorutil.h"

LangSwitch::LangSwitch(QWidget *parent)
    : QWidget(parent)
{
    createScreen();
}

void LangSwitch::createScreen()
{
    combo = new QComboBox;
    combo->addItem("English", "en");			//(a)
    combo->addItem("Chinese", "cn");
    label = new QLabel;
    updateUI();								//设置标签的内容
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(combo, 1);
    layout->addWidget(label, 5);
    setLayout(layout);
    connect(combo, SIGNAL(currentIndexChanged(int)),
          this, SLOT(changeLang(int)));			//(b)
}
//注意：当程序中如果有label是settext方式显示的文字，需要单独写一个刷新Ui的函数，
//然后放在translate的里面，原因目前不详，但是不放的话就会导致显示不了，而且只需要放置在第一个界面刷新的函数
void LangSwitch::updateUI()
{
      label->setText(tr("TXT_HELLO_WORLD", "Hello World"));		//(a)

}

void LangSwitch::changeLang(int index)
{
      QString langCode = combo->itemData(index).toString();		//(a)
      TranslatorUtil::changeTr(langCode);
      //changeTr(langCode);		//读取相应的“.qm”文件
      updateUI();			//刷新标签上的文字
}

LangSwitch::~LangSwitch()
{

}
