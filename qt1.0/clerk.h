
#ifndef CLERK_H
#define CLERK_H


#include <QObject>


class clerk : public QObject
{
    Q_OBJECT
public:
    explicit clerk(QObject *parent = nullptr);

signals:

};

#endif // CLERK_H
