//#include <QApplication>
//#include <QHBoxLayout>
//#include <QLabel>
//#include <QListWidget>

#include "AppViewer.h"
#include "FileDownload.h"

AppViewer::AppViewer()
{
	setupUi(this);

	connect(l_menu, SIGNAL(itemSelectionChanged()), this,
			SLOT(slot_menu_select()));
	connect(l_viewer, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
			SLOT(slot_viewitem_click(QListWidgetItem*)));
	connect(bu_grid, SIGNAL(clicked()), this, SLOT(slot_setGrid()));
	connect(bu_list, SIGNAL(clicked()), this, SLOT(slot_setList()));
	connect(bu_uniform, SIGNAL(clicked()), this, SLOT(slot_setUniform()));
	connect(bu_spread, SIGNAL(clicked()), this, SLOT(slot_setSpread()));
	//connect(bu_rdpSetting, SIGNAL(clicked()), this,
	//		SLOT(onbuttonRDPSettings()));
	connect(bu_reset, SIGNAL(clicked()), this, SLOT(slot_reset()));
	connect(e_search, SIGNAL(textChanged(QString)), this,
			SLOT(setFilter(QString)));
	connect(this, SIGNAL(closeEvent()), this, SLOT(slot_Exiting()));

	connect(&m_networkAccessManagerIconApp, SIGNAL(finished(QNetworkReply*)),
			this, SLOT(downloadFinished(QNetworkReply*)));

	mspacing = SIZE_SPACING;
	mviewX = SIZE_GRID_X;
	mviewY = SIZE_GRID_Y;

	setWindowTitle("TSE Apps");

	mFileDownload = new FileDownload();
	connect(mFileDownload, SIGNAL(downloadFinish(QString)), this,
			SLOT(slot_updateUI(QString)));

}

void AppViewer::insert(AppItem item)
{
	mAppsCollection.append(item);
}
void AppViewer::remove()
{

}
void AppViewer::reset(int opt)
{
	for (int i = 0; i < l_viewer->count(); i++)
	{
		if (opt == VIEWER_ITEMS_HIDDEN)
			l_viewer->item(i)->setHidden(true);
		else
			l_viewer->item(i)->setHidden(false);
	}
}

void AppViewer::setFilter(QString filter)
{
	if (filter == "")
	{
		reset(); // show all
		return;
	}
	reset(VIEWER_ITEMS_HIDDEN);
	QList<QListWidgetItem*> itemData = l_viewer->findItems(filter,
			Qt::MatchContains);
	foreach(QListWidgetItem* item , itemData)item->setHidden(false);
	l_viewer->clearSelection();
}
void AppViewer::init()
{
	initMenu();
	initView();
}
void AppViewer::initMenu()
{
//	l_menu->setAlternatingRowColors(true);
	l_menu->setGridSize(QSize(35, 40));
	l_menu->setIconSize(QSize(35, 35));
	l_menu->insertItem(0,
			new QListWidgetItem(QIcon(LOADING_ICON_HOME), "Home"));

	for (int i = 0; i < mAppsCollection.count(); i++)
	{
		QString testGroup = (mAppsCollection.at(i).appGroup);
		if (mGroup.contains(testGroup, Qt::CaseInsensitive) == false)
			mGroup.push_back(testGroup);
	}

	foreach(QString item,mGroup)l_menu->insertItem(1, new QListWidgetItem( QIcon(LOADING_ICON_FOLDER), item));
}
void AppViewer::initView()
{
	l_viewer->clear();
	l_viewer->setViewMode(QListView::IconMode);
	l_viewer->setUpdatesEnabled(true);
	l_viewer->setSortingEnabled(true);
	l_viewer->setDragEnabled(false);

	QDir dir(PATH_TSEICON_CACHE);
	if (!dir.exists())
	{
		dir.mkpath(".");
	}

	for (int i = 0; i < mAppsCollection.count(); i++)
	{
		// search for icons start download if not available
		QString iconName(mAppsCollection.at(i).appIcon);
		int backslash = (iconName.lastIndexOf(QRegExp("/")) + 1);
		int forslash = (iconName.lastIndexOf(QRegExp("\\")) + 1);

		iconName = iconName.mid((backslash > forslash ? backslash : forslash));

		// fullpath
		iconName.prepend(PATH_TSEICON_CACHE);

		bool iconExist = QFileInfo(iconName).exists();
		if (iconExist == true)
		{
			mAppsCollection[i].appIconLocal = iconName;
			logger->Log(DEBUG, "  Cached Icon [%s]", iconName.toUtf8().data());
			l_viewer->insertItem(i,
					new QListWidgetItem(QIcon(mAppsCollection[i].appIconLocal),
							mAppsCollection.at(i).appName));
		}
		else
		{
			l_viewer->insertItem(i,
					new QListWidgetItem(QIcon(LOADING_ICON_LOADING),
							mAppsCollection.at(i).appName));
			QUrl url(mAppsCollection.at(i).appIcon);

			// same thread
			//		m_networkRequest = new QNetworkRequest(url);
			//		m_networkReply = m_networkAccessManagerIconApp.get(*m_networkRequest);

			// threaded
			mFileDownload->download(mAppsCollection.at(i).appIcon, iconName);

			logger->Log(DEBUG, " Download Icon [%s]", iconName.toUtf8().data());
			mAppsCollection[i].appIconLocal = iconName;
		}
		mFileDownload->start();
	}
}

