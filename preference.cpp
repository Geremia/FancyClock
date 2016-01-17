#include <QSettings>
#include "preference.h"
#include "ui_preference.h"

Preference::Preference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);

    QSettings sts;
    ui->colorBox->setCurrentIndex(sts.value("Color").toInt());

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Preference::onAccepted);
}

Preference::~Preference()
{
    delete ui;
}

void Preference::onAccepted()
{
    QSettings sts;
    sts.setValue("Color",ui->colorBox->currentIndex());
    this->accept();
}
