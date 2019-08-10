#include "person.h"
#include <qDebug>

Person::Person(const QByteArray &name, const QByteArray &post, QObject *parent) : QObject (parent)
{
    _post = post;
    _name = name;
    _visible = false;
}

const QByteArray Person::getName()
{
    return _name;
}

const QByteArray Person::getPost()
{
    return _post;
}

bool Person::getVisible()
{
    return _visible;
}

bool Person::setName(const QByteArray &name)
{
    _name = name;
    return true;
}

bool Person::setPost(const QByteArray &post)
{
    _post = post;
    return true;
}

bool Person::setVisiblie(bool visible)
{
    qDebug() << _name << visible;
    _visible = visible;
    return true;
}


