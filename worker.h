#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QVariant>
#include "simplelistmodel.h"

class Worker : public QObject
{
    Q_OBJECT

    Q_PROPERTY(SimpleListModel* items READ items NOTIFY itemsChanged)
public:
    explicit Worker(QObject *parent = nullptr);

    SimpleListModel* items() { return m_itemsModel; }

public slots:
    void addModelItem();
    void removeLastModelItem();

signals:
    void itemsChanged();

private:
    SimpleListModel* m_itemsModel;
};

#endif // WORKER_H
