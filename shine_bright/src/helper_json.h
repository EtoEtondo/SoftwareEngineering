#pragma once

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QFile>
#include <QString>


QJsonObject read_json(QString file) {
    QFile json_file;
    QString content;
    json_file.setFileName(file);
    json_file.open(QIODevice::ReadOnly | QIODevice::Text);
    content = json_file.readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(content.toUtf8());
    QJsonObject json_obj = json_doc.object();
    return json_obj;
}


QJsonValue get_json_keys(QJsonObject json_obj, int n) {
    return json_obj.value(json_obj.keys()[n]);
}
