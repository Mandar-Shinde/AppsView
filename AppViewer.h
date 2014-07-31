
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtCore>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "ui_TSEApps.h"
#include "FileDownload.h"
#include "PLog.h"

#define PATH_TSEICON_CACHE "/tmp/Cache/"

#define LOADING_ICON_LOADING ":/Res/Resources/loading.png"
#define LOADING_ICON_HOME ":/Res/Resources/home.png"
#define LOADING_ICON_FOLDER ":/Res/Resources/group.png"
#define SIZE_SPACING  40
#define SIZE_GRID_X	 150
#define SIZE_GRID_Y	 70
#define VIEWER_ITEMS_VISIBLE	 1
#define VIEWER_ITEMS_HIDDEN	 2

extern PLog* logger;

using namespace Ui;

class AppItem
{
public :
	AppItem(){}
	AppItem(QString name,QString id,QString group,QString icon);
	QString appName;
	QString appID;
	QString appGroup;
	QString appIcon;
	QString appIconLocal;
	QString appDescription;
};

class AppViewer : public QDialog , public TSEAppDialog
{
    Q_OBJECT

public:
    AppViewer();
    void init();
    void initMenu();
    void initView();
    void insert(AppItem  item);
    void remove();
    void reset(int a=0);

    QList<AppItem> mAppsCollection;
    QNetworkAccessManager m_networkAccessManagerIconApp;
   	QNetworkRequest* m_networkRequest;
   	QNetworkReply* m_networkReply;

   	QStringList mGroup;

   	FileDownload* mFileDownload;

   	int mspacing;
   	int mviewX;
   	int mviewY;

private slots:
   		void downloadFinished(QNetworkReply *reply);
   		void slot_setGrid();
   		void slot_setList();
   		void slot_setUniform();
   		void slot_setSpread();
   		void slot_menu_select();
   		void slot_reset();
   		void slot_viewitem_click(QListWidgetItem*);
   		void setFilter(QString filter);
   		void slot_Exiting();
   		void slot_updateUI(QString fname);

private:
    QLabel *createLabel(const QString &text);
};




#endif
