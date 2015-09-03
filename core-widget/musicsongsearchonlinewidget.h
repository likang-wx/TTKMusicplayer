#ifndef MUSICSONGSEARCHONLINEWIDGET_H
#define MUSICSONGSEARCHONLINEWIDGET_H

/* =================================================
 * This file is part of the Music Player project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicdownloadquerythread.h"
#include "musicquerytablewidget.h"

class MusicDataDownloadThread;
class MusicTextDownLoadThread;

class MUSIC_WIDGET_EXPORT MusicSongSearchOnlineTableWidget : public MusicQueryTableWidget
{
    Q_OBJECT
public:
    explicit MusicSongSearchOnlineTableWidget(QWidget *parent = 0);
    virtual ~MusicSongSearchOnlineTableWidget();

    void startSearchQuery(const QString &text);

signals:
    void musicBgDownloadFinished();

public slots:
    void listCellClicked(int row, int column);
    void clearAllItems();
    void creatSearchedItems(const QString &songname,
                            const QString &artistname,
                            const QString &time);
    void itemDoubleClicked(int row, int column);

protected:
    void addSearchMusicToPlayList(int row);
    void musicDownloadLocal(int row);

};


class QLabel;
class QPushButton;

class MUSIC_WIDGET_EXPORT MusicSongSearchOnlineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MusicSongSearchOnlineWidget(QWidget *parent = 0);
    ~MusicSongSearchOnlineWidget();

    void startSearchQuery(const QString &name) const;

signals:
    void musicBgDownloadFinished();
    void showDownLoadInfoFinished(const QString &name);
    void muiscSongToPlayListChanged(const QString &name);
    void showDownLoadInfoFor(DownLoadType type);

public slots:
    void buttonClicked(int index);

protected:
    void createToolWidget();
    QLabel *m_textLabel;
    MusicSongSearchOnlineTableWidget *m_searchTableWidget;

};

#endif // MUSICSONGSEARCHONLINEWIDGET_H
