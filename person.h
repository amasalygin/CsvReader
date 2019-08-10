#ifndef TABLEITEM_H
#define TABLEITEM_H

#include <QObject>

/**
 * @brief The Person class - класс реализующий объекты модели
 */
class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(const QByteArray &name = nullptr, const QByteArray &post = nullptr, QObject *parent = nullptr);

    /** Селекторы
     * @brief getName
     * @brief getPost
     * @brief getVisiblie
     */
    const QByteArray getName();
    const QByteArray getPost();
    bool getVisible();

    /** Модификаторы
     * @brief setName
     * @brief setPost
     * @brief setVisiblie
     */
    bool setName(const QByteArray &name);
    bool setPost(const QByteArray &post);
    bool setVisiblie(bool visible);

private:
    QByteArray _name;
    QByteArray _post;
    bool _visible;
};

#endif // TABLEITEM_H
