/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (directui@nokia.com)
**
** This file is part of meegotouch-controlpanelapplets.
**
** If you have questions regarding the use of this file, please contact
** Nokia at directui@nokia.com.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/
#ifndef WALLPAPERITRANS_H
#define WALLPAPERITRANS_H

#include <QObject>
#include <QPointF>
#include <QSize>
#include <MApplication>

class QSize;
class QPixmap;


/*!
 * A class to manipulate and save images for the meego control panel wallpaper 
 * applet.
 */
class WallpaperITrans : public QObject
{
    Q_OBJECT

public:
    WallpaperITrans ();
    WallpaperITrans (const WallpaperITrans &orig);

    WallpaperITrans &operator= (const WallpaperITrans &rhs);
    int operator* (const int i) const;
    WallpaperITrans &operator+= (const QPointF &rsh);

    int x () const;
    int y () const;
    qreal scale () const;
    void modScale (int i);
    
    void setOffset (const QPointF &offset);
    void setScale (qreal scale);
    
    void setExpectedSize (const QSize &size);
    QSize expectedSize () const;

    int expectedWidth () const;
    int expectedHeight () const;

    M::Orientation orientation () const;
    void setOrientation (M::Orientation orientation);
    
private:
    M::Orientation   m_Orientation;
    qreal            m_Scale;
    QPointF          m_Offset;
    QSize            m_ExpectedSize;
};
#endif
