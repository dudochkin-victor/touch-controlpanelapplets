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
#ifndef STATUSINDICATORMENU_STUB_H
#define STATUSINDICATORMENU_STUB_H

#include <QObject>
#include <MWidget>
#include <MStatusIndicatorMenuExtensionInterface>

class StatusIndicatorMenuStub : public MWidget, public MStatusIndicatorMenuInterface
{
    Q_OBJECT

    public:
        virtual void showStatusIndicatorMenu ();
        virtual void hideStatusIndicatorMenu ();

};

#endif
