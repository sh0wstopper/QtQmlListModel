#include <QObject>
#include <QString>

class DataObject : public QObject {  // my custom container class
    Q_OBJECT
public:
    DataObject(const QString &firstName,
               const QString &lastName,
               QObject* parent = 0):
        QObject(parent),
        first(firstName),
        last(lastName) {
    }

    QString first;
    QString last;
};
