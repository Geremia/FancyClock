/********************************************************************************
** Form generated from reading UI file 'preference.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCE_H
#define UI_PREFERENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Preference
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *colorBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Preference)
    {
        if (Preference->objectName().isEmpty())
            Preference->setObjectName(QStringLiteral("Preference"));
        Preference->resize(184, 76);
        formLayout = new QFormLayout(Preference);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(Preference);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        colorBox = new QComboBox(Preference);
        colorBox->setObjectName(QStringLiteral("colorBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, colorBox);

        buttonBox = new QDialogButtonBox(Preference);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(1, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(Preference);
        QObject::connect(buttonBox, SIGNAL(rejected()), Preference, SLOT(reject()));

        QMetaObject::connectSlotsByName(Preference);
    } // setupUi

    void retranslateUi(QDialog *Preference)
    {
        Preference->setWindowTitle(QApplication::translate("Preference", "Dialog", 0));
        label->setText(QApplication::translate("Preference", "Color:", 0));
        colorBox->clear();
        colorBox->insertItems(0, QStringList()
         << QApplication::translate("Preference", "Black", 0)
         << QApplication::translate("Preference", "White", 0)
         << QApplication::translate("Preference", "Green", 0)
         << QApplication::translate("Preference", "Red", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class Preference: public Ui_Preference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCE_H
