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

#include "testbrief.h"
#include <dcpwidgettypes.h>

#undef DEBUG
#include "../debug.h"

TestBrief::TestBrief ()
{
}

QString 
TestBrief::valueText() const
{
    return "Applet for testing";
}

int
TestBrief::widgetTypeID() const
{
    return DcpWidgetType::Label;
}

