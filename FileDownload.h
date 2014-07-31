/*
 * FileDownload.h
 *
 *  Created on: 25-Jul-2014
 *      Author: vijender
 */

#ifndef FILEDOWNLOAD_H_
#define FILEDOWNLOAD_H_

#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class DownloadCollection;

class FileDownload: public QThread
{
Q_OBJECT

public:
	FileDownload();
	~FileDownload();
	void download(QString url, QString file);
	QList<DownloadCollection> m_downloads;

protected:
	void run();

private:
	int m_completed;
	QList<QNetworkReply *> currentDownloads;
	QNetworkAccessManager networkMgr;
	QNetworkRequest* m_networkRequest;
	QNetworkReply* m_networkReply;

public slots:
	void downloadFinished(QNetworkReply *reply);

signals:
	void update(QString fullfilename);
	void downloadFinish(QString fullfilename);

};

class DownloadCollection
{
public:
	DownloadCollection(QString, QString);
	QString url;
	QString path;
};

#endif /* FILEDOWNLOAD_H_ */
