import QtQuick 2.0
import Sailfish.Silica 1.0
import custom.ListStrings 1.0


Page {
    id: page

    allowedOrientations: Orientation.All

    ListStrings {
        id: list_strings
    }

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height

        Column {
            id: column
            width: page.width
            spacing: Theme.paddingLarge

            PageHeader { title: "Page 2"}

            TextField {
                id: text_field
                width: parent.width
                placeholderText: "Поле для ввода"
            }

            Button {
                text: "Добавить слово"
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked: {
                    list_strings.append(text_field.text);
                    text_field.text = "";
                }
            }

            Button {
                text: "Удалить последнее слово"
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked: list_strings.removeLast()
            }

            Label {
                id: label_list_strings
                width: page.width
                wrapMode: "Wrap"
                text: list_strings.list
            }
        }
    }
}
