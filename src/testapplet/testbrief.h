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
#ifndef TESTBRIEF_H
#define TESTBRIEF_H

#include <QPointer>
#include "dcpbrief.h"

class TestBrief: public DcpBrief
{
    Q_OBJECT

public:
    TestBrief ();
    virtual QString valueText() const;
    virtual int widgetTypeID() const;
};

#endif
