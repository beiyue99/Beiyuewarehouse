#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextDocument>
#include<QObject>
class MySyntaxHighlighter:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QObject* parent = 0);
protected:
    //重写实现高亮
    void highlightBlock(const QString& text);
};

#endif // MYSYNTAXHIGHLIGHTER_H
