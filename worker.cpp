#include "worker.h"
#include "dataobject.h"
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{
    m_itemsModel = new SimpleListModel(this);
    emit itemsChanged();
    // Create dummy data for the list
    DataObject *first = new DataObject(QString("Arthur"), QString("Dent"), this);
    DataObject *second = new DataObject(QString("Ford"), QString("Prefect"), this);
    DataObject *third = new DataObject(QString("Zaphod"), QString("Beeblebrox"), this);
    m_itemsModel->addItem(first);
    m_itemsModel->addItem(second);
    m_itemsModel->addItem(third);
}

void Worker::addModelItem()
{
    int index =  m_itemsModel->rowCount()+1;
    DataObject *item = new DataObject(QString("First %1").arg(index),
                                      QString("Last %1").arg(index),
                                      this);
    m_itemsModel->addItem(item);
}

void Worker::removeLastModelItem()
{
    int index =  m_itemsModel->rowCount()-1;
    DataObject *item = m_itemsModel->removeItem(index);
    if(item)
        item->deleteLater();
}
