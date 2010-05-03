/*=============================================================================

  Library: CTK

  Copyright (c) 2010 German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef CTKPLUGINTABLEMODEL_H
#define CTKPLUGINTABLEMODEL_H

#include <QAbstractTableModel>

#include <QList>

#include <PluginFramework/ctkPlugin.h>

namespace ctk {

  class PluginContext;

  class PluginTableModel : public QAbstractTableModel
  {
  public:

    PluginTableModel(PluginContext* pc, QObject* parent = 0);

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

  private:

    QString getStringForState(const Plugin::State state) const;

    QList<Plugin*> plugins;
  };

}

#endif // CTKPLUGINTABLEMODEL_H