void AppViewer::downloadFinished(QNetworkReply *reply)
{
	logger->Log(DEBUG, " Starting download for [%s]",
			reply->request().url().toString().toUtf8().data());

	if (reply->error() != QNetworkReply::NoError)
	{
		logger->Log(DEBUG, "failed to download icon ");
	}

	QNetworkRequest req = reply->request();
	QUrl requrl(req.url());

	QString str(requrl.path());

	int lastOfFwdSlash = str.lastIndexOf("/");
	int lastOfBkwdSlash = str.lastIndexOf("\\");
	QString appIconName;

	if (lastOfFwdSlash > lastOfBkwdSlash)
	{
		//substring from lastOfFwdSlash to end
		appIconName = str.remove(0, lastOfFwdSlash + 1);
	}
	else if (lastOfFwdSlash < lastOfBkwdSlash)
	{
		//substring from lastOfBkwdSlash to end
		appIconName = str.remove(0, lastOfBkwdSlash + 1);
	}

	QString iconfullpath(PATH_TSEICON_CACHE);
	iconfullpath.append(appIconName);

	logger->Log(DEBUG, " downloadFinished [%s]", appIconName.toUtf8().data());
	logger->Log(DEBUG, " downloadFinished [%s]", iconfullpath.toUtf8().data());

	QByteArray jpegData = reply->readAll();
	QFile file(iconfullpath);
	file.open(QIODevice::ReadWrite);
	file.write(jpegData);
	file.close();

	logger->Log(DEBUG,
			"downloadFinished: icon saved, finding AppName from collection ");

	QString AppName;
	QString iconurl = requrl.toString();
	foreach(AppItem appitem, mAppsCollection){

	if( appitem.appIcon.contains(appIconName)==true)
	{
		AppName= appitem.appName;
		break;
	}
}

	QList<QListWidgetItem*> itemData = l_viewer->findItems(AppName,
			Qt::MatchExactly);
	logger->Log(DEBUG, "downloadFinished: found items:[%d] for [%s]",
			itemData.count(), AppName.toUtf8().data());
	foreach(QListWidgetItem* item , itemData){
	item->setIcon(QIcon(iconfullpath));
	logger->Log(DEBUG,"downloadFinished: setting icon display:[%s]",iconfullpath.toUtf8().data());
}
}

// RDP App To execute
// item clicked
void AppViewer::slot_viewitem_click(QListWidgetItem* clickedItem)
{
	QString runApp = clickedItem->text();
	logger->Log(DEBUG, "  Clicked Icon [%s]", runApp.toUtf8().data());

	// todo
	//...
	//...

	l_viewer->clearSelection();

}

void AppViewer::slot_setGrid()
{
	l_viewer->setViewMode(QListView::IconMode);
	l_viewer->update();
}
void AppViewer::slot_setList()
{
	l_viewer->setViewMode(QListView::ListMode);
	l_viewer->update();
}
void AppViewer::slot_setUniform()
{
	l_viewer->setUniformItemSizes(false);
	mviewX = mviewX + 5;
	mviewY = mviewY + 5;
	l_viewer->setGridSize(QSize(mviewX, mviewY));

	l_viewer->update();
}
void AppViewer::slot_setSpread()
{
	mspacing = mspacing + 5;
	l_viewer->setUniformItemSizes(true);
	l_viewer->setSpacing(mspacing);
	l_viewer->update();
}
void AppViewer::slot_reset()
{
	mspacing = SIZE_SPACING;
	mviewX = SIZE_GRID_X;
	mviewY = SIZE_GRID_Y;
	l_viewer->setSpacing(mspacing);
	l_viewer->setGridSize(QSize(mviewX, mviewY));
	l_viewer->update();
}
void AppViewer::slot_menu_select()
{
	reset();
	e_search->clear();

	QString selects = l_menu->selectedItems().first()->text();

	QString AppName;
	foreach(AppItem appitem, mAppsCollection){
	if( appitem.appGroup.contains(selects)==true)
	{
		AppName= appitem.appName;
		break;
	}
}

	QList<QListWidgetItem*> itemData = l_viewer->findItems(AppName,
			Qt::MatchExactly);
	logger->Log(DEBUG, "  Clicked slot_menu_select [%s][%d]",
			AppName.toUtf8().data(), itemData.count());
	foreach(QListWidgetItem* item , itemData)item->setHidden(true);
	l_viewer->update();
}
void AppViewer::slot_updateUI(QString fname)
{
	initView();
	logger->Log(DEBUG, " updating ui");
}
void AppViewer::slot_Exiting()
{
	logger->Log(DEBUG, " Exiting Application ");
}

AppItem::AppItem(QString name, QString id, QString group, QString icon)
{
	appName = name;
	appID = id;
	appGroup = group;
	appIcon = icon;
}

