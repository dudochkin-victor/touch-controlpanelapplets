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
#ifndef UT_DISPLAYBUSINESSLOGIC_H
#define UT_DISPLAYBUSINESSLOGIC_H

#include <QtTest/QtTest>
#include <QObject>

class MApplication;
class DisplayBusinessLogic;

class Ut_DisplayBusinessLogic : public QObject 
{
Q_OBJECT

private slots:
    void init ();
    void cleanup ();
    void initTestCase ();
    void cleanupTestCase ();

    void testGetBrightnessValues ();
    void testLightTimeouts ();
    void testSetBrightness ();
    void testSetBlankInhibitValue ();
    void testScreenLightsValues ();

private:
    MApplication       *m_App;
    DisplayBusinessLogic *m_Api;
    int                   m_MaxBrightness, m_MinBrightness;
    int                   m_Maxtimeout, m_Mintimeout;
};

#endif
