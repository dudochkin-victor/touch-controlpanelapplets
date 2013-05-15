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

#include "ut_profiledatainterface.h"
#include "profiledatainterface.h"

#include <MApplication>

#define DEBUG
#include "../../src/debug.h"

/******************************************************************************
 * Ut_ProfileDataInterface implementation. 
 */
void 
Ut_ProfileDataInterface::init()
{
}

void 
Ut_ProfileDataInterface::cleanup()
{
}

static int argc = 1;
static char* app_name = (char*) "./Ut_ProfileDataInterface";

void 
Ut_ProfileDataInterface::initTestCase()
{

    m_App = new MApplication (argc, &app_name);
    m_Api = new ProfileDataInterface;
}

void 
Ut_ProfileDataInterface::cleanupTestCase()
{
    delete m_Api;
    m_App->deleteLater();
}

/*!
 * Reads the profile data and prints the details with debug messages. Chacks if
 * there is at least 1 available profiles.
 */
void 
Ut_ProfileDataInterface::testGetProfilesData ()
{
    QList<ProfileDataInterface::ProfileData> list = m_Api->getProfilesData ();
    int n = 0;

    foreach (ProfileDataInterface::ProfileData item, list) {
        qDebug() << "----------------------------------------------";
        qDebug() << "profile[" << n << "].name        = " <<
            item.profileName;
        qDebug() << "profile[" << n << "].id          = " <<
            item.profileId;
        qDebug() << "profile[" << n << "].vibrationEnabled = " <<
            (item.vibrationEnabled ? "yes" : "no");

        ++n;
    }

    /*
     * We have to get at least one profile. We actually should get 4 of them?
     */
    QVERIFY (n > 0);
}

/*!
 * Will go through the profiles and set each and every one of them as current
 * profile. Tests if the setting of the current profile was successfull.
 */
void 
Ut_ProfileDataInterface::testSetGetProfile ()
{
    for (int profileId = 0; profileId <= 3; ++profileId) {
        qDebug() << "Setting profile to " << profileId;
        m_Api->setProfile (profileId);

        QVERIFY (m_Api->getCurrentProfile() == profileId);
    }
}

/*!
 * Tests if the vibration can be enabled/disabled in the profile. 
 *
 * Please note that this test is currently disabled, since there is some bug in
 * the backend. Ok, as NB#161433 is fixed I re-enable the test.
 */
void 
Ut_ProfileDataInterface::testSetVibration ()
{
    QList<ProfileDataInterface::ProfileData> list;

    /*
     * Let's disable the vibration for all the profiles and check if it is
     * really diabled.
     */
    list = m_Api->getProfilesData ();
    foreach (ProfileDataInterface::ProfileData item, list) {
        m_Api->setVibration (item.profileId, false);
    }

    list = m_Api->getProfilesData ();
    foreach (ProfileDataInterface::ProfileData item, list) {
        if (item.vibrationEnabled)
            qDebug() << "Vibration for " << item.profileName << " is " <<
                (item.vibrationEnabled ? "enabled" : "disabled") <<
                "(should be disabled)";

        QVERIFY (!item.vibrationEnabled);
    }

    /*
     * The same with enabled vibration.
     */
    list = m_Api->getProfilesData ();
    foreach (ProfileDataInterface::ProfileData item, list) {
        m_Api->setVibration (item.profileId, true);
    }

    list = m_Api->getProfilesData ();
    foreach (ProfileDataInterface::ProfileData item, list) {
        if (!item.vibrationEnabled)
            qDebug() << "Vibration for " << item.profileName << " is " <<
                (item.vibrationEnabled ? "enabled" : "disabled") <<
                "(should be enabled)";

        QVERIFY (item.vibrationEnabled);
    }
}

QTEST_APPLESS_MAIN(Ut_ProfileDataInterface)
