/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "private/qdeclarativefocuspanel_p.h"

#include "private/qdeclarativeitem_p.h"

#include <QtWidgets/qgraphicsscene.h>
#include <QEvent>

QT_BEGIN_NAMESPACE

/*!
   \qmltype FocusPanel
    \instantiates QDeclarativeFocusPanel
    \since 4.7
    \ingroup qml-basic-interaction-elements

   \brief The FocusPanel item explicitly creates a focus panel.
   \inherits Item

    Focus panels assist in keyboard focus handling when building QML
    applications.  All the details are covered in the
    \l {qmlfocus}{keyboard focus documentation}.
*/

QDeclarativeFocusPanel::QDeclarativeFocusPanel(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    Q_D(QDeclarativeItem);
    d->flags |= QGraphicsItem::ItemIsPanel;
}

QDeclarativeFocusPanel::~QDeclarativeFocusPanel()
{
}

/*!
    \qmlproperty bool FocusPanel::active

    Sets whether the item is the active focus panel.
*/

bool QDeclarativeFocusPanel::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowActivate ||
        event->type() == QEvent::WindowDeactivate)
        emit activeChanged();
    return QDeclarativeItem::sceneEvent(event);
}

QT_END_NAMESPACE