/*
 * FileDownload.cpp
 *
 *  Created on: 25-Jul-2014
 *      Author: vijender
 */

#include "FileDownload.h"
#include "PLog.h"
extern PLog* logger;

FileDownload::FileDownload()
{
	m_completed = 0;
	connect(&networkMgr, SIGNAL(finished(QNetworkReply*)), this,
			SLOT(downloadFinished(QNetworkReply*)));
}

FileDownload::~FileDownload()
{
}

void FileDownload::run()
{
	m_completed = 0;
	for (int i = 0; i < m_downloads.count(); i++)
	{
		logger->Log(DEBUG, " START Download [%s]",
				m_downloads[i].url.toUtf8().data());
		m_networkRequest = new QNetworkRequest(
				QUrl::fromEncoded(m_downloads[i].url.toLocal8Bit()));
		m_networkReply = networkMgr.get(*m_networkRequest);
	}
	exec();
}

void FileDownload::download(QString url, QString path)
{
	m_downloads.append(DownloadCollection(url, path));
}

void FileDownload::downloadFinished(QNetworkReply *reply)
{
	QUrl url = reply->url();
	QString fullfilename;

	if (reply->error())
	{
		logger->Log(DEBUG, "Download of %s failed: %s\n",
				url.toEncoded().constData(), qPrintable(reply->errorString()));
	}
	else
	{
		foreach(DownloadCollection item, m_downloads){
		if( item.url.contains(url.toString())==true)
		{
			fullfilename= item.path;
			break;
		}
	}

	QByteArray jpegData = reply->readAll();
	QFile file(fullfilename);
	file.open(QIODevice::ReadWrite);
	file.write(jpegData);
	file.close();

	logger->Log(DEBUG,"Download of %s succeeded (saved to %s)\n",
			url.toEncoded().constData(), qPrintable(fullfilename));
}

	m_completed++;

	if (m_completed == m_downloads.count())
		emit downloadFinish("FinishedAll");

	emit update(fullfilename);
}

DownloadCollection::DownloadCollection(QString _url, QString _path)
{
	url = _url;
	path = _path;
}

