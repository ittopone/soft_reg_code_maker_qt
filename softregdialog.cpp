#include "softregdialog.h"
#include "ui_softregdialog.h"
#include "iconhelper.h"
#include "myhelper.h"
#include "global.h"

SoftRegDialog::SoftRegDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SoftRegDialog)
{
    ui->setupUi(this);

    //关乎界面
    myHelper::FormInCenter(this);

    //安装事件监听器,让标题栏识别鼠标双击
    ui->lab_Title->installEventFilter(this);

    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置窗体关闭时自动释放内存
    this->setAttribute(Qt::WA_DeleteOnClose);
    //设置窗口左上角图标
    //IconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf015), 12);
    //设置关闭按钮图标
    IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d), 10);
    //设置样式
    this->setStyleSheet(".QWidget{border:1px solid #1B89CA;border-radius:0px;}");
    //关联关闭按钮
    this->m_mousePressed = false;
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
    //窗体居中显示
    myHelper::FormInCenter(this);
}

SoftRegDialog::~SoftRegDialog()
{
    delete ui;
}


void SoftRegDialog::mouseMoveEvent(QMouseEvent *e)
{
    if (m_mousePressed && (e->buttons() && Qt::LeftButton))
    {
        this->move(e->globalPos() - m_mousePoint);
        e->accept();
    }
}

void SoftRegDialog::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_mousePressed = true;
        m_mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void SoftRegDialog::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);

    m_mousePressed = false;
}

void SoftRegDialog::on_btnOk_clicked()
{
    QString admin = ui->lineEdit_2->text().trimmed();
    QString pswd = ui->lineEdit_3->text().trimmed();

    if(admin.isNull() || admin.isEmpty())
    {
        myHelper::ShowMessageBoxError(tr("管理人员不能为空！"));
        return;
    }

    if(pswd.isNull() || pswd.isEmpty())
    {
        myHelper::ShowMessageBoxError(tr("授权密码不能为空！"));
        return;
    }

    if(admin != "yujunwu")
    {
        myHelper::ShowMessageBoxError(tr("管理人员错误！"));
        return;
    }

    if(pswd != "yjw785116032493")
    {
        myHelper::ShowMessageBoxError(tr("授权密码错误！"));
        return;
    }

    QString cpuid;
    Global::getCPUID(cpuid);

    cpuid.append("yjw");
    QByteArray byte_array;
    byte_array.append(cpuid);
    qDebug() << tr("about to code to md5:") << byte_array;
    QByteArray hash_byte_array = QCryptographicHash::hash(byte_array, QCryptographicHash::Md5);
    QString md5 = hash_byte_array.toHex();

    qDebug() << tr("md5:") << md5;

    ui->lineEdit->setText(md5);
}
