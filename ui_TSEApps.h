/********************************************************************************
** Form generated from reading UI file 'TSEApps.ui'
**
** Created: Fri Jul 25 17:33:08 2014
**      by: Qt User Interface Compiler version 4.6.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSEAPPS_H
#define UI_TSEAPPS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TSEAppDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QWidget *w_explorer_top;
    QPushButton *bu_rdpSetting;
    QListWidget *l_menu;
    QVBoxLayout *verticalLayout_6;
    QWidget *w_viewer_top;
    QLineEdit *e_search;
    QLabel *label;
    QPushButton *bu_grid;
    QPushButton *bu_list;
    QPushButton *bu_spread;
    QPushButton *bu_uniform;
    QPushButton *bu_reset;
    QListWidget *l_viewer;
    QWidget *w_statusbar;

    void setupUi(QDialog *TSEAppDialog)
    {
        if (TSEAppDialog->objectName().isEmpty())
            TSEAppDialog->setObjectName(QString::fromUtf8("TSEAppDialog"));
        TSEAppDialog->resize(786, 549);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        TSEAppDialog->setFont(font);
        TSEAppDialog->setWindowOpacity(1);
        gridLayout = new QGridLayout(TSEAppDialog);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        widget = new QWidget(TSEAppDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 139, 199);"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(14, 8, 223, 35));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Res/Resources/thinspace.png")));
        label_2->setScaledContents(true);

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
        w_explorer_top = new QWidget(TSEAppDialog);
        w_explorer_top->setObjectName(QString::fromUtf8("w_explorer_top"));
        w_explorer_top->setMinimumSize(QSize(0, 35));
        bu_rdpSetting = new QPushButton(w_explorer_top);
        bu_rdpSetting->setObjectName(QString::fromUtf8("bu_rdpSetting"));
        bu_rdpSetting->setGeometry(QRect(146, 6, 101, 23));

        verticalLayout_8->addWidget(w_explorer_top);

        l_menu = new QListWidget(TSEAppDialog);
        l_menu->setObjectName(QString::fromUtf8("l_menu"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(l_menu->sizePolicy().hasHeightForWidth());
        l_menu->setSizePolicy(sizePolicy);
        l_menu->setFrameShadow(QFrame::Plain);

        verticalLayout_8->addWidget(l_menu);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        w_viewer_top = new QWidget(TSEAppDialog);
        w_viewer_top->setObjectName(QString::fromUtf8("w_viewer_top"));
        w_viewer_top->setMinimumSize(QSize(0, 35));
        w_viewer_top->setMaximumSize(QSize(16777215, 16777215));
        w_viewer_top->setAutoFillBackground(false);
        e_search = new QLineEdit(w_viewer_top);
        e_search->setObjectName(QString::fromUtf8("e_search"));
        e_search->setGeometry(QRect(72, 8, 191, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(e_search->sizePolicy().hasHeightForWidth());
        e_search->setSizePolicy(sizePolicy1);
        label = new QLabel(w_viewer_top);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(2, 12, 69, 16));
        bu_grid = new QPushButton(w_viewer_top);
        bu_grid->setObjectName(QString::fromUtf8("bu_grid"));
        bu_grid->setEnabled(true);
        bu_grid->setGeometry(QRect(272, 6, 25, 25));
        sizePolicy1.setHeightForWidth(bu_grid->sizePolicy().hasHeightForWidth());
        bu_grid->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Res/Resources/grid.png"), QSize(), QIcon::Normal, QIcon::Off);
        bu_grid->setIcon(icon);
        bu_grid->setIconSize(QSize(14, 14));
        bu_grid->setAutoDefault(false);
        bu_grid->setDefault(false);
        bu_grid->setFlat(false);
        bu_list = new QPushButton(w_viewer_top);
        bu_list->setObjectName(QString::fromUtf8("bu_list"));
        bu_list->setGeometry(QRect(300, 6, 25, 25));
        sizePolicy1.setHeightForWidth(bu_list->sizePolicy().hasHeightForWidth());
        bu_list->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Res/Resources/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        bu_list->setIcon(icon1);
        bu_list->setIconSize(QSize(14, 14));
        bu_spread = new QPushButton(w_viewer_top);
        bu_spread->setObjectName(QString::fromUtf8("bu_spread"));
        bu_spread->setGeometry(QRect(376, 6, 25, 25));
        sizePolicy1.setHeightForWidth(bu_spread->sizePolicy().hasHeightForWidth());
        bu_spread->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Res/Resources/spread.png"), QSize(), QIcon::Normal, QIcon::Off);
        bu_spread->setIcon(icon2);
        bu_spread->setIconSize(QSize(14, 14));
        bu_uniform = new QPushButton(w_viewer_top);
        bu_uniform->setObjectName(QString::fromUtf8("bu_uniform"));
        bu_uniform->setGeometry(QRect(350, 6, 25, 25));
        sizePolicy1.setHeightForWidth(bu_uniform->sizePolicy().hasHeightForWidth());
        bu_uniform->setSizePolicy(sizePolicy1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Res/Resources/uniform.png"), QSize(), QIcon::Normal, QIcon::Off);
        bu_uniform->setIcon(icon3);
        bu_uniform->setIconSize(QSize(14, 14));
        bu_reset = new QPushButton(w_viewer_top);
        bu_reset->setObjectName(QString::fromUtf8("bu_reset"));
        bu_reset->setGeometry(QRect(404, 6, 25, 25));
        sizePolicy1.setHeightForWidth(bu_reset->sizePolicy().hasHeightForWidth());
        bu_reset->setSizePolicy(sizePolicy1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Res/Resources/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        bu_reset->setIcon(icon4);
        bu_reset->setIconSize(QSize(16, 16));

        verticalLayout_6->addWidget(w_viewer_top);

        l_viewer = new QListWidget(TSEAppDialog);
        l_viewer->setObjectName(QString::fromUtf8("l_viewer"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(l_viewer->sizePolicy().hasHeightForWidth());
        l_viewer->setSizePolicy(sizePolicy2);
        l_viewer->setFrameShadow(QFrame::Plain);
        l_viewer->setAutoScrollMargin(16);
        l_viewer->setResizeMode(QListView::Adjust);
        l_viewer->setSpacing(10);
        l_viewer->setUniformItemSizes(false);
        l_viewer->setSortingEnabled(true);

        verticalLayout_6->addWidget(l_viewer);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout);

        w_statusbar = new QWidget(TSEAppDialog);
        w_statusbar->setObjectName(QString::fromUtf8("w_statusbar"));
        w_statusbar->setMinimumSize(QSize(20, 20));

        verticalLayout->addWidget(w_statusbar);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(TSEAppDialog);

        QMetaObject::connectSlotsByName(TSEAppDialog);
    } // setupUi

    void retranslateUi(QDialog *TSEAppDialog)
    {
        TSEAppDialog->setWindowTitle(QApplication::translate("TSEAppDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        bu_rdpSetting->setText(QApplication::translate("TSEAppDialog", "RDP Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TSEAppDialog", "Search", 0, QApplication::UnicodeUTF8));
        bu_grid->setText(QString());
        bu_list->setText(QString());
        bu_spread->setText(QString());
        bu_uniform->setText(QString());
        bu_reset->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TSEAppDialog: public Ui_TSEAppDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSEAPPS_H
