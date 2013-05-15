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

#include "profileplugin.h"
#include "profilewidget.h"

Q_EXPORT_PLUGIN2(profile, ProfilePlugin);

ProfilePlugin::ProfilePlugin() : statusIndicatorMenu(0), profile(0)
{
}

void ProfilePlugin::setStatusIndicatorMenuInterface(MStatusIndicatorMenuInterface &menuInterface)
{
    statusIndicatorMenu = &menuInterface;
}

MStatusIndicatorMenuInterface *ProfilePlugin::statusIndicatorMenuInterface() const
{
    return statusIndicatorMenu;
}

// Methods derived from MApplicationExtensionInterface
bool ProfilePlugin::initialize(const QString &)
{
    profile = new ProfileWidget(this);

    return true;
}

QGraphicsWidget *ProfilePlugin::widget()
{
    return profile;
}

